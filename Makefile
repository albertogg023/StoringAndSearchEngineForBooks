a.out: main.o Interprete.o ColeccionLibros.o TablaHash.o Arbol.o Nodo.o ListaApariciones.o Aparicion.o Libro.o TextosFunciones.o
	g++ -Wall main.o Aparicion.o Libro.o TextosFunciones.o Interprete.o ColeccionLibros.o TablaHash.o Nodo.o Arbol.o ListaApariciones.o

main.o: main.cpp Interprete.h ColeccionLibros.h
	g++ -c main.cpp

Interprete.o: Interprete.cpp Interprete.h TextosFunciones.h Libro.h Aparicion.h ColeccionLibros.h ListaApariciones.h
	g++ -c Interprete.cpp

ColeccionLibros.o: ColeccionLibros.cpp ColeccionLibros.h TablaHash.h Arbol.h Aparicion.h Libro.h
	g++ -c ColeccionLibros.cpp

TablaHash.o: TablaHash.cpp TablaHash.h Libro.h
	g++ -c TablaHash.cpp

Arbol.o: Arbol.cpp Arbol.h Nodo.h ListaApariciones.h Aparicion.h
	g++ -c Arbol.cpp

Nodo.o: Nodo.cpp Nodo.h Aparicion.h ListaApariciones.h
	g++ -c Nodo.cpp

ListaApariciones.o: ListaApariciones.cpp ListaApariciones.h Aparicion.h
	g++ -c ListaApariciones.cpp

Aparicion.o: Aparicion.cpp Aparicion.h Libro.h
	g++ -c Aparicion.cpp

Libro.o: Libro.cpp Libro.h
	g++ -c Libro.cpp

TextosFunciones.o: TextosFunciones.cpp TextosFunciones.h
	g++ -c TextosFunciones.cpp