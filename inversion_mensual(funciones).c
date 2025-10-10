#include <stdio.h>

int captura_deposito();
int captura_meta();
int calcula(int deposito, int meta, int *mes, int *saldo_final, int *interes_ganado);
void imprime( int total_depositado, int *mes, int *saldo_final, int *interes_ganado);


int main()
{
    int  deposito, meta, total_depositado;
    int  mes = 0, saldo_final = 0, interes_ganado = 0;
    
    deposito = captura_deposito();
    meta = captura_meta();

    total_depositado = calcula( deposito, meta, &mes, &saldo_final, &interes_ganado);
    imprime(total_depositado, &mes, &saldo_final, &interes_ganado);
}

int captura_deposito()
{
    int inversion;
    printf("Cuantos piensas invertir en cada mes: ");
    scanf("%d",&inversion);
    return(inversion);
}

int captura_meta()
{
    int dinero;
    printf("Dime hasta que cantidad quieres llegar: ");
    scanf("%d",&dinero);
    return(dinero);
}

int calcula(int deposito, int meta, int *mes, int *saldo_final, int *interes_ganado)
{
    while ( (*saldo_final) < meta)
    {
        int interes = ( (*saldo_final) * 5) / 1000;
        (*saldo_final)+= ( interes + deposito);
        (*mes)++;
    }
    int total_depositado = (*mes) * deposito;
    (*interes_ganado) = (*saldo_final) - total_depositado;
    return(total_depositado);
}

void imprime( int total_depositado, int *mes, int *saldo_final, int  *interes_ganado)
{
    printf("total depositado: %d\n",total_depositado);
    printf("meses: %d\n",*mes);
    printf("saldo final: %d\n", *saldo_final);
    printf("interes ganado: %d\n", *interes_ganado);
}
