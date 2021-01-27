#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "nodo.h"

class Lista {

    // Atributos
    private:
        Nodo* primero;
        Nodo* actual;
        int cantidad;

    // Metodos
    public:
        // Constructor
        // Crea una lista vacia
        Lista();

        // PRE: 0 < pos <= cantidad + 1
        // POS: Se inserto el dato 'd' en la posicion 'd' (empezando por el nro 1)
        // y se sumo 1 a la cantidad.
        void agregar(Dato d, int pos);

        // PRE: 0 < pos <= cantidad
        // POS: Se elimino el elemento que se encuentra en 'pos'
        void eliminar(int pos);

        // PRE: 0 < pos <= cantidad
        // POS: Se devolvio el dato que se encuentra en 'pos'
        Dato consultar(int pos);

        // Devuelve true si la lista esta vacia, false en caso contrario
        bool esta_vacia();

        // Destructor
        // POS: Libera la memoria
        virtual ~Lista();

        // Devuelve la cantidad de elementos de la lista
        int obtener_cantidad();

        // Reinicia el puntero a la primera posicion (NULL si esta vacia)
        // POS: El puntero ahora apunta al primer elemento o a NULL.
        void reiniciar ( );

        // Devuelve true si hay un elemento siguiente, false en caso contrario
        bool hay_siguiente ( );

        // Devuelve el Dato del siguiente elemento
        // PRE: Hay un elemento siguiente (hay_siguiente devuelve true)
        // POS: Se devolvio el Dato del siguiente
        Dato siguiente ( );


        // Devuelve true si el dato 'd' se encuentra en la lista, false en caso contrario
        bool esta(Dato d);


    private:
        Nodo* obtener_nodo(int pos);
};


#endif // LISTA_H_INCLUDED
