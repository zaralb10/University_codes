#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <strings.h>
#define N 4

typedef struct
{
    int clave;
    char carrera;
    float promedio;
    char nombre[101];
} T_Alumno;

void genera( T_Alumno array[]);
void imprime (T_Alumno array []);
void baraja(T_Alumno array[]);
int bus_sec_ord( T_Alumno array[], char nombre[]);

int main()
{
 T_Alumno array[N];
 srand(time(NULL));
 
 genera ( array);
 imprime ( array);
 
 baraja(array);
 imprime ( array);
 int pos = bus_sec_ord(array, "Zarate");
 printf("%d",bus_sec_ord(array, "Zarate"));

if (pos == -1) 
{
    printf("\nNo se encontró\n");
} 
else 
{
    printf("\nENCONTRADO en %d:\nNombre: %s\nPromedio: %.2f\nCarrera: %c\nClave: %d\n",pos + 1, array[pos].nombre, array[pos].promedio, array[pos].carrera, array[pos].clave);
}

}

void genera( T_Alumno array[])
{
    for ( int i = 0; i < N; i++)
    {
        printf("Dime el nombre del alumno %d:", i + 1);
        scanf(" %100[^\n]",array[i].nombre);
        array[i].clave = ( rand () % 900000) + 100000;
        array[i].carrera = ( rand () % 2 ) ? 'c' : 's';
        array[i].promedio = ( rand() % 100000 / 10000.0 );
        
    }
}

void imprime (T_Alumno array [])
{
    
    for ( int i = 0; i < N; i++)
    {
        printf("\nDatos del alumno %d:\nNombre: %s\nPromedio: %.2f\nCarrera: %c\nClave: %d\n", i + 1, array[i].nombre, array[i].promedio, array[i].carrera, array[i].clave);
    }
    
}

void baraja(T_Alumno array[])
{
    T_Alumno temp;
    for ( int i = 1; i < N; i++)
    {
        for (int j = i; j > 0 && strcmp(array[j].nombre, array[j - 1].nombre) < 0; j--)
        {
            temp = array[j];
            array[j] = array[j - 1];
            array[j - 1] = temp;
        }
    }
}

int bus_sec_ord( T_Alumno array[], char nombre[])
{
    int i;
    for ( i = 0; i < N && strcmp(array[i].nombre, nombre) < 0; i++);
    {
        if ( i == N || strcmp(array[i].nombre, nombre) > 0)
        {
            return(-1);
        }
        return(i);
    }
}


