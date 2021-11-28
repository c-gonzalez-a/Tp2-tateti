#ifndef CARTA_H_
#define CARTA_H_

enum TipoCarta {
    perderTurno,
    volverAtras,
    bloquearCasillero,
    anularCasillero,
    intercambiarFicha,
    repetirTurno,
};

class Carta {

    private: 
        TipoCarta nombre;

    public:

        /**
         * Post: Construye una carta del tipo indicado
         */
        Carta(TipoCarta tipo);

        /**
         * Post: Imprime la carta en pantalla
         */
        void imprimirCarta();

        /*
         * Post: Devuelve el tipo
         */
        TipoCarta getNombre();
};

#endif //CARTA_H_