#include <stdio.h>
#include <stdint.h>

void captura_numeros( int *numero_1, int *numero_2);
void genera( int *numero_1, int *numero_2, int arreglo_bi[20][20]);
void imprime( int *numero_1, int *numero_2, int arreglo_bi[20][20]);

int main() 
{
  int numero_1;
  int numero_2;
  int arreglo_bi [20][20];
  
  captura_numeros( &numero_1, &numero_2);
  genera( &numero_1, &numero_2, arreglo_bi);
  imprime( &numero_1, &numero_2, arreglo_bi);
  
}

void captura_numeros( int *numero_1, int *numero_2)
{
    printf("DIme cuantos renglones quieres: ");
    scanf("%d",numero_1);
    
    printf("DIme cuantas columnas quieres: ");
    scanf("%d",numero_2);
}

void genera( int *numero_1, int *numero_2, int arreglo_bi[20][20])
{
    int renglones= *numero_1;
    int columnas = *numero_2;
    int contador = 1;
    
    for (int i = 0; i < renglones; i++)
    {
        if (i % 2 == 0) 
        { 
            for (int j = 0; j < columnas; j++) 
            {
                arreglo_bi[i][j] = contador++;
            }
        } 
        else 
        {          
            for (int j = columnas - 1; j >= 0; j--) 
            {
                arreglo_bi[i][j] = contador++;
            }
        }
    }
}

void imprime( int *numero_1, int *numero_2, int arreglo_bi[20][20])
{
    int renglones = *numero_1;
    int columnas  = *numero_2;

    for (int i = 0; i < renglones; i++) 
    {
        for (int j = 0; j < columnas; j++) 
        {
            if (j) printf(" ");
            printf("%d", arreglo_bi[i][j]);
        }
        printf("\n");
    }
}
