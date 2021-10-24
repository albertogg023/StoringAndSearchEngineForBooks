#include "Aparicion.h"
#include "Libro.h"


// Constructor de la clase donde el puntero a libro el número de capítulos y el número de parrafos de la aparición son pasados como parámetros
Aparicion::Aparicion(Libro * pl, int num_capitulo, int num_parrafo){
	this->pl = pl;
	this->num_capitulo = num_capitulo;
	this->num_parrafo = num_parrafo;
}

// Método encargado de mostrar los atributos de la aparición
void Aparicion::mostrar(){
	this->pl->mostrarCorto();
 	cout << ", Cap. " << this->num_capitulo << ", par. " << this->num_parrafo << endl;
}

// Método encargado de definir la operación "menor que" de las apariciones
bool Aparicion::operator<(const Aparicion &otra){
	if( this->pl->get_isbn() < otra.pl->get_isbn() )	return true; // primero se compara por ISBN
	else if( this->pl->get_isbn() > otra.pl->get_isbn() ) return false;
	else{
		if(this->num_capitulo < otra.num_capitulo) return true; // después por capítulos
		else if(this->num_capitulo > otra.num_capitulo) return false;
		else{
			if(this->num_parrafo < otra.num_parrafo) return true; // por último por párafos
			else return false;
		}
	}
}
// Método encargado de definir la operación "igual que" de las apariciones
bool Aparicion::operator==(const Aparicion &otra){
	if(this->pl->get_isbn() == otra.pl->get_isbn() 		// tanto número de capitulos, número de párrafos e ISBN deben ser iguale
			&& this->num_capitulo == otra.num_capitulo
			&& this->num_parrafo == otra.num_parrafo)
		return true;
	else
		return false;
}