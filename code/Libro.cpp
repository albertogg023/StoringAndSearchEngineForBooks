#include "Libro.h"
#include <iostream>
using namespace std;


Libro::Libro(){
	this->isbn = 0;
	this->ano = 0;
	this->num_capitulos = 0;
	this->titulo = "Sin asignar";
	this->autores = "Sin asignar";
}

int Libro::get_num_capitulos(){
	return this->num_capitulos;
}

// Leer se encarga de establecer los datos de un libro según lo introducido por entrada estándar
void Libro::leer(){
	cin >> this->isbn >> this->ano >> this->num_capitulos;
	string ignorar;
	getline(cin, ignorar);
	getline(cin, this->titulo);
	getline(cin, this->autores);
}

void Libro::mostrarCorto(){
	cout << this->titulo << ", " << this->autores << ", " << this->ano;
}

void Libro::mostrarLargo(){
	cout << this->titulo << endl << this->autores <<  ", " << this->ano << endl << this->num_capitulos <<  " capítulos";
}

unsigned long long int Libro::get_isbn(){
	return this->isbn;
}
