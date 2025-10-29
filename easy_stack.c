#include <stdio.h>
#include <stdlib.h>   
#include <time.h>     
#define N 1000000

typedef struct
{
    int Pila[N];
    int tope;
    int tam;
} T_Pila;

void Inicializa_Pila(T_Pila *p, int longitud);
int  Pila_llena(T_Pila p);
int  Pila_Vacia(T_Pila p);
int  Push(T_Pila *p, int dato);
int  Pop(T_Pila *p, int *dato);
int  Top(T_Pila p, int *dato);

int main()
{
    int num_acciones;
    printf("dime cuantas acciones quieres hacer: ");
    scanf("%d",&num_acciones);
    
    T_Pila pila;
    Inicializa_Pila(&pila,num_acciones);
    
    int i, x,  tipo_accion, numero;
    
    for ( i = 0; i < num_acciones; i++)
    {
        printf("\n1 = insertar un numero \n2 = eliminar numero insertado \n3 = imprime\nOpcion: ");
        scanf("%d",&tipo_accion);
        
        if ( tipo_accion == 1)
        {
            printf("\nDime el numero a insertar: ");
            scanf("%d",&numero);
            Push(&pila, numero);
            
        }
        if ( tipo_accion == 2)
        {
            if (!Pop(&pila, &x))
            {
                printf("La pila esta vacia, no se puede hacer pop.\n"); 
            }
            else
            {
                printf("Se elimino %d\n", x);
            }
            
        }
        if ( tipo_accion == 3)
        {
            if (Top(pila, &x))
            {
                printf("%d\n", x);
            }
            else
            {
                printf("Empty!\n");
            }
        }
        
    }

    return 0;
}

void Inicializa_Pila(T_Pila *p, int longitud)
{
    if (longitud <= N)
    {
        p->tam = longitud;
    }
    else
    {
        p->tam = N;
    }
    p->tope = 0;
}

int Push(T_Pila *p, int dato) 
{
    int reg = 0;
    if (!Pila_llena(*p)) 
    {
        p->Pila[p->tope] = dato;
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

int Pop(T_Pila *p, int *dato)
{
    int reg = 0;
    if (!Pila_Vacia(*p))
    {
        p->tope--;
        *dato = p->Pila[p->tope];
        reg = 1;
    }
    return (reg);
}

int Top(T_Pila p, int *dato)
{
    if (Pila_Vacia(p))
    {
        return 0;
    }
    *dato = p.Pila[p.tope - 1];
    return (1);
}

