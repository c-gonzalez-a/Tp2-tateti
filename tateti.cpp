#include "tateti.h"

#include <ctime>
#include <string>
#include <iostream>

const char SI = 'S';

#define PERDER_TURNO "perderTurno"
#define VOLVER_ATRAS "volverAtras"
#define BLOQUEAR_CASILLERO "bloquearCasillero"
#define ANULAR_CASILLERO "anularCasillero"
#define INTERCAMBIAR_FICHA "intercambiarFicha"
#define REPETIR_TURNO "repetirTurno"


void darBienvenida(){

    std::cout << " \
     ########    ###             ######## ########          ######## #### \n \
        ##      ## ##               ##    ##                   ##     ##  \n \
        ##     ##   ##              ##    ##                   ##     ##  \n \
        ##    ##     ##  #######    ##    ######    #######    ##     ##  \n \
        ##    #########             ##    ##                   ##     ##  \n \
        ##    ##     ##             ##    ##                   ##     ##  \n \
        ##    ##     ##             ##    ########             ##    #### \n " 
    <<std::endl;

} 

int pedirAlUsuarioUnDato(std::string dato){

    int datoObtenido;

    std::cout << "Ingrese el valor de la " << dato << "que desea" << std::endl;
    std::cin >> datoObtenido;
    
    return datoObtenido;
}

char pedirFicha(int numeroJugador){

    char fichaObtenida;

    std::cout << "Jugador " << numeroJugador << " ingrese la ficha que usara durante el juego" << std::endl;
    std::cin >> fichaObtenida;

    return fichaObtenida;

}

int dimensionMasGrande(int dim1, int dim2,int dim3){
    
    int respuesta;

    if ( (dim1 >= dim2) && (dim1 >= dim3) ){
        respuesta = dim1;
    }
    else if ( (dim2 >= dim1) && (dim2 >= dim3) ){
        respuesta = dim2;
    }
    else if ( (dim3 >= dim1) && (dim3 >= dim2) ){
        respuesta = dim3;
    }

    return respuesta;

}

TaTeTi::TaTeTi(){
    
    darBienvenida(); 

    int dim1 = pedirAlUsuarioUnDato("primera dimension");
    int dim2 = pedirAlUsuarioUnDato("segunda dimension");
    int dim3 = pedirAlUsuarioUnDato("tercera dimension");
    this->tablero = new Tablero( dim1, dim2, dim3);
    
    this->mazo = new Mazo();
    
    this->jugadores = new Lista<Jugador*>();
    
    int cantJugadores = pedirAlUsuarioUnDato("cantidad de jugadores");
    for (int i = 1; i <= cantJugadores; i++){

        Jugador * nuevoJugador = new Jugador(pedirFicha(i) , i, dimensionMasGrande(dim1,dim2,dim3) );
        this->jugadores->agregar(nuevoJugador);

        if (i == cantJugadores){
            jugadores->ligarUltimoConPrimero();
        }
    }
    
    jugadores->iniciarCursor();
    this->turnoActual = jugadores->obtenerCursor();

    this->estado = JUGANDO;
};

void TaTeTi::repartirCartas(){

    for(int i = 0; i < (this->jugadores->contarElementos() ); i++){

        this->jugadores->obtenerCursor()->tomarcartaDelMazo();

        this->jugadores->avanzarCursor();
    }
    
}

bool deseaJugarCarta(){
    
    bool deseaJugar = true;
    char respuestaJugador;

    std::cout << "Desea jugar alguna carta? (S para si, cualquier letra para no" << std::endl;
    std::cin >> respuestaJugador;

    if ( respuestaJugador != SI ){
        deseaJugar = false;
    }

    return deseaJugar;
}

TipoCarta pedirCarta(){

    TipoCarta cartaElegida;
    std::string respuesta;
    
    bool respuestaValida = true;

    do {
        std::cout << "Ingrese el nombre de la carta que desea jugar" << std::endl;
        std::cin >> respuesta;

        if ( respuesta == PERDER_TURNO ){
            cartaElegida = perderTurno;
        }
        else if ( respuesta == VOLVER_ATRAS){
            cartaElegida = volverAtras;
        }
        else if ( respuesta == BLOQUEAR_CASILLERO){
            cartaElegida = bloquearCasillero;
        }
        else if ( respuesta == ANULAR_CASILLERO){
            cartaElegida = anularCasillero;
        }
        else if ( respuesta == INTERCAMBIAR_FICHA){
            cartaElegida = intercambiarFicha;
        }
        else if ( respuesta == REPETIR_TURNO){
            cartaElegida = repetirTurno;
        }
        else {
            respuestaValida = false;
        }

    } while (!respuestaValida);

    return cartaElegida;
}

Coordenada& pedirPosicionFicha(){

    int piso, fil, col;

    std::cout << "Ingrese el piso: " << std::endl;
    std::cin >> piso;
    std::cout << "Ingrese la fila: " << std::endl;
    std::cin >> fil;
    std::cout << "Ingrese la columna: " << std::endl;
    std::cin >> col;

    col--;
    fil--;
    piso--;

    Coordenada * posicion = new Coordenada(col, fil, piso);

    return *posicion;
}

void TaTeTi::posicionarFicha(){
    
    Coordenada * posicion;
    bool posicionValida = false;

    while (!posicionValida){
    
        *posicion = pedirPosicionFicha();

        if ( tablero->agregarFicha(*posicion) ){
            posicionValida = true;
        }
    }

}

void TaTeTi::moverFicha(){

    bool cambioValido = false;
    while(!cambioValido){
        
        Coordenada * posicionActual;
        *posicionActual = pedirPosicionFicha();
        Coordenada * posicionNueva;
        *posicionNueva = pedirPosicionFicha();

        if ( this->tablero->moverFicha(posicionActual, posicionNueva, this->turnoActual) ){
            cambioValido = true;
        }
    }
}

void TaTeTi::jugarTurno(Jugador * jugador){

    bool respuesta = false;
    TipoCarta cartaAJugar;

    do {
        
        jugador->listarCartas();
        respuesta = deseaJugarCarta();
            
            if ( respuesta ){
                cartaAJugar = pedirCarta();
            }

    } while ( !(jugador->jugarCarta(cartaAJugar)) && (respuesta) );

    if ( jugador->obtenerEstado() == POSICIONANDO){
        this->posicionarFicha();
    }
    else if ( jugador->obtenerEstado() == MOVIENDO){
        moverFicha();
    }

}

void TaTeTi::actualizarEstadoDelJuego(){

}


void TaTeTi::jugar(){

    while (this->estado == JUGANDO){
        
        this->tablero->imprimirTablero();

        repartirCartas();
        
        jugarTurno(this->turnoActual);
        
        actualizarEstadoDelJuego();

    }
}

TaTeTi::~TaTeTi(){
    tablero->~Tablero();
    mazo->~Mazo();
}