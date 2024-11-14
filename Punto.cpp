#include "Punto.h"
#include <cmath>
float Punto::distancia(Punto p) const {
    float dx = this->x - p.x;
    float dy = this->y - p.y;
    float dz = this->z- p.z;
    return sqrt(dx * dx + dy * dy + dz * dz);
}

float Punto::getX() const {
    return x;
}

void Punto::setX(float x) {
    Punto::x = x;
}

float Punto::getY() const {
    return y;
}

void Punto::setY(float y) {
    Punto::y = y;
}

float Punto::getZ() const {
    return z;
}

void Punto::setZ(float z) {
    Punto::z = z;
}
