#include <stdio.h>
#include <stdint.h>
#include <string.h>

void capturar_password( char string_password[]);
void verificar_password( char saved_string[], char string_password[]);

int main()
{
    char string_password[101], saved_string[101] = "hola";
    
    capturar_password ( string_password);
    verificar_password( saved_string, string_password);
}

void capturar_password( char string_password[])
{
    int j = 0;
    char new_string[100];
    
    printf("Dime la contraseña sin espacios: ");
    scanf("%s",string_password);
    int n_password = strlen(string_password);
    
    for (int i = 0; i < n_password; i++)
    {
        new_string[j++] = string_password[i];         // letra de la contraseña
        new_string[j++] = 'a' + (i % 26);             // letra del abecedario
    }

    new_string[j] = '\0';
    strcpy(string_password, new_string);
    printf("%s\n", string_password);  
}

void verificar_password( char saved_string[], char string_password[])
{
    char recuperada[101];
    int j = 0;
    for ( int i = 0; string_password[i] != '\0'; i += 2)
    {
        recuperada[j++] = string_password[i];
    }
    recuperada[j] = '\0';
    
    if (strcmp(recuperada, saved_string) == 0)
    {
        printf("La contraseña es correcta\n");
    }
    else
    {
        printf("Contraseña incorrecta\n");
    }
 
}
