#include "Nodo.h"
#include <cmath>
#include <iostream>

Nodo *Nodo::getPadre() const {
    return padre;
}

void Nodo::setPadre(Nodo *padre)  {
    Nodo::padre = padre;
}

const Punto &Nodo::getDato() const {
    return dato;
}

void Nodo::setDato(const Punto &dato) {
    Nodo::dato = dato;
}



bool Nodo::esHoja() const {
    if (getDer() == nullptr && getIzq() == nullptr){
        return true;
    } else{
        return false;
    }
}

float Nodo::distancia(Punto p) const {
    float dx = this->getDato().x - p.x;
    float dy = this->getDato().y - p.y;
    float dz = this->getDato().z- p.z;
    return sqrt(dx * dx + dy * dy + dz * dz);
}
float Nodo::encontrarDistanciaEje(Punto p)const {
    if(this->getDimension()=='x') {
        float a = p.x -this->getDato().x;
        a = abs(a);
        return a;
    }
    else if(this->getDimension()=='y') {
        float b = p.y -this->getDato().y;

        return b;
    }
    else if(this->getDimension()=='z') {
        float c = p.z -this->getDato().z;

        return c;
    }

}
Nodo *Nodo::getDer() const {
    return der;
}

void Nodo::setDer(Nodo *der) {
    Nodo::der = der;
}

Nodo *Nodo::getIzq() const {
    return izq;
}

void Nodo::setIzq(Nodo *izq) {
    Nodo::izq = izq;
}

const char Nodo::getDimension() const {
    return dimension;
}

void Nodo::setDimension(const char &d) {
    this->dimension = d;
}


const Punto Nodo::encontrarCercano(Punto p,float dis,Punto aux) const{

    float a=distancia(p);
        if(a<dis || dis==-1) {
            dis = a;
            aux=this->getDato();
        }

    if(dis==0){
        return aux;
    }
    if(!this->esHoja()) {
        if (dimension == 'x') {
            if (p.x > this->getDato().x) {

                this->getDer()->encontrarCercano(p, dis, aux);
            } else {
                this->getIzq()->encontrarCercano(p, dis, aux);
            }

        }
        if (dimension == 'y') {
            if (p.y > this->getDato().y) {
                this->getDer()->encontrarCercano(p, dis, aux);
            } else {
                this->getIzq()->encontrarCercano(p, dis, aux);
            }

        }
        if (dimension == 'z') {
            if (p.z > this->getDato().z) {
                this->getDer()->encontrarCercano(p, dis, aux);
            } else {
                this->getIzq()->encontrarCercano(p, dis, aux);
            }
        }
    }
    float b=this->encontrarDistanciaEje(p);
    if (b < dis) {
        encontrarCercano(p, dis, aux);
    }
    return aux;
}