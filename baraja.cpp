#include "baraja.h"
#include <iostream>

Baraja::Baraja(){
    this->baraja = new Lista<Carta*>();
}

void Baraja::agregarCartas(Lista<Carta *> &cartas) {
    this->baraja->agregar(cartas);
}

void Baraja::agregarCarta(Carta &carta) {
    this->baraja->agregar(&carta);
}

bool Baraja::seleccionarCartaPorTipo(TipoCarta tipo) {
    for (unsigned i = 1; i <= this->baraja->contarElementos(); i++) {
        if (tipo == this->baraja->obtener(i)->getNombre()) {
            this->baraja->remover(i);
            return true;
        }
    }
    return false;
}

void Baraja::imprimirBaraja() {
    bool primeraVez = true;
    std::cout << "[";

    for (unsigned i = 1; i <= this->baraja->contarElementos(); i++) {
        if (primeraVez) {
            this->baraja->obtener(i)->imprimirCarta();
            primeraVez = false;
        } else {
            std::cout << ";";
            this->baraja->obtener(i)->imprimirCarta();
        }
    }
    std::cout << "]";
}

Baraja::~Baraja(){
    delete baraja;
}