#ifndef JUGADOR_H_
#define JUGADOR_H_

#include "baraja.h"

class Jugador {
    
    private: 
        char ficha;
        int numero;
        Baraja mazo;

    public:           

        /**
         * Pre: -
         * Post: Contruye un jugador con una baraja vacia
         */
        Jugador(char ficha, int numero);

        /**
         * Pre: El jugador debe estar creado
         * Post: Imprime por pantalla la baraja del jugador, enumerando las cartas
         */
        void listarCartas();

        /** 
         * Pre: El jugador debe estar creado, y debe haber listado las cartas para saber la posicion de la que desea utilizar
         * Post: Se juega la carta seleccionada
         */
        void jugarCarta(int carta);

};

#endif /* JUGADOR_H_ */