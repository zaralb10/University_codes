#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

typedef struct
{
    int ID;
    char marca[31];
    char sub_marca[31];
    int modelo;
    float precio;
    
}T_coche;

T_coche coches[101]; 
int activo[101];

int captura_tam();
int captura_op();
T_coche captura_informacion(int tam);




int main()
{
    int tam, num_operaciones, i = 0;
    T_coche arrray[101];
    
    tam = captura_tam();
    if ( tam < 1) tam = 1;
    if ( tam > 100) tam = 100;
    
    for (int i2 = 1; i2 <= tam; i2++) 
    {
        activo[i2] = 0;
        coches[i2].ID = 0;
        coches[i2].marca[0] = '\0';
        coches[i2].sub_marca[0] = '\0';
        coches[i2].modelo = 0;
        coches[i2].precio = 0;
    }
    
    num_operaciones = captura_op();
    
    if (num_operaciones < 0) num_operaciones = 0;
    if (num_operaciones > 101) num_operaciones = 101;
    
    while(  i  < num_operaciones)
   {
       printf("\nAccion  N%d\n",i + 1); 
       arrray[i] = captura_informacion(tam);
       i++;
   }
   return 0;

}

int captura_tam()
{
    int tamaño;
    printf("Dime cuantos autos hay en tu conseccionario:");
    scanf("%d",&tamaño);
    return(tamaño);
}

int captura_op()
{
    int operaciones;
    printf("Cuantas operaciones quieres hacer: ");
    scanf("%d",&operaciones);
    return(operaciones);
}

T_coche captura_informacion(int tam)
{
    T_coche saver = (T_coche){0};;
    int accion;
    
    printf("MENU\nDime el tipo de accion que quieres hacer  \n1:alta\n2:baja\n3:consulta coches\n4:Salir\n ");
    scanf("%d",&accion);
    printf("\n");
    switch(accion)
    {
        case 1:
        {
            printf("dime el ID del coche:");
            scanf("%d",&saver.ID);
            printf("dime el nombre de la marca:");
            scanf("%30s",saver.marca);
            printf("dime el nombre de la sub-marca:");
            scanf("%30s",saver.sub_marca);
            printf("dime el año del auto: ");
            scanf("%d",&saver.modelo);
            printf("dime el precio del auto: ");
            scanf("%f",&saver.precio);
            
            int num_coche = saver.ID;
            
            if (num_coche < 1 || num_coche > tam || activo[num_coche])
            {
                printf("ERROR\n");
            } 
            else 
            {
                activo[num_coche] = 1;
                coches[num_coche].ID = num_coche;
                
                strncpy(coches[num_coche].marca, saver.marca, 30);
                coches[num_coche].marca[30] = '\0';
                strncpy(coches[num_coche].sub_marca, saver.sub_marca, 30);
                coches[num_coche].sub_marca[30] = '\0';
                
                coches[num_coche].modelo = saver.modelo;
                coches[num_coche].precio = saver.precio;
                printf("OK\n");
                saver = coches[num_coche];
            }
        }
        break;
        
        case 2:
        {
            printf("dime el ID del coche:");
            scanf("%d",&saver.ID);
            
            int num_coche = saver.ID;
            if (num_coche < 1 || num_coche > tam || !activo[num_coche]) 
            { 
                printf("ERROR\n");
            } 
            else 
            {
                activo[num_coche] = 0;
                coches[num_coche].ID = 0;
                coches[num_coche].marca[0] = '\0';
                coches[num_coche].sub_marca[0] = '\0';
                coches[num_coche].modelo = 0;
                coches[num_coche].precio = 0;
                printf("OK\n");
            }
        }
        break;
        
        case 3: // CONSULTA (lista todos los activos)
        {
            int disponibles= 0;
            printf("Coches en activo\n");
            for (int i = 1; i <= tam; i++)
            {
                if (activo[i])
                {
                    printf("#%d  ID:%d  %s %s  %d  $%.2f\n",
                           i, coches[i].ID, coches[i].marca,
                           coches[i].sub_marca, coches[i].modelo, coches[i].precio);
                    disponibles = 1;
                }
            }
            if (!disponibles) printf("(sin registros activos)\n");
        }
        break;
        
        case 4: // SALIR (no hace nada especial)
        {
        printf("Saliendo del programa...\n");
        exit(0); // <-- Esto termina el programa inmediatamente
        }
        break;
        
        default:
        {
            printf("Opcion invalida.\n");
        }
        break;
    }
    return(saver);
}


