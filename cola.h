#ifndef COLA_H_INCLUDED
#define COLA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "universales.h"

///Declaracion de estructuras
typedef tNodo *tCola;

///Firma de funciones
int crearCola(tCola *pC);

int InsertarEnCola(tCola *pC, void *info, unsigned tamInfo);

int colaLlena(unsigned tamInfo);

int verTopeCola(tCola *pC, void *info, unsigned tamInfo);

int sacarDeCola(tCola *pC, void *info, unsigned tamInfo);

int colaVacia(tCola *pC);

int destruirCola(tCola *pC);

#endif // COLA_H_INCLUDED
