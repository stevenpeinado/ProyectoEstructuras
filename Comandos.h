#ifndef COMANDOS_H
#define COMANDOS_H

#include <string>
#include <unordered_set>
#include "Objeto3D.h"
#include "Grafo.h"

using namespace std;
class Comandos {
private:
    vector<Object3D> objetosCargados; // Almacena los nombres de los objetos cargados

public:
    int cantObjetos = 0;
    Object3D objetoActual;
    void run();
    void mostrarAyuda();
    void mostrarAyudaComando(const std::string& comando);
    bool archivoExiste(const std::string& nombreArchivo);
    bool objetoExiste(const std::string& nombreObjeto);

    void ejecutarCargar(const std::string& nombreArchivo);
    void ejecutarListado();
    void ejecutarEnvolventeObjeto(const std::string& nombreObjeto);
    void ejecutarEnvolvente();
    void ejecutarDescargar(const std::string& nombreObjeto);
    void ejecutarGuardar(const std::string& nombreObjeto, const std::string& nombreArchivo);
    void ejecutarClear();
    void ejecutarCercanoNombre(float px, float py, float pz,string n,vector<Object3D>objetosCargados);
    void ejecutarCercano(float px, float py, float pz,vector<Object3D>objetos);
    void ejecutarCercanoCaja(string n);
    void ejecutarRutaCorta(int i1, int i2, string nombreObjeto);
    void ejecutarRutaCortaCentro(int i1, string nombreObjeto);
    Grafo* construirGrafo(Object3D* objeto);

};

#endif // COMANDOS_H
/*
 #include ""
 nodo

 */