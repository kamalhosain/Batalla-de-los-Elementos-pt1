#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

#include "personajes.h"

typedef Personaje* Dato;

class Nodo {

    // Atributos
    private:
        Dato dato;
        Nodo* siguiente;
        Nodo* anterior;

    // Metodos
    public:
        // Constructor
        // Crea un nodo con Dato 'd' y siguiente = 0
        Nodo(Dato d);

        // Reemplaza el Dato anterior por un nuevo Dato 'd'
        void cambiar_dato(Dato d);

        // Apunta el 'siguiente' a otro Nodo 's'
        void cambiar_siguiente(Nodo* s);

        // Devuelve el dato del nodo
        Dato obtener_dato();

        // Devuelve un puntero hacia el Nodo siguiente
        Nodo* obtener_siguiente();
};

#endif // NODO_H_INCLUDED
