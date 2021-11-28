#include "tateti.h"

#include <ctime>
#include <string>
#include <iostream>

const char SI = 'S';

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
    this->turnoActual = turnos->obtenerCursor();

    this->estado = JUGANDO;
};

TipoCarta generarCartaAleatoria(){

    TipoCarta resultado;
    srand(time(NULL));

    int numeroAleatorio = ran()%6;

    if (numeroAleatorio == 0){
        resultado = perderTurno;
    }
    else if(numeroAleatorio == 1){
        resultado = volverAtras;
    }
    else if(numeroAleatorio == 2){
        resultado = bloquearCasillero;
    }
    else if(numeroAleatorio == 3){
        resultado = anularCasillero;
    }
    else if(numeroAleatorio == 4){
        resultado = intercambiarFicha;
    }
    else if(numeroAleatorio == 5){
        resultado = repetirTurno;
    }

    return resultado;

}

void TaTeTi::repartirCartas(){

    for(int i = 0; i < (this->jugadores->contarElementos); i++){

        Carta * cartaAleatoria = new Carta( generarCartaAleatoria() );

        this->jugadores->obtenerCursor()->agregarCartaABaraja(cartaAleatoria);

        this->jugadores->avanzarCursor();
    }
    
}

bool deseaJugarCarta(){
    
    bool deseaJugar = true;
    char respuestaJugador;

    std::cout << "Desea jugar alguna carta? (S para si, cualquier letra para no" << std::endl;
    std::cin >> respuestaJugador;

    if ( respuesta != SI ){
        deseaJugar = false;
    }

    return deseaJugar;
}

int pedirCarta(){

    int respuesta;

    std::cout << "Ingrese el numero de la carta que desea jugar" << std::endl;
    std::cin >> respuesta;

    return respuesta;

}

Coordenada pedirPosicionFicha(){

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

    return posicion;
}

void TaTeTi::posicionarFicha(){
    
    Coordenada posicion;
    bool posicionValida = false;

    while (!posicionValida){
    
        posicion = pedirPosicionFicha();

        if ( tablero->agregarFicha() ){
            posicionValida = true;
        }
    }

}

void TaTeTi::moverFicha(){



}

void TaTeTi::jugarTurno(Jugador * jugador){

    do {
        
        jugador->listarCartas();
        bool respuesta = deseaJugarCarta();
            
            if ( respuesta ){
                int posicionCartaAJugar = pedirCarta();
             }

    } while ( !(jugador->jugarCarta(posicionCartaAJugar)) && (respuesta) );

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
        
        jugarTurno(this->turno);
        
        actualizarEstadoDelJuego();

    }
}

TaTeTi::~TaTeTi(){
    tablero->~Tablero();
    mazo->~Mazo();
}


#endif //string