#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10


void genera_valor_arreglo_A ( int datos_A[N]);
void imprime_A ( int datos_A[N]);

void genera_valor_arreglo_B ( int datos_B[N]);
void imprime_B( int datos_B[N]);

void calcula_arreglos ( int datos_A[N], int datos_B[N], int datos_C[N]);
void imprime_calcula ( int datos_C[N] );

int main()
{
    srand(time(NULL));
    int datos_A[N], datos_B[N], datos_C[N];
    
    
    genera_valor_arreglo_A( datos_A );
    imprime_A( datos_A );
    
    genera_valor_arreglo_B( datos_B );
    imprime_B( datos_B);
    
    calcula_arreglos( datos_A, datos_B, datos_C);
    imprime_calcula( datos_C);

}

void genera_valor_arreglo_A ( int datos_A[N])
{
    
    for ( int i = 0; i < N; i++)
    {
        datos_A[i] = rand () % 101;
    }
}

void imprime_A ( int datos_A[N])
{
    printf("EXISTENCIA DE PRODUCTOS\n");
    for ( int i = 0; i < N; i++)
    {
        printf("%d) %d\n",i + 1, datos_A[i]);
    }
}

void genera_valor_arreglo_B ( int datos_B[N])
{
    for ( int i = 0; i < N; i++)
    {
        datos_B[i] = rand () % 101;
    }
}

void imprime_B( int datos_B[N])
{
    printf("\nCANTIDAD DE PRODUCTOS\n");
    for ( int i = 0; i < N; i++)
    {
        printf("%d) %d\n",i + 1, datos_B[i]);
    }
}

void calcula_arreglos ( int datos_A[N], int datos_B[N], int datos_C[N])
{
    
    for ( int i  = 0; i < N; i++)
    {
        if ( datos_A[i] == datos_B[i])
        {
            datos_C[i] = datos_A[i];
        }
        if ( datos_B[i] > datos_A[i])
        {
            datos_C[i] = 2 * ( datos_B[i] - datos_A[i]);
        }
        if ( datos_A[i] > datos_B[i])
        {
            datos_C[i] = datos_B[i];
        }
    }
}

void imprime_calcula ( int datos_C[N])
{
    printf("\nProductos requeridos para mantener el stock\n");
    for ( int i = 0; i < N; i++)
    {
        printf("%d) %d\n",i + 1, datos_C[i]);
    }
}
