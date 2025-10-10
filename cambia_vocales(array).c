#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 1000

int captura();
void recibe ( char letras [ N ], int tamaño );
void imprime_arreglo_recibe ( char letras [ N ], int tamaño);
void detectar_vocales ( char letras [ N ], int tamaño);


int main()
{
char letras[N];
int tamaño;
srand ( time ( 0 ));// cambiar el numero base del randomizer a tiempo real de la PC 
tamaño = captura();
recibe ( letras, tamaño);
imprime_arreglo_recibe ( letras, tamaño);
detectar_vocales ( letras, tamaño);
}

int captura()
{
    int cantidad;
    printf("Dime de cuantos caracteres va a ser el arreglo de caracteres: ");
    scanf("%d",&cantidad);
    return( cantidad );
}

void recibe ( char letras [ N ], int tamaño )
{
    for ( int i = 0; i < tamaño; i++ )
    {
        letras [ i ] = ( 'z' - 'a')  - (rand() % 25) + 'a'; 
    }
}   
    
void imprime_arreglo_recibe ( char letras [ N ], int tamaño)
{
    for ( int i2 = 0; i2 < tamaño; i2++ )
    {
    printf("La letra num %d es %c\n", i2 +1, letras[i2]);

    }
}

void detectar_vocales ( char letras [ N ], int tamaño)
{
    int ivocales = 0;
    for ( int i3 = 0; i3 < tamaño; i3++ )
    {
    if ( letras[i3] == 'a' || letras[i3] == 'e' || letras[i3] == 'i' || letras[i3] == 'o' || letras[i3] == 'u'  )
    {
    letras[i3] = '*';
    ivocales++;
    }
    printf("%c\n", letras [i3]);
    }
    printf("La cantidad de vocales que hay son de: %d",ivocales);
}
