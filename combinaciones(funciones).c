#include <stdio.h>

int capturan();
int capturar();
int calculaf ( int num );
int calculac ( int n1, int  r1 );
void imprime ( int res);

int main()
{
   int n,r,factorial;
   int comb;
   n = capturan();
   r = capturar();
   factorial = calculaf ( n );
   comb = calculac ( n, r );
   imprime ( comb );
}

int capturan()
{
    int n1;
    printf("Ingresa el valor de n: ");
    scanf("%d",&n1);
    return(n1);
}

int capturar()
{
    int r1;
    printf("Ingresa el valor de r: ");
    scanf("%d",&r1);
    return(r1);
}



int calculaf ( int  num )
{
    int f = 1, i;
    for ( i = 1; i <= num; i++)
    {
        f *= i;
    }
    return(f);
}

int calculac ( int n1, int  r1 )
{
    int a,b,c,res;
    a = calculaf(n1);
    b = calculaf(r1);
    c = calculaf(  n1 - r1 );
    res = a / (b * c);
    return(res);
}

void imprime ( int res)
{
    printf(" %d combinaciones: ",res);
}
