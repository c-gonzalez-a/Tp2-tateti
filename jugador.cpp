#include "jugador.h"

Jugador::Jugador(char _ficha, int _numeroDelJugador, int cantFichas){
    this->ficha = _ficha;
    this->numero = _numeroDelJugador;
    this->estado = POSICIONANDO;
    this->baraja = new Baraja();
    this->cantFichaPorPoner = cantFichas;
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

void Jugador::establecerEstado(EstadoJugador estado) {
    this->estado = estado;
}

EstadoJugador Jugador::obtenerEstado() {
    return this->estado;
}