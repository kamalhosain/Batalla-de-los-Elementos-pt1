#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "funciones.h"
#include "lista.h"

using namespace std;

// POS: Se ingreso un nuevo personaje
void ingresar_personaje(Lista* lista);

// PRE: La posicion 'pos' se encuentra dentro del rango valido.
// POS: Se elimino al personaje que se encontraba en la posicion 'pos'
void eliminar_personaje(Lista* lista);

// POS: Se mostraron los detalles del personaje que esta
// en la posicion 'pos'
void detallar_personaje(Lista* lista);

// POS: Se llamo al metodo 'alimentar' del personaje que
// se encuentra en la posicion 'pos'
void alimentar_personaje(Lista* lista);

// Elimina los personajes que hayan quedado en la
// lista una vez que se haya salido del menu
void limpiar_lista(Lista* lista);

// Imprime las opciones del menu
void imprimir_menu();

// Menu de opciones
void menu(Lista* lista);

#endif