#include <stdio.h>
#define max 100

typedef struct
{
    int id;
    float promedio;
    int edad;
} T_usuario;

int captura_usuarios();
void captura_datos( T_usuario usuarios[], int tam);
void burbuja ( T_usuario usuarios[], int tamaño);
int leer_confirmacion();

int main()
{
    int tam, confirmacion;
    T_usuario usuarios[max];
    
    tam = captura_usuarios();
    captura_datos( usuarios, tam);
    burbuja( usuarios, tam);
    
    confirmacion = leer_confirmacion();
    
    if (confirmacion < 0 || confirmacion >= tam)
    {
        printf("ERROR\n");  
    }
        
    else
    {
        printf("%08d\n%.2f\n%d\n", usuarios[confirmacion].id, usuarios[confirmacion].promedio, usuarios[confirmacion].edad);
    }
    return 0;
}

int captura_usuarios()
{
    int usuarios;
    printf("Dime cuantos usuarios son: ");
    scanf("%d",&usuarios);
    return(usuarios);
}

void captura_datos( T_usuario usuarios[], int tam)
{
    for ( int i = 0; i < tam; i++)
    {
        printf("\nUsuario %d\n",i + 1);
        
        printf("dime el id: " );
        scanf("%d",&usuarios[i].id);
        
        printf("dime el promedio: ");
        scanf("%f",&usuarios[i].promedio);
        
        printf("dime la edad: ");
        scanf("%d",&usuarios[i].edad);
    }
}

void burbuja ( T_usuario usuarios[], int tam)
{
    for( int i = 0; i < tam - 1; i++)
    {
        for( int j = 0; j < tam - ( i + 1); j++)
        {
             if (usuarios[j].edad > usuarios[j + 1].edad) 
             {
                T_usuario temp = usuarios[j];
                usuarios[j] = usuarios[j + 1];
                usuarios[j + 1] = temp;
             }
        }
    }
    
}

int leer_confirmacion()
{
    int confirmar;
    printf("\n¿Qué posición quieres ver?: ");
    scanf("%d", &confirmar);
    return (confirmar);
}



