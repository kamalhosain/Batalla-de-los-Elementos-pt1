#include "personajes.h"

/**
 * Metodos Clase PERSONAJE
 **/

Personaje::Personaje(string elem, string n, int esc, int v, int enrg) {
    elemento = elem;
    nombre = n;
    escudo = esc;
    vida = v;
    energia = enrg;
}

string Personaje::obtener_elemento() {
    return elemento;
}

string Personaje::obtener_nombre() {
    return nombre;
}

int Personaje::obtener_escudo() {
    return escudo;
}

int Personaje::obtener_vida() {
    return vida;
}

int Personaje::obtener_energia() {
    return energia;
}

/**
 * Metodos Clase PJ AGUA
 **/

Pj_agua::Pj_agua(string elem, string n, int esc, int v, int enrg) : Personaje(elem,n,esc,v,enrg) {
    contador_alimentar = 0;
};

bool Pj_agua::alimentar() {
    if(contador_alimentar >= 3){
        return false;
    }

    int energia_actual = obtener_energia();
    
    int energia_nueva = energia_actual + 10;
    if(energia_nueva > 20){
        energia_nueva = 20;
    }

    energia = energia_nueva;
    contador_alimentar++;

    return true;
}

/**
 * Metodos Clase PJ FUEGO
 **/

Pj_fuego::Pj_fuego(string elem, string n, int esc, int v, int enrg) : Personaje(elem,n,esc,v,enrg) {};

bool Pj_fuego::alimentar() {
    int vida_actual = obtener_vida();

    int vida_nueva = vida_actual + 15;
    if(vida_nueva > 100){
        vida_nueva = 100;
    }

    vida = vida_nueva;
    return true;
}

/**
 * Metodos Clase PJ TIERRA
 **/

Pj_tierra::Pj_tierra(string elem, string n, int esc, int v, int enrg) : Personaje(elem,n,esc,v,enrg) {};

bool Pj_tierra::alimentar() {
    int energia_actual = obtener_energia();
    
    int energia_nueva = energia_actual + 8;
    if(energia_nueva > 20){
        energia_nueva = 20;
    }

    energia = energia_nueva;
    return true;
}

/**
 * Metodos Clase PJ AIRE
 * */

Pj_aire::Pj_aire(string elem, string n, int esc, int v, int enrg) : Personaje(elem,n,esc,v,enrg) {};

bool Pj_aire::alimentar() {
    return false;
}