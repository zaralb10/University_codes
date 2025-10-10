#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100
#include <stdio.h>

int captura_alumnos();
void genera_valor_horas_tiempo( int datos_horas[N], int datos_minutos[N], int alumnos);
void imprime_genera_valor_horas_tiempo( int datos_horas[N], int datos_minutos[N], int alumnos);
void alumno_rapido( int datos_horas[N], int datos_minutos[N], int alumnos);



int main()
{
int datos_horas[N], datos_minutos[N], alumnos;
srand(time(NULL));
alumnos = captura_alumnos();
genera_valor_horas_tiempo( datos_horas, datos_minutos, alumnos);
imprime_genera_valor_horas_tiempo( datos_horas, datos_minutos, alumnos);
alumno_rapido( datos_horas, datos_minutos, alumnos);
}

int captura_alumnos()
{
    int alumnos;
    printf("Cuantos alumnos hay en el examen: ");
    scanf("%d",&alumnos);
    return(alumnos);
}

void genera_valor_horas_tiempo( int datos_horas[N], int datos_minutos[N], int alumnos)
{
    for ( int i = 0; i < alumnos; i++)
    {
        datos_horas[i] = rand () % 3;
        datos_minutos[i] = rand () % 60;
    }
}

void imprime_genera_valor_horas_tiempo( int datos_horas[N], int datos_minutos[N], int alumnos)
{
    for ( int i = 0; i < alumnos; i++)
    {
        printf("El alumno %d: %d horas y %d minutos\n", i + 1, datos_horas[i], datos_minutos[i]);
    }
}

void alumno_rapido( int datos_horas[N], int datos_minutos[N], int alumnos)
{
   int temp = 0;
   for ( int i = 1; i < alumnos; i++)
   {
        if ( datos_horas[i] < datos_horas[temp] ||
        ( datos_horas [i] == datos_horas[temp] && 
        datos_minutos[i] < datos_minutos[temp] ))
        {
            temp = i;
        }
   }
    printf("\nEl alumnos que acabo primero fue el alumno %d: %d horas y %d minutos",
    temp + 1, datos_horas[temp], datos_minutos[temp]);
}
