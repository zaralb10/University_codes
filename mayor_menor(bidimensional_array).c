#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int captura_renglon();
int captura_columna();
void genera_valor_array_bi( int renglon, int columna, float array_bidimensional[100][100] );
void compara_añade( int renglon, int columna, float array_mayores[100], float array_menores[100], float array_bidimensional[100][100]);   
void imprime(int renglon, int columna, float array_mayores[100], float array_menores[100]);

int main()
{
    int renglon, columna;
    float array_mayores[100], array_menores[100], array_bidimensional[100][100];
    renglon = captura_renglon();
    columna = captura_columna();
    srand(time(NULL));

    genera_valor_array_bi( renglon, columna, array_bidimensional );
    compara_añade( renglon, columna, array_mayores, array_menores, array_bidimensional);
    imprime(renglon, columna, array_mayores, array_menores);
}

int captura_renglon()
{
    int renglon;
    printf("Dime la cantidad de renglones: ");
    scanf("%d",&renglon);
    return(renglon);
}

int captura_columna()
{
    int columna;
    printf("Dime la cantidad de columnas: ");
    scanf("%d",&columna);
    return(columna);
}

void genera_valor_array_bi( int renglon, int columna, float array_bidimensional[100][100] )
{
    for ( int renglon_i = 0; renglon_i < renglon; renglon_i++)
    {
        printf("\n");
        for( int columna_i = 0; columna_i < columna; columna_i++)
        {
            array_bidimensional[renglon_i][columna_i] = ( rand() % 101 ) / 10.0;
            printf("%.2f ",array_bidimensional[renglon_i][columna_i]);
        }
    }
    printf("\n");
}

void compara_añade( int renglon, int columna, float array_mayores[100], float array_menores[100], float array_bidimensional[100][100])
{
    float n_mayor, n_menor;
    int i = 0;
    for ( int renglon_i = 0; renglon_i < renglon; renglon_i++)
    {
        n_mayor = array_bidimensional[renglon_i][0]; 
        
        for (int columna_i = 1; columna_i < columna; columna_i++)
        {
            if ( array_bidimensional[renglon_i][columna_i] > n_mayor)
            {
                n_mayor = array_bidimensional[renglon_i][columna_i];
            }
        }
        array_mayores[i++] = n_mayor;
    }
    printf("\n");
    
    int j = 0;
    for ( int columna_i2 = 0; columna_i2 < columna; columna_i2++)
    {
        n_menor = array_bidimensional[0][columna_i2];
        
        for( int renglon_i2 = 1; renglon_i2 < renglon; renglon_i2++)
        {
            if (  array_bidimensional[renglon_i2][columna_i2] < n_menor)
            {
                n_menor = array_bidimensional[renglon_i2][columna_i2];
            }
        }
        array_menores[j++] = n_menor;
    }
}

void imprime(int renglon, int columna, float array_mayores[100], float array_menores[100])
{
    for ( int renglon_i = 0; renglon_i < renglon; renglon_i++)
    {
        printf("\nEn en renglon %d el numero mayor es: %.2f",renglon_i + 1,array_mayores[renglon_i]);
    }
    printf("\n");
    
    for ( int columna_i = 0; columna_i < columna; columna_i++)
    {
        printf("\nEn la columna %d el numero menor es: %.2f",columna_i + 1,array_menores[columna_i]);
    }
}
