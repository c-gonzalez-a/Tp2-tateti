#include "casillero.h"

Casillero::Casillero(){
    this->estado = LIBRE;
    this->ficha = VACIO;
}

char Casillero::getFicha(){
    return this->ficha;
}

Estado Casillero::getEstado(){
    return this->estado;
}

void Casillero::bloquearCasillero(){
    this->estado = BLOQUEADO;
}

void Casillero::liberarCasillero(){
    this->estado = LIBRE;
}

void Casillero::ocuparCasillero(){
    this->estado = OCUPADO;
}
