#include <stdio.h>
#include <stdlib.h>   
#include <time.h>    
#define N 100
typedef int Tipo_dato;

typedef struct
{
    Tipo_dato Pila[N];
    int tope;
    int tam;
} T_Pila;

void Genera_Pila(T_Pila *p);
void Inicializa_Pila(T_Pila *p, int tam);
int  Pila_llena(T_Pila p);
int  Pila_Vacia(T_Pila p);
int  Push(T_Pila *p, Tipo_dato d);
int  Pop(T_Pila *p, Tipo_dato *d);

int main()
{
    T_Pila pila;
    Tipo_dato valor;
    
    Inicializa_Pila(&pila, 8); 
    srand(time(NULL));
    Genera_Pila(&pila); 
    
    printf("=== PILA (estructura del profesor) ===\n");

    printf("\nMostrando el último número ingresado:\n");
    if (!Pila_Vacia(pila))
    {
        Pop(&pila, &valor);
        printf("El último número ingresado fue: %d\n", valor);
    }

    return 0;
}

void Genera_Pila(T_Pila *p)
{
    printf("Generando valores aleatorios en la pila:\n");
    for (int i = 0; i < p->tam; i++)
    {
        int num = rand() % 100;
        Push(p, num);
        printf("Se apiló: %d\n", num);
    }
}
void Inicializa_Pila(T_Pila *p, int tam)
{
    if (tam <= N)
    {
        p->tam = tam;
    }
    else
    {
        p->tam = N;
    }
    p->tope = 0;
}

int Push(T_Pila *p, Tipo_dato d)
{
    int reg = 0;
    if (!Pila_llena(*p)) 
    {
        p->Pila[p->tope] = d;
        p->tope++;
        reg = 1;
    }
    return (reg);
}

int Pila_llena(T_Pila p)
{
    int reg = 1;
    if (p.tope < p.tam)
    {
        reg = 0;
    }
    return (reg);
}

int Pila_Vacia(T_Pila p)
{
    int reg = 1;
    if (p.tope > 0)
    {
        reg = 0;
    }
    return (reg);
}

int Pop(T_Pila *p, Tipo_dato *d)
{
    int reg = 0;
    if (!Pila_Vacia(*p)) 
    {
        p->tope--;
        *d = p->Pila[p->tope];
        reg = 1;
    }
    return (reg);
}
