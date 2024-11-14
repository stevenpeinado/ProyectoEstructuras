#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include "Punto.h"
#ifndef UNTITLED_CARA_H
#define UNTITLED_CARA_H
class Cara {
public:
    std::deque<Punto> vertices;
    Cara(const Punto& v1, const Punto& v2, const Punto& v3, const Punto& v4) {
        vertices.push_back(v1);
        vertices.push_back(v2);
        vertices.push_back(v3);
        vertices.push_back(v4);
    }
    Cara() = default;

    const std::deque<Punto> &getVertices() const {
        return vertices;
    }

    void setVertices(const std::deque<Punto> &vertices) {
        Cara::vertices = vertices;
    }
};
#endif //UNTITLED_CARA_H
