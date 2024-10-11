#ifndef UNTITLED_PUNTO_H
#define UNTITLED_PUNTO_H
class Punto {
public:
    float x, y, z;

    Punto(float xVal, float yVal, float zVal) : x(xVal), y(yVal), z(zVal) {}
    Punto ()=default;
    float distancia(Punto p) const;
};
#endif //UNTITLED_PUNTO_H//
