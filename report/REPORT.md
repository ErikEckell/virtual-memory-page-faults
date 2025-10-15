![fifo scan](https://github.com/icc3201-202420/tarea-2-eckell_guzman/blob/main/imagenes/fifo%20scan.jpg)

![random scan](https://github.com/icc3201-202420/tarea-2-eckell_guzman/blob/main/imagenes/random%20scan.jpg)

![faltas scan](https://github.com/icc3201-202420/tarea-2-eckell_guzman/blob/main/imagenes/faltas%20scan.jpg)

![SCAN graficos](https://github.com/icc3201-202420/tarea-2-eckell_guzman/blob/main/imagenes/scanresto1.jpg)

Para los datos obtenidos en el algoritmo de Scan, al comparar los gráficos del método FIFO y random se puede evidenciar como, para el gráfico de las faltas de página ambos métodos mantienen una igual cantidad de faltas hasta los 20 marcos de página donde el método FIFO continua con 1200 faltas de página hasta caer abruptamente a las 200 en los 100 marcos, mientras que el método random comienza a disminuir su número de faltas gradualmente formando una pequeña curva de caída hasta también llegar a las 200 faltas.

Para el gráfico de Marcos de página vs Lecturas de disco el comportamiento es similar al de faltas de página, donde el método FIFO se mantiene constante hasta los 90 marcos y el método random a partir de los 20 marcos decae, juntándose ambos en las 100 lecturas de disco.

Para el gráfico de escrituras de disco ambos métodos mantienen 100 lecturas de disco constantes hasta los 80 marcos para el método random y 90 para el método fifo donde caen a 0 lecturas en los 100 marcos


![fifo sort](https://github.com/icc3201-202420/tarea-2-eckell_guzman/blob/main/imagenes/fifo%20sort.jpg)

![random sort](https://github.com/icc3201-202420/tarea-2-eckell_guzman/blob/main/imagenes/random%20sort.jpg)

![faltas sort](https://github.com/icc3201-202420/tarea-2-eckell_guzman/blob/main/imagenes/faltas%20sort.jpg)

![sort graficos](https://github.com/icc3201-202420/tarea-2-eckell_guzman/blob/main/imagenes/sort%20resto.jpg)

Al usar Sort los tres gráficos presentan una pendiente similar, en la que según aumenta el número de marcos, disminuye el número de faltas, lecturas y escrituras. El método random se mantiene por encima del método FIFO hasta los 60 marcos donde este último lo supera ligeramente hasta que se vuelven a reunir en los 100 marcos, en 200 faltas de páginas, 100 lecturas de disco y 0 escrituras de disco.

Se puede identificar que en 0 marcos el método random presenta muchas más faltas de página y lecturas de disco que el método FIFO, aun así, en los siguientes números de marco se mantiene una diferencia menor.

![fifo focus](https://github.com/icc3201-202420/tarea-2-eckell_guzman/blob/main/imagenes/fifo%20focus.jpg)

![random focus](https://github.com/icc3201-202420/tarea-2-eckell_guzman/blob/main/imagenes/random%20focus.jpg)

![faltas focus](https://github.com/icc3201-202420/tarea-2-eckell_guzman/blob/main/imagenes/faltas%20focus.jpg)

![focus graficos](https://github.com/icc3201-202420/tarea-2-eckell_guzman/blob/main/imagenes/resto%20focus.jpg)

Para los datos utilizando focus en el gráfico de faltas de página ambos métodos disminuyen de manera similar según aumenta el número de marcos, a partir de los 50 marcos el método FIFO presenta picos de 40 faltas de diferencia en comparación con random hasta que se reúnen en 200 faltas de página a los 100 marcos.

Para el gráfico de lecturas de disco hasta los 60 marcos es similar al de faltas de página para luego el método FIFO permanecer en 200 hasta los 100 marcos donde se reúne con el método random, que se mantuvo similar al gráfico de faltas.

Para el gráfico de escrituras de disco hasta los 40 marcos mantenían un registro similar, luego el método random disminuye su cantidad de escrituras en comparación con el método fifo que se mantiene sobre este por 30 escrituras y en algunos casos hasta el doble de los datos de random. Finalmente se reúnen en las 0 escrituras a los 100 marcos.



