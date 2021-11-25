#ifndef MAZO_H_
#define MAZO_H_

class Mazo {

    private: 
        Carta cartas; //cola 
        /*  
            Perder el turno de un jugador (solo para el que sigue en la cola)
            Bloquear un casillero / ficha
            Volver un movimiento para atrás
            Anular casillero

            Repetir un turno
            Mover una ficha a cualquier casillero vacio
            Intercambiar fichas
        */

    public:
        Mazo();
        ~Mazo();

};

#endif /* MAZO_H_ */