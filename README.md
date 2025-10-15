# 🧠 Virtual Memory - Page Fault Management  
### 💻 Tarea 2 — Memoria Virtual: Manejo de faltas de página  
### 💻 Assignment 2 — Virtual Memory: Page Fault Handling

---

## 🇪🇸 Español

Este proyecto fue desarrollado como parte del curso **Sistemas Operativos** en la **Universidad de los Andes**.  
El objetivo fue implementar un **administrador de memoria virtual con paginación bajo demanda**, simulando faltas de página y distintos algoritmos de reemplazo.

### 🔹 Funcionalidades

- **Manejador de faltas de página (`page_fault_handler`)**  
  - Selecciona marcos libres o páginas víctima para reemplazo
  - Aplica algoritmos **FIFO** y **Random**
  - Actualiza la tabla de páginas y los bits de protección (lectura/escritura)

- **Simulación de programas** (`scan`, `sort`, `focus`)  
  - Permite observar el comportamiento de los algoritmos bajo distintos patrones de acceso a memoria
  - Genera estadísticas de número de faltas de página, lecturas y escrituras a disco

### ⚙️ Compilación y ejecución

```bash
git clone <tu-repo-url>
cd virtmem
make
./virtmem -n 100 -f 10 -a fifo -p scan
```

- `-n`: Número de páginas de memoria virtual
- `-f`: Número de marcos físicos
- `-a`: Algoritmo de reemplazo (`rand` o `fifo`)
- `-p`: Programa a ejecutar (`scan`, `sort`, `focus`)

### 🧪 Resultados y análisis

Se deben generar gráficos de línea comparando **faltas de página**, **lecturas** y **escrituras** entre los algoritmos FIFO y Random, variando la cantidad de marcos de memoria.

### 👥 Autor

**Erik Eckell**  
Estudiante de Ingeniería Civil en Ciencias de la Computación  
Universidad de los Andes  
📫 [epeckell@miuandes.cl](mailto:epeckell@miuandes.cl)

---

## 🇬🇧 English

This project was developed as part of the **Operating Systems** course at **Universidad de los Andes**.  
The goal was to implement a **virtual memory manager with demand paging**, simulating page faults and replacement algorithms.

### 🔹 Features

- **Page fault handler (`page_fault_handler`)**  
  - Chooses free frames or victim pages for replacement
  - Implements **FIFO** and **Random** algorithms
  - Updates the page table and access bits (read/write)

- **Program simulation** (`scan`, `sort`, `focus`)  
  - Shows the behavior of replacement algorithms under different memory access patterns
  - Produces stats: page faults, disk reads, disk writes

### ⚙️ Build and run

```bash
git clone <your-repo-url>
cd virtmem
make
./virtmem -n 100 -f 10 -a fifo -p scan
```

- `-n`: Number of virtual memory pages
- `-f`: Number of physical frames
- `-a`: Replacement algorithm (`rand` or `fifo`)
- `-p`: Program to run (`scan`, `sort`, `focus`)

### 🧪 Results and Analysis

Generate line charts comparing **page faults**, **disk reads**, and **disk writes** for FIFO and Random algorithms, varying the number of physical frames.

### 👥 Author

**Erik Eckell**  
Computer Science Engineering Student  
Universidad de los Andes  
📫 [epeckell@miuandes.cl](mailto:epeckell@miuandes.cl)

---

### 🧾 Licencia / License

Educational use only.
