#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "universales.h"

///Declaracion de estructuras
typedef tNodo *tLista;

///Firma de funciones
int crearLista(tLista *pL);

int InsertarPrimeroEnLista(tLista *pL, void *info, unsigned tamInfo);

int InsertarUltimoEnLista(tLista *pL, void *info, unsigned tamInfo);

int InsertarOrdenadoEnLista(tLista *pL, void *info, unsigned tamInfo, int (*cmp)(void*, void*), int(*accion)(void*, void*));

int listaLlena(unsigned tamInfo);

int verPrimeroLista(tLista *pL, void *info, unsigned tamInfo);

int verUltimoLista(tLista *pL, void *info, unsigned tamInfo);

int verPorClaveLista(tLista *pL, void *info, unsigned tamInfo, void* clave, int (*cmp)(void*, void*));

int recorrerLista(tLista *pL, void* param, int (*cmp)(void*, void*), int(*accion)(void*, void*));

int sacarDeLista(tLista *pL, void *info, unsigned tamInfo, int (*cmp)(void*, void*));

int listaVacia(tLista *pL);

int destruirLista(tLista *pL);

#endif // LISTA_H_INCLUDED
