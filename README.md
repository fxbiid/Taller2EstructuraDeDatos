# Taller 2 – Estructuras de Datos
**Autor:** Fabián Nicolás Díaz Navarrete  
**Fecha:** Octubre 2025  
Implementación de una **matriz poco poblada (Sparse Matrix)** en **C++**, utilizando **listas enlazadas simples** para optimizar el uso de memoria.  
El programa permite realizar operaciones de:

- Inserción de datos (`add`)
- Obtención de datos (`get`)
- Eliminación (`remove`)
- Cálculo de densidad (`density`)
- Multiplicación de matrices (`multiply`)


 **Compilacion:**
 ```bash
 g++ -std=c++17 -O2 -Wall -Wextra -pedantic \
Nodo.cpp SparseMatrix.cpp main.cpp -o SparseMatrixApp
./SparseMatrixApp
