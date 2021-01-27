#include "menu.h"

void ingresar_personaje(Lista* lista) {

    srand(time(0));

    string nombre, elemento;
    int esc, vida;

    cout << endl;
    cout << "Ingrese el nombre del personaje: " << endl;
    cin >> nombre;

    cout << endl;
    cout << "Ingrese el elemento del personaje: " << endl;
    cin >> elemento;

    esc = rand() % 3;
    vida = (rand() % 91) + 10;

    bool ingreso = agregar_personaje(lista,elemento,nombre,esc,vida);

    if(!ingreso){
        cout << "Error al intentar ingresar al personaje." << endl;
        cout << "Por favor, intentelo de nuevo." << endl;
    } else {
        cout << "\n Se ingreso a " << nombre << "!" << endl;
    }
}

void eliminar_personaje(Lista* lista) {

    cout << "Elija el numero del personaje que desee eliminar..." << endl;
    int numero = elegir_pos(lista);
    
    Personaje* personaje = (*lista).consultar(numero);
    string nombre = (*personaje).obtener_nombre();

    delete personaje;
    (*lista).eliminar(numero);
    
    cout << "Se elimino a " << nombre << "!" << endl;
}

void detallar_personaje(Lista* lista) {

    cout << "Elija el numero de personaje que desee ver...\n" << endl;
    
    int numero = elegir_pos(lista);

    if(numero != 0){
        Personaje* personaje = (*lista).consultar(numero);

        string elemento = (*personaje).obtener_elemento();
        string nombre = (*personaje).obtener_nombre();
        int escudo = (*personaje).obtener_escudo();
        int vida = (*personaje).obtener_vida();
        int energia = (*personaje).obtener_energia();

        cout << "\n" << endl;
        cout << "Elemento: " << elemento << endl;
        cout << "Nombre: " << nombre << endl;
        cout << "Escudo: " << escudo << endl;
        cout << "Vida: " << vida << endl;
        cout << "Energia: " << energia << endl;
    }
}

void alimentar_personaje(Lista* lista) {

    int numero;
    string nombre;
    bool se_alimento;

    cout << "Elija el numero del personaje que desee alimentar... " << endl;
    numero = elegir_pos(lista);

    if(numero != 0){
        Personaje* personaje = (*lista).consultar(numero);
        nombre = (*personaje).obtener_nombre();

        se_alimento = (*personaje).alimentar();

        if(se_alimento) {
            cout << "Se alimento a " << nombre << endl;
            cout << "Vida: " << (*personaje).obtener_vida();
            cout << "  Energia: " << (*personaje).obtener_energia() << endl;
        } else {
            cout << "No se pudo alimentar a " << nombre << "!" << endl;
        }
    } 
}

void limpiar_lista(Lista* lista) {
    
    while(!(*lista).esta_vacia()) {
        Personaje* personaje = (*lista).consultar(1);
        delete personaje;
        (*lista).eliminar(1);
    }
}

void imprimir_menu() {
    cout << endl;
    cout << "~~~ MENU ~~~" << endl;
    cout << "1 - Ingresar un personaje." << endl;
    cout << "2 - Eliminar un personaje." << endl;
    cout << "3 - Ver todos los personajes." << endl;
    cout << "4 - Ver detalles de personaje." << endl;
    cout << "5 - Alimentar a un personaje." << endl;
    cout << "6 - Salir." << endl;
    cout << endl << "Elija la opcion que desee: ";
}

void menu(Lista* lista) {
    bool salir = false;
    
    while(!salir){
        int opcion;
        imprimir_menu();
        cin >> opcion;
        cout << endl;

        switch(opcion){

            case 1:
                limpiar_pantalla();
                ingresar_personaje(lista);
                break;

            case 2:
                limpiar_pantalla();
                eliminar_personaje(lista);
                break;
            
            case 3:
                limpiar_pantalla();
                cout << "Se muestra una lista de los personajes... \n" << endl;
                mostrar_personajes(lista);
    
                break;
            case 4:
                limpiar_pantalla();
                detallar_personaje(lista);
                break;
            case 5:
                limpiar_pantalla();
                alimentar_personaje(lista);
                break;
            case 6:
                limpiar_pantalla();
                cout << "Adios. :)" << endl;
                limpiar_lista(lista);
                salir = true;
                break;
            
            default:
                limpiar_pantalla();
                cout << endl << "Opcion invalida." << endl;
                cout << "Por favor, intentelo de nuevo." << endl;
                break;
        }
    }
}