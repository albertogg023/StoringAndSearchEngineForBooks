#ifndef __NODO_H__
#define __NODO_H__
#include "ListaApariciones.h"
#include "Aparicion.h"


class Nodo {
    private:
        Nodo ** hijos;  // array de punteros a nodo
        ListaApariciones * apariciones; // lista de apariciones que nos sirve también como marca de fin de palabra
    public: 
        Nodo();
        ~Nodo();
        Nodo * consultaCaracter(char letra);
        void insertaCaracter(char letra);
        void insertaAparicion(Aparicion aparicion);
        ListaApariciones * obtenerApariciones();
        bool hayMarca();
        void ponMarca();
        void quitaMarca();
};


#endif