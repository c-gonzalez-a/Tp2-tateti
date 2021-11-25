#include "carta.h"

Carta::Carta(TipoCarta tipo){
    this->nombre = tipo;
}

TipoCarta Carta::getNombre(){
    return this->nombre;
}