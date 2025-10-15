/*
Main program for the virtual memory project.
Make all of your modifications to this file.
You may add or rearrange any code or data as you need.
The header files page_table.h and disk.h explain
how to use the page table and disk interfaces.
*/

#include "page_table.h"
#include "disk.h"
#include "program.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#include <time.h>

#define MAX_FRAMES 100 

int frames[MAX_FRAMES]; 
int frame_queue[MAX_FRAMES]; 
int frame_count = 0;
int fifo_victim = 0; 
int next_frame = 0;

int page_faults = 0;  
int disk_reads = 0;  
int disk_writes = 0; 
struct disk *disk;

void initialize_frames(int nframes) {
    for (int i = 0; i < nframes; i++) {
        frames[i] = 0;
    }
}

void page_fault_handler_fifo(struct page_table *pt, int page) {
    page_faults++;

    int frame, bits;
    int nframes = page_table_get_nframes(pt);
    page_table_get_entry(pt, page, &frame, &bits);

    if (bits & PROT_READ) {
        if (!(bits & PROT_WRITE)) {
            page_table_set_entry(pt, page, frame, PROT_READ | PROT_WRITE);
        }
        return;
    }

    for (int i = 0; i < nframes; i++) {
        if (frames[i] == 0) { 
            page_table_set_entry(pt, page, i, PROT_READ);
            disk_reads++;
            disk_read(disk, page, page_table_get_physmem(pt) + i * PAGE_SIZE);
            frames[i] = 1;
            return;
        }
    }

    int j = 0;
    while (j < page_table_get_npages(pt)) {
        page_table_get_entry(pt, j, &frame, &bits); 

        if (frame == fifo_victim) {
            if (bits & PROT_READ) { 
                if (bits & PROT_WRITE) {
                    disk_write(disk, j, page_table_get_physmem(pt) + frame * PAGE_SIZE);
                    disk_writes++;
                }

                disk_read(disk, page, page_table_get_physmem(pt) + frame * PAGE_SIZE);
                page_table_set_entry(pt, j, 0, 0); 
                page_table_set_entry(pt, page, fifo_victim, PROT_READ);
                disk_reads++;
                fifo_victim = (fifo_victim + 1) % nframes; 
                return;
            }
        }
        j++;
    }
}


void page_fault_handler_random(struct page_table *pt, int page) {
    page_faults++;

    int frame, bits;
    int nframes = page_table_get_nframes(pt);
    page_table_get_entry(pt, page, &frame, &bits);

    if (bits & PROT_READ) {
        if (!(bits & PROT_WRITE)) {
            page_table_set_entry(pt, page, frame, PROT_READ | PROT_WRITE);
        }
        return;
    }

    for (int i = 0; i < nframes; i++) {
        if (frames[i] == 0) { 
            page_table_set_entry(pt, page, i, PROT_READ);
            disk_reads++;
            disk_read(disk, page, page_table_get_physmem(pt) + i * PAGE_SIZE);
            frames[i] = 1; 
            return;
        }
    }

    int victim_frame = lrand48() % nframes; 
    int j = 0;
    while (j < page_table_get_npages(pt)) {
        page_table_get_entry(pt, j, &frame, &bits); 

        if (frame == victim_frame) { 
            if (bits & PROT_READ) { 
                if (bits & PROT_WRITE) { 
                    disk_write(disk, j, page_table_get_physmem(pt) + frame * PAGE_SIZE);
                    disk_writes++;
                }

                disk_read(disk, page, page_table_get_physmem(pt) + frame * PAGE_SIZE);
                page_table_set_entry(pt, j, 0, 0);  
                page_table_set_entry(pt, page, victim_frame, PROT_READ);  
                disk_reads++;
                return; 
            }
        }
        j++;
    }
}



int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("use: virtmem <npages> <nframes> <random|fifo> <sort|scan|focus>\n");
        return 1;
    }

    int npages = atoi(argv[1]);
    int nframes = atoi(argv[2]);
    const char *algorithm = argv[3];
    const char *program = argv[4];

    initialize_frames(nframes);  

    disk = disk_open("myvirtualdisk", npages);  
    if (!disk) {
        fprintf(stderr, "couldn't create virtual disk: %s\n", strerror(errno));
        return 1;
    }

    page_fault_handler_t handler;
    if (!strcmp(algorithm, "fifo")) {
        handler = page_fault_handler_fifo;
    } else if (!strcmp(algorithm, "random")) {
        handler = page_fault_handler_random;
    } else {
        fprintf(stderr, "Unknown algorithm: %s\n", algorithm);
        return 1;
    }

    struct page_table *pt = page_table_create(npages, nframes, handler);
    if (!pt) {
        fprintf(stderr, "couldn't create page table: %s\n", strerror(errno));
        return 1;
    }

    char *virtmem = page_table_get_virtmem(pt);
    char *physmem = page_table_get_physmem(pt);

    if (!strcmp(program, "sort")) {
        sort_program(virtmem, npages * PAGE_SIZE);
    } else if (!strcmp(program, "scan")) {
        scan_program(virtmem, npages * PAGE_SIZE);
    } else if (!strcmp(program, "focus")) {
        focus_program(virtmem, npages * PAGE_SIZE);
    } else {
        fprintf(stderr, "unknown program: %s\n", program);
    }

    printf("Page faults: %d\n", page_faults);
    printf("Disk reads: %d\n", disk_reads);
    printf("Disk writes: %d\n", disk_writes);

    page_table_delete(pt);
    disk_close(disk);

    return 0;
}
