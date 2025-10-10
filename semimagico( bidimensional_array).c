#include <stdio.h>
#include <stdint.h>

int captura_tamaño();
int captura_valores( int tamaño, int arreglo_bi[100][100]);
int comprobar_semimagico( int tamaño, int arreglo_bi[100][100]);
void imprime( int tamaño, int arreglo_bi[100][100], int semimagico);

int main()
{
int tamaño,arreglo_bi[100][100], semimagico;

tamaño = captura_tamaño();
captura_valores( tamaño, arreglo_bi);
semimagico = comprobar_semimagico( tamaño, arreglo_bi);
imprime( tamaño, arreglo_bi, semimagico);

}

int captura_tamaño()
{
    int tamaño;
    printf("Dime el tamaño de la matriz: ");
    scanf("%d",&tamaño);
    return(tamaño);
}

int captura_valores( int tamaño, int arreglo_bi[100][100])
{
    for(int ren = 0; ren < tamaño; ren++)
    {
        for ( int col = 0; col < tamaño; col++)
        {
        printf("Ingresa un numero: ");
        scanf("%d",&arreglo_bi[ren][col]);
        }
    
    }
}

int comprobar_semimagico( int tamaño, int arreglo_bi[100][100])
{
    int suma = 0;
    for ( int col = 0; col < tamaño; col++)
    {
        suma += arreglo_bi[0][col];
    }
    
    // verifica todas los renglones
    for ( int ren = 0; ren < tamaño; ren++)
    {
        int suma_fila = 0;
        for( int col = 0; col < tamaño; col++)
        {
            suma_fila += arreglo_bi[ren][col];
        }
        if ( suma_fila != suma)
        {
            return (0);
        }
    }
    
    // verifica todas las columnas
    for ( int col = 0; col < tamaño; col++)
    {
        int suma_col = 0;
        for( int ren = 0; ren < tamaño; ren++)
        {
            suma_col += arreglo_bi[ren][col];
        }
        if ( suma_col != suma)
        {
            return(0);
        }
    }
    
    // verifica la diagonal principal
    int suma_diagonal_mayor = 0;
    for( int i = 0; i < tamaño; i++)
    {
        suma_diagonal_mayor += arreglo_bi[i][i];
    }
    if ( suma_diagonal_mayor != suma)
    {
        return(0);
    }
    
    //verifica la diagonal menor
    int suma_diagonal_menor = 0;
    for ( int i = 0; i < tamaño; i++)
    {
        suma_diagonal_menor += arreglo_bi[i][tamaño - ( i + 1)];
    }
    if (suma_diagonal_menor != suma)
    {
        return(0);
    }
return (1);
}

void imprime( int tamaño, int arreglo_bi[100][100], int semimagico)
{
    for ( int ren = 0; ren < tamaño; ren++)
    {
        for( int col = 0; col < tamaño; col++)
        {
            printf("%d", arreglo_bi[ren][col]);
           
        }
         printf("\n");
    }
    printf("\n\n");
    if ( semimagico == 0)
    {
        printf("Esta matriz no es semimagica");
    }
    else
    {
        printf("Esta matriz si es semimagica");
    }
}
