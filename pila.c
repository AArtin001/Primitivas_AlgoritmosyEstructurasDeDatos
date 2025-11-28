#include "pila.h"

#define ERROR 1
#define TODOBIEN 0
#define MENOR(x,y) (x<y)? x:y

int crearPila(tPila *pP){
    *pP = NULL;
    return TODOBIEN;
}

int InsertarEnPila(tPila *pP, void *info, unsigned tamInfo){

    tNodo *nuevo = (tNodo*)malloc(sizeof(tNodo));
    if(!nuevo){
        printf("\nNo hay memoria para el nodo");
        return ERROR;
    }
    nuevo->info = malloc(tamInfo);
    if(!nuevo->info){
        printf("\nNo hay memoria para la info");
        free(nuevo);
        return ERROR;
    }

    nuevo->tamInfo = tamInfo;
    memcpy(nuevo->info, info, tamInfo);
    nuevo->sig = *pP;
    *pP = nuevo;

    return TODOBIEN;
}

int pilaLlena(unsigned tamInfo){

    void *nuevo = malloc(sizeof(tNodo));
    if(!nuevo){
        printf("\nNo hay memoria para el nodo");
        return ERROR;
    }

    void *info = malloc(tamInfo);
    if(!info){
        printf("\nNo hay memoria para la info");
        free(nuevo);
        return ERROR;
    }

    free(nuevo);
    free(info);
    return TODOBIEN;
}

int verTopePila(tPila *pP, void *info, unsigned tamInfo){

    if(!(*pP)){
        printf("\nPila Vacia");
        return ERROR;
    }

    memcpy(info, (*pP)->info, MENOR(tamInfo, (*pP)->tamInfo));

    return TODOBIEN;
}

int sacarDePila(tPila *pP, void *info, unsigned tamInfo){

    tNodo *eliminar;

    if(!(*pP)){
        printf("\nPila Vacia");
        return ERROR;
    }

    //Devuelvo la info al usuario
    memcpy(info, (*pP)->info, MENOR(tamInfo, (*pP)->tamInfo));

    eliminar = *pP;
    *pP = eliminar->sig;

    free(eliminar->info);
    free(eliminar);

    return TODOBIEN;
}

int pilaVacia(tPila *pP){

    if(!(*pP)) return 0;
    return 1;
}

int destruirPila(tPila *pP){

    tNodo *eliminar;

    while(*pP){
        eliminar = *pP;
        *pP = eliminar->sig;

        free(eliminar->info);
        free(eliminar);
    }

    return TODOBIEN;
}
