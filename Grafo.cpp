#include "Grafo.h"
#include "Punto.h"
#include <queue>
#include <limits>
#include <cmath>
#include <iostream>

Grafo::Grafo() {}

Grafo::~Grafo() {
    clear();
}

void Grafo::clear() {
    for(auto nodo : nodos) {
        delete nodo;
    }
    nodos.clear();
}

void Grafo::agregarNodo(int id, Punto p) {
    nodos.push_back(new NodosG(id, p));
}

void Grafo::agregarArista(int id1, int id2) {
    NodosG* n1 = getNodo(id1);
    NodosG* n2 = getNodo(id2);
    if(n1 && n2) {
        float peso = n1->getPunto().distancia(n2->getPunto());
        n1->agregarAdyacente(n2, peso);
        n2->agregarAdyacente(n1, peso);  // Grafo no dirigido
    }
}

void Grafo::limpiarEstado() {
    for(auto nodo : nodos) {
        nodo->setVisitado(false);
        nodo->setDistancia(std::numeric_limits<float>::infinity()); // Mejor uso que INFINITY
        nodo->setAnterior(nullptr);
    }
}

NodosG* Grafo::getNodo(int id) {
    for(auto nodo : nodos) {
        if(nodo->getId() == id) return nodo;
    }
    return nullptr;
}

std::vector<int> Grafo::dijkstra(int inicio, int fin) {
    limpiarEstado();
    std::vector<int> camino;

    // Cola de prioridad para Dijkstra
    auto comp = [](NodosG* a, NodosG* b) { return a->getDistancia() > b->getDistancia(); };
    std::priority_queue<NodosG*, std::vector<NodosG*>, decltype(comp)> pq(comp);

    // Inicializar nodo inicial
    NodosG* nodoInicio = getNodo(inicio);
    if(!nodoInicio) return camino;
    nodoInicio->setDistancia(0);
    pq.push(nodoInicio);

    while(!pq.empty()) {
        NodosG* actual = pq.top();
        pq.pop();

        if(actual->getId() == fin) break;
        if(actual->getVisitado()) continue;

        actual->setVisitado(true);

        // Explorar vecinos
        for(const auto& par : actual->getAdyacentes()) {
            NodosG* vecino = par.first;
            float peso = par.second;

            if(!vecino->getVisitado()) {
                float nuevaDistancia = actual->getDistancia() + peso;
                if(nuevaDistancia < vecino->getDistancia()) {
                    vecino->setDistancia(nuevaDistancia);
                    vecino->setAnterior(actual);
                    pq.push(vecino);
                }
            }
        }
    }

    // Reconstruir camino
    NodosG* actual = getNodo(fin);
    if(actual && actual->getDistancia() != std::numeric_limits<float>::infinity()) {
        while(actual) {
            camino.insert(camino.begin(), actual->getId());
            actual = actual->getAnterior();
        }
    }

    return camino;
}
