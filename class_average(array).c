#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 40

int captura();
void genera ( float calificaciones [N], int num_alumnos);
void imprime_arreglo ( float calificaciones [N], int num_alumnos);
float calcula ( float calificaciones [ N ], int num_alumnos, int *reprobados);
void imprime ( float promedio, int reprobados);

int main () 
{
    int num_alumnos, reprobados;
    float calificaciones [N], promedio;
    
    srand ( time ( 0 ));// cambiar el numero base del randomizer a tiempo real de la PC 
    num_alumnos = captura();
    genera (calificaciones, num_alumnos);
    imprime_arreglo ( calificaciones, num_alumnos);
    promedio = calcula ( calificaciones, num_alumnos, &reprobados);
    imprime ( promedio, reprobados);
}

int captura()
{
    int num_alumnos;
    do{
    printf("Dime cuantos alumnos hay en el salon: \n");
    scanf("%d",&num_alumnos);
    } while ( num_alumnos > N);
}

void genera ( float calificaciones [N], int num_alumnos)
{
    for ( int i = 0 ; i < num_alumnos; i++ )
    {
       calificaciones[i] = ( rand() % 101 ) / 10.0;
    }
}
void imprime_arreglo ( float calificaciones [N], int num_alumnos)
{
    for ( int i2 = 0; i2 < num_alumnos; i2++)
    {
        printf("La calificacion del alumno %d es %.2f\n", i2 + 1, calificaciones[i2]);
    }
}

float calcula ( float calificaciones [N], int num_alumnos, int *reprobados)
{
   float  promedio,suma;
   for ( int i3 = 0; i3 < num_alumnos; i3++)
   {
     if ( calificaciones[i3] < 6 )
     {
        (*reprobados)++;
     }
     suma += calificaciones[i3];
   }
   promedio = suma / num_alumnos;
   return( promedio );
}

void imprime ( float promedio, int reprobados)
{
    printf("El promedio del grupo fue de: %f \nLa cantidad de reprobados fue de: %d",promedio,reprobados);
}
