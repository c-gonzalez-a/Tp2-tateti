//lista dinamica de cartas del usuario con un maximo

#include "carta.h"

class Baraja {
    private: 
        Carta cartas; //lista dinamica 
  
    public:

        /**
         * Pre: -
         * Post: Crea una baraja sin cartas
         */
        Baraja();

        /**
         * Pre: La baraja debe estar creada
         * Post: La destruye 
         */
        ~Baraja();

};