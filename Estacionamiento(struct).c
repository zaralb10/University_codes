#include <stdio.h>



typedef struct 
{
    int minutos;
    int horas;
    
}T_hora;

typedef struct
{
    T_hora entrada;
    T_hora salida;
    
    int num_movimientos;
    int movs[5];
    
}T_Info_cliente;

int captura_total_clientes();
T_Info_cliente captura_cliente();
void calcula(T_Info_cliente *informacion);
void imprime(T_Info_cliente *informacion);


int main()
{
    T_Info_cliente datos_cliente, informacion;
    int num_cliente, i = 0;
    
    num_cliente = captura_total_clientes();
    
    while ( i < num_cliente)
    {
    printf("\nCliente %d\n",i + 1);  
    datos_cliente = captura_cliente();
    calcula(&datos_cliente);
    imprime(&datos_cliente);
    printf("\n");
    i++;
    }
}

int captura_total_clientes()
{
    int total;
    printf("Dime cuantos clientes hay en total: ");
    scanf("%d",&total);
    return(total);
}

T_Info_cliente captura_cliente()
{
    T_Info_cliente saver;
    
    printf("Dime la hora de llegada: ");
    scanf("%d",&saver.entrada.horas);
    
    printf("Dime los minutos de llegada: ");
    scanf("%d",&saver.entrada.minutos);
    
    printf("\n");
    
    printf("Dime la cantidad de movimientos: ");
    scanf("%d",&saver.num_movimientos);
    
    for ( int i = 0; i < saver.num_movimientos; i++)
    {
        printf("Movimiento %d a realizar: ", i + 1);
        scanf("%d",&saver.movs[i]);
    }
    return(saver);
}


void calcula(T_Info_cliente *informacion)
{
    informacion -> salida = informacion -> entrada;
    for ( int i = 0; i < (informacion ->  num_movimientos); i++)
    {
        if ( informacion -> movs[i] == 1)
        {
            informacion ->salida.minutos += 5;
        }
        if ( informacion -> movs[i] == 2)
        {
            informacion ->salida.minutos += 8;
        }
        if ( informacion -> movs[i] == 3)
        {
            informacion ->salida.minutos += 10;
        }
    }
    
    if( informacion -> salida.minutos >= 60)
    {
        informacion -> salida.horas += 1;
        informacion -> salida.minutos -= 60;
    }
}

void imprime(T_Info_cliente *informacion)
{
    printf("La hora de salida de este cliente fue a las %d:%d",informacion -> salida.horas, informacion -> salida.minutos);
    
}
