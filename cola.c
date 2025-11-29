#include "cola.h"

#define ERROR 1
#define TODOBIEN 0
#define MENOR(x,y) (x<y)? x:y

int crearCola(tCola *pC){
    *pC = NULL;
    return TODOBIEN;
}

int InsertarEnCola(tCola *pC, void *info, unsigned tamInfo){

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
    nuevo->sig = NULL;

    //Recorro hasta el ultimo nodo
    while(*pC){
        pC = &((*pC)->sig);
    }

    *pC = nuevo;
    return TODOBIEN;

}

int colaLlena(unsigned tamInfo){

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

    free(nuevo->info);
    free(nuevo);
    return TODOBIEN;
}

int verTopeCola(tCola *pC, void *info, unsigned tamInfo){

    if(!(*pC)){
        printf("\nCola Vacia");
        return ERROR;
    }

    memcpy(info, (*pC)->info, MENOR(tamInfo, (*pC)->tamInfo));
    return TODOBIEN;
}

int sacarDeCola(tCola *pC, void *info, unsigned tamInfo){

    tNodo *eliminar = *pC;
    memcpy(info, (*pC)->info, MENOR(tamInfo, (*pC)->tamInfo));

    *pC = eliminar->sig;
    free(eliminar->info);
    free(eliminar);
    return TODOBIEN;
}

int colaVacia(tCola *pC){
    if(!(*pC)) return 0;
    return 1;
}

int destruirCola(tCola *pC){

    tNodo *eliminar = *pC;

    if(!(*pC)) return TODOBIEN;

    while(*pC){
        *pC = eliminar->sig;
        free(eliminar->info);
        free(eliminar);

        eliminar = *pC;
    }
    return TODOBIEN;
}
