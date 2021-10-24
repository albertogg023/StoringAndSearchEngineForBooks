#ifndef __INTERPRETE_H__
#define __INTERPRETE_H__
#include "ColeccionLibros.h"


void insertar(ColeccionLibros &dic);

void consultaISBN(ColeccionLibros &dic);

void consultaAND(ColeccionLibros &dic);

void consultaOR(ColeccionLibros &dic);

void salir();

void interprete(char comando, ColeccionLibros &dic);


#endif