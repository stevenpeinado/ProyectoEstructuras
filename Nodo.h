//
// Created by SPein on 5/10/2024.
//

#ifndef PROYECTOENTREGA1CARRERO_ETAL_NODO_H
#define PROYECTOENTREGA1CARRERO_ETAL_NODO_H
#include "punto.h"

using namespace std;
class Nodo {
private:
    Nodo* padre;
    Punto dato;
    Nodo* der;
    Nodo* izq;
    char dimension;
    float encontrarDistanciaEje(Punto p)const;
public:
    Nodo(const Punto& p, char dim) :padre(nullptr) ,dato(p), der(nullptr), izq(nullptr), dimension(dim) {

    }
    Nodo() : padre(nullptr),dato(), der(nullptr), izq(nullptr), dimension('\0') {
        // Constructor sin parámetros
    }
    Nodo *getPadre() const;

    void setPadre(Nodo *padre);

    const Punto &getDato() const;

    void setDato(const Punto &dato);

    Nodo *getDer() const;

    void setDer(Nodo *der);

    Nodo *getIzq() const;

    void setIzq(Nodo *izq);

    const char getDimension() const;

    void setDimension(const char &d);

    bool esHoja() const;

    float distancia(Punto p) const;

    const Punto encontrarCercano(Punto p,float dis,Punto aux)const ;

};


#endif //PROYECTOENTREGA1CARRERO_ETAL_NODO_H
