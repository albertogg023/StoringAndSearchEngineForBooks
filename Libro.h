#ifndef __LIBRO_H__
#define __LIBRO_H__
#include <iostream>
using namespace std;


class Libro{
	private:
		unsigned long long int isbn;
		int ano, num_capitulos;
		string titulo, autores;

	public:
		Libro();
		int get_num_capitulos();
		void leer();
		void mostrarCorto();
		void mostrarLargo();
		unsigned long long int get_isbn();
};


#endif