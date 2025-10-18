#include <stdio.h>
#include <stdlib.h>   
#include <time.h>  
#include <math.h>
#define N 100

typedef struct
{
    int Pila[N];
    int tope;
    int tam;
} T_Pila;

void generar_datos_pila(T_Pila *numeros);
void divide_pila(T_Pila *numeros, T_Pila *pares, T_Pila *impares);
void imprime_pila(T_Pila numeros);
void inicializa(T_Pila *numeros, int longitud);
int push(T_Pila *numeros, int dato);
int pop(T_Pila *numeros, int *dato);
int pila_llena(T_Pila numeros);
int pila_vacia(T_Pila numeros);

int main()
{
    T_Pila numeros, pares, impares;
    srand((unsigned)time(NULL));
    
    inicializa(&numeros, 10);
    inicializa(&pares, 10);
    inicializa(&impares, 10);
    
    generar_datos_pila(&numeros);
    imprime_pila(numeros);
    
    divide_pila(&numeros, &pares, &impares);
    
    printf("\nPares:\n");
    imprime_pila(pares);
    printf("\nImpares:\n");
    imprime_pila(impares);
    
    return 0;
}

void generar_datos_pila(T_Pila *numeros)
{
    int num;
    while (!pila_llena(*numeros))
    {
        num = rand() % 101;
        push(numeros, num);
    }
}

void divide_pila(T_Pila *numeros, T_Pila *pares, T_Pila *impares)
{ 
    int x;
    while (!pila_vacia(*numeros))
    {
        pop(numeros, &x);
        if (x % 2 == 0)
        {
            push(pares, x);
        }
        else
        {
            push(impares, x);
        }
    }
}

void imprime_pila(T_Pila pila)
{
    int i;
    for (i = pila.tope - 1; i >= 0; i--)
    {
        printf("%d ", pila.Pila[i]);
    }
    printf("\n");
}

void inicializa(T_Pila *numeros, int longitud)
{
    if (longitud <= N)
    {
        numeros->tam = longitud;
    }
    else
    {
        numeros->tam = N;
    }
    numeros->tope = 0;
}

int pila_vacia(T_Pila numeros)
{
    return (numeros.tope == 0);
}

int pila_llena(T_Pila numeros)
{
    return (numeros.tope >= numeros.tam);
}

int push(T_Pila *numeros, int dato)
{
    int reg = 0;
    if (!pila_llena(*numeros))
    {
        numeros->Pila[numeros->tope] = dato;
        numeros->tope++;
        reg = 1;
    }
    return reg;
}

int pop(T_Pila *numeros, int *dato)
{
    int reg = 0;
    if (!pila_vacia(*numeros))
    {
        numeros->tope--;
        *dato = numeros->Pila[numeros->tope];
        reg = 1;
    }
    return reg;
}
