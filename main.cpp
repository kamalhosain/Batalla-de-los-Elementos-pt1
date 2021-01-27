#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

#include "nodo.h"
#include "personajes.h"
#include "funciones.h"
#include "menu.h"
#include "lista.h"

int main() {

    Lista lista = Lista();

    leer_archivo(&lista);
    menu(&lista);

    return 0;
}