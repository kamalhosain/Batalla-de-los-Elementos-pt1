#include <iostream>
#include <fstream>
#include <cstdlib>

#include "funciones.h"

using namespace std;

void convertir_mayus(string &cadena) {

    int largo = (int)cadena.length();

    for(int i = 0; i < largo; i++){
        cadena[i] = toupper(cadena[i]);
    }
}

bool validar_valores(int esc, int v){
    if(esc < 0 || esc > 2 || v < 10 || v > 100){
        return false;
    }

    return true;
}

void mostrar_personajes(Lista* lista) {
    int cantidad = lista->obtener_cantidad();
    if(cantidad == 0) {
        cout << "No hay personajes." << endl;
    } else {
        string nombre;
        for(int i = 1; i < cantidad + 1; i++){
            Personaje* personaje = (*lista).consultar(i);
            nombre = personaje->obtener_nombre();
            cout << i << "- " << nombre << endl;
        }
    }
}

int elegir_pos(Lista* lista) {
    int numero;
    mostrar_personajes(lista);
    
    if((*lista).obtener_cantidad() == 0){
        return 0;
    }

    cout << "Ingrese el numero: ";
    cin >> numero;

    cout << endl;

    return numero;
}

bool agregar_personaje(Lista* lista, string elem, string n, int esc, int v) {

    // Si el escudo o la vida estan fuera del rango valido
    // se devuelve false
    if(!validar_valores(esc,v)){
        return false;
    }

    int enrg = rand() % 21; // 0 <= enrg <= 20

    convertir_mayus(elem);

    int pos = (*lista).obtener_cantidad() +1;

    if(elem == "AGUA"){

        Pj_agua* personaje = new Pj_agua(elem,n,esc,v,enrg);
        (*lista).agregar(personaje,pos);

    } else if(elem == "FUEGO"){

        Pj_fuego* personaje = new Pj_fuego(elem,n,esc,v,enrg);
        (*lista).agregar(personaje,pos);

    } else if(elem == "TIERRA"){

        Pj_tierra* personaje = new Pj_tierra(elem,n,esc,v,enrg);
        (*lista).agregar(personaje,pos);

    } else if(elem == "AIRE"){

        Pj_aire* personaje = new Pj_aire(elem,n,esc,v,enrg);
        (*lista).agregar(personaje,pos);

    } else{
        return false;
    }

    return true;
}

void limpiar_pantalla() {
    #ifdef WINDOWS
        system("cls");
    #else
        system("clear");
    #endif
}

void leer_archivo(Lista* lista) {
    
    bool lectura;

    ifstream archivo("personajes.csv");

    if(!archivo.is_open()){
        lectura = false;
    }

    string elemento, nombre, escudo, vida;

    while(!archivo.eof() && lectura){

        getline(archivo,elemento,',');
        getline(archivo,nombre,',');
        getline(archivo,escudo,',');
        getline(archivo,vida,'\n');

        int _escudo = stoi(escudo);
        int _vida = stoi(vida);

        lectura = agregar_personaje(lista,elemento,nombre,_escudo,_vida);
    }

    archivo.close();

    if(!lectura){
        cout << "Error al leer el archivo." << endl;
    } else{
        cout << "Archivo cargado exitosamente!" << endl;
    }
}