#ifndef __LISTA_APARICIONES_H__
#define __LISTA_APARICIONES_H__
#include "Aparicion.h"
#include <list>


class ListaApariciones{
	private:
		list<Aparicion> listaApariciones;	// lista de Apariciones
		int num_elementos;	// numero de elementos insertados
		void interseca(list<Aparicion> & lista);
		void une(list<Aparicion> & lista);
	public:
		ListaApariciones();
		void insertar(Aparicion nuevo);
		bool esVacia();
		void mostrar();
		void copiarLista(ListaApariciones * copia);
		void interseca(ListaApariciones * lista);
		void une(ListaApariciones * lista);
};


#endif