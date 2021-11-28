#include "carta.h"
#include <iostream>

Carta::Carta(TipoCarta tipo){
    this->nombre = tipo;
}

void Carta::imprimirCarta() {
    std::cout << this->getNombre();
}

TipoCarta Carta::getNombre(){
    return this->nombre;
}