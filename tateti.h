#ifndef TATETI_H_
#define TATETI_H_

#include "tablero.h"
#include "mazo.h"
#include "jugador.h"

class TaTeTi {

    private:

        int turno;
        int ganador;    //Se define el numero del jugador que gano o -1 si aun no gano nadie
        Tablero * tablero;
        Mazo * mazo;
        int cantJugadores;
        Lista<Jugador*> * jugadores;

    public:

        /**
         * Post: Construye un juego de tateti, con la cantidad de jugadores y dimensiones
         *  deseadas, con una cantidad de fichas y cartas acorde.
         */
        TaTeTi();

        /**
         * Post: Destruye el juego
         */
        ~TaTeTi();

        /**
         * Pre: El juego debe estar construido
         * Post: Se lleva a cabo el procedimiento del juego hasta que haya un ganador o se rindan
         */
        void jugar();

};

#endif /* TATETI_H_ */