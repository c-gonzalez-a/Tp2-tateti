#include "Mazo.h"

Mazo::Mazo(int cantidadDeCartas) {
    this->mazo = new Pila<Carta *>();
    for (int i = 0; i < cantidadDeCartas; i++){
        mazo->apilar(new Carta());
    }
}

Mazo::~Mazo(){
    while(!this->mazo->estaVacia()){
        this->mazo->desapilar();
    }
    delete this->mazo;
}

Carta * Mazo::sacarCarta() {
    return this->mazo->desapilar();
}

int Mazo::getCartasRestantes() {
    return this->mazo->contarElementos();
}

bool Mazo::estaVacio() {
    return this->mazo->estaVacia();
}