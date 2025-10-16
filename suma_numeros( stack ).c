#include <stdio.h>
#include <stdint.h>
#include <string.h>
#define N 100000

typedef struct
{
    int Pila[N];
    int tope;
    int tam;
} T_Pila;

int captura_acciones();
void capturar_informacion(int acciones, T_Pila *pila);

void inicializa(T_Pila *pila, int acciones);
int push(T_Pila *pila, int acciones);
int pila_llena(T_Pila pila);
int pila_vacia(T_Pila pila);
int pop(T_Pila *pila, int *acciones);

int main()
{
   T_Pila pila;
   char letra[11];
   int acciones;
   
   acciones = captura_acciones();
   inicializa(&pila,acciones);
   capturar_informacion(acciones,&pila);
   
   
   push(&pila,acciones);
   pila_llena(pila);
   pila_llena(pila);
   pop(&pila,&acciones);
   return(0);
}

int captura_acciones()
{
    int acciones;
    printf("Dime cuantas acciones quieres realizar: ");
    scanf("%d",&acciones);
    return(acciones);
}

void capturar_informacion(int acciones, T_Pila *pila)
{
    int numero;
    char palabra[11];
    for ( int i = 0; i < acciones; i++)
    {
        printf("\nDime la accion a realizar.\nagrega\nconsume\nimprime\n");
        scanf("%10s",palabra);
        
        if ((strcmp(palabra,"agrega")) == 0 || (strcmp(palabra,"AGREGA")) == 0 || (strcmp(palabra,"Agrega")) == 0) 
        {
            printf("Dime un numero: ");
            scanf("%d",&numero);
            push(pila,numero);
        }
        
        if ((strcmp(palabra,"consume")) == 0 || (strcmp(palabra,"CONSUME")) == 0 || (strcmp(palabra,"Consume")) == 0) 
        {
            int x,y,r;
            pop(pila,&x);
            pop(pila,&y);
            r = x + y;
            push(pila,r);
        }
        
        if ((strcmp(palabra,"imprime")) == 0 || (strcmp(palabra,"IMPRIME")) == 0 || (strcmp(palabra,"Imprime")) == 0) 
        {
            int impreso;
            pop(pila,&impreso);
            printf("%d\n", impreso);
            push(pila,impreso);
        }
         
    }
}

void inicializa(T_Pila *pila, int acciones)
{
    if ( acciones <= N)
    {
        pila->tam = acciones;
    }
    else
    {
        pila->tam = N;
    }
    pila->tope = 0;
}

int push(T_Pila *pila, int acciones)
{
    int reg = 0;
    if (!pila_llena(*pila)) // ✅ se deja por valor (así la definiste)
    {
        pila->Pila[pila->tope] = acciones;
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

int pop(T_Pila *pila, int *acciones)
{
    int reg = 0;
    if (!pila_vacia(*pila)) 
    {
        pila->tope--;
        *acciones = pila->Pila[pila->tope];
        reg = 1;
    }
    return (reg);
}

