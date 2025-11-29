#include "pila.h"
#include "cola.h"
#include "lista.h"
#define OK 0
#define ERROR 1

/*************************CASOS DE PRUEBA LISTA DINAMICA*************************/
#define ASSERT(msg, cond) \
    printf("%s: %s\n", msg, (cond) ? "OK" : "FAIL");

// Comparación de enteros
int cmpEnteros(void *a, void *b)
{
    int x = *(int*)a;
    int y = *(int*)b;

    if(x < y) return -1;
    if(x > y) return 1;
    return 0;
}

// Acción si la clave ya existe (sumo valores por ejemplo)
int accionSumar(void *dest, void *src)
{
    *(int*)dest += *(int*)src;
    return OK;
}

int printInt(void* a, void* b){
    printf("%d\n", *(int*)a);
    return OK;
}

int main()
{
    tLista lista;
    int r, x, aux;

    printf("==== CASOS DE PRUEBA LISTA DINÁMICA ====\n\n");

    // ---------------------------------------------------------
    // 1) Crear lista (debe quedar vacía)
    // ---------------------------------------------------------
    crearLista(&lista);
    ASSERT("1. Lista recién creada debe estar vacía", listaVacia(&lista) == 0);


    // ---------------------------------------------------------
    // 2) Insertar primero en lista vacía
    // ---------------------------------------------------------
    x = 50;
    r = InsertarPrimeroEnLista(&lista, &x, sizeof(int));
    ASSERT("2. InsertarPrimero en lista vacía", r == OK);
    ASSERT("3. Lista NO vacía luego de insertar", listaVacia(&lista) == 1);

    aux = 0;
    verPrimeroLista(&lista, &aux, sizeof(int));
    ASSERT("4. Primer elemento es 50", aux == 50);


    // ---------------------------------------------------------
    // 3) Insertar último
    // ---------------------------------------------------------
    x = 80;
    r = InsertarUltimoEnLista(&lista, &x, sizeof(int));
    ASSERT("5. InsertarUltimo", r == OK);

    aux = 0;
    verUltimoLista(&lista, &aux, sizeof(int));
    ASSERT("6. Último elemento es 80", aux == 80);


    // ---------------------------------------------------------
    // 4) Insertar ordenado
    // ---------------------------------------------------------
    x = 60;
    r = InsertarOrdenadoEnLista(&lista, &x, sizeof(int), cmpEnteros, accionSumar);
    ASSERT("7. InsertarOrdenado (60)", r == OK);

    // Lista debería ser: 50 → 60 → 80
    aux = 50;
    verPorClaveLista(&lista, &aux, sizeof(int), &aux, cmpEnteros);
    ASSERT("8. verPorClaveLista encuentra 50", aux == 50);

    aux = 60;
    r = verPorClaveLista(&lista, &aux, sizeof(int), &aux, cmpEnteros);
    ASSERT("9. verPorClaveLista encuentra 60", r == OK);

    aux = 80;
    r = verPorClaveLista(&lista, &aux, sizeof(int), &aux, cmpEnteros);
    ASSERT("10. verPorClaveLista encuentra 80", r == OK);

    printf("\nRecorro lista imprimiendo los valores:\n");
    recorrerLista(&lista, NULL, cmpEnteros, printInt);

    // ---------------------------------------------------------
    // 5) Insertar repetido para probar 'accion'
    // ---------------------------------------------------------
    x = 60;   // la clave ya existe
    r = InsertarOrdenadoEnLista(&lista, &x, sizeof(int), cmpEnteros, accionSumar);
    ASSERT("11. Insertar repetido (accionSumar)", r == OK);

    aux = 120;
    verPorClaveLista(&lista, &aux, sizeof(int), &aux, cmpEnteros);
    ASSERT("12. El valor de 60 ahora es 120", aux == 120);

    printf("\nRecorro lista imprimiendo los valores:\n");
    recorrerLista(&lista, NULL, cmpEnteros, printInt);
    // ---------------------------------------------------------
    // 6) Ver primero y último
    // ---------------------------------------------------------
    aux = 0;
    verPrimeroLista(&lista, &aux, sizeof(int));
    ASSERT("13. Primero sigue siendo 50", aux == 50);

    aux = 0;
    verUltimoLista(&lista, &aux, sizeof(int));
    ASSERT("14. Último sigue siendo 80", aux == 80);


    // ---------------------------------------------------------
    // 7) Sacar por clave
    // ---------------------------------------------------------
    x = 120;   // valor actual luego de sumar
    r = sacarDeLista(&lista, &x, sizeof(int), cmpEnteros);
    ASSERT("15. sacarDeLista(120)", r == OK);

    // Ahora lista: 50 → 80
    aux = 0;
    verPrimeroLista(&lista, &aux, sizeof(int));
    ASSERT("16. Primero sigue siendo 50", aux == 50);


    // ---------------------------------------------------------
    // 8) Sacar el primero
    // ---------------------------------------------------------
    x = 50;
    r = sacarDeLista(&lista, &x, sizeof(int), cmpEnteros);
    ASSERT("17. sacarDeLista(50)", r == OK);

    // Lista: 80
    aux = 0;
    verPrimeroLista(&lista, &aux, sizeof(int));
    ASSERT("18. Primer elemento ahora es 80", aux == 80);


    // ---------------------------------------------------------
    // 9) Sacar el último restante → queda vacía
    // ---------------------------------------------------------
    x = 80;
    r = sacarDeLista(&lista, &x, sizeof(int), cmpEnteros);
    ASSERT("19. sacarDeLista(80)", r == OK);
    ASSERT("20. Lista vacía", listaVacia(&lista) == 0);


    // ---------------------------------------------------------
    // 10) destruirLista con lista vacía (no debe fallar)
    // ---------------------------------------------------------
    destruirLista(&lista);
    ASSERT("21. destruir Lista en lista vacía no rompe nada", listaVacia(&lista) == 0);


    printf("\n==== FIN DE PRUEBAS ====\n");
    return 0;
}

/*************************CASOS DE PRUEBA COLA DINAMICA*************************/
/*
#define ASSERT(msg, cond) \
    printf("%s: %s\n", msg, (cond) ? "OK" : "FAIL");

int main()
{
    tCola cola;
    int r, x;
    int aux;

    printf("==== CASOS DE PRUEBA COLA DINAMICA ====\n\n");

    // ---------------------------------------------------------
    // 1) Crear cola → debe quedar vacía
    // ---------------------------------------------------------
    crearCola(&cola);
    ASSERT("1. Cola recién creada debe estar vacia", colaVacia(&cola) == 0);


    // ---------------------------------------------------------
    // 2) Insertar un entero
    // ---------------------------------------------------------
    x = 42;
    r = InsertarEnCola(&cola, &x, sizeof(int));
    ASSERT("2. Insertar primer elemento", r == OK);
    ASSERT("3. Cola NO debe estar vacia", colaVacia(&cola) == 1);


    // ---------------------------------------------------------
    // 3) Ver frente de la cola
    // ---------------------------------------------------------
    aux = 0;
    r = verTopeCola(&cola, &aux, sizeof(int));
    ASSERT("4. verTopeCola devuelve OK", r == OK);
    ASSERT("5. verTopeCola devuelve valor correcto (42)", aux == 42);


    // ---------------------------------------------------------
    // 4) Insertar otro valor
    // ---------------------------------------------------------
    x = 77;
    r = InsertarEnCola(&cola, &x, sizeof(int));
    ASSERT("6. Insertar segundo elemento", r == OK);

    aux = 0;
    verTopeCola(&cola, &aux, sizeof(int));
    ASSERT("7. Frente de la cola sigue siendo 42", aux == 42);


    // ---------------------------------------------------------
    // 5) Sacar un elemento (FIFO)
    // ---------------------------------------------------------
    aux = 0;
    r = sacarDeCola(&cola, &aux, sizeof(int));
    ASSERT("8. sacarDeCola devuelve OK", r == OK);
    ASSERT("9. Valor extraído debe ser 42", aux == 42);

    aux = 0;
    verTopeCola(&cola, &aux, sizeof(int));
    ASSERT("10. Frente de la cola ahora debe ser 77", aux == 77);


    // ---------------------------------------------------------
    // 6) Sacar último elemento → cola queda vacía
    // ---------------------------------------------------------
    aux = 0;
    r = sacarDeCola(&cola, &aux, sizeof(int));
    ASSERT("11. Sacar último elemento", r == OK);
    ASSERT("12. Valor debe ser 77", aux == 77);
    ASSERT("13. Cola debe estar vacía", colaVacia(&cola) == 0);


    // ---------------------------------------------------------
    // 7) Intentar verTopeCola con cola vacía
    // ---------------------------------------------------------
    aux = -1;
    r = verTopeCola(&cola, &aux, sizeof(int));
    ASSERT("14. verTopeCola con cola vacía debe fallar", r == ERROR);


    // ---------------------------------------------------------
    // 8) Insertar y destruir cola
    // ---------------------------------------------------------
    x = 123;
    InsertarEnCola(&cola, &x, sizeof(int));
    destruirCola(&cola);

    ASSERT("15. destruirCola deja la cola vacía", colaVacia(&cola) == 0);


    // ---------------------------------------------------------
    // 9) destruirCola sobre cola ya vacía
    // ---------------------------------------------------------
    destruirCola(&cola);
    ASSERT("16. destruirCola sobre cola vacía no rompe nada", colaVacia(&cola) == 0);


    printf("\n==== FIN DE PRUEBAS ====\n");
    return 0;
}
*/

/*************************CASOS DE PRUEBA PILA DINAMICA*************************/
/*#define ASSERT(msg, cond) \
printf("%s: %s\n", msg, (cond) ? "OK" : "FAIL");

int main()
{
    tPila pila;
    int r, x;
    int aux;

    printf("==== CASOS DE PRUEBA PILA DINAMICA ====\n\n");

    // ---------------------------------------------------------
    // 1) Crear pila → debe quedar vacía
    // ---------------------------------------------------------
    crearPila(&pila);
    ASSERT("1. Pila recien creada debe estar vacia", pilaVacia(&pila) == 0);


    // ---------------------------------------------------------
    // 2) Insertar un entero
    // ---------------------------------------------------------
    x = 42;
    r = InsertarEnPila(&pila, &x, sizeof(int));
    ASSERT("2. Insertar primer elemento", r == OK);
    ASSERT("3. Pila NO debe estar vacia", pilaVacia(&pila) == 1);


    // ---------------------------------------------------------
    // 3) Ver tope
    // ---------------------------------------------------------
    aux = 0;
    r = verTopePila(&pila, &aux, sizeof(int));
    ASSERT("4. verTopePila devuelve OK", r == OK);
    ASSERT("5. verTopePila devuelve el valor correcto (42)", aux == 42);


    // ---------------------------------------------------------
    // 4) Insertar otro valor
    // ---------------------------------------------------------
    x = 77;
    r = InsertarEnPila(&pila, &x, sizeof(int));
    ASSERT("6. Insertar segundo elemento", r == OK);

    aux = 0;
    verTopePila(&pila, &aux, sizeof(int));
    ASSERT("7. Tope ahora debe ser 77", aux == 77);


    // ---------------------------------------------------------
    // 5) Sacar un elemento
    // ---------------------------------------------------------
    aux = 0;
    r = sacarDePila(&pila, &aux, sizeof(int));
    ASSERT("8. sacarDePila devuelve OK", r == OK);
    ASSERT("9. Valor extraído debe ser 77", aux == 77);


    // ---------------------------------------------------------
    // 6) Tope después de un pop
    // ---------------------------------------------------------
    aux = 0;
    verTopePila(&pila, &aux, sizeof(int));
    ASSERT("10. Tope ahora debe ser 42", aux == 42);


    // ---------------------------------------------------------
    // 7) Sacar último elemento → pila queda vacía
    // ---------------------------------------------------------
    aux = 0;
    r = sacarDePila(&pila, &aux, sizeof(int));
    ASSERT("11. Sacar ultimo elemento", r == OK);
    ASSERT("12. Valor debe ser 42", aux == 42);
    ASSERT("13. Pila debe estar vacia", pilaVacia(&pila) == 0);


    // ---------------------------------------------------------
    // 8) Intentar verTopePila con pila vacía
    // ---------------------------------------------------------
    aux = -1;
    r = verTopePila(&pila, &aux, sizeof(int));
    ASSERT("14. verTopePila con pila vacia debe fallar", r == ERROR);


    // ---------------------------------------------------------
    // 9) Insertar y destruir pila
    // ---------------------------------------------------------
    x = 123;
    InsertarEnPila(&pila, &x, sizeof(int));
    destruirPila(&pila);

    ASSERT("15. destruirPila deja la pila vacia", pilaVacia(&pila) == 0);


    // ---------------------------------------------------------
    // 10) destruirPila sobre pila ya vacía (debe estar OK)
    // ---------------------------------------------------------
    destruirPila(&pila);
    ASSERT("16. destruirPila sobre pila vacia no rompe nada", pilaVacia(&pila) == 0);


    printf("\n==== FIN DE PRUEBAS ====\n");
    return 0;
}
*/
