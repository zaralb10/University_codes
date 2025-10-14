#include <stdio.h>
#include <stdlib.h>   
#include <time.h>  
#include <math.h>
#define N 100

typedef struct
{
    float coef;
    int expo;
} T_termino;

typedef struct
{
    T_termino Pila[N];
    int tope;
    int tam;
} T_Pila;

int captura_grado_mayor();
void captura_ecuacion( T_Pila *pila, int grado);
float captura_X();
float evalua( T_Pila pila, float x);
void imprime( float y);

void inicializa(T_Pila *pila, int grado);
int push(T_Pila *pila, T_termino d);
int pila_llena(T_Pila pila);
int pila_vacia(T_Pila pila);
int pop(T_Pila *pila, T_termino *d);

int main()
{
    T_Pila pila;
    int grado;
    float x,y;
    
    grado = captura_grado_mayor();
    inicializa(&pila, grado + 1);
    captura_ecuacion(&pila,grado);
    x = captura_X();
    y = evalua(pila,x);
    imprime(y);
    return 0;
}

int captura_grado_mayor()
{
    int potencia_may;
    printf("Dime la potencia mas alta de la ecuacion: ");
    scanf("%d",&potencia_may);
    return(potencia_may);
}

void captura_ecuacion( T_Pila *pila, int grado)
{
    T_termino saver;
    for ( int i = grado; i >= 0; i--)
    {
        printf("Dime el coeficiente de x a la %d:", i);
        scanf("%f",&saver.coef);
        
        saver.expo = i;
        
        if (saver.coef != 0)
        {
            push(pila, saver);
        }
    }
}

float captura_X()
{
    float x;
    printf("Dime cuanto vale la x en la funcion: ");
    scanf("%f",&x);
    return(x);
}

float evalua( T_Pila pila, float x)
{
    float y = 0.0f;
    T_termino user;

    while(pop(&pila,&user))
    {
        y += user.coef * pow( x, user.expo);
    }
    return(y);
}
void imprime( float y)
{
    printf("%.2f",y);
}

void inicializa(T_Pila *pila, int grado)
{
    if ( grado <= N)
    {
        pila->tam = grado;
    }
    else
    {
        pila->tam = N;
    }
    pila->tope = 0;
}

int push(T_Pila *pila, T_termino d)
{
    int reg = 0;
    if (!pila_llena(*pila)) // ✅ se deja por valor (así la definiste)
    {
        pila->Pila[pila->tope] = d;
        pila->tope++;
        reg = 1;
    }
    return (reg);
}

int pila_llena(T_Pila pila)
{
    int reg = 1;
    if (pila.tope < pila.tam)
    {
        reg = 0;
    }
    return (reg);
}

int pila_vacia(T_Pila pila)
{
    int reg = 1;
    if (pila.tope > 0)
    {
        reg = 0;
    }
    return (reg);
}

int pop(T_Pila *pila, T_termino *d)
{
    int reg = 0;
    if (!pila_vacia(*pila)) // ✅ igual que arriba, por valor
    {
        pila->tope--;
        *d = pila->Pila[pila->tope];
        reg = 1;
    }
    return (reg);
}

