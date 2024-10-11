#include "Punto.h"
#include <cmath>
float Punto::distancia(Punto p) const {
    float dx = this->x - p.x;
    float dy = this->y - p.y;
    float dz = this->z- p.z;
    return sqrt(dx * dx + dy * dy + dz * dz);
}