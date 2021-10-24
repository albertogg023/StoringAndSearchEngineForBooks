#ifndef __TABLA_HASH_H__
#define __TABLA_HASH_H__
#include "Libro.h"


class TablaHash{
	private:
		int num_cubetas;	// numero de cubetas
		Libro ** tablaHash;	// array de punteros a libro
		int num_elementos;	// numero de elementos insertados
		unsigned int hashCode(unsigned long long int clave);	// función de dispersión
		unsigned int hashRedispersion(unsigned long long int clave, unsigned int inicio, unsigned int i);	// función de redispersión
		void secuenciaDeInsercion(unsigned long long int isbn, unsigned int inicio, Libro * libro);
		Libro * secuenciaDeBusqueda(unsigned long long int isbn, unsigned int inicio);
		void reestructurar();	// restructura la tabla si num_elementos > 2*num_cubetas
	public:
		TablaHash();
		~TablaHash();
		void insertar(Libro * nuevo);
		Libro * consultar(unsigned long long int isbn);
};


#endif