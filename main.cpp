#include "tateti.h"
#include <iostream>

int main (){

    TaTeTi * juego = new TaTeTi();

    juego->jugar();

    juego->~TaTeTi();

    return 0;
}

