#ifndef __COLECCION_LIBROS__H
#define __COLECCION_LIBROS__H
#include "TablaHash.h"
#include "Arbol.h"
#include "ListaApariciones.h"
#include "Aparicion.h"
#include "Libro.h"
#include <iostream>
using namespace std;


class ColeccionLibros{
	private:
		TablaHash tablahash;
		Arbol arbol;
	public:
		ColeccionLibros();
		void insertarLibro(Libro * nuevo);
		Libro * consultarLibro(unsigned long long int isbn);
		void insertarAparicionPalabra(string cadena, Aparicion aparicion);
		ListaApariciones * obtenerAparicionesPalabra(string cadena);
		ListaApariciones * interseccionAparicionesDePalabras(string cadena);
		ListaApariciones * unionAparicionesDePalabras(string cadena);
};


#endif
