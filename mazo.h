#ifndef _MAZO_H
#define _MAZO_H


#include "carta.h"
#include "pila.h"


class Mazo {

private:
    Pila<Carta *> * mazo;

public:

    /* Pre: Recibe un entero indicando la cantidad de cartas a apilar.
     * Post: Crea un mazo
     */
    Mazo(int cantidadDeCartas);

    /* Pre:
     * Post: Libera la memoria reservada para el mazo.
     */
    virtual ~Mazo();

    /* Pre: -
     * Post: Saca una carta del mazo desapilando la ultima de la pila y la retorna.
     */
    Carta * sacarCarta();

    /* Pre: -
     * Post: Devuelve la cantidad de cartas que quedan en el mazo.
     */
    int getCartasRestantes();

    /* Pre:
     * Post: Indica si el mazo esta vacio.
     */
    bool estaVacio();


};

#endif //PRUEBAMAZO_MAZO_H