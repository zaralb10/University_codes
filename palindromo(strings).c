#include <stdio.h>
#include <stdint.h>
#include <string.h>

void captura ( char texto [] );
int es_palindromo( char texto[], char arreglo_sines[] );
void imprime ( int resultado );

int main()
{
    char texto[100];
    char arreglo_sines[100];
    int resultado;
    
    captura(texto);
    resultado = es_palindromo(texto, arreglo_sines);
    imprime( resultado );
}

void captura ( char texto[] )
{
    printf("Ingresa el texto: ");
    scanf("%[^\n]", texto);
}


int es_palindromo( char texto[], char arreglo_sines[] )
{
    int n = strlen ( texto );
    for ( int i = 0, j = 0; i < n; i++)
    {
        if ( texto[i] != ' ')
        {
            arreglo_sines[j] = texto[i];
            j++;
        }
    }
    int m = strlen( arreglo_sines);
    for( int i2 = 0, j2 = ( m - 1);  i2 < j2; i2++, j2-- )
    {
        if ( arreglo_sines[i2] != arreglo_sines[j2])
        {
            return (0);
        }
    }
    return(1);
}

void imprime ( int resultado )
{
    if ( resultado == 0)
    {
        printf("\nEl texto no es un palindromo");
    }
    if ( resultado == 1)
    {
        printf("\nEl texto es un palidromo");
    }
}
