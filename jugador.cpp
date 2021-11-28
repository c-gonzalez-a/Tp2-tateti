#include "jugador.h"

Jugador::Jugador(char _ficha, int _numeroDelJugador){
    this->ficha = _ficha;
    this->numero = _numeroDelJugador;
    this->estado = POSICIONANDO;
    this->baraja = new Baraja();
}

void Jugador::listarCartas(){
    this->baraja->imprimirBaraja();
}

bool Jugador::jugarCarta(TipoCarta carta){
    this->baraja->seleccionarCartaPorTipo(carta);
}

int Jugador::obtenerNumero() {
    return this->numero;
}

char Jugador::obtenerFicha() {
    return this->ficha;
}

void Jugador::establecerEstado(Estado estado) {
    this->estado = estado;
}

Estado Jugador::obtenerEstado() {
    return this->estado;
}