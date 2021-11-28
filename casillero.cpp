#include "casillero.h"

Casillero::Casillero(){
    this->estado = LIBRE;
    this->ficha = VACIO;
}

char Casillero::getFicha(){
    return this->ficha;
}

EstadoCasillero Casillero::getEstado(){
    return this->estado;
}

void Casillero::bloquearCasillero(){
    this->estado = BLOQUEADO;
}

void Casillero::liberarCasillero(){
    this->estado = LIBRE;
}

void Casillero::ocuparCasillero(char ficha){
    this->estado = OCUPADO;
    this->ficha = ficha
}
