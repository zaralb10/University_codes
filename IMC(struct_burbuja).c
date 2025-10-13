#include <stdio.h>
#define max 100

typedef struct 
{
    int id;
    char nombre[100];
    float peso;
    float estatura;
    float imc;
} T_paciente;


int captura_pacientes();
void captura_datos( T_paciente array_pacientes[], int num_pacientes);
void burbuja(T_paciente array_pacientes[], int num_pacientes);
void imprime(T_paciente array_pacientes[], int num_pacientes);

int main()
{
    int num_pacientes;
    T_paciente array_pacientes[max];
    
    num_pacientes = captura_pacientes();
    captura_datos(array_pacientes,num_pacientes);
    burbuja(array_pacientes,num_pacientes);
    imprime(array_pacientes,num_pacientes);
}

int captura_pacientes()
{
    int pacientes;
    printf("Dime cuantos pacientes son: ");
    scanf("%d",&pacientes);
    return(pacientes);
}


void captura_datos( T_paciente array_pacientes[], int num_pacientes)
{
   for ( int i = 0; i < num_pacientes; i++)
    {
        printf("\nDime los datos del pacientes %d\n", i + 1);
        
        printf("Dime el id: ");
        scanf("%d", &array_pacientes[i].id);
        
        printf("Dime su nombre: ");
        scanf(" %[^\n]", array_pacientes[i].nombre);
        
        printf("Dime su peso: ");
        scanf("%f", &array_pacientes[i].peso);
        
        printf("Dime su altura: ");
        scanf("%f", &array_pacientes[i].estatura);
        array_pacientes[i].imc = array_pacientes[i].peso / ( array_pacientes[i].estatura * array_pacientes[i].estatura);
    }   
}

void burbuja(T_paciente array_pacientes[], int num_pacientes) 
{
    T_paciente temp;
    for (int i = 0; i < num_pacientes - 1; i++) 
    {
        for (int j = 0; j < num_pacientes - ( i + 1); j++)
        {
            if (array_pacientes[j].imc < array_pacientes[j + 1].imc) 
            {
                temp = array_pacientes[j];
                array_pacientes[j] = array_pacientes[j + 1];
                array_pacientes[j + 1] = temp;
            }
        }
    }
}

void imprime(T_paciente array_pacientes[], int num_pacientes)
{
    for ( int i = 0; i < num_pacientes; i++)
    {
        printf("\n%d %s %.1f", array_pacientes[i].id, array_pacientes[i].nombre, array_pacientes[i].imc);
    }
}



