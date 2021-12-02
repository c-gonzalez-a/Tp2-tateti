#ifndef _CARTA_H
#define _CARTA_H

#include <cstdlib>
#include <ctime>
#include <string>


const char * CARTAS[] = {
        "perderTurno",
        "volverAtras",
        "bloquearCasillero",
        "anularCasillero",
        "intercambiarFicha",
        "repetirTurno",
};


class Carta {

private:
    std::string nombre;

public:

    /**
     * Pre: -
     * Post: Construye una carta
     */
    Carta();

    /**
     * Pre: -
     * Post: Imprime la carta en pantalla
     */
    void imprimirCarta();

    /*
     * Pre: -
     * Post: Retorna el nombre de la carta
     */
    std::string getNombreCarta();
};


#endif //PRUEBAMAZO_CARTA_H
