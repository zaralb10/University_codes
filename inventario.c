#include <string.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int ID;
    char nombre[50];
    float precio;
    int stock;
} t_producto;

void agregar_producto();    
void mostrar_productos();   
void buscar_producto(); 
void modificar_producto();  
void eliminar_producto();   

int main ()
{
    int opcion;
    do
    {
        printf("\n=== MENU ===\n");
        printf("1- Agregar producto\n");
        printf("2- Mostrar productos\n");
        printf("3- Buscar producto por ID\n");
        printf("4- Modificar producto\n");
        printf("5- Eliminar producto\n");
        printf("0- Salir\n");
        printf("Opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1: agregar_producto(); break;
            case 2: mostrar_productos(); break;
            case 3: buscar_producto(); break;
            case 4: modificar_producto(); break;
            case 5: eliminar_producto(); break;
            case 0: printf("Saliendo...\n"); break;
            default: printf("Opcion no valida.\n"); break;
        }
    } while (opcion != 0);

    return 0;
}

int existeID(int id)
{
    t_producto p;
    FILE *fb = fopen("productos.bin", "rb");
    if (!fb) return 0;

    while (fread(&p, sizeof(t_producto), 1, fb) == 1)
    {
        if (p.ID == id)
        {
            fclose(fb);
            return 1;
        }
    }

    fclose(fb);
    return 0;
}

void agregar_producto()
{
    t_producto producto;
    FILE *fb = fopen("productos.bin", "ab");
    if (!fb)
    {
        printf("No se pudo abrir productos.bin\n");
        return;
    }

    printf("Ingrese ID del producto: ");
    scanf("%d", &producto.ID);

    if (existeID(producto.ID))
    {
        printf("ERROR: Ese ID ya existe.\n");
        fclose(fb);
        return;
    }

    printf("Ingrese nombre del producto: ");
    // Limpiar buffer de entrada
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    scanf("%49[^\n]", producto.nombre); // ACEPTA ESPACIOS

    printf("Ingrese precio del producto: ");
    scanf("%f", &producto.precio);

    printf("Ingrese stock del producto: ");
    scanf("%d", &producto.stock);

    fwrite(&producto, sizeof(t_producto), 1, fb);
    fclose(fb);

    printf("Producto agregado exitosamente.\n");
}

void mostrar_productos()
{
    t_producto producto;
    FILE *fb = fopen("productos.bin", "rb");

    if (!fb)
    {
        printf("No hay productos aun.\n");
        return;
    }

    int hayDatos = 0;

    printf("\n=== LISTA DE PRODUCTOS ===\n");
    while (fread(&producto, sizeof(t_producto), 1, fb) == 1)
    {
        hayDatos = 1;
        printf("ID: %d\nNombre: %s\nPrecio: %.2f\nStock: %d\n\n",
               producto.ID, producto.nombre, producto.precio, producto.stock);
    }

    if (!hayDatos)
        printf("No hay productos registrados.\n");

    fclose(fb);
}

void buscar_producto()
{
    int id_buscar;
    t_producto producto;
    FILE *fb = fopen("productos.bin", "rb");

    if (!fb)
    {
        printf("No se pudo abrir productos.bin\n");
        return;
    }

    printf("Ingrese ID del producto a buscar: ");
    scanf("%d", &id_buscar);

    while (fread(&producto, sizeof(t_producto), 1, fb) == 1)
    {
        if (producto.ID == id_buscar)
        {
            printf("\nProducto encontrado:\n");
            printf("ID: %d\nNombre: %s\nPrecio: %.2f\nStock: %d\n",
                   producto.ID, producto.nombre,
                   producto.precio, producto.stock);
            fclose(fb);
            return;
        }
    }

    printf("Producto con ID %d no encontrado.\n", id_buscar);
    fclose(fb);
}

void modificar_producto()
{
    int id_buscar;
    t_producto producto;

    FILE *fb = fopen("productos.bin", "r+b");

    if (!fb)
    {
        printf("No se pudo abrir productos.bin\n");
        return;
    }

    printf("Ingrese ID del producto a modificar: ");
    scanf("%d", &id_buscar);

    while (fread(&producto, sizeof(t_producto), 1, fb) == 1)
    {
        if (producto.ID == id_buscar)
        {
            int opcion;
            printf("\nModificar precio (1) o stock (2)? ");
            scanf("%d", &opcion);

            if (opcion == 1)
            {
                printf("Nuevo precio: ");
                scanf("%f", &producto.precio);
            }
            else if (opcion == 2)
            {
                printf("Nuevo stock: ");
                scanf("%d", &producto.stock);
            }
            else
            {
                printf("Opcion no valida.\n");
                fclose(fb);
                return;
            }
            fseek(fb, -(long)sizeof(t_producto), SEEK_CUR);
            fwrite(&producto, sizeof(t_producto), 1, fb);

            printf("Producto modificado exitosamente.\n");
            fclose(fb);
            return;
        }
    }

    printf("Producto con ID %d no encontrado.\n", id_buscar);
    fclose(fb);
}

void eliminar_producto()
{
    int id_eliminar;
    t_producto producto;

    FILE *fb = fopen("productos.bin", "rb");
    FILE *temp = fopen("temp.bin", "wb");

    if (!fb || !temp)
    {
        printf("No se pudieron abrir los archivos necesarios.\n");
        return;
    }

    printf("Ingrese ID del producto a eliminar: ");
    scanf("%d", &id_eliminar);

    while (fread(&producto, sizeof(t_producto), 1, fb) == 1)
    {
        if (producto.ID != id_eliminar)
        {
            fwrite(&producto, sizeof(t_producto), 1, temp);
        }
    }

    fclose(fb);
    fclose(temp);

    remove("productos.bin");
    rename("temp.bin", "productos.bin");

    printf("Producto eliminado exitosamente.\n");
}
