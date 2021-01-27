#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "lista.h"
#include "personajes.h"

using namespace std;

// Agrega un personaje a la lista. Los datos del mismo se pasan
// por parametro y la energia se determina de forma aleatoria
// PRE: Los valores de escudo y vida estan dentro del rango valido.
// POS: Se agrego el personaje a la lista.
bool agregar_personaje(Lista* lista, string elem, string n, int esc, int v);

// Convierte una cadena a mayusculas
void convertir_mayus(string &cadena);

// Verifica que el escudo y la vida esten
// dentro del rango valido.
bool validar_valores(int esc, int v);

// Muestra los nombres de todos los personajes
void mostrar_personajes(Lista* lista);

// Muestra los nombres de todos los personajes
// y permite elegir el numero de posicion de un personaje
// que se usa en otras funciones
int elegir_pos(Lista* lista);

// Lee el archivo 'personajes.csv' y carga los
// personajes. Devuelve false en caso de error.
void leer_archivo(Lista* lista);

// Limpia la pantalla
void limpiar_pantalla();

#endif