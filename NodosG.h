#ifndef NODOSG_H
#define NODOSG_H

#include <vector>
#include "Punto.h"

class NodosG {
private:
    int id;
    Punto punto;
    std::vector<std::pair<NodosG*, float>> adyacentes; // par de (nodo, peso)
    bool visitado;
    float distancia;  // para Dijkstra
    NodosG* anterior;  // para reconstruir el camino

public:
    NodosG(int id, Punto p);
    void agregarAdyacente(NodosG* nodo, float peso);
    int getId() const;
    Punto getPunto() const;
    const std::vector<std::pair<NodosG*, float>>& getAdyacentes() const;
    void setVisitado(bool v);
    bool getVisitado() const;
    void setDistancia(float d);
    float getDistancia() const;
    void setAnterior(NodosG* n);
    NodosG* getAnterior() const;
};

#endif // NODOSG_H


