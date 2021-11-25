#ifndef COLA_H_
#define COLA_H_

#include "nodo.h"

template<class T> class Cola {

    private:

        Nodo<T> * front;
        Nodo<T> * end;


    public:

        /**
         * Pre: -
         * Post: Devuelve una cola vacia preparada para ser usada
         */
        Cola();

        /** 
         * Pre: La cola debe haber sido creada
         * Post: Destruye la cola
         */
        ~Cola();

        /** 
         * Pre: La cola debe estar creada, no debe estar vacia
         * Post: Devuelve el valor del primer elemento de la cola
         */
        T getFront();

        /**
         * Pre: La cola debe haber sido creada
         * Post: Da de alta en la cola un elemento que se ubicará al final
         */
        void acolar(T elemento);

        /**
         * Pre: La cola debe estar creada y no vacía
         * Post: Cola modificada por la eliminación del elemento del frente
         */
        void desacolar();

        /**
         * Pre: La cola debe estar creada
         * Post: Devuelve un valor logico indicando si la cola esta vacia
         */
        bool vacia();

};

template<class T>
Cola<T>::Cola(){
    this->front = NULL;
    this->end = NULL;
    this->tamanio = 0;
}

template<class T>
T Cola<T>::getFront(){

    if (this->front != NULL){
        return this->front;
    }

}

template<class T>
void Cola<T>::acolar(T elemento){

    Nodo<T> *nuevo = new Nodo<T>(elemento);

    if (this->front == NULL){
        this->front = nuevo;
        this->end = nuevo;
    }  

    else {
        this->end->cambiarSiguiente(nuevo);
    }
}

template<class T>
void Cola<T>::desacolar(){

    Nodo<T> *removido;
    removido = this->front;

    this->front = this->front->obtenerSiguiente();

    delete removido;
    
}

template<class T>
bool Cola<T>::vacia(){
    return (this->tamanio == 0);
}

template<class T>
Cola<T>::~Cola(){
    while (this->primero != NULL){
        this->desacolar();
    }
}
