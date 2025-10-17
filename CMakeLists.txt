cmake_minimum_required(VERSION 4.0)
project(Taller2Estructura)

set(CMAKE_CXX_STANDARD 20)

add_executable(Taller2Estructura main.cpp
        SparseMatrix.cpp
        SparseMatrix.h
        Nodo.cpp
        Nodo.h)
