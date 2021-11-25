#ifndef TATETI_H_
#define TATETI_H_

#include "tablero.h"
#include "mazo.h"
#include "jugador.h"

enum Estado {
    POSICIONANDO,
    MOVIENDO,
    FINALIZADO,
};

class TaTeTi {

    private:

        int turno;
        int ganador;
        Tablero tablero;
        Mazo mazo;
        int cantJugadores;
        Jugador[] jugadores;

    public:

        /**
         * Post: Construye un juego de tateti con la cantidad de jugadores y dimensiones dadas por el usuario,
         *  con una cantidad de fichas y cartas acorde.
         */
        TaTeTi(int cantJugadores, int ancho, int alto, int profundidad, int cantFichas);

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