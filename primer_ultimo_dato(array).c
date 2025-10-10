#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#define N 5

void genera_datos ( int datos [ N ]);
void imprime_arreglo ( int datos [ N ]);
void intercambia ( int datos [ N ]);

int main()
{
    int datos[ N ];
    srand ( time ( 0 )); // cambiar el numero base del randomizer a tiempo real de la PC 
    genera_datos( datos );
    imprime_arreglo ( datos );
    intercambia( datos );
    imprime_arreglo ( datos );
}

void genera_datos ( int datos [ N ])
{

    for ( int i = 0; i < N; i++)
    {
        datos [ i ] = rand ( ) % 51;
    }
}

void imprime_arreglo ( int datos [  ])
{
    for ( int i2 = 0; i2 < N; i2++)
    {
        printf("%d ",datos [ i2 ]);
    }
    printf("\n");
}

void intercambia ( int datos [  ])
{
    int temp = datos [ 0 ];
    datos[ 0 ] = datos [ N - 1 ];
    datos[ N -1 ] = temp;
}
