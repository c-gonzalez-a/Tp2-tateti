#ifndef TABLERO_H_
#define TABLERO_H_

#include "casillero.h"
#include "lista.h"

class Tablero {

    private:
        // Se indicará el ganador con el numero del jugador que corresponda, de no haber ganadores um 0
        int winner;                              
        Lista<Lista<Lista<Casillero*>*>*> *tablero;

    public:

        /**
         * Pre: -
         * Post: Construye el tablero
         */
        Tablero(int dim1, int dim2, int dim3); 

        /** 
         * Pre: El tablero debe estar creado
         * Post: Lo destruye 
         */
        ~Tablero();


        void initBoard(int, int);               // inicia la variable board con un tablero con dimensiones igual a los dos argumentos
        void addChecker(int, int, int);         // agrega ficha en casillero con coordenadas (x,y) = a los argumentos
        void moveChecker(int, int, int, int);   // mueve ficha del casillero con (x,y) = a los primero dos argunmentos a casillero con (x,y) = a los segundos dos argumentos
        void printState();                      // imprime estado del tablero
        void printFile(int, int, std::ofstream &);                // imprime el estado actual del tablero a un archivo de texto
        bool checkIfEmpty(int, int);            // chequea si casillero esta vacio para colocar o  mover
        bool validateMove(int , int , int , int);
        bool validateOwnership(int, int, int);  // chequea si una ficha pertenece al jugador en cuestion
        //bool allSame(std::string);                   // chequea si todos los elementos de un array(fila, columna o diagonal) son iguales
        bool checkIfWinner();                   // chequea si hay alguna linea de elementos iguales
};

#endif /* TABLERO_H_ */