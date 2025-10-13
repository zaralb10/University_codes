#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 500

typedef struct
{
    int clave;
    char carrera;
    float promedio;
}T_alumno;

void generar_datos( T_alumno array_alumnos[]);
void burbuja(T_alumno array_alumnos[]); 
void baraja(T_alumno array_alumnos[]);
void seleccion(T_alumno array_alumnos[]);
void QuickSort(T_alumno array_alumnos[], int inicio, int fin);
void imprime( T_alumno array_alumnos4[]);

int main()
{
    T_alumno array_alumnos[N], array_alumnos1[N], array_alumnos2[N], array_alumnos3[N], array_alumnos4[N];
    clock_t tiempo1, tiempo2;
    float seg;
    
    srand(time(NULL));
    generar_datos(array_alumnos);
    for ( int i  = 0; i < N; i++)
    {
        array_alumnos1[i] = array_alumnos[i];
        array_alumnos2[i] = array_alumnos[i];
        array_alumnos3[i] = array_alumnos[i];
        array_alumnos4[i] = array_alumnos[i];
    }
    printf("Calculando tiempo de cada ordenamiento...\n\n");
    
    //Burbuja
    tiempo1 = clock();
    burbuja(array_alumnos1);
    tiempo2 = clock();
    seg = (float)(tiempo2 - tiempo1) / CLOCKS_PER_SEC;
    printf("Burbuja: %.4f segundos\n", seg);
    
    //Baraja
    tiempo1 = clock();
    baraja(array_alumnos2);
    tiempo2 = clock();
    seg = (float)(tiempo2 - tiempo1) / CLOCKS_PER_SEC;
    printf("Baraja: %.4f segundos\n", seg);
    
    //Seleccion 
    tiempo1 = clock();
    seleccion(array_alumnos3);
    tiempo2 = clock();
    seg = (float)(tiempo2 - tiempo1) / CLOCKS_PER_SEC;
    printf("Seleccion: %.4f segundos\n", seg);
    
    //QuickSort
    tiempo1 = clock();
    QuickSort(array_alumnos4, 0, N - 1);
    tiempo2 = clock();
    seg = (float)(tiempo2 - tiempo1) / CLOCKS_PER_SEC;
    printf("QuickSort: %.4f segundos\n", seg);
    
    imprime(array_alumnos4);
    
    return 0;
}

void generar_datos( T_alumno array_alumnos[])
{
    for ( int i = 0; i < N; i++)
    {
        array_alumnos[i].clave = (rand() % 900000 ) + 100000;
        array_alumnos[i].carrera = rand() % 2 == 1? 'c' : 's';
        array_alumnos[i].promedio = ( rand() % 10001 ) / 1000.0;
        /* printf("alumno %d: promedio %.4f, carrera %c, clave %d\n",i + 1, array_alumnos[i].promedio, array_alumnos[i].carrera, array_alumnos[i].clave);
    */
    }
}

void burbuja(T_alumno array_alumnos[]) 
{
    T_alumno temp;
    for (int i = 0; i < ( N - 1); i++) 
    {
        for (int j = 0; j < N - ( i + 1); j++)
        {
            if ( (array_alumnos[j].promedio)  < (array_alumnos[j + 1].promedio)) 
            {
                temp = array_alumnos[j];
                array_alumnos[j] = array_alumnos[j + 1];
                array_alumnos[j + 1] = temp;
            }
        }
    }
}

void baraja( T_alumno array_alumnos[])
{
    int i, j;
    T_alumno temp;
    for (i = 1; i < N; i++)
    {
        for (j = i; j > 0 && (array_alumnos[j].promedio )  >  ( array_alumnos[j - 1].promedio ); j--)
        {
            temp = array_alumnos[j];
            array_alumnos[j] = array_alumnos[j - 1];
            array_alumnos[j - 1] = temp;
        }
    }
} 

void seleccion(T_alumno array_alumnos[])
{
    int i, j, min_idx;
    T_alumno temp;

    // Recorremos cada posición del arreglo
    for (i = 0; i < N - 1; i++)
    {
        min_idx = i;         // Suponemos que el mínimo está en la posición i
        
        for (j = i + 1; j < N; j++) // Buscamos un valor más pequeño en el resto del arreglo
        {
            if (array_alumnos[j].promedio > array_alumnos[min_idx].promedio)
            {
                min_idx = j; // Actualizamos la posición del mínimo
            }
        }
        
        if (min_idx != i) // Si encontramos un valor menor, intercambiamos
        {
            temp = array_alumnos[i];
            array_alumnos[i] = array_alumnos[min_idx];
            array_alumnos[min_idx] = temp;
        }
    }
}

void QuickSort(T_alumno array_alumnos[], int inicio, int fin)
{
    if (inicio >= fin) return;

    int i = inicio;
    int j = fin;
    float piv = array_alumnos[(inicio + fin) / 2].promedio;

    // Orden DESC por promedio
    while (i <= j)
    {
        while (array_alumnos[i].promedio > piv) i++;   // elementos "mayores" a la izquierda
        while (array_alumnos[j].promedio < piv) j--;   // elementos "menores" a la derecha

        if (i <= j)
        {
            T_alumno temp = array_alumnos[i];
            array_alumnos[i] = array_alumnos[j];
            array_alumnos[j] = temp;
            i++;
            j--;
        }
    }
    if (inicio < j) QuickSort(array_alumnos, inicio, j);
    if (i < fin) QuickSort(array_alumnos, i, fin);
}

void imprime( T_alumno array_alumnos[])
{
    int m = ( N < 10) ? N : 10;
    printf("Los 10 mejores top globales:\n");
    for ( int i = 0; i < m; i++)
    {
         printf("%2d) Promedio: %.4f | Carrera: %c | Clave: %d\n",i + 1, array_alumnos[i].promedio, array_alumnos[i].carrera, array_alumnos[i].clave);
    }
}
