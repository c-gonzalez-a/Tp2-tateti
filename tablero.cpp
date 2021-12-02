#include "tablero.h"
#include "casillero.h"
#include "lista.h"

Tablero::Tablero(int dim1, int dim2, int dim3){
    
    this->tablero = new Lista<Lista<Lista<Casillero*>*>*>();
    
    for (int k = 0; k < dim1; k++){
        Lista<Lista<Casillero*>*>*columna = new Lista<Lista<Casillero*>*>();
        for (int i = 0; i < dim2; i++){
            Lista<Casillero*>*fila = new Lista<Casillero*>();
            for (int j = 0; j < dim3; j++ ){
                Casillero * casillero = new Casillero();
                fila->agregar(casillero);
            }
            columna->agregar(fila);

        }
        this->tablero->agregar(columna);
    
    }

}



// #include "Tablero.h"


//Constructor de un tablero con las dimensiones especificadas


Tablero::~Tablero()
{
    //std::cout << "DESTRUCTED [" << this << "]\n";
}

Casillero * Tablero::obtenerCasillero(int x, int y, int z, Lista<Lista<Lista<Casillero*>*>*> Tablero){

    this->tablero->iniciarCursor();
    for(int i=1;i<x;i++){
        this->tablero->avanzarCursor();
    }

    ((tablero)->obtenerCursor())->iniciarCursor();
    for(int i=1;i<y;i++){
        ((tablero)->obtenerCursor())->avanzarCursor();
    }

    (((tablero)->obtenerCursor())->obtenerCursor())->iniciarCursor();
    for(int i=1;i<z;i++){
        (((tablero)->obtenerCursor())->obtenerCursor())->avanzarCursor();
    }

    return (((tablero)->obtenerCursor())->obtenerCursor())->obtenerCursor();

}


// addChecker() agrega una ficha en un lugar determinado del tablero
void Tablero::agregarFicha(Coordenada &coord, Jugador &jugar){

    int pos_x = coord.getX();
    int pos_y = coord.getY();
    int pos_z = coord.getZ();

    char ficha = jugar.obtenerFicha();

    (this->tablero)->iniciarCursor();
    for(int i=1;i<pos_x;i++){
        (this->tablero)->avanzarCursor();
    }

    ((this->tablero)->obtenerCursor())->iniciarCursor();
    for(int i=1;i<pos_y;i++){
        ((this->tablero)->obtenerCursor())->avanzarCursor();
    }

    (((this->tablero)->obtenerCursor())->obtenerCursor())->iniciarCursor();
    for(int i=1;i<pos_z;i++){
        (((this->tablero)->obtenerCursor())->obtenerCursor())->avanzarCursor();
    }

    ((((this->tablero)->obtenerCursor())->obtenerCursor())->obtenerCursor())->ocuparCasillero(ficha);

}

// moveChecker() mueve una pieza de una posicion de origen hacia una de destino
void Tablero::moverFicha(Coordenada &origen, Coordenada &destino){

    char espacio = ' ';
    int de_x = origen.getX();
    int de_y = origen.getY();
    int de_z = origen.getZ();

    int a_x = destino.getX();
    int a_y = destino.getY();
    int a_z = destino.getZ();

    Casillero * casilleroOrigen = obtenerCasillero(de_x,de_y,de_z, *(this->tablero));
    Casillero * casilleroDestino = obtenerCasillero(a_x,a_y,a_z, *(this->tablero));

    char ficha = casilleroOrigen->getFicha();
    casilleroOrigen->ocuparCasillero(espacio);
    casilleroOrigen->liberarCasillero();

    casilleroDestino->ocuparCasillero(ficha);
}

void Tablero::intercambiarFicha(Coordenada &origen, Coordenada &destino){

    char espacio = ' ';
    int de_x = origen.getX();
    int de_y = origen.getY();
    int de_z = origen.getZ();

    int a_x = destino.getX();
    int a_y = destino.getY();
    int a_z = destino.getZ();

    Casillero * casilleroOrigen = obtenerCasillero(de_x,de_y,de_z, *(this->tablero));
    Casillero * casilleroDestino = obtenerCasillero(a_x,a_y,a_z, *(this->tablero));

    char fichaOrigen = casilleroOrigen->getFicha();
    char fichaDestino = casilleroDestino->getFicha();
    casilleroOrigen->ocuparCasillero(fichaDestino);
    casilleroDestino->ocuparCasillero(fichaOrigen);
}

void Tablero::quitarFicha(Coordenada &_coordenada){

    char espacio = ' ';
    int de_x = _coordenada.getX();
    int de_y = _coordenada.getY();
    int de_z = _coordenada.getZ();

    Casillero * _casillero = obtenerCasillero(de_x,de_y,de_z, *(this->tablero));

    (*_casillero).ocuparCasillero(espacio);
    (*_casillero).liberarCasillero();
}


void Tablero::imprimirTablero(){




// }


// // printState() imprime el estado actual del tablero
// void Tablero::printState(){
//     std::cout << "-------------" << std::endl;
//     for(int i=0 ; i < this->rows ; i++ ){
//         std::cout << "|" << std::ends;
//         for(int j=0 ; j < this->columns ; j++ ){
//            std::cout <<this->board[i][j]<<" |" << std::ends;
//         }
//         std::cout << "" << std::endl;
//         std::cout << "-------------" << std::endl;
//     }
// }

// // checkIfEmpty() revisa si un casillero se encuentra vacio tanto para colocar una ficha ahi como para moverla hacia ahi
// bool Tablero::checkIfEmpty(int row, int column){
//     if (this->board[row][column] == ' '){
//         return 0;}
//     else{
//         std:: cout << "Movimiento prohibido. Solo puede colocar/mover su ficha en/a lugares vacios" << std::endl;
//         return 1;}
// }


// // validateMove() valida que el movimiento de una pieza se realice hacia lugares adyacentes a donde se encuentra la misma actualmente
// bool Tablero::validateMove(int row_act, int col_act, int row_to,int col_to){
//     if(abs((row_act-row_to) + (col_act-col_to)) != 1 ){
//         std:: cout << "Movimiento prohibido. Solo puede mover su ficha a lugares adyacentes" << std::endl;
//         return 1;
//     }
//     return 0;
// }






// // validateOwnership() valida si un jugador es duenio de la ficha que esta intentando mover
// bool Tablero::validateOwnership(int row, int column, int player){
//     char mark;
//     if(player==1)
//         mark = 'X';
//     if(player==2)
//         mark = 'O';
//     if(this->board[row][column] != mark){
//         std:: cout << "Esa ficha no le pertenece. Solo puede mover fichas suyas" << std::endl;
//         return 1;
//     }
//     return 0;
// }


// // allSame() es una funcion auxiliar que verifica en forma recursiva si un string contiene valores identicos
// bool allSame(const std::string&, int );

// bool allSame(const std::string &str, int N){

//     if(N==1){return true;}
//     if(str[0] != str[N-1]){
//         return false;}
//     return allSame(str, N-1);
// }


// bool Tablero::checkIfWinner(){

//     int min_dim = std::min(this->rows, this->columns);
//     std::string aux;

//     // chequeo filas
//     for(int i=0; i<min_dim; i++){
//         for(int j=0; j<min_dim; j++){
//             aux[j]=(this->board[i][j]);
//         }
//         if(allSame(aux, min_dim)){
//             std:: cout << "Hay ganador!(fila "<< i+1 << ")"<< std::endl;
//             return 1;
//         }
//     }

//     // chequeo columnas
//     for(int i=0; i<min_dim; i++){
//         for(int j=0; j<min_dim; j++){
//             aux[j]=this->board[j][i];
//         }
//         if(allSame(aux, min_dim)){
//             std:: cout << "Hay ganador!(columna "<< i+1 << ")" << std::endl;
//             return 1;
//         }
//     }

//     // chequeo diagonales
//     for(int i=0; i<min_dim; i++){
//         aux[i]=this->board[i][i];
//     }
//     if(allSame(aux, min_dim)){
//         std:: cout << "Hay ganador!(diagonal)" << std::endl;
//         return 1;
//     }

//     for(int i=0; i<min_dim; i++){
//         aux[i]=this->board[i][min_dim-i-1];
//     }
//     if(allSame(aux, min_dim)){
//         std:: cout << "Hay ganador!(antidiagonal)" << std::endl;
//         return 1;
//     }
//     return 0;
// }


// void Tablero::printFile(int turno, int jugador, std::ofstream &archivo){
//     archivo << "Turno "<< turno << " del Jugador "<< jugador << "\n";
//     archivo << "------------- \n" ;
//     for(int i=0 ; i < this->rows ; i++ ){
//         archivo << "|" ;
//         for(int j=0 ; j < this->columns ; j++ ){
//            archivo << this->board[i][j] <<" |";
//         }
//         archivo << " \n" ;
//         archivo << "------------- \n";
//     }
// }