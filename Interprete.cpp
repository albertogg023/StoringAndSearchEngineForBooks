#include "Interprete.h"
#include "ColeccionLibros.h"
#include "ListaApariciones.h"
#include "Aparicion.h"
#include "Libro.h"
#include "TextosFunciones.h"
#include <sstream>
#include <iostream>
using namespace std;


// Insertamos la información libro y su contenido en la colección de libros
void insertar(ColeccionLibros &dic){
    Libro * libro = new Libro();
    libro->leer();
	int capitulo_actual = 1;  // aparición
    int parrafo_actual = 1; // aparición
    int num_parrafos_totales = 1;   // información libro
    int num_palabras_totales = 0;   // información libro
    int num_FL = 0; // variable para controlar los párrafos
    string linea;
    string palabra;
    while( capitulo_actual <= libro->get_num_capitulos() ){
        getline(cin, linea);
        linea = normalizar(linea) + " FL";   // añadimos a la línea leída "FL", para así poder contar los saltos de líneas facilmente
        istringstream palabras(linea);
        while(palabras >> palabra){
            if(palabra == "findecapitulo"){
                if( capitulo_actual != libro->get_num_capitulos() ) ++num_parrafos_totales;     
                ++capitulo_actual;
                num_FL = 0;
                parrafo_actual = 1;
            }
            else{
                if(palabra == "FL"){
                    ++num_FL;
                    if(num_FL == 2){            // cuando los fin de línea son igual a 2 sumamos un párrafo tatno a la aparicón como al libro
                        ++num_parrafos_totales;
                        ++parrafo_actual;   
                    }
                }
                else{
                    Aparicion aparicion = Aparicion(libro, capitulo_actual, parrafo_actual);
                    dic.insertarAparicionPalabra(palabra, aparicion);
             		++num_palabras_totales;
             		num_FL = 0;	                 // si la palabra no es FL se queda en 0 e insrtamos la palabra y la aparición en la colección
                }
            }
        }
    }
    libro->mostrarLargo();
    cout << endl;
    cout << num_parrafos_totales  << " párrafos" << endl;
    cout << num_palabras_totales << " palabras" << endl;
    dic.insertarLibro(libro);       // finalmente, insertamos el libro
}

// Consulta si un libro se encuentra en una colección, si es así, muestra sus propiedades
void consultaISBN(ColeccionLibros &dic){
    unsigned long long int isbn;
    cin >> isbn;
	Libro * libro = dic.consultarLibro(isbn);
    if(libro == NULL) cout << "ISBN " << isbn << " no encontrado" << endl;
    else{
        cout << "ISBN " << isbn << " encontrado" << endl;
        libro->mostrarLargo();
        cout << endl;
    } 

}

void consultaAND(ColeccionLibros &dic){
    string cadena;
    cin.ignore(1, ' ');
    getline(cin, cadena);
    cadena = normalizar(cadena);
    cout << "a " << cadena << endl;
    ListaApariciones * intersecionPalabras = dic.interseccionAparicionesDePalabras(cadena); // ESTO SERIA LO QUE TENIAMOS EN EL 302
    if( intersecionPalabras == NULL)
        cout << "Total: 0 resultados" << endl;
    else{
        intersecionPalabras->mostrar();
        delete intersecionPalabras; // liberamos la lista de la intersección que estaba en memoria dinámica una vez la hemos mostrado
    }
}

void consultaOR(ColeccionLibros &dic){
    string cadena;
    cin.ignore(1, ' ');
    getline(cin, cadena);
    cadena = normalizar(cadena);
    cout << "o " << cadena << endl;
    ListaApariciones * unionPalabras = dic.unionAparicionesDePalabras(cadena); // ESTO SERIA LO QUE TENIAMOS EN EL 302
    if( unionPalabras == NULL)
        cout << "Total: 0 resultados" << endl;
    else{
        unionPalabras->mostrar();
        delete unionPalabras; // liberamos la lista de la intersección que estaba en memoria dinámica una vez la hemos mostrado
    }
}

void salir(){
}

// Se encarga de selección que acción realizar sobre una colección de libros
void interprete(char comando, ColeccionLibros &dic){
    if(comando == 'i') insertar(dic);
    else if(comando == 'c') consultaISBN(dic);
    else if(comando == 'a') consultaAND(dic);
    else if(comando == 'o') consultaOR(dic);
    else if(comando == 's') salir();
}