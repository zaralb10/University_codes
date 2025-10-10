#include <stdio.h>

int capturan ();
void  tableroA ( int numero1 );

int main()
{
    int numero;
    numero = capturan();
    tableroA ( numero );
}

int capturan ()
{
    int num;
    printf("De cuanto sera tu tablero de ajedrez? ");
    scanf("%d",&num);
    return(num);
}

void tableroA ( int numero1 )
{
    for(int fila = 0; fila < numero1; fila++)
     {
        for(int columna = 0; columna < numero1; columna++) 
        {
            if( ( fila + columna ) % 2  == 0 ) 
            {
                printf("1");
            } else 
            {
                printf("0");
            }
        }
        printf("\n"); 
    }
}














  
}
