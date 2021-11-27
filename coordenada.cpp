#include "coordenada.h"

Coordenada::Coordenada(int x, int y, int z){
    this->coordX = x;
    this->coordY = y;
    this->coordZ = z;
}

int Coordenada::getX(){
    return (this->coordX);
}

int Coordenada::getY(){
    return (this->coordY);
}

int Coordenada::getZ(){
    return (this->coordZ);
}