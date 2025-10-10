#include <stdio.h>
#include <stdint.h>
#include <string.h>

void capturar_strings( char string_A[], char string_B[]);
void inversion( char string_A[], char invertir_A[]);
void intercalacion( char string_A[], char string_B[], char intercalar_AB[]);
void inversion_intercalacion( char string_A[], char invertir_A[], char invertir_intercalar_A[]);
void imprime_string( char strings_impresos[]);


int main ()
{
    char string_A[101], string_B[101];
    char invertir_A[101], invertir_B[101];
    char intercalar_AB[101], intercalar_BA[101];
    char invertir_intercalar_A[101], invertir_intercalar_B[101];
    
    capturar_strings( string_A, string_B);
    
    inversion( string_A, invertir_A);
    inversion( string_B, invertir_B);
    
    intercalacion( string_A, string_B, intercalar_AB);
    intercalacion( string_B, string_A, intercalar_BA);
    
    inversion_intercalacion( string_A, invertir_A, invertir_intercalar_A);
    inversion_intercalacion( string_B, invertir_B, invertir_intercalar_B);
    
    imprime_string( invertir_A);
    imprime_string( invertir_B);
    imprime_string( intercalar_AB);
    imprime_string( intercalar_BA);
    imprime_string( invertir_intercalar_A);
    imprime_string( invertir_intercalar_B);
}

void capturar_strings( char string_A[], char string_B[])
{
    printf("Dime la cadena A: ");
    scanf(" %100[^\n]", string_A);
    
    printf("Dime la cadena B: ");
    scanf(" %100[^\n]", string_B);    
}

void inversion( char string_A[], char invertir_A[])
{
    int n = strlen( string_A);
    for ( int i = 0; i < n; i++)
    {
        invertir_A[i] = string_A[n - ( i + 1 )];
    }
    invertir_A[n] = '\0';
}

void intercalacion( char string_A[], char string_B[], char intercalar_AB[])
{
    int i = 0, j = 0, k = 0;
    int n_string_A = strlen( string_A);
    int n_string_B = strlen( string_B);
    
    while ( i < n_string_A && j  < n_string_B)
    {
        intercalar_AB[k++] = string_A[i++];
        intercalar_AB[k++] = string_B[j++];
    }
    
    while( i < n_string_A)
    {
        intercalar_AB[k++] = string_A[i++];
    }
    while( j < n_string_B)
    {
        intercalar_AB[k++] = string_B[j++];
    }
    intercalar_AB[k] = '\0';
}

void inversion_intercalacion( char string_A[], char invertir_A[], char invertir_intercalar_A[])
{
    intercalacion( string_A, invertir_A, invertir_intercalar_A);
}

void imprime_string( char strings_impresos[])
{
    printf("\n%s\n", strings_impresos);
}


