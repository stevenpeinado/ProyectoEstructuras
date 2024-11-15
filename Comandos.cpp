#include "Comandos.h"
#include <iostream>
#include <string>
#include <fstream>
#include "Objeto3D.h"
#include <algorithm>  // para std::min_element y std::max_element
#include <cmath>

using namespace std;

void Comandos::run() {
    string comando;

    while (true) {
        cout << "$ ";
        getline(cin, comando);

        if (comando.find("ayuda") == 0) {
            if (comando.length() > 6) {
                string param = comando.substr(6);
                mostrarAyudaComando(param);
            } else {
                mostrarAyuda();
            }
        } else if (comando.find("cargar") == 0) {
            if (comando.length() > 7) {
                string param = comando.substr(7);
                ejecutarCargar(param);
            } else {
                cout << "Uso: cargar <nombre_archivo>\n";
            }
        } else if (comando == "listado") {
            ejecutarListado();
        } else if (comando.find("envolvente") == 0) {
            if (comando.length() > 11) {
                string param = comando.substr(11);
                ejecutarEnvolventeObjeto(param);
            }else if(comando.length() < 11){
                ejecutarEnvolvente();
            }else {
                cout << "Uso: envolvente <nombre_objeto> | 'vacio'\n";
            }
        } else if(comando.find("v_cercano") == 0) {
            if (comando.length() > 11){
                float x,y,z;
                string nombre;
                nombre = comando.substr(10);
                cout<<"Ingrese el punto x\n";
                cin>>x;
                cout<<"Ingrese el punto y\n";
                cin>>y;
                cout<<"Ingrese el punto z\n";
                cin>>z;
                ejecutarCercanoNombre(x,y,z,nombre,objetosCargados);
            } else if(comando.length() < 11){
                float x,y,z;
                cout<<"Ingrese el punto x\n";
                cin>>x;
                cout<<"Ingrese el punto y\n";
                cin>>y;
                cout<<"Ingrese el punto z\n";
                cin>>z;
                ejecutarCercano(x,y,z, objetosCargados);
            }else{
                cout << "Uso: v_cercano <nombre_objeto> | 'vacio'\n";
            }
        } else if(comando.find("v_cercanio_caja")== 0){
            if(comando.length() > 15){
                string param = comando.substr(15);
                ejecutarCercanoCaja(param);
            } else{
                cout << "Uso: v_cercano_caja <nombre_objeto>\n";
            }
        } else if (comando.find("ruta_corta") == 0) {
            // Si el comando contiene "centro", es ruta_corta_centro
            if (comando.length() > 10) {
                int param;
                int param2;
                string juanito;
                cout<<"Ingrese el primer indice:";
                cin>>param;
                cout<<"Ingrese el segundo indice:";
                cin>>param2;
                cout<<"Ingrese el nombre del objeto:";
                cin>>juanito;
                ejecutarRutaCorta(param, param2, juanito);
                } else {
                    cout << "Uso: ruta_corta_centro <indice_vertice> <nombre_objeto>\n";
                }
            }
            else if (comando.find("ruta_corta_centro") == 0) {
            if (comando.length() > 17) {
                int param;
                string juanito;
                cout<<"Ingrese el primer indice:";
                cin>>param;
                cout<<"Ingrese el nombre del objeto:";
                cin>>juanito;
                ejecutarRutaCortaCentro(param, juanito);
            } else {
                cout << "Uso: ruta_corta <indice_vertice1> <indice_vertice2> <nombre_objeto>\n";
            }
        } else if (comando.find("descargar") == 0) {
            if (comando.length() > 10) {
                string param = comando.substr(10);
                ejecutarDescargar(param);
            } else {
                cout << "Uso: descargar <nombre_objeto>\n";
            }
        } else if (comando.find("guardar") == 0) {
            size_t pos1 = comando.find(' ', 7);
            if (pos1 != string::npos && pos1 + 1 < comando.length()) {
                size_t pos2 = comando.find(' ', pos1 + 1);
                if (pos2 != string::npos) {
                    string param1 = comando.substr(8, pos2 - 8);
                    string param2 = comando.substr(pos2 + 1);
                    if (!param1.empty() && !param2.empty()) {
                        ejecutarGuardar(param1, param2);
                    } else {
                        cout << "Uso: guardar <nombre_objeto> <nombre_archivo>\n";
                    }
                }
            } else {
                cout << "Uso: guardar <nombre_objeto> <nombre_archivo>\n";
            }
        } else if (comando == "clear") {
            ejecutarClear();
        } else if (comando == "salir") {
            break;
        } else {
            cout << "Comando no reconocido o parametros incorrectos.\n";
        }
    }
}

void Comandos::mostrarAyuda() {
    cout << "Comandos disponibles:\n";
    cout << "  ayuda [comando] - Muestra esta ayuda o la ayuda de un comando especifico\n";
    cout << "  cargar <nombre_archivo> - Carga un objeto 3D desde un archivo\n";
    cout << "  listado - Lista los objetos cargados en memoria\n";
    cout << "  envolvente [nombre_objeto] - Calcula la caja envolvente de un objeto o de todos los objetos\n";
    cout << "  envolvente - calcula la caja envolvente de todos los objetos en el sistema\n";
    cout << "  descargar <nombre_objeto> - Descarga un objeto de la memoria\n";
    cout << "  guardar <nombre_objeto> <nombre_archivo> - Guarda un objeto en un archivo\n";
    cout << "  clear - Limpia la consola\n";
    cout << "  salir - Termina la ejecucion de la aplicacion\n";
    cout << "  v_cercano <nombre_objeto> - Identifica el vertice del objeto <nombre_objeto> mas cercano al punto indicado por px, py, pz\n";
    cout << "  v_cercano - Identifica el vertice mas cercano al punto dado entre todos los objetos cargados\n";
    cout << "  v_cercanio_caja <nombre_objeto> - Identifica los vertices del objeto <nombre_objeto> mas cercanos a las esquinas de su caja envolvente\n";
    cout << "  ruta_corta <indice_vertice1> <indice_vertice2> <nombre_objeto> - Encuentra la ruta más corta entre dos vértices\n";
    cout << "  ruta_corta_centro <indice_vertice> <nombre_objeto> - Encuentra la ruta más corta desde un vértice hasta el centro del objeto\n";
}

void Comandos::mostrarAyudaComando(const string& comando) {
    if (comando == "cargar") {
        cout << "Uso: cargar <nombre_archivo>\n";
        cout << "Descripcion: Carga un objeto 3D desde un archivo.\n";
    } else if (comando == "listado") {
        cout << "Uso: listado\n";
        cout << "Descripcion: Lista los objetos cargados en memoria.\n";
    } else if (comando == "envolvente objeto") {
        cout << "Uso: envolvente [nombre_objeto]\n";
        cout << "Descripcion: Calcula la caja envolvente de un objeto.\n";
    } else if (comando == "tenvolvente") {
        cout << "Uso: tenvolvente\n";
        cout << "Descripcion: Calcula la caja envolvente de todos los objetos.\n";
    } else if (comando == "descargar") {
        cout << "Uso: descargar <nombre_objeto>\n";
        cout << "Descripcion: Descarga un objeto de la memoria.\n";
    } else if (comando == "guardar") {
        cout << "Uso: guardar <nombre_objeto> <nombre_archivo>\n";
        cout << "Descripcion: Guarda un objeto en un archivo.\n";
    } else if (comando == "clear") {
        cout << "Uso: clear\n";
        cout << "Descripcion: Limpia la consola.\n";
    } else if (comando == "salir") {
        cout << "Uso: salir\n";
        cout << "Descripcion: Termina la ejecucion de la aplicacion.\n";
    } else if (comando == "v_cercano") {
        cout << "Uso: v_cercano [nombre_objeto] | 'vacio'\n";
        cout << "Descripcion: Identifica el vértice más cercano al punto dado en un objeto o entre todos los objetos cargados.\n";
    } else if (comando == "v_cercanos_caja") {
        cout << "Uso: v_cercanio_caja <nombre_objeto>\n";
        cout << "Descripcion: Identifica los vértices más cercanos a las esquinas de la caja envolvente del objeto especificado.\n";
    } else if (comando == "ruta_corta") {
        cout << "Uso: ruta_corta <indice_vertice1> <indice_vertice2> <nombre_objeto>\n";
        cout << "Descripcion: Encuentra la ruta más corta entre dos vértices del objeto especificado.\n";
        cout << "El comando retorna los índices de los vértices que conforman la ruta más corta y la distancia total.\n";
    } else if (comando == "ruta_corta_centro") {
        cout << "Uso: ruta_corta_centro <indice_vertice> <nombre_objeto>\n";
        cout << "Descripcion: Encuentra la ruta más corta desde un vértice hasta el centro del objeto especificado.\n";
        cout << "El comando calcula el centroide del objeto, conecta el vértice más cercano al centroide,\n";
        cout << "y encuentra la ruta más corta desde el vértice dado hasta el centroide.\n";
    } else {
        cout << "Comando no reconocido.\n";
    }
}

bool Comandos::archivoExiste(const string& nombreArchivo) {
    ifstream archivo(nombreArchivo); // Usa el nombre del archivo proporcionado
    return archivo.good(); // Verifica si el archivo está abierto correctamente
}

bool Comandos::objetoExiste(const string& nombreObjeto) {
    for (const auto& obj : objetosCargados) {
        if (obj.nombre == nombreObjeto) {
            return true;
        }
    }
    return false;

}

void Comandos::ejecutarCargar(const string& nombreArchivo) {

    if (archivoExiste(nombreArchivo)) {
        ifstream file(nombreArchivo);

        if (!file.is_open()) {
            cerr << "No se pudo abrir el archivo: " << nombreArchivo << endl;
            return;
        }

        Object3D objeto;
        string line;
        int nPuntos = 0;


        if (!getline(file, line)) {
            cerr << "Error: No se pudo leer el nombre del objeto en el archivo." << endl;
            return;
        }
        for (const auto& objet : objetosCargados) {
            if(objet.nombre == line)
                cout<<"Ese objeto ya fue cargado\n";
            return;
        }
        objeto.nombre = line;
        cout << "Cargando objeto: " << objeto.nombre << endl;


        if (!getline(file, line)) {
            cerr << "Error: No se pudo leer la cantidad de puntos en el archivo." << endl;
            return;
        }
        try {
            nPuntos = stoi(line);
            if (nPuntos <= 0) {
                cerr << "Error: El archivo no contiene suficientes puntos o la cantidad es inválida." << endl;
                return;
            }
            objeto.cantPuntos = nPuntos;
        } catch (const invalid_argument& e) {
            cerr << "Error: La línea de la cantidad de puntos no es válida: " << line << endl;
            return;
        }


        for (int n = 0; n < nPuntos; n++) {
            float x = 0, y = 0, z = 0;
            if (!(file >> x >> y >> z)) {
                cerr << "Error: No se pudo leer todos los puntos correctamente." << endl;
                return;
            }
            Punto punto(x, y, z);
            objeto.puntos.push_back(punto);
        }


        int nPuntosxCara, caras = 0;
        file >> nPuntosxCara;

        while (nPuntosxCara != -1) {
            objeto.cantAristas += nPuntosxCara;
            Cara cara;
            caras++;
            objeto.cantCaras = caras;
            cara.vertices.clear();

            for (int i = 0; i < nPuntosxCara; i++) {
                int a;
                file >> a;
                if (a < 0 || a >= objeto.puntos.size()) {
                    cerr << "Error: Índice de vértice fuera de rango." << endl;
                    return;
                }
                cara.vertices.push_back(objeto.puntos[a]);
            }

            objeto.caras.push_back(cara);
            file >> nPuntosxCara;
        }


        objetosCargados.push_back(objeto);
        file.close();
        cantObjetos++;
        cout << "Objeto cargado correctamente: " << objeto.nombre << endl;
        Nodo nAux;
        Nodo* n =objeto.crearArbol(objeto.puntos,1, nullptr);
        objeto.arbol.setRaiz(*n);



    } else {
        cerr << "Error: El archivo " << nombreArchivo << " no existe." <<endl;
        }
}

void Comandos::ejecutarListado() {
    cout << "Listado de objetos en memoria:\n";
    for (const auto& objeto : objetosCargados) {
        cout <<"    "<<objeto.nombre<<" contiene "<<objeto.cantPuntos<<" vertices, " <<objeto.cantAristas <<" aristas y "<<objeto.cantCaras<<" caras."<<endl;

    }
}

void Comandos::ejecutarEnvolventeObjeto(const string& nombreObjeto) {
    cout << "Envolvente del objeto: " << nombreObjeto << "\n";

    for(int b=0; b<cantObjetos; b++){
        objetoActual=objetosCargados[b];
        if(nombreObjeto==objetoActual.nombre)
            break;
    }
    int xMax=-9000, yMax=-9000, zMax=-9000, xMin=70000, yMin=70000, zMin=90000;

    for(const auto& punto : objetoActual.puntos) {
        if(punto.x > xMax) xMax = punto.x;
        if(punto.x < xMin) xMin = punto.x;
        if(punto.y > yMax) yMax = punto.y;
        if(punto.y < yMin) yMin = punto.y;
        if(punto.z > zMax) zMax = punto.z;
        if(punto.z < zMin) zMin = punto.z;
    }

    Object3D envolvente;

    envolvente.nombre="env_"+objetoActual.nombre;
    Punto punto1(xMax,yMax,zMax);
    Punto punto2(xMax,yMax,zMin);
    Punto punto3(xMax,yMin,zMax);
    Punto punto4(xMax,yMin,zMin);
    Punto punto5(xMin,yMax,zMax);
    Punto punto6(xMin,yMax,zMin);
    Punto punto7(xMin,yMin,zMax);
    Punto punto8(xMin,yMin,zMin);
    envolvente.puntos.push_back(punto1);
    envolvente.puntos.push_back(punto2);
    envolvente.puntos.push_back(punto3);
    envolvente.puntos.push_back(punto4);
    envolvente.puntos.push_back(punto5);
    envolvente.puntos.push_back(punto6);
    envolvente.puntos.push_back(punto7);
    envolvente.puntos.push_back(punto8);

    Cara cara1 = {envolvente.puntos[0], envolvente.puntos[2], envolvente.puntos[6], envolvente.puntos[4]};
    envolvente.caras.push_back(cara1);
    envolvente.cantCaras++;

    Cara cara2 = {envolvente.puntos[1], envolvente.puntos[3], envolvente.puntos[7], envolvente.puntos[5]};
    envolvente.caras.push_back(cara2);
    envolvente.cantCaras++;

    Cara cara3 = {envolvente.puntos[4], envolvente.puntos[6], envolvente.puntos[7], envolvente.puntos[5]};
    envolvente.caras.push_back(cara3);
    envolvente.cantCaras++;

    Cara cara4 = {envolvente.puntos[0], envolvente.puntos[2], envolvente.puntos[3], envolvente.puntos[1]};
    envolvente.caras.push_back(cara4);
    envolvente.cantCaras++;

    Cara cara5 = {envolvente.puntos[0], envolvente.puntos[1], envolvente.puntos[5], envolvente.puntos[4]};
    envolvente.caras.push_back(cara5);
    envolvente.cantCaras++;

    Cara cara6 = {envolvente.puntos[2], envolvente.puntos[3], envolvente.puntos[7], envolvente.puntos[6]};
    envolvente.caras.push_back(cara6);
    envolvente.cantCaras++;
    envolvente.cantAristas=12;
    envolvente.cantPuntos=8;
    objetosCargados.push_back(envolvente);
    Nodo nAux;

    Nodo* n =envolvente.crearArbol(envolvente.puntos,1, nullptr);
    envolvente.arbol.setRaiz(*n);
}

void Comandos::ejecutarEnvolvente() {
    int xMax=-9000, yMax=-9000, zMax=-9000, xMin=70000, yMin=70000, zMin=90000;

    for (int b = 0; b < cantObjetos; b++) {
        objetoActual = objetosCargados[b];
        for (const auto& punto : objetoActual.puntos) {
            if (punto.x > xMax) xMax = punto.x;
            if (punto.x < xMin) xMin = punto.x;
            if (punto.y > yMax) yMax = punto.y;
            if (punto.y < yMin) yMin = punto.y;
            if (punto.z > zMax) zMax = punto.z;
            if (punto.z < zMin) zMin = punto.z;
        }
    }

    Object3D envolvente;
    envolvente.nombre = "env_global";
    // envolvente.puntos.resize(8);
    Punto punto1(xMax,yMax,zMax);
    Punto punto2(xMax,yMax,zMin);
    Punto punto3(xMax,yMin,zMax);
    Punto punto4(xMax,yMin,zMin);
    Punto punto5(xMin,yMax,zMax);
    Punto punto6(xMin,yMax,zMin);
    Punto punto7(xMin,yMin,zMax);
    Punto punto8(xMin,yMin,zMin);
    envolvente.puntos.push_back(punto1);
    envolvente.puntos.push_back(punto2);
    envolvente.puntos.push_back(punto3);
    envolvente.puntos.push_back(punto4);
    envolvente.puntos.push_back(punto5);
    envolvente.puntos.push_back(punto6);
    envolvente.puntos.push_back(punto7);
    envolvente.puntos.push_back(punto8);

    Cara cara1 = {envolvente.puntos[0], envolvente.puntos[2], envolvente.puntos[6], envolvente.puntos[4]};
    envolvente.caras.push_back(cara1);
    envolvente.cantCaras++;

    Cara cara2 = {envolvente.puntos[1], envolvente.puntos[3], envolvente.puntos[7], envolvente.puntos[5]};
    envolvente.caras.push_back(cara2);
    envolvente.cantCaras++;

    Cara cara3 = {envolvente.puntos[4], envolvente.puntos[6], envolvente.puntos[7], envolvente.puntos[5]};
    envolvente.caras.push_back(cara3);
    envolvente.cantCaras++;

    Cara cara4 = {envolvente.puntos[0], envolvente.puntos[2], envolvente.puntos[3], envolvente.puntos[1]};
    envolvente.caras.push_back(cara4);
    envolvente.cantCaras++;

    Cara cara5 = {envolvente.puntos[0], envolvente.puntos[1], envolvente.puntos[5], envolvente.puntos[4]};
    envolvente.caras.push_back(cara5);
    envolvente.cantCaras++;

    Cara cara6 = {envolvente.puntos[2], envolvente.puntos[3], envolvente.puntos[7], envolvente.puntos[6]};
    envolvente.caras.push_back(cara6);
    envolvente.cantCaras++;

    envolvente.cantAristas=12;
    envolvente.cantPuntos=8;
    envolvente.cantCaras=6;
    objetosCargados.push_back(envolvente);
    Nodo* n =envolvente.crearArbol(envolvente.puntos,1, nullptr);
    envolvente.arbol.setRaiz(*n);

}

void Comandos::ejecutarCercanoNombre(float px, float py, float pz,string n,vector<Object3D>objetosCargados){
    if (objetosCargados.empty()) {
        cout << "Memoria vacía: Ningún objeto ha sido cargado en memoria." << endl;
        return;
    }



    Punto punto(px, py, pz);
    Nodo* nodoMasCercano = nullptr;
    Punto cercano;
    bool existe = false;

    Object3D objet;
    for (const auto& objeto : objetosCargados) {
        if(objeto.nombre==n){
            objet = objeto;
            existe=true;}
            break;
    }

    if(existe==false){
        cout<<"Error: El objeto "<< n <<" no ha sido cargado en memoria\n";
        return;
    }

    cercano=objet.arbol.getRaiz().encontrarCercano(punto,-1,punto);
    float distancia=cercano.distancia(punto);
    cout<< "El vertice("<<cercano.x <<","<<cercano.y<<","<<cercano.z<<")del objeto"<<n<<" es el mas cercano\n""al punto ("<<punto.x <<","<<punto.y<<","<<punto.z<<" a una distancia de"<<distancia<<endl;
}

void Comandos::ejecutarCercano(float px, float py, float pz,vector<Object3D>objetos){
    if (objetosCargados.empty()) {
        cout << "Memoria vacía: Ningun objeto ha sido cargado en memoria." << endl;
        return;
    }


    Punto punto(px, py, pz);

    Punto cercano;
    float dis=-1;

    for (const auto& objeto : objetosCargados) {
        cercano=objeto.arbol.getRaiz().encontrarCercano(punto,dis,punto);
        dis=cercano.distancia(punto);
    }
    cout<< "El vertice("<<cercano.x <<","<<cercano.y<<","<<cercano.z<<" es el mas cercano\n""al punto ("<<punto.x <<","<<punto.y<<","<<punto.z<<" a una distancia de"<<dis<<endl;
}

void Comandos::ejecutarCercanoCaja (string n){
    bool existe= false,existeE=false;
    string nEnvol="env_"+n;
    Object3D objeto,envolvente;
    for(const auto& objet : objetosCargados) {
        if(objet.nombre==n) {
            existe = true;
            objeto=objet;
        }if(objet.nombre==nEnvol){
            existeE=true;
            envolvente=objet;
        }
    }
    if(existe==false){
        cout<<"Error: El objeto "<< n <<" no ha sido cargado en memoria\n";;
    }
    if(existeE==false){
        ejecutarEnvolventeObjeto(n);
        for(const auto& objet : objetosCargados) {
            if(objet.nombre==nEnvol)
                envolvente=objet;
        }
    }
    int a=1;
    Punto cercano;
    float dis;
    cout<<"Los vertices del objeto"<< n<< "más cercanos a las esquinas de su caja envolvente son:";
    cout<<"Esquina               Vertice               Distancia";
    for(const auto& objet : envolvente.puntos){
        cercano=objeto.arbol.getRaiz().encontrarCercano(objet,-1,objet);

        dis=cercano.distancia(objet);
        cout<<a<<" ("<<objet.x<<objet.y<<objet.z<<")              "<<"i"<<a<<" ("<<cercano.x<<cercano.y<<cercano.z<<")              "<< dis;
    }

}

void Comandos::ejecutarDescargar(const string& nombreObjeto) {

    if (objetoExiste(nombreObjeto)) {
        for(int b=0; b<cantObjetos; b++){
            if(nombreObjeto==objetosCargados[b].nombre)
                if (0 <= b && b < objetosCargados.size()) {
                    objetosCargados.erase(objetosCargados.begin() + b);
                }
        }

        cout << "El objeto " << nombreObjeto << "ha sido eliminado de la memoria de trabajo."<<endl;
    } else {
        cout << "Error: El objeto " << nombreObjeto << " no existe.\n";
    }
}

void Comandos::ejecutarGuardar(const string& nombreObjeto, const string& nombreArchivo) {
    cout<<nombreObjeto<<endl;
    if (!objetoExiste(nombreObjeto)) {
        cout << "Error: el objeto " << nombreObjeto << " no existe.\n";
        return;
    }

    Object3D objetoGuardar;
    for (const auto& obj : objetosCargados) {
        if (obj.nombre == nombreObjeto) {
            objetoGuardar = obj;
            break;
        }
    }
    cout << "Objeto seleccionado tiene " << objetoGuardar.puntos.size() << " puntos y " << objetoGuardar.caras.size() << " caras." << endl;
    ofstream archivo(nombreArchivo+".txt");
    if (!archivo.is_open()) {
        cout << "Error: no se pudo abrir el archivo " << nombreArchivo << " para guardar.\n";
        return;
    }

    archivo << objetoGuardar.nombre << endl;
    archivo << objetoGuardar.cantPuntos << endl;

    // Escribir cada vértice
    for (const auto& punto : objetoGuardar.puntos) {
        archivo << punto.x << " " << punto.y << " " << punto.z << endl;
    }

    // Escribir cada cara
    for (const auto& cara : objetoGuardar.caras) {
        archivo << cara.vertices.size();
        for (const auto& vertice : cara.vertices) {
            int indice = -1;
            for (int i = 0; i < objetoGuardar.puntos.size(); i++) {
                if (objetoGuardar.puntos[i].x == vertice.x &&
                    objetoGuardar.puntos[i].y == vertice.y &&
                    objetoGuardar.puntos[i].z == vertice.z) {
                    indice = i;
                    break;
                }
            }
            if (indice != -1) {
                archivo << " " << indice;  // Un solo espacio para separar los índices
            } else {
                cout << "Advertencia: no se encontró un vértice correspondiente.\n";
            }
        }
        archivo << endl;
    }
    cout<<"Archivo creado exitosamente.\n";
}

void Comandos::ejecutarRutaCorta(int i1, int i2, string nombreObjeto) {
    // Verificar si el objeto existe
    Object3D* obj = nullptr;
    for (auto& o : objetosCargados) {
        if (o.getNombre() == nombreObjeto) {
            obj = &o;
            break;
        }
    }

    if (!obj) {
        cout << "(Objeto no existe) El objeto " << nombreObjeto << " no ha sido cargado en memoria." << endl;
        return;
    }

    // Verificar índices
    if (i1 == i2) {
        cout << "(Índices iguales) Los indices de los vertices dados son iguales." << endl;
        return;
    }

    if (i1 < 0 || i2 < 0 || i1 >= obj->getCantPuntos() || i2 >= obj->getCantPuntos()) {
        cout << "(Índices no existen) Algunos de los indices de vertices estan fuera de rango para el objeto " << nombreObjeto << "." << endl;
        return;
    }

    // Construir el grafo a partir del objeto
    Grafo grafo;
    grafo.construirGrafo(*obj);

    // Encontrar la ruta más corta
    vector<int> ruta = grafo.encontrarRutaCorta(i1, i2);

    if (ruta.empty()) {
        cout << "No existe una ruta entre los vertices dados." << endl;
    } else {
        float distanciaTotal = 0;
        for (size_t i = 0; i < ruta.size() - 1; i++) {
            Punto p1 = obj->getPuntos()[ruta[i]];
            Punto p2 = obj->getPuntos()[ruta[i + 1]];
            distanciaTotal += p1.distancia(p2);
        }

        cout << "(Resultado exitoso) La ruta más corta que conecta los vertices " << i1 << " y " << i2
             << " del objeto " << nombreObjeto << " pasa por: ";
        for (size_t i = 0; i < ruta.size(); i++) {
            cout << ruta[i];
            if (i < ruta.size() - 1) cout << ",";
        }
        cout << "; con una longitud de " << distanciaTotal << "." << endl;
    }
}

void Comandos::ejecutarRutaCortaCentro(int i1, string nombreObjeto) {
    // Verificar si el objeto existe
    Object3D* obj = nullptr;
    for (auto& o : objetosCargados) {
        if (o.getNombre() == nombreObjeto) {
            obj = &o;
            break;
        }
    }

    if (!obj) {
        cout << "(Objeto no existe) El objeto " << nombreObjeto << " no ha sido cargado en memoria." << endl;
        return;
    }

    // Verificar índice
    if (i1 < 0 || i1 >= obj->getCantPuntos()) {
        cout << "(Índice no existe) El indice de vertice esta fuera de rango para el objeto " << nombreObjeto << "." << endl;
        return;
    }

    // Calcular el centro (centroide)
    float sumX = 0, sumY = 0, sumZ = 0;
    for (const auto& punto : obj->getPuntos()) {
        sumX += punto.getX();
        sumY += punto.getY();
        sumZ += punto.getZ();
    }
    int n = obj->getCantPuntos();
    Punto centro(sumX / n, sumY / n, sumZ / n);

    // Encontrar el vértice más cercano al centro
    float minDist = numeric_limits<float>::infinity();
    int indiceCentro = 0;
    for (int i = 0; i < n; i++) {
        float dist = obj->getPuntos()[i].distancia(centro);
        if (dist < minDist) {
            minDist = dist;
            indiceCentro = i;
        }
    }

    // Construir el grafo a partir del objeto
    Grafo grafo;
    grafo.construirGrafo(*obj);

    // Encontrar la ruta más corta hasta el centro
    vector<int> ruta = grafo.encontrarRutaCorta(i1, indiceCentro);

    if (ruta.empty()) {
        cout << "No existe una ruta entre el vertice y el centro." << endl;
    } else {
        float distanciaTotal = 0;
        for (size_t i = 0; i < ruta.size() - 1; i++) {
            Punto p1 = obj->getPuntos()[ruta[i]];
            Punto p2 = obj->getPuntos()[ruta[i + 1]];
            distanciaTotal += p1.distancia(p2);
        }

        cout << "(Resultado exitoso) La ruta más corta que conecta el vertice " << i1
             << " con el centro del objeto " << nombreObjeto << ", ubicado en ct ("
             << centro.getX() << ", " << centro.getY() << ", " << centro.getZ()
             << "), pasa por: ";
        for (size_t i = 0; i < ruta.size(); i++) {
            cout << ruta[i];
            if (i < ruta.size() - 1) cout << ",";
        }
        cout << "ct; con una longitud de " << (distanciaTotal + minDist) << "." << endl;
    }
}


void Comandos::ejecutarClear() {


#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}