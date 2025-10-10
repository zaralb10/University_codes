#include <stdio.h>

void recursivo(int numero);

int main()
{
    int numero = 103;
    
    recursivo(numero);
   
    
}

void recursivo(int numero) {
    printf("%d ", numero);

    if (numero == 1) 
    {
        return;   // CASO BASE
    }
    if (numero % 2 == 0)       // SI ES PAR
    {
        recursivo(numero / 2); // llamada recursiva con valor reducido
    }
    else                       // SI ES IMPAR
    {
        recursivo(3 * numero + 1); // llamada recursiva con valor transformado
    }
}
