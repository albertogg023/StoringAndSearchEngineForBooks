#ifndef __ARBOL_H__
#define __ARBOL_H__
#include "Nodo.h"
#include "ListaApariciones.h"
#include "Aparicion.h"
#include <iostream>
using namespace std;


class Arbol {
	private:
		 Nodo * raiz;
	public:
		 Arbol();
		 ~Arbol();
		 void insertarAparicionPalabra(string cadena, Aparicion aparicion);
		 ListaApariciones * obtenerAparicionesPalabra(string cadena);
};


#endif