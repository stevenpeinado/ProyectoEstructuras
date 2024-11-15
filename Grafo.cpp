// Grafo.cpp
#include "Grafo.h"
#include <cmath>
#include <queue>
#include <limits>
#include <algorithm>

void Grafo::construirGrafo(const Object3D& objeto) {
    // Limpiar el grafo
    nodos.clear();

    // Crear nodos para cada vértice
    for (size_t i = 0; i < objeto.getPuntos().size(); i++) {
        nodos.push_back(NodosG(i, objeto.getPuntos()[i]));
    }

    // Conectar nodos según las caras del objeto
    for (const Cara& cara : objeto.getCaras()) {
        const auto& vertices = cara.getVertices();
        // Conectar todos los vértices de la cara entre sí
        for (size_t i = 0; i < vertices.size(); i++) {
            for (size_t j = i + 1; j < vertices.size(); j++) {
                float peso = calcularDistancia(vertices[i], vertices[j]);
                nodos[i].agregarAdyacente(j, peso);
                nodos[j].agregarAdyacente(i, peso);
            }
        }
    }
}

float Grafo::calcularDistancia(const Punto& p1, const Punto& p2) const {
    float dx = p1.getX() - p2.getX();
    float dy = p1.getY() - p2.getY();
    float dz = p1.getZ() - p2.getZ();
    return std::sqrt(dx*dx + dy*dy + dz*dz);
}

std::vector<int> Grafo::encontrarRutaCorta(int inicio, int fin) {
    // Inicializar todos los nodos
    for (NodosG& nodo : nodos) {
        nodo.reset();
    }

    // Configurar nodo inicial
    nodos[inicio].setDistancia(0);

    // Cola de prioridad para Dijkstra
    std::priority_queue<std::pair<int, float>,
            std::vector<std::pair<int, float>>,
            ComparadorNodos> cola;
    cola.push({inicio, 0});

    // Algoritmo de Dijkstra
    while (!cola.empty()) {
        int actual = cola.top().first;
        float distActual = cola.top().second;
        cola.pop();

        // Si encontramos el destino, terminamos
        if (actual == fin) break;

        // Si la distancia actual es mayor que la almacenada, ignoramos
        if (distActual > nodos[actual].getDistancia()) continue;

        // Revisar todos los vecinos
        for (const auto& vecino : nodos[actual].getAdyacentes()) {
            int indiceVecino = vecino.first;
            float peso = vecino.second;
            float nuevaDistancia = nodos[actual].getDistancia() + peso;

            if (nuevaDistancia < nodos[indiceVecino].getDistancia()) {
                nodos[indiceVecino].setDistancia(nuevaDistancia);
                nodos[indiceVecino].setAnterior(actual);
                cola.push({indiceVecino, nuevaDistancia});
            }
        }
    }

    // Reconstruir el camino
    std::vector<int> camino;
    if (nodos[fin].getDistancia() == std::numeric_limits<float>::infinity()) {
        return camino; // Camino vacío si no hay ruta
    }

    for (int actual = fin; actual != -1; actual = nodos[actual].getAnterior()) {
        camino.push_back(actual);
    }
    std::reverse(camino.begin(), camino.end());

    return camino;
}
