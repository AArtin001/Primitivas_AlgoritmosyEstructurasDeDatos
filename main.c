#include "pila.h"
#include "cola.h"
#include "lista.h"
#define OK 0
#define ERROR 1

int main(){
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
