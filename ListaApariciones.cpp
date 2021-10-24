#include "Aparicion.h"
#include "ListaApariciones.h"
#include <list>


ListaApariciones::ListaApariciones(){
	this->num_elementos = 0;
}

// Inserción de un nuevo puntero en un la lista
// Los Apariciones estan ordenados por ISBN en la lista
void ListaApariciones::insertar(Aparicion nueva){
	list<Aparicion>::iterator it = this->listaApariciones.begin();
	while( it != this->listaApariciones.end() && *it < nueva )	++it;			
	if( it == this->listaApariciones.end() || !(nueva == *it ) ){
		this->listaApariciones.insert(it, nueva);
		this->num_elementos+=1;
	}
}

// Comprobamos si la lista es vacía
bool ListaApariciones::esVacia(){
	return num_elementos == 0;
}

// Método encargado de mostrar las apariciones de una lista de apariciones
void ListaApariciones::mostrar(){
	cout << "Total: " << num_elementos << " resultados" << endl;
	list<Aparicion>::iterator it = this->listaApariciones.begin();
	for(int i = 1; i <= num_elementos; ++i){
		cout << i << ". ";
		(*it).mostrar();
		++it;
	}
}

// Copiamos en la lista pasada como parámetro
// el contenido de la lista que realiza la instancia
void ListaApariciones::copiarLista(ListaApariciones * copia){
	list<Aparicion>::iterator it = this->listaApariciones.begin();	// iterador para recorrer la lista a copiar
    for(int i = 0; i < num_elementos; ++i){
        copia->listaApariciones.push_back(*it);
    	++it;
    }
    copia->num_elementos = this->num_elementos;
}

// Se borran de la lista que realiza la instancia, las apariciones
// que no serían fruto de la intersección entre ella y la pasada como parámetro
void ListaApariciones::interseca(list<Aparicion> & lista){	// método privado auxiliar
	list<Aparicion>::iterator it1 = this->listaApariciones.begin();	//iterador de la lista que realiza la instancia
	list<Aparicion>::iterator it2 = lista.begin(); //iterador de la lista pasada como parámetro
	
	while( it1 != this->listaApariciones.end() ){
		if(it2 == lista.end() || *it1 < *it2){
			this->listaApariciones.erase(it1++);
			--this->num_elementos;
		}
		else if(*it1 == *it2){
			++it1;
			++it2;
		}
		else ++it2;
	}
}

// Se borran de la lista que realiza la instancia, las apariciones
// que no serían fruto de la intersección entre ella y la pasada como parámetro
void ListaApariciones::une(list<Aparicion> & lista){	// método privado auxiliar
	list<Aparicion>::iterator it1 = this->listaApariciones.begin();	//iterador de la lista que realiza la instancia
	list<Aparicion>::iterator it2 = lista.begin(); //iterador de la lista pasada como parámetro
	
	while( it2 != lista.end() ){
		if( it1 == this->listaApariciones.end() ){
			this->listaApariciones.push_back(*it2++);
			++this->num_elementos;
		}
		else if(*it1 < *it2)
			++it1;
		else if(*it2 < *it1){
			this->listaApariciones.insert(it1, *it2);
			++this->num_elementos;
			++it2;
		}
		else{
			++it1;
			++it2;
		}

	}
}

// Llama a la función auxiliar que realiza la interseción
void ListaApariciones::interseca(ListaApariciones * lista){
	this->interseca(lista->listaApariciones);
}

// Llama a la función auxiliar que realiza la interseción
void ListaApariciones::une(ListaApariciones * lista){
	this->une(lista->listaApariciones);
}