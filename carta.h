#ifndef CARTA_H_
#define CARTA_H_

enum TipoCarta {
    perderTurno,
    volverAtras,
    bloquearCasillero,
    anularCasillero,
    intercambiarFicha,
    repetirTurno,
    moverFicha,
};

class Carta {

    private: 
        TipoCarta nombre;

    public:

        /**
         * Pre: -
         * Post: Construye una carta del tipo indicado
         */
        Carta(TipoCarta tipo);

        /*
         * Devuelve el tipo 
         */
        TipoCarta getNombre();
};

#endif //CARTA_H_