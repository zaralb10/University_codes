#include <stdio.h>

void captura(char texto[]);
int cuenta_palabra(char texto[]);
void imprime(int palabras);

int main(void)
{
    char texto[100];
    int palabras;

    captura(texto);
    palabras = cuenta_palabra(texto);
    imprime(palabras);

    return 0;
}

void captura(char texto[])
{
    printf("Dime el texto:\n");
    // espacio inicial para consumir saltos de línea previos; 99 para no desbordar
    scanf(" %99[^\n]", texto);
}

int cuenta_palabra(char texto[])
{
    int contador = 0;

    for (int i = 0; texto[i] != '\0'; i++)
    {
        if (texto[i] != ' ' && texto[i] != '\t')
        {
            // si lo que sigue es espacio, tab o fin de cadena, cerramos palabra
            if (texto[i + 1] == ' ' || texto[i + 1] == '\t' || texto[i + 1] == '\0')
            {
                contador++;
            }
        }
    }
    return contador;
}

void imprime(int palabras)
{
    printf("La cantidad de palabras en el texto es de: %d\n", palabras);
} 
