#include "ColeccionLibros.h"
#include "Arbol.h"
#include "ListaApariciones.h"
#include "Aparicion.h"
#include "Libro.h"
#include <iostream>
#include <sstream>
using namespace std;


ColeccionLibros::ColeccionLibros(){
}

// Inserta un libro en la Coleccion
void ColeccionLibros::insertarLibro(Libro * nuevo){
	tablahash.insertar(nuevo);
}

// Consulta si un libro se encuentra en la Coleccion, si es así lo devuelve
// si el libro no está devuelve NULL
Libro * ColeccionLibros::consultarLibro(unsigned long long int isbn){
		return this->tablahash.consultar(isbn);
}

void ColeccionLibros::insertarAparicionPalabra(string cadena, Aparicion Aparicion){
	arbol.insertarAparicionPalabra(cadena, Aparicion);
}

ListaApariciones * ColeccionLibros::obtenerAparicionesPalabra(string cadena){
	return arbol.obtenerAparicionesPalabra(cadena);
}

ListaApariciones * ColeccionLibros::interseccionAparicionesDePalabras(string cadena){
	istringstream palabras(cadena);	// palabras a hacer intersección de sus apariciones
	string palabra;
	palabras >> palabra;	// primera palabra de la lista de palabras
	ListaApariciones  * aparicionesPalabra = obtenerAparicionesPalabra(palabra); // la intersección inicial es la lista de apariciones de la primera palabra	
	if(aparicionesPalabra == NULL)	// si la lista de apariciones de la primera palabra es vacía
		return NULL;
	else{	// procedemos a realizar todas las intersecciones
		ListaApariciones * intersecciones = new ListaApariciones();	// creamos una lista vacía
		aparicionesPalabra->copiarLista(intersecciones);	// copiamos la lista de apariciones del árbol en nuestra lista de intersección, la cual estaba vacía
		while(palabras >> palabra){	// para cada palabra
			aparicionesPalabra = obtenerAparicionesPalabra(palabra);
			if(aparicionesPalabra != NULL){	// si la lista de la palabra actual no es vacía
				intersecciones->interseca(aparicionesPalabra);
				if( intersecciones->esVacia() ){	// si el conjunto fruto de la intersección es vacío
					delete intersecciones;
					return NULL;
				}
			}
			else{
				delete intersecciones;
				return NULL;
			}
		}
		return intersecciones;
	}
}

ListaApariciones * ColeccionLibros::unionAparicionesDePalabras(string cadena){
	istringstream palabras(cadena);	// palabras a hacer union de sus apariciones
	string palabra;
	ListaApariciones * aparicionesPalabra;
	ListaApariciones * uniones = new ListaApariciones();	// creamos una lista vacía
	while(palabras >> palabra){	// para cada palabra
		aparicionesPalabra = obtenerAparicionesPalabra(palabra);
		if(aparicionesPalabra != NULL) {	// si la lista de la palabra actual no es vacía
			uniones->une(aparicionesPalabra);
		}
	}
	if( uniones->esVacia() ){
		delete uniones;
		return NULL;
	}
	else
		return uniones;
}