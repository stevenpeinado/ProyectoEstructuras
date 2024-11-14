cmake_minimum_required(VERSION 3.27)
project(pro6oct)

set(CMAKE_CXX_STANDARD 17)

add_executable(pro6oct main.cpp
        Arbol.cpp
        Arbol.h
        Nodo.cpp
        Nodo.h
        Punto.cpp
        Punto.h
        Objeto3D.cpp
        Objeto3D.h
        Comandos.cpp
        Comandos.h
        Cara.cpp
        Cara.h
        Grafo.cpp
        Grafo.h
        NodosG.cpp
        NodosG.h
)
