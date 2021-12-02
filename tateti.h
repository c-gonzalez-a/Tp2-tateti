#ifndef TATETI_H_
#define TATETI_H_

#include "tablero.h"
#include "mazo.h"
#include "jugador.h"

enum EstadoJuego {
    JUGANDO,
    FINALIZADO,
};

class TaTeTi {

    private:

        Tablero * tablero;
        Mazo * mazo;
        Lista<Jugador*> * jugadores;
        Jugador * turnoActual;
        EstadoJuego estado;

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

    private:

        /**
         * Pre: El juego debe estar correctamente inicializado
         * Post: Cada jugador tomara una carta del mazo
         */
        void tomarCartas();

        /**
         * Pre: El juego tateti debe estar creado correctamente
         * Post: Juega el turno del jugador que le corresponde
         */
        void jugarTurno(Jugador * jugador);

        /**
         * Pre: -
         * Post: Si hay algun ganador se cambia el estado del juego, sino se pasa al siguiente turno
         */
        void actualizarEstadoDelJuego();

        /**
         * Pre: El juego debe estar correctamente definido
         * Post: Posiciona una ficha en el tablero
         */
        void posicionarFicha();

        /**
         * Pre: El jugador debe haber ya posicionado todas sus fichas
         * Post: Mueve una de sus fichas a un casillero vacio
         */
        void moverFicha();

};

#endif /* TATETI_H_ */