#ifndef UNIVERSALES_H_INCLUDED
#define UNIVERSALES_H_INCLUDED


///Declaracion de estructuras
//Se hace la declaracion de tNodo en este lugar para que no haya conflictos al importar todos los headers en el main
typedef struct sNodo{
    void *info;
    unsigned tamInfo;
    struct sNodo *sig;
}tNodo;


#endif // UNIVERSALES_H_INCLUDED
