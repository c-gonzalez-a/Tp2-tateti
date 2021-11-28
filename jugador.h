#ifndef JUGADOR_H
#define JUGADOR_H_

#include "baraja.h"

enum EstadoJugador {
    POSICIONANDO,
    MOVIENDO,
};

class Jugador {
    
    private: 
        char ficha;
        int numero;
        Baraja * baraja;
        EstadoJugador estado;
        int cantFichaPorPoner; //Igual al numero de la mayor dimension del tablero

    public:           

        /**
         * Post: Construye un jugador con una baraja vacia
         */
        Jugador(char ficha, int numeroDelJugador, int cantFichas);

        /**
         * Post: Imprime por pantalla la baraja del jugador, enumerando las cartas
         */
        void listarCartas();

        /**
         * Post: Se juega el tipo de carta si devuelve true, false si no se puede jugar porque no existe en la baraja
         */
        bool jugarCarta(TipoCarta carta);

        /**
         * Post: obtiene el numero del jugador
         */
        int obtenerNumero();


        /**
         * Post: obtiene la ficha del jugador
         */
        char obtenerFicha();

        /**
         * Post: Establece el estado deseado en el jugador
         * @param estado = Estado a setear
         */
        void establecerEstado(EstadoJugador estado);

        /**
         * Post: Devuelve el estado actual del jugador
         * @return El estado actual del jugador
         */
        EstadoJugador obtenerEstado();

        void agregarCartaABaraja(Carta &nuevaCarta);

};

#endif /* JUGADOR_H_ */