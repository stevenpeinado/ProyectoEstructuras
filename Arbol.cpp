

#include "Arbol.h"
#include "Nodo.h"

class punto;

const Nodo Arbol::getRaiz() const {
    return raiz;
}

void Arbol::setRaiz(const Nodo &raiz) {
    Arbol::raiz = raiz;
}
