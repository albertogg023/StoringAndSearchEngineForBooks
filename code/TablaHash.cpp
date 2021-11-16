#include "TablaHash.h"
#include "Libro.h"
#define NUM_CUBETAS_INICIAL 16384


TablaHash::TablaHash(){
	this->num_cubetas = NUM_CUBETAS_INICIAL;
	this->tablaHash = new Libro*[num_cubetas];
	this->num_elementos = 0;
}

TablaHash::~TablaHash(){
	for(int i = 0; i < this->num_cubetas; ++i){
		if(this->tablaHash[i] != NULL)
			delete this->tablaHash[i];
	}
	delete[] this->tablaHash;
}

// Consulta si un libro se encuentra en una tablaHash
// la clave usada es el ISBN
Libro * TablaHash::consultar(unsigned long long int isbn){
	unsigned int indice = hashCode(isbn);
	if(tablaHash[indice] == NULL)
		return NULL;
	if(tablaHash[indice]->get_isbn() == isbn)
		return tablaHash[indice];
	else
		return secuenciaDeBusqueda(isbn, indice);
}

// Inserta el libro en una tablaHash.
// la clave es el ISBN
void TablaHash::insertar(Libro * nuevo){
	if(num_elementos > num_cubetas*0.75)
		reestructurar();

	unsigned int indice = hashCode(nuevo->get_isbn());
	if(tablaHash[indice] == NULL){ 
		tablaHash[indice] = nuevo;
		++num_elementos;
	}
	else{
		secuenciaDeInsercion(nuevo->get_isbn(), indice, nuevo);
		++num_elementos;
	}
}

unsigned int TablaHash::hashCode(unsigned long long int clave){	// método privado
	unsigned int result = 0; 
	unsigned int factor = 17;
	while (clave > 0) {
 	  	result *= factor;
  		result += clave % 10; 
  		clave /= 10;
	}
	result %= num_cubetas;
	return result;	
}

unsigned int TablaHash::hashRedispersion(unsigned long long int clave, unsigned int inicio, unsigned int i){	// método privado
	unsigned int resultado = (inicio+i*((2*clave+1)%num_cubetas))%num_cubetas;
	return resultado;
}


Libro * TablaHash::secuenciaDeBusqueda(unsigned long long int isbn, unsigned int inicio){	// método privado
	unsigned int i = 1;	// tamaño de los saltos
	unsigned int indice = hashRedispersion(isbn, inicio, i);	// indice cambiante 
	Libro * elem = tablaHash[indice]; 
	while(elem != NULL){
		if(elem->get_isbn() == isbn)
			return tablaHash[indice]; 
		indice = hashRedispersion(isbn, indice, i);
		++i;
		elem = tablaHash[indice];
	}
	return NULL;
}

void TablaHash::secuenciaDeInsercion(unsigned long long int isbn, unsigned int inicio, Libro * libro){	// método privado
	unsigned int i = 1;		// tamaño de los saltos
	unsigned int indice = hashRedispersion(isbn, inicio, i);	// indice cambiante 
	Libro * elem = tablaHash[indice]; 
	while(elem != NULL){
		indice = hashRedispersion(isbn, indice, i);
		++i;
		elem = tablaHash[indice]; 
	}
	tablaHash[indice] = libro;
}

void TablaHash::reestructurar(){	// método privado
	int n_num_cubetas_original = this->num_cubetas;
	this->num_cubetas = 0;

	Libro ** original = this->tablaHash;
	this->tablaHash = new Libro*[n_num_cubetas_origina*2];
	Libro * elem;
	unsigned int indice_insertar;
	for(int i = 0; i < n_num_cubetas_original; ++i){
		elem = original[i];
		if(elem != NULL)
			insertar(elem);
	}

	for (int i = 0; i < n_num_cubetas_original; ++i)	// hacemos NULL todos los elementos de nuestra tabla original
		original[i] = NULL;								// para así evitar que liberemos los libros
	delete [] original;	// liberamos nuestra Tabla Hash antigua
}
