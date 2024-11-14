
#include <vector>
#include <queue>
#include "NodosG.h"
#include "Punto.h"

class Grafo {
private:
    std::vector<NodosG*> nodos;
    void limpiarEstado();  // Resetea visitado, distancia y anterior

public:
    Grafo();
    ~Grafo();
    void agregarNodo(int id, Punto p);
    void agregarArista(int id1, int id2);
    std::vector<int> dijkstra(int inicio, int fin);
    NodosG* getNodo(int id);
    void clear();
};
