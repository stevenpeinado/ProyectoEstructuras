// NodoG.h
#ifndef NODOG_H
#define NODOG_H

#include <vector>
#include <memory>
#include "Punto.h"

class NodosG {
private:
    int indice;
    Punto punto;  // Almacenamos el punto directamente, no como puntero
    std::vector<std::pair<int, float>> adyacentes; // Par de (índice del nodo, peso)
    float distancia;
    int anterior;

public:
    // Constructor
    NodosG(int idx = -1, const Punto& p = Punto());

    // Getters y setters
    int getIndice() const { return indice; }
    const Punto& getPunto() const { return punto; }
    void setPunto(const Punto& p) { punto = p; }

    // Manejo de adyacencia
    void agregarAdyacente(int indiceNodo, float peso);
    const std::vector<std::pair<int, float>>& getAdyacentes() const { return adyacentes; }

    // Métodos para Dijkstra
    void setDistancia(float d) { distancia = d; }
    float getDistancia() const { return distancia; }
    void setAnterior(int a) { anterior = a; }
    int getAnterior() const { return anterior; }

    // Reset del nodo para nuevo cálculo
    void reset();
};

#endif


