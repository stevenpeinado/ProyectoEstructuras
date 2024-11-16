#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include "Punto.h"
#ifndef UNTITLED_CARA_H
#define UNTITLED_CARA_H
class Cara {
public:
    std::deque<int> vertices; // Índices de los vértices

    Cara(int v1, int v2, int v3, int v4) {
        vertices.push_back(v1);
        vertices.push_back(v2);
        vertices.push_back(v3);
        vertices.push_back(v4);
    }
    Cara() = default;

    const std::deque<int>& getVertices() const {
        return vertices;
    }

    void setVertices(const std::deque<int>& vertices) {
        this->vertices = vertices;
    }
};

#endif //UNTITLED_CARA_H
