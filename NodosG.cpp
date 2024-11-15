// NodoG.cpp
#include "NodosG.h"
#include <limits>

NodosG::NodosG(int idx, const Punto& p) :
        indice(idx),
        punto(p),
        distancia(std::numeric_limits<float>::infinity()),
        anterior(-1)
{}

void NodosG::agregarAdyacente(int indiceNodo, float peso) {
    adyacentes.push_back({indiceNodo, peso});
}

void NodosG::reset() {
    distancia = std::numeric_limits<float>::infinity();
    anterior = -1;
}