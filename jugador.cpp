#include "jugador.h"

Jugador::Jugador(char _ficha, int _numeroDelJugador){
    this->ficha = _ficha;
    this->numero = _numeroDelJugador;
    this->estado = POSICIONANDO;
    this->baraja = new Baraja();
}

void Jugador::listarCartas(){
    //muestra las cartas que tiene el jugador y las enumera asi puede elegir cual jugar con la funcion jugarCarta
}

void Jugador::jugarCarta(int carta){
    //seleccionar una carta de la baraja, lista dinamica, borrarla y reordenar la baraja
}