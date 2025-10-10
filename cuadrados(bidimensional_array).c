#include <stdio.h>

int captura_renglon();
int captura_columna();
void genera_valor( int renglon, int columna, int array_bi[101][101]);



int main()
{

    int columna, renglon,array_bi[101][101];
    
    renglon = captura_renglon();
    columna = captura_columna();
    
    genera_valor(renglon, columna, array_bi);

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

void genera_valor( int renglon, int columna, int array_bi[101][101])
{
    int k = 1;
    for ( int i = 0; i < renglon; i++)
    {
        for ( int j = 0; j < columna; j++)
        { 
            int d = i; 
            if (j < d)
            {
                d = j;
            }
            if (renglon - (1 + i) < d)
            {
                d = renglon - (1 +  i);
            }
            if ( columna - (1 + j) < d) 
            {
                d = columna - ( 1 + j);
            }
            array_bi[i][j] = d + 1;
            printf("%d ", array_bi[i][j]);
        }
        k++;
        printf("\n");
    }
}
