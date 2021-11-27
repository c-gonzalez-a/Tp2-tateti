//lista dinamica de cartas del usuario con un maximo

#ifndef BARAJA_H_
#define BARAJA_H_

#include "carta.h"
#include "lista.h"

class Baraja {
    private: 
        Lista<Carta*> * baraja; //lista dinamica 
  
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

#endif //BARAJA_H_