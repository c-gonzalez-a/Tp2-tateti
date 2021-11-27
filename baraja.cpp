#include "baraja.h"

Baraja::Baraja(){
    this->baraja = new Lista<Carta*>();
}

Baraja::~Baraja(){
    delete baraja;
}