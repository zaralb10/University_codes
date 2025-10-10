#include <stdio.h>
#include <math.h>

int capturaO();
void calculaO ( int operacion1 );
void imprime ( int resultado1 );

int main()
{
int operacion;
operacion = capturaO();
calculaO( operacion );
}

int capturaO()
{
    int numero;
    do 
    {
        printf("1)Suma:\n2)Resta:\n3)Multiplicacion:\n4)Factorial:\n5)Binario\n\n");
        scanf("%d",&numero);
    } while ( numero < 1 || numero > 5 );
    return( numero );
}

void calculaO ( int operacion1 )
{
    int a = 0;
    int b = 0 ;
    int resultado = 0;
    if ( operacion1 <= 3 )
    {
        printf("\nDime 2 numeros:\n");
        scanf("%d%d",&a,&b);
    }
    else 
    {
        printf("\nDime 1 numero:\n");
        scanf("%d",&a);
    }
    
    switch( operacion1 )
    {
        case 1:
        resultado = a + b; break;
        
        case 2:
        resultado = a - b; break;
        
        case 3:
        resultado = a * b; break;
        
        case 4:
        b = a ;
        resultado = 1;
        for ( ; b  > 0 ; b --)
        {
            resultado = resultado * b;
        } break;
        
        case 5:
        resultado = a;
        int binario = 0, lugar = 1;
        while (resultado > 0)
        {
        binario += (resultado % 2) * lugar;
        resultado = resultado / 2;
        lugar *= 10;
        }

    printf("Binario: %d\n", binario);
    return;
        
    }
    imprime ( resultado );
}

void imprime ( int resultado1 )
{
    printf("\n%d",resultado1);
}
