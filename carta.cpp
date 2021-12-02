#include <iostream>

Carta::Carta(){
    this->nombre = CARTAS[rand() % 6];
}

void Carta::imprimirCarta() {
    std::cout << this->nombre;
}

std::string Carta::getNombreCarta(){
    return this->nombre;
}