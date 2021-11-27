#include "tateti.h"

#include <string>
#include <iostream>

/* void jugar(...){
    mostrarMazoJugador();
    si estado = moviendo
        pedirUbicacionDeFicha();
    
    ubicarFichaEnLugarVacio();
    opcionDeJugarCarta();
}
*/

/**
 * Pre: -
 * Post: Imprime por pantalla una bienvenida al usuario al juego 
 */
void darBienvenida();

/**
 * Pre: -
 * Post: Pide datos al usuario
 */
int pedirAlUsuario(std::string dato);

/**
 * Pre: -
 * Post: Pide al usuario que ingrese la ficha que usuara durante la partida
 */
char pedirFicha(int numeroJugador);

/**
 * Pre: -
 * Post: Pregunta si el jugador desea jugar alguna carta de su baraja, si no tiene ninguna no hace nada
 */
void preguntarSiDeseaJugarUnaCarta();
        
/**
 * Pre: El juego tateti debe estar creado correctamente
 * Post: Juega el turno del jugador que le corresponde
 */
void jugarTurno(this->turno);
        
/**
 * Pre: -
 * Post: Si hay algun ganador se cambia el estado del juego, sino se pasa al siguiente turno
 * 
 */
void actualizarEstadoDelJuego();

TaTeTi::TaTeTi(){
    
    darBienvenida(); 

    this->cantJugadores = pedirAlUsuario(string cantJugadores);
    
    this->tablero = new Tablero( pedirAlUsuario("primera dimension"), pedirAlUsuario("segunda dimension"), pedirAlUsuario("tercera dimension") );

    this->ganador = -1;

    this->turno = 1;

    this->mazo = new Mazo();

    this->jugadores = new Lista<Jugador*>();
    
    for (int i = 1; i <= (this->cantJugadores=); i++){

        Jugador * jugadorActual = new Jugador(pedirFicha(i) , i);
        this->jugadores->agregar(jugadorActual);
    }
   
};

void TaTeTi::jugar(){

    while (this->ganador == -1){

        preguntarSiDeseaJugarUnaCarta();
        
        jugarTurno(this->turno);
        
        actualizarEstadoDelJuego();
    }
}

TaTeTi::~TaTeTi(){
    //hay que hacer
}

#endif //string