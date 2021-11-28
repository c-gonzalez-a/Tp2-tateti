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
         * Post: Crea una baraja sin cartas\n
         */
        Baraja();

        /**
         * Post: Agrega Cartas a la baraja
         */
        void agregarCartas(Lista<Carta*> &cartas);

        /**
         * Post: Agrega una carta a la baraja
         */
        void agregarCarta(Carta &carta);

        /**
         * Post: Selecciona una carta de la baraja por el tipo, luego elimina la carta de la baraja, si el tipo de carta existe en la baraja devuelve true, sino false
         */
        bool seleccionarCartaPorTipo(TipoCarta tipo);

         /**
          * Post: Imprime la baraja en pantalla
          */
         void imprimirBaraja();

        /**
         * Post: Destruye la baraja
         */
        ~Baraja();

};

#endif //BARAJA_H_