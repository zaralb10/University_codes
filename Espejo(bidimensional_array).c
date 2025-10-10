#include <stdio.h>

int captura_ren();
int captura_col();
void llenar_arreglos( int renglon, int columna, int array1[101][101], int array2[101][101]);
int comparar_arreglos( int renglon, int  columna, int  array1[101][101], int array2[101][101]);
void imprime(  int determinar);


int main()
{
    int renglon, columna, array1[101][101], array2[101][101], determinar;
    
    renglon = captura_ren();
    columna = captura_col();
    
    llenar_arreglos(renglon, columna, array1, array2);
    determinar = comparar_arreglos(renglon, columna, array1, array2);
    imprime( determinar);
    return 0;
}

int captura_ren()
{
    int renglon;
    printf("dime la cantidad de renglones: ");
    scanf("%d",&renglon);
    return(renglon);
    
}

int captura_col()
{
    int columna;
    printf("dime la cantidad de columnas: ");
    scanf("%d",&columna);
    return(columna);
}

void llenar_arreglos( int renglon, int columna, int array1[101][101], int array2[101][101])
{
    
    printf("\nPrimer arreglo bidimensional\n");
    for ( int i  = 0; i < renglon; i++)
    {
        printf("\n");
        for ( int j = 0; j < columna; j++)
        {
            printf("Dime un numero para [%d] [%d]: ",i + 1, j + 1);
            scanf("%d",&array1[i][j]);
        }
    }
    
    printf("\nSegundo arreglo bidimensional\n");
    for ( int i2  = 0; i2 < renglon; i2++)
    {
        printf("\n");
        for ( int j2 = 0; j2 < columna; j2++)
        {
            printf("Dime un numero para [%d] [%d]: ",i2 + 1, j2 + 1);
            scanf("%d",&array2[i2][j2]);
        }
    }
}

int comparar_arreglos( int renglon, int  columna, int  array1[101][101], int array2[101][101])
{
for ( int i = 0, i2 = 0; i < renglon && i2 < renglon; i++, i2++)
{
    for ( int j = 0, j2 = columna - 1; j < columna && j2 >= 0 ; j++, j2--)
    {
        if ( array1[i][j] != array2[i2][j2])
        {
            return 0;
        }
    }
}
return 1;
}

void imprime(  int determinar)
{
    if ( determinar == 1 )
    {
        printf("Es espejo\n");
    }
    if ( determinar ==0 )
    {
        printf("No es espejo");
    }
}
