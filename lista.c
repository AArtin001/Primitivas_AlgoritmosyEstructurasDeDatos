#include "lista.h"

#define ERROR 1
#define TODOBIEN 0
#define MENOR(x,y) (x<y)? x:y

int crearLista(tLista *pL){
    *pL = NULL;
    return TODOBIEN;
}

int InsertarPrimeroEnLista(tLista *pL, void *info, unsigned tamInfo){
    tNodo *nuevo = (tNodo*)malloc(sizeof(tNodo));
    if(!nuevo){
        printf("\nNo hay memeria para el nodo");
        return ERROR;
    }
    nuevo->info = malloc(tamInfo);
    if(!nuevo->info){
        printf("No hay memoria para la info");
        free(nuevo);
        return ERROR;
    }

    nuevo->tamInfo = tamInfo;
    memcpy(nuevo->info, info, tamInfo);
    nuevo->sig = *pL;
    *pL = nuevo;

    return TODOBIEN;
}

int InsertarUltimoEnLista(tLista *pL, void *info, unsigned tamInfo){
    tNodo *nuevo = (tNodo*)malloc(sizeof(tNodo));
    if(!nuevo){
        printf("\nNo hay memeria para el nodo");
        return ERROR;
    }
    nuevo->info = malloc(tamInfo);
    if(!nuevo->info){
        printf("No hay memoria para la info");
        free(nuevo);
        return ERROR;
    }

    nuevo->tamInfo = tamInfo;
    memcpy(nuevo->info, info, tamInfo);
    nuevo->sig = NULL;

    while(*pL){
        pL = &((*pL)->sig);
    }
    *pL = nuevo;

    return TODOBIEN;
}

int InsertarOrdenadoEnLista(tLista *pL, void *info, unsigned tamInfo, int (*cmp)(void*, void*), int(*accion)(void*, void*)){
    int aux;

    while((*pL) && (aux = cmp((*pL)->info, info)) < 0){ //Si la lista no esta vacia entonces busco la posicion donde insertar
        pL = &((*pL)->sig);
    }

    if(aux == 0){ //Actualizo
        accion((*pL)->info, info);
        return TODOBIEN;
    }

    //Si aux == 1 inserto -> reservo la memoria
    tNodo *nuevo = (tNodo*)malloc(sizeof(tNodo));
    if(!nuevo){
        printf("\nNo hay memeria para el nodo");
        return ERROR;
    }
    nuevo->info = malloc(tamInfo);
    if(!nuevo->info){
        printf("No hay memoria para la info");
        free(nuevo);
        return ERROR;
    }

    nuevo->sig = *pL;
    nuevo->tamInfo = tamInfo;
    memcpy(nuevo->info, info, tamInfo);
    *pL = nuevo;

    return TODOBIEN;
}

int listaLlena(unsigned tamInfo){
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

int verPrimeroLista(tLista *pL, void *info, unsigned tamInfo){
    if(!(*pL)){
        printf("\nLista Vacia");
        return ERROR;
    }

    memcpy(info,(*pL)->info, MENOR(tamInfo, (*pL)->tamInfo));
    return TODOBIEN;
}

int verUltimoLista(tLista *pL, void *info, unsigned tamInfo){
    if(!(*pL)){
        printf("\nLista Vacia");
        return ERROR;
    }

    while((*pL)->sig){
        pL = &((*pL)->sig);
    }

    memcpy(info,(*pL)->info, MENOR(tamInfo, (*pL)->tamInfo));
    return TODOBIEN;
}

int verPorClaveLista(tLista *pL, void *info, unsigned tamInfo, void* clave, int (*cmp)(void*, void*)){
    int aux;
    if(!(*pL)){
        printf("\nLista Vacia");
        return ERROR;
    }

    while(*pL && (aux = cmp((*pL)->info, clave)) != 0){
        pL = &((*pL)->sig);
    }
    if(aux == 0){
        memcpy(info,(*pL)->info, MENOR(tamInfo, (*pL)->tamInfo));
        return TODOBIEN;
    }

    return ERROR;
}

int recorrerLista(tLista *pL, void* param, int (*cmp)(void*, void*), int(*accion)(void*, void*)){

    while(*pL){
        accion((*pL)->info, param);
        pL = &((*pL)->sig);
    }

    return TODOBIEN;
}


int sacarDeLista(tLista *pL, void *info, unsigned tamInfo, int (*cmp)(void*, void*)){
    tNodo *eliminar;

    if(!(*pL)){
        printf("\nPila Vacia");
        return ERROR;
    }


    while(*pL && cmp((*pL)->info, info)){
        pL = &((*pL)->sig);
    }

    memcpy(info,(*pL)->info, MENOR(tamInfo, (*pL)->tamInfo));
    eliminar = *pL;
    (*pL) = eliminar->sig;
    free(eliminar->info);
    free(eliminar);
    return TODOBIEN;
}

int listaVacia(tLista *pL){
    if(!(*pL)) return 0;
    return 1;
}

int destruirLista(tLista *pL){
    tNodo *eliminar;

    while(*pL){
        eliminar = *pL;
        pL = &(eliminar->sig);
        free(eliminar->info);
        free(eliminar);
    }

    return TODOBIEN;
}
