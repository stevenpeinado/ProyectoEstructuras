#include "Objeto3D.h"

#include <algorithm>
#include <iostream>
using namespace std;
Nodo* Object3D::crearArbol(deque<Punto> puntos, int aux,Nodo* nodo) {

    Nodo* n = new Nodo();

    if(aux==1)
        n->setPadre(nullptr);
    else{
        n->setPadre(nodo);
    }

    int residuo= aux % 3;
    if(residuo==1){
        sort(puntos.begin(), puntos.end(), [](const Punto& a, const Punto& b) {
                return a.x < b.x;
        });


        int medianaIndex = puntos.size() / 2;

        Punto medianaPunto = puntos[medianaIndex];

        deque<Punto> nuevo;
        for (int i = 0; i < medianaIndex; ++i) {
            nuevo.push_back(puntos[i]);
        }
        aux+=1;

        n->setDato(medianaPunto);
        n->setDimension('x');


        if(nuevo.size() > 0 ){
            Nodo* hijo=crearArbol(nuevo,aux,n);

            n->setIzq(hijo);
        }
        else {
            n->setIzq(nullptr);
        }

        nuevo.clear();
        for (int i = medianaIndex+1; i < puntos.size(); ++i) {
            nuevo.push_back(puntos[i]);
        }
        if(nuevo.size()>0 ) {
            Nodo* hijo=crearArbol(nuevo,aux,n);

            n->setDer(hijo);

        }
        else {
            n->setDer(nullptr);}
    }
    else if(residuo==2){
        sort(puntos.begin(), puntos.end(), [](const Punto& a, const Punto& b) {
            return a.y < b.y;

        });


        int medianaIndex = puntos.size() / 2;

        Punto medianaPunto = puntos[medianaIndex];
        deque<Punto> nuevo;
        for (int i = 0; i < medianaIndex; ++i) {
            nuevo.push_back(puntos[i]);
        }
        aux+=1;

        n->setDato(medianaPunto);
        n->setDimension('y');
        if(nuevo.size()>0 ) {
            Nodo* hijo=crearArbol(nuevo,aux,n);
            n->setIzq(hijo);
        }
        else {
            n->setIzq(nullptr);}
        nuevo.clear();
        for (int i = medianaIndex+1; i < puntos.size(); ++i) {
            nuevo.push_back(puntos[i]);
        }
        if(nuevo.size()>0 ){
            Nodo* hijo=crearArbol(nuevo,aux,n);
            n->setDer(hijo);
        }
        else {
            n->setDer(nullptr);}
    }
    else if(residuo==0){
        sort(puntos.begin(), puntos.end(), [](const Punto& a, const Punto& b) {
            return a.z < b.z;
        });


        int medianaIndex = puntos.size() / 2;

        Punto medianaPunto = puntos[medianaIndex];
        deque<Punto> nuevo;
        for (int i = 0; i < medianaIndex; ++i) {
            nuevo.push_back(puntos[i]);
        }
        aux+=1;

        n->setDato(medianaPunto);
        n->setDimension('z');

        if(nuevo.size()>0 ){
            Nodo* hijo=crearArbol(nuevo,aux,n);
            n->setIzq(hijo);
        }
        else {
            n->setIzq(nullptr);}

        nuevo.clear();
        for (int i = medianaIndex+1; i < puntos.size(); ++i) {
            nuevo.push_back(puntos[i]);
        }
        if(nuevo.size()>0 ){
            Nodo* hijo=crearArbol(nuevo,aux,n);
            n->setDer(hijo);
        }
        else {
            n->setDer(nullptr);}
    }
     return n;
}

const string &Object3D::getNombre() const {
    return nombre;
}

void Object3D::setNombre(const string &nombre) {
    Object3D::nombre = nombre;
}

int Object3D::getCantPuntos() const {
    return cantPuntos;
}

void Object3D::setCantPuntos(int cantPuntos) {
    Object3D::cantPuntos = cantPuntos;
}

const deque<Punto> &Object3D::getPuntos() const {
    return puntos;
}

void Object3D::setPuntos(const deque<Punto> &puntos) {
    Object3D::puntos = puntos;
}

const vector<Cara> &Object3D::getCaras() const {
    return caras;
}

void Object3D::setCaras(const vector<Cara> &caras) {
    Object3D::caras = caras;
}
