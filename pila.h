#ifndef PILA_H_INCLUDED
#define PILA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "universales.h"

///Declaracion de estructuras
typedef tNodo *tPila;

///Firma de funciones
int crearPila(tPila *pP);

int InsertarEnPila(tPila *pP, void *info, unsigned tamInfo);

int pilaLlena(unsigned tamInfo);

int verTopePila(tPila *pP, void *info, unsigned tamInfo);

int sacarDePila(tPila *pP, void *info, unsigned tamInfo);

int pilaVacia(tPila *pP);

int destruirPila(tPila *pP);

#endif // PILA_H_INCLUDED
