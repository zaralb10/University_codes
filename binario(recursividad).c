#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int captura_tam();
void genera_valor_array( int tamaño, int array[]);
int funcion_recursiva( int tamaño, int array[], int inicio);
void imprime( int valor);

int main()
{
    int tamaño,array[101], valor, inicio = 0 ;
    srand(time(NULL));
    
    tamaño = captura_tam();
    genera_valor_array( tamaño, array);

    valor = funcion_recursiva(tamaño,array, inicio);
    imprime( valor);
    return 0;
}

int captura_tam()
{
    int tamaño;
    printf("Dime la cantidad de bits: ");
    scanf("%d",&tamaño);
    return(tamaño);
}

void genera_valor_array( int tamaño, int array[])
{
    for( int i = tamaño - 1; i >= 0; i--)
    {
        array[i] = rand() % 2;
        printf("%d ",array[i]);
    }
}

int funcion_recursiva( int tamaño, int array[], int  inicio)
{
    if ( inicio == tamaño) 
    {
        return(0);
    }
    return(  2 * funcion_recursiva( tamaño , array , inicio + 1 ) + array[inicio]);
}

void imprime( int valor)
{
    printf("\nDe binario a decimal es de: %d ",valor);
}
