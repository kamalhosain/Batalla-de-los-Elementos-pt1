#ifndef PERSONAJES_H_INCLUDED
#define PERSONAJES_H_INCLUDED

#include <string>

using namespace std;

/* Clase PERSONAJE */
class Personaje {

    // Atributos
    protected:
        string elemento;
        string nombre;
        int escudo;
        int vida;
        int energia;

    // Metodos
    public:

        // Constructor
        // POS: Se creo un Personaje con nombre 'n', escudo = 'esc',
        // vida = 'v' y energia = 'enrg'
        Personaje(string elem, string n, int esc, int v, int enrg);

        // Devuelve el elemento del personaje
        string obtener_elemento();

        // Devuelve el nombre del personaje
        string obtener_nombre();

        // Devuelve el valor de escudo del personaje
        int obtener_escudo();

        // Devuelve el valor de vida del personaje
        int obtener_vida();

        // Devuelve el valor de energia del personaje
        int obtener_energia();

        virtual bool alimentar() = 0; // Virtual pura
};

/* Clase PERSONAJE AGUA */
class Pj_agua : public Personaje {

    private:
        int contador_alimentar; // Cuenta la cantidad de veces que fue alimentado

    public:

        // Constructor
        Pj_agua(string elem, string n, int esc, int v, int enrg);

        // Incrementa en 10 el valor de la energia
        // En caso de que salga del rango, la establece al maximo (20)
        // Devuelve false si ya se llamo al metodo mas de 3 veces
        virtual bool alimentar();
};

/* Clase PERSONAJE FUEGO */
class Pj_fuego : public Personaje {

    public:

        // Constructor
        Pj_fuego(string elem, string n, int esc, int v, int enrg);

        // Incrementa en 15 el valor de la energia
        // En caso de que salga del rango, la establece al maximo (100)
        virtual bool alimentar();
};

/* Clase PERSONAJE TIERRA */
class Pj_tierra : public Personaje {

    public:

        // Constructor
        Pj_tierra(string elem, string n, int esc, int v, int enrg);

        // Incrementa en 8 el valor de la energia
        // En caso de que salga del rango, la establece al maximo (20)
        virtual bool alimentar();
};

/* Clase PERSONAJE AIRE */
class Pj_aire : public Personaje {

    public:

        // Constructor
        Pj_aire(string elem, string n, int esc, int v, int enrg);

        // Devuelve false
        virtual bool alimentar();
};

#endif