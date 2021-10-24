#include "Nodo.h"
#include "ListaApariciones.h"
#include "Aparicion.h"
#define TAMANO_ARRAY 27 


Nodo::Nodo(){
	this->hijos = new Nodo *[TAMANO_ARRAY];	// array de punteros a nodo
	for(int i = 0; i < TAMANO_ARRAY; ++i)
		this->hijos[i] = NULL;	// inicializamos a null los punteros
	this->apariciones = NULL;	// no hay lista de apariciones inicialmente
}

Nodo::~Nodo(){
	delete[] this->hijos;
	delete this->apariciones;
}

Nodo * Nodo::consultaCaracter(char letra){
	if( letra == char(0xC3) )
		return hijos[TAMANO_ARRAY-1];	// la ñ es un caso especial, la almacenamos en la ultima posicion del array
	else
		return hijos[letra - 'a'];

}

void Nodo::insertaCaracter(char letra){
	if( letra == char(0xC3) )
		hijos[TAMANO_ARRAY-1] = new Nodo();	// la ñ es un caso especial, la almacenamos en la ultima posicion del array
	else
		hijos[letra - 'a'] = new Nodo();
		
}

void Nodo::insertaAparicion(Aparicion aparicion){
	if( hayMarca() ) apariciones->insertar(aparicion);	// si ya había una lista de apariciones la insertamos en ella
	else{
		ponMarca();	// si no había una lista la creamos e insertamos la aparición
		apariciones->insertar(aparicion);
	}
}

ListaApariciones * Nodo::obtenerApariciones(){
	if( hayMarca() ) return apariciones;	// comprobamos si hay una lista de apariciones, si la hay entonces la devolvermos 
	else return NULL;
}

bool Nodo::hayMarca(){
	return apariciones != NULL;
}

void Nodo::ponMarca(){
	if( !hayMarca() ) apariciones = new ListaApariciones();	// si no había una lista de apariciones, la creamos
}

void Nodo::quitaMarca(){
	delete apariciones;
	apariciones = NULL;
}