// Grafo.h
#ifndef GRAFO_H
#define GRAFO_H

#include <vector>
#include <queue>
#include "NodosG.h"
#include "Objeto3D.h"

class Grafo {
private:
    std::vector<NodosG> nodos;

    // Estructura auxiliar para la cola de prioridad en Dijkstra
    struct ComparadorNodos {
        bool operator()(const std::pair<int, float>& a, const std::pair<int, float>& b) {
            return a.second > b.second;
        }
    };

public:
    // Constructor que construye el grafo a partir de un Objeto3D
    void construirGrafo(const Object3D& objeto);

    // Método principal de Dijkstra
    std::vector<int> encontrarRutaCorta(int inicio, int fin);

    // Método para calcular distancia euclidiana entre dos puntos
    float calcularDistancia(const Punto& p1, const Punto& p2) const;

    // Método para obtener el número de nodos
    size_t getTamanio() const { return nodos.size(); }

    // Método para obtener un nodo específico
    const NodosG& getNodo(int indice) const { return nodos[indice]; }
};

#endif
