    #ifndef UNTITLED_OBJETO3D_H
#define UNTITLED_OBJETO3D_H
#include <iostream>
#include <vector>
#include <deque>
#include <string>
#include "Punto.h"
#include "Cara.h"
#include "Arbol.h"

using namespace std;
class Object3D {
private:
public:
    deque<Nodo> nodos;
    Arbol arbol;
    string nombre;
    int cantPuntos=0;
    int cantAristas=0;
    int cantCaras=0;
    deque<Punto> puntos;
    vector<Cara> caras;
    // Constructor por defecto
    Object3D() : arbol(),nombre(""), puntos(), caras() {}
    Nodo* crearArbol(deque<Punto> puntos,int aux,Nodo* nodo);

};
#endif //UNTITLED_OBJETO3D_H