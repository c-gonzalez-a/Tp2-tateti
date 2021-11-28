#ifndef CASILLERO_H_
#define CASILLERO_H_

const char VACIO = ' ';

enum Estado {
    BLOQUEADO,
    LIBRE,
    OCUPADO,
};

class Casillero {

    private:
        char ficha;
        Estado estado;

    public:


        /**
         * Crea el casillero con el char indicado
         */
        Casillero();
    
        /**
         * Pre: El casillero debe estar creado\n
         * Post: Devuelve la ficha que contiene el casillero
         */ 
        char getFicha();

        /**
         * Pre: El casillero debe estar creado
         * Post: Devuelve el estado en el que se encuentra el casillero
         */
        Estado getEstado();
        
        /**
         * Pre: El casillero debe estar creado
         * Post: Cambia el estado del casillero a OCUPADO
         */
        void ocuparCasillero(char ficha);

        /** Pre: El casillero debe estar creado
         * Post: Pone el estado del casillero en LIBRE
         */
        void liberarCasillero();

        /** Pre: El casillero debe estar creado
         * Post: Pone el estado del casillero en BLOQUEADO
         */
        void bloquearCasillero();
};

#endif /* CASILLERO_H_ */