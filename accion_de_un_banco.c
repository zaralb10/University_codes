#include <stdio.h>
#include <string.h>

typedef struct
{
    int num_cliente;
    char nom_cliente[11];
    int monto_inicial;
} T_cliente;

T_cliente clientes[11]; 
int activo[11]; 


int captura_acciones();
T_cliente captura_informacion();


int main()
{
   T_cliente datos_accion[101];
   int numero_acciones, i = 0;
   
    for (int i2 = 0; i2 <= 10; i2++) 
    {
        activo[i2] = 0;
        clientes[i2].num_cliente = 0;
        clientes[i2].nom_cliente[0] = '\0';
        clientes[i2].monto_inicial = 0;
    }
   numero_acciones = captura_acciones();
   
   if ( numero_acciones > 101)
   {
       numero_acciones = 101;
   }
   
   while( i < numero_acciones)
   {
       printf("\nAccion  N%d\n",i + 1); 
       datos_accion[i] = captura_informacion();
       i++;
   }
   return 0;
}

int captura_acciones()
{
    int acciones;
    printf("Cuantas acciones quieres hacer: ");
    scanf("%d",&acciones);
    return(acciones);
}

T_cliente captura_informacion()
{
    T_cliente saver = (T_cliente){0};;
    char letra;
    
    printf("Dime el tipo de accion que quieres hacer  \nA:alta\nB:baja\nC:consulta\nD:deposito\nE:retiro\n");
    scanf(" %c",&letra);
    printf("\n");
    switch(letra)
    {

        case 'A':
        {
            printf("dime el numero de cliente: ");
            scanf("%d",&saver.num_cliente);
            printf("dime el nombre del cliente: ");
            scanf("%10s",saver.nom_cliente);
            printf("dime cuanto quieres depositar en tu nueva cuenta: ");
            scanf("%d",&saver.monto_inicial);
            
            int nc = saver.num_cliente;
            
            if (nc < 1 || nc > 10 || activo[nc])
            {
                printf("ERROR\n");
            } 
            else 
            {
                activo[nc] = 1;
                clientes[nc].num_cliente = nc;
                strncpy(clientes[nc].nom_cliente, saver.nom_cliente, 10);
                clientes[nc].nom_cliente[10] = '\0';
                clientes[nc].monto_inicial = saver.monto_inicial;
                printf("OK\n");
                saver = clientes[nc];
            }
        }
        break;
        
        
        case 'B':
        {
            printf("dime el numero de cliente: ");
            scanf("%d",&saver.num_cliente);
            
            int nc = saver.num_cliente;
            if (nc < 1 || nc > 10 || !activo[nc]) 
            { 
                printf("ERROR\n");
            } 
            else 
            {
                activo[nc] = 0;
                clientes[nc].num_cliente = 0;
                clientes[nc].nom_cliente[0] = '\0';
                clientes[nc].monto_inicial = 0;
                printf("OK\n");
            }
        }
        break;
        
        
        case 'C':
        {
            printf("dime el numero de cliente: ");
            scanf("%d",&saver.num_cliente);
            
            int nc = saver.num_cliente;
            if (nc < 1 || nc > 10 || !activo[nc]) 
            {
                printf("ERROR\n");
            }
            else
            {
                printf("-> Consulta: %s %d\n",clientes[nc].nom_cliente,clientes[nc].monto_inicial);
                saver = clientes[nc];
            }
        }
        break;
        
        case 'D':
        {
            printf("dime el numero de cliente: ");
            scanf("%d",&saver.num_cliente);
            printf("dime cuanto quieres depositar: ");
            scanf("%d",&saver.monto_inicial);
            
            int nc = saver.num_cliente;
            int p  = saver.monto_inicial;
            if (nc < 1 || nc > 10 || !activo[nc]) 
            {
                printf("-> Resultado: ERROR (no existe la cuenta)\n");
            } 
            else 
            {
                clientes[nc].monto_inicial += p;
                printf("-> Nuevo saldo: %s %d\n",clientes[nc].nom_cliente,clientes[nc].monto_inicial);
                saver = clientes[nc];
            }
        }
        break;
        
        case 'E':
        {
            printf("dime el numero de cliente: ");
            scanf("%d",&saver.num_cliente);
            printf("dime cuanto quieres retirar: ");
            scanf("%d",&saver.monto_inicial);
            
            int nc = saver.num_cliente;
            int p  = saver.monto_inicial;
            if (nc < 1 || nc > 10 || !activo[nc]) 
                {
                    printf("\n-> Resultado: ERROR (no existe la cuenta)\n");
                } 
                else if (p > clientes[nc].monto_inicial) 
                    {
                    printf("\n-> Resultado: ERROR (fondos insuficientes)\n");
                    } 
            else 
                 {
                    clientes[nc].monto_inicial -= p;
                    printf("\n-> Nuevo saldo: %s %d\n",clientes[nc].nom_cliente,clientes[nc].monto_inicial);
                    saver = clientes[nc];
        }
        break;
        
        default: printf("No existe esta opcion\n");
        break; 
        }
    }
    
    return(saver);
}

