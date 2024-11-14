#include "NodosG.h"
#include <limits>

NodosG::NodosG(int id, Punto p) : id(id), punto(p), visitado(false), distancia(std::numeric_limits<float>::infinity()), anterior(nullptr) {}

void NodosG::agregarAdyacente(NodosG* nodo, float peso) {
    adyacentes.push_back({nodo, peso});
}

int NodosG::getId() const { return id; }
Punto NodosG::getPunto() const { return punto; }
const std::vector<std::pair<NodosG*, float>>& NodosG::getAdyacentes() const { return adyacentes; }
void NodosG::setVisitado(bool v) { visitado = v; }
bool NodosG::getVisitado() const { return visitado; }
void NodosG::setDistancia(float d) { distancia = d; }
float NodosG::getDistancia() const { return distancia; }
void NodosG::setAnterior(NodosG* n) { anterior = n; }
NodosG* NodosG::getAnterior() const { return anterior; }
