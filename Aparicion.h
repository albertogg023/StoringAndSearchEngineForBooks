#ifndef __APARICION_H__
#define __APARICION_H__
#include "Libro.h"


class Aparicion{
	private:
		Libro * pl;
		int num_capitulo;
		int num_parrafo;

	public:
		Aparicion(Libro * pl, int num_capitulo, int num_parrafo);
		void mostrar();
		bool operator< (const Aparicion &otra);
    	bool operator== (const Aparicion &otra);
};


#endif