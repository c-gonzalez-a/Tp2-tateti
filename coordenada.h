#ifndef COORDENADA_H_
#define COORDENADA_H_

class Coordenada{
    
    private:
        int coordX;
        int coordY;
        int coordZ;
    
    public: 

        /**
         * Pre: -
         * Post: construye una coordenada
         */
        Coordenada(int x, int y, int z);

        ~Coordenada();

        /** 
         * Pre: La coordenada debe estar creada
         * Post: Devuelve la coordenada x
         */
        int getX();

        /** 
         * Pre: La coordenada debe estar creada
         * Post: Devuelve la coordenada y
         */
        int getY();

        /** 
         * Pre: La coordenada debe estar creada
         * Post: Devuelve la coordenada z
         */
        int getZ();
};

#endif //COORDENADA_H_