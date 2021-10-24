#include "Arbol.h"
#include "Nodo.h"
#include "ListaApariciones.h"
#include "Aparicion.h"
#include <iostream>
using namespace std;


// Constructor de la clase Arbol que se encarga de incializar un nodo como raíz
Arbol::Arbol(){
	this->raiz = new Nodo();	
}

// Destructor de la clase árbol, llama al destructor del nodo, que a su vez llama recursivamente a todos los nodos de todos los subárboles
Arbol::~Arbol(){
	delete this->raiz;
}

// Método encargado de insertar una aparición de una palabra en el nodo
void Arbol::insertarAparicionPalabra(string cadena, Aparicion aparicion){
 	Nodo * actual = raiz;
 	int i = 0;
 	while( i < cadena.length() ){		// recorremos toda la palabra
 		if(actual->consultaCaracter(cadena[i])== NULL) 	
 			actual->insertaCaracter(cadena[i]);			// si no hay una asociación para el caracter actual, la creamos
		actual = actual->consultaCaracter(cadena[i]);
		if( cadena[i] == char(0xC3) )	// si nos encontramos con la ñ avanzamos doblemente, ya que está representada por 2 bytes
			++i;
		++i;
 	}
 	actual->insertaAparicion(aparicion);	// al final, insertaamos la aparición
}

// Método encargado de obtener una aparición de una palabra en el nodo
ListaApariciones * Arbol::obtenerAparicionesPalabra(string cadena){
	int i = 0;
 	Nodo * actual = raiz;
 	while( i < cadena.length() && !(actual->consultaCaracter(cadena[i]) == NULL) ){ // avanzamos mientras no sea el final de la cadena o mientras haya una asociación para el caracter actual
		actual = actual->consultaCaracter(cadena[i]);	// avanzamos en el nodod
		if( cadena[i] == char(0xC3) )	// si nos encontramos con la ñ avanzamos doblemente, ya que está representada por 2 bytes
			++i;
		++i;	//avanzamos en la cadena
 	}
 	if(i < cadena.length() || actual->obtenerApariciones() == NULL)		// comprobamos si la palabra estaba en el nodo
 		return NULL;
	else
		return actual->obtenerApariciones();
}