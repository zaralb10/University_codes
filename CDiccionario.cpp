#include "CDiccionario.h"

// Chavez y Zarate
CDiccionario::CDiccionario()
{
    archivo = NULL;
    nAtributos = 0;
    tambloque = 0;
    diractiva = -1;
    activa.atr = -1;
    activa.sig = -1;
    activa.data = -1;
    strcpy(activa.nombre, "");
    strcpy(nombreArchivo, "");
}

void CDiccionario::menuPrincipal()
{
    int op;
    do
    {
        printf("\nQue desea hacer:\n1.Nuevo diccionario\n2.Abrir diccionario\n3.Salir\n");
        scanf("%d", &op);

        switch(op)
        {
            case 1:
                nuevoDiccionario();
                break;

            case 2:
                abrirDiccionario();
                break;

            case 3:
                printf("\nSaliendo...");
                break;

            default:
                printf("\nNo es una opcion");
        }
    } while(op != 3);
}

// ============================ NUEVO / ABRIR ============================

void CDiccionario::nuevoDiccionario()
{
    char nombre[50];
    printf("\nNombre del nuevo diccionario: ");
    scanf("%s", nombre);

    archivo = fopen(nombre, "rb");
    if(archivo)
    {
        printf("\nEl archivo ya existe\n");
        fclose(archivo);
        archivo = NULL;
    }
    else
    {
        printf("\nEl archivo NO existe, creando...");
        archivo = fopen(nombre, "wb+");

        if(!archivo)
        {
            printf("\nError al crear el archivo");
            return;
        }

        strcpy(nombreArchivo, nombre);
        printf("\nArchivo %s creado correctamente\n", nombre);
        escribeCabEntidades(-1);
        MenuEntidades();
        fclose(archivo);
        archivo = NULL;
    }
}

void CDiccionario::abrirDiccionario()
{
    char nombre[50];
    printf("\nNombre del archivo: ");
    scanf("%s", nombre);

    archivo = fopen(nombre, "rb+");
    if(archivo != NULL)
    {
        strcpy(nombreArchivo, nombre);
        printf("\nArchivo abierto correctamente");
        MenuEntidades();
        fclose(archivo);
        archivo = NULL;
    }
    else
    {
        printf("\nNo existe el archivo");
    }
}

// ============================ MENU ENTIDADES ============================

void CDiccionario::MenuEntidades()
{
    int op;
    do
    {
        printf("\n1.Nueva 2.Consultar 3.Eliminar 4.Modificar 5.Atributos 6.Datos 7.Regresar\n");
        scanf("%d", &op);

        switch(op)
        {
            case 1: altaEntidad(); break;
            case 2: consultarEntidades(); break;
            case 3: bajaEntidad(); break;
            case 4: modificaEntidad(); break;
            case 5: menuAtributos(); break;
            case 6: menuDatos(); break;
            case 7: printf("\nRegresando..."); break;
            default: printf("\nOpcion no valida");
        }

    } while(op != 7);
}

// ============================ CABECERA ============================

void CDiccionario::escribeCabEntidades(long cab)
{
    fseek(archivo, 0, SEEK_SET);
    fwrite(&cab, sizeof(long), 1, archivo);
}

long CDiccionario::getCabEntidades()
{
    long dir;
    fseek(archivo, 0, SEEK_SET);
    fread(&dir, sizeof(long), 1, archivo);
    return dir;
}

// ============================ ENTIDADES ============================

Entidad CDiccionario::capturaEntidad()
{
    Entidad ent;
    printf("\nNombre de la entidad: ");
    scanf(" %[^\n]", ent.nombre);
    ent.atr = -1;
    ent.sig = -1;
    ent.data = -1;
    return ent;
}

long CDiccionario::buscaEntidad(Entidad ent)
{
    long cab = getCabEntidades();
    Entidad actual;

    while(cab != -1)
    {
        actual = leeEntidad(cab);

        if(strcmp(actual.nombre, ent.nombre) == 0)
            return cab;

        cab = actual.sig;
    }

    return -1;
}

long CDiccionario::escribeEntidad(Entidad ent)
{
    long dir;
    fseek(archivo, 0, SEEK_END);
    dir = ftell(archivo);
    fwrite(&ent, sizeof(Entidad), 1, archivo);
    return dir;
}

Entidad CDiccionario::leeEntidad(long dir)
{
    Entidad nvo;
    fseek(archivo, dir, SEEK_SET);
    fread(&nvo, sizeof(Entidad), 1, archivo);
    return nvo;
}

void CDiccionario::reescribeEntidad(long dir, Entidad ent)
{
    fseek(archivo, dir, SEEK_SET);
    fwrite(&ent, sizeof(Entidad), 1, archivo);
}

void CDiccionario::insertaEntidad(Entidad nvo, long dir)
{
    Entidad act, ant;
    long cab = getCabEntidades(), dirant;

    if(cab == -1)
    {
        cab = dir;
        escribeCabEntidades(cab);
    }
    else
    {
        act = leeEntidad(cab);

        if(strcmp(act.nombre, nvo.nombre) > 0)
        {
            nvo.sig = cab;
            reescribeEntidad(dir, nvo);
            escribeCabEntidades(dir);
        }
        else
        {
            while(cab != -1 && strcmp(nvo.nombre, act.nombre) > 0)
            {
                dirant = cab;
                ant = act;
                cab = act.sig;

                if(cab != -1)
                    act = leeEntidad(cab);
            }

            nvo.sig = cab;
            reescribeEntidad(dir, nvo);

            ant.sig = dir;
            reescribeEntidad(dirant, ant);
        }
    }
}

void CDiccionario::altaEntidad()
{
    long dir;
    Entidad nueva = capturaEntidad();

    if(buscaEntidad(nueva) == -1)
    {
        dir = escribeEntidad(nueva);
        insertaEntidad(nueva, dir);
        printf("\nEntidad agregada correctamente");
    }
    else
        printf("\nError: La entidad ya existe");
}

void CDiccionario::consultarEntidades()
{
    Entidad actual;
    long cab = getCabEntidades();

    if(cab == -1)
    {
        printf("\nNo hay entidades registradas");
        return;
    }

    printf("\n--- ENTIDADES ---\n");
    while(cab != -1)
    {
        actual = leeEntidad(cab);
        printf("\n%s | atr:%ld | data:%ld | sig:%ld", actual.nombre, actual.atr, actual.data, actual.sig);
        cab = actual.sig;
    }
    printf("\n");
}

long CDiccionario::eliminaEntidad(cadena nom)
{
    Entidad ant, le;
    long dirant, cab;

    cab = getCabEntidades();
    if(cab == -1) // no hay entidades
        return -1;

    le = leeEntidad(cab);

    if(strcmp(nom, le.nombre) == 0) // la primera entidad es la que se elimina
    {
        escribeCabEntidades(le.sig);
        return cab;
    }
    else // se busca la entidad a eliminar
    {
        while(cab != -1 && strcmp(nom, le.nombre) != 0) // se recorre la lista de entidades
        {
            dirant = cab;
            ant = le;
            cab = le.sig;

            if(cab != -1) // se lee la siguiente entidad
                le = leeEntidad(cab);
        }

        if(cab != -1 && strcmp(le.nombre, nom) == 0) // se encontró la entidad a eliminar
        {
            ant.sig = le.sig;
            reescribeEntidad(dirant, ant);
            return cab;
        }
        else
            return -1;
    }
}

void CDiccionario::bajaEntidad()
{
    long dir;
    char nom[30];

    printf("\nIngrese nombre: ");
    scanf(" %[^\n]", nom);

    Entidad aux;
    strcpy(aux.nombre, nom);

    dir = buscaEntidad(aux);

    if(dir == -1)
        printf("\nERROR: La entidad no existe");
    else
    {
        eliminaEntidad(nom);
        printf("\nEntidad eliminada correctamente");
    }
}

void CDiccionario::modificaEntidad()
{
    Entidad nueva, aux;
    long dir;

    printf("\nQue entidad desea modificar: ");
    scanf(" %[^\n]", aux.nombre);

    if(buscaEntidad(aux) != -1)
    {
        printf("Ingrese la nueva info: ");
        nueva = capturaEntidad();

        if(buscaEntidad(nueva) == -1 || strcmp(aux.nombre, nueva.nombre) == 0)
        {
            dir = eliminaEntidad(aux.nombre);
            reescribeEntidad(dir, nueva);
            insertaEntidad(nueva, dir);
            printf("\nEntidad modificada correctamente");
        }
        else
            printf("\nNo se puede actualizar, ya existe otra entidad con ese nombre");
    }
    else
        printf("\nNo existe la entidad");
}

// ============================ ATRIBUTOS ============================

int CDiccionario::pideEntidad()
{
    long cab = getCabEntidades();
    if(cab == -1)
    {
        printf("\nError: No hay entidades creadas.");
        return 0;
    }

    Entidad aux;
    printf("\nNombre de la entidad para gestionar atributos/datos: ");
    scanf(" %[^\n]", aux.nombre);

    diractiva = buscaEntidad(aux);
    if(diractiva == -1)
    {
        printf("\nError: La entidad no existe.");
        return 0;
    }

    activa = leeEntidad(diractiva);
    return 1;
}

void CDiccionario::menuAtributos()
{
    if (!pideEntidad()) return;

    int op;
    do
    {
        printf("\n1.Nuevo 2.Consultar 3.Eliminar 4.Modificar 5.Regresar\n");
        scanf("%d", &op);

        switch(op)
        {
            case 1: altaAtributo(); break;
            case 2: consultarAtributos(); break;
            case 3: bajaAtributo(); break;
            case 4: modificaAtributo(); break;
            case 5: printf("\nRegresando..."); break;
            default: printf("\nOpcion no valida");
        }

    } while(op != 5);
}

Atributo CDiccionario::capturaAtributo()
{
    Atributo nuevoA;

    printf("\nDame el nombre: ");
    scanf(" %[^\n]", nuevoA.nombre);

    printf("¿Que tipo es? 1.Char 2.Entero 3.Float 4.Double 5.Long: ");
    scanf("%u", &nuevoA.tipo);

    if(nuevoA.tipo == 1)
    {
        printf("¿Cuantas letras?: ");
        scanf("%u", &nuevoA.tamano);
    }
    else
    {
        switch(nuevoA.tipo)
        {
            case 2: nuevoA.tamano = sizeof(int); break;
            case 3: nuevoA.tamano = sizeof(float); break;
            case 4: nuevoA.tamano = sizeof(double); break;
            case 5: nuevoA.tamano = sizeof(long); break;
            default: nuevoA.tamano = 0;
        }
    }

    printf("¿Este atributo es clave primaria? (s/n): ");
    scanf(" %c", &nuevoA.iskp);

    printf("¿Permite nulos? (s/n): ");
    scanf(" %c", &nuevoA.nulo);

    printf("Indique una descripcion: ");
    scanf(" %[^\n]", nuevoA.descripcion);

    nuevoA.sig = -1;
    return nuevoA;
}

long CDiccionario::escribeAtributo(Atributo atr)
{
    long dir;
    fseek(archivo, 0, SEEK_END);
    dir = ftell(archivo);
    fwrite(&atr, sizeof(Atributo), 1, archivo);
    return dir;
}

Atributo CDiccionario::leeAtributo(long dir)
{
    Atributo atr;
    fseek(archivo, dir, SEEK_SET);
    fread(&atr, sizeof(Atributo), 1, archivo);
    return atr;
}

void CDiccionario::reescribeAtributo(long dir, Atributo atr)
{
    fseek(archivo, dir, SEEK_SET);
    fwrite(&atr, sizeof(Atributo), 1, archivo);
}

long CDiccionario::buscaAtributo(Atributo atr)
{
    long cab = activa.atr;

    while(cab != -1)
    {
        Atributo actual = leeAtributo(cab);

        if(strcmp(actual.nombre, atr.nombre) == 0)
            return cab;

        cab = actual.sig;
    }

    return -1;
}

long CDiccionario::buscaAtributo(cadena nombre)
{
    Atributo aux;
    strcpy(aux.nombre, nombre);
    return buscaAtributo(aux);
}

void CDiccionario::insertaAtributo(Atributo nvo, long dir)
{
    long cab = activa.atr;

    if(activa.atr == -1)
    {
        activa.atr = dir;
        reescribeEntidad(diractiva, activa);
    }
    else
    {
        Atributo actual = leeAtributo(cab);

        if(strcmp(actual.nombre, nvo.nombre) > 0)
        {
            nvo.sig = cab;
            reescribeAtributo(dir, nvo);
            activa.atr = dir;
            reescribeEntidad(diractiva, activa);
        }
        else
        {
            Atributo atrant;
            long dirant = cab;

            while(cab != -1 && strcmp(nvo.nombre, actual.nombre) > 0)
            {
                atrant = actual;
                dirant = cab;
                cab = actual.sig;

                if(cab != -1)
                    actual = leeAtributo(cab);
            }

            nvo.sig = cab;
            reescribeAtributo(dir, nvo);

            atrant.sig = dir;
            reescribeAtributo(dirant, atrant);
        }
    }
}

void CDiccionario::altaAtributo()
{
    if(activa.data != -1)
    {
        printf("\nNo se pueden agregar atributos porque la entidad ya tiene bloques registrados.");
        return;
    }

    Atributo nuevoA = capturaAtributo();

    if(buscaAtributo(nuevoA) != -1)
    {
        printf("\nEse atributo ya existe en la entidad.");
        return;
    }

    // Contar cuantas PK ya existen
    int pkActuales = 0;
    long cab = activa.atr;
    while(cab != -1)
    {
        Atributo aux = leeAtributo(cab);
        if(aux.iskp == 's' || aux.iskp == 'S')
            pkActuales++;
        cab = aux.sig;
    }

    // Solo permitir una PK, pero puede estar en cualquier posición
    if((nuevoA.iskp == 's' || nuevoA.iskp == 'S') && pkActuales >= 1)
    {
        printf("\nError: ya existe una clave primaria. Solo se permite una.");
        return;
    }

    long dir = escribeAtributo(nuevoA);
    insertaAtributo(nuevoA, dir);
    printf("\nAtributo insertado con exito.");
}

void CDiccionario::consultarAtributos()
{
    cargaAtributos();

    printf("\n--- Atributos de %s ---", activa.nombre);

    if(nAtributos == 0)
    {
        printf("\nError: la entidad debe tener exactamente una clave primaria.\n");
        return;
    }

    printf("\n%-15s | %-5s | %-6s | %-3s | %-3s | %-15s | %-5s",
           "Nombre", "Tipo", "Tam", "PK", "Nul", "Descripcion", "Sig");

    for(int i = 0; i < nAtributos; i++)
    {
        Atributo a = arrAtributos[i];
        printf("\n%-15s | %-5u | %-6u | %-3c | %-3c | %-15s | %-5ld",
               a.nombre, a.tipo, a.tamano, a.iskp, a.nulo, a.descripcion, a.sig);
    }
    printf("\n");
}

void CDiccionario::bajaAtributo()
{
    if(activa.data != -1)
    {
        printf("\nNo se pueden eliminar atributos porque la entidad ya tiene bloques registrados.");
        return;
    }
    long dir;
    char nombre[30];

    printf("\nIngrese el nombre del atributo a eliminar: ");
    scanf(" %[^\n]", nombre);

    dir = buscaAtributo(nombre);

    if(dir == -1)
        printf("\nError: El atributo no existe");
    else
    {
        eliminaAtributo(nombre);
        printf("\nAtributo eliminado correctamente");
    }
}

long CDiccionario::eliminaAtributo(cadena nombre)
{
    long cab = activa.atr;
    long dirant = -1;
    Atributo ant, actual;

    if(cab == -1) // no hay atributos
        return -1;

    actual = leeAtributo(cab);

    if(strcmp(actual.nombre, nombre) == 0) // el primer atributo es el que se elimina
    {
        activa.atr = actual.sig;
        reescribeEntidad(diractiva, activa);
        return cab;
    }
    else // se busca el atributo a eliminar
    {
        while(cab != -1 && strcmp(nombre, actual.nombre) != 0)
        {
            dirant = cab;
            ant = actual;
            cab = actual.sig;

            if(cab != -1)
                actual = leeAtributo(cab);
        }

        if(cab != -1 && strcmp(actual.nombre, nombre) == 0)
        {
            ant.sig = actual.sig;
            reescribeAtributo(dirant, ant);
            return cab;
        }
        else
            return -1;
    }
}

void CDiccionario::modificaAtributo()
{
    if(activa.data != -1)
    {
        printf("\nNo se pueden modificar atributos porque la entidad ya tiene bloques registrados.");
        return;
    }

    char nombre[30];
    Atributo nvo;
    long dir1, dir2, dir3;

    printf("\nAtributo a modificar: ");
    scanf(" %[^\n]", nombre);

    dir1 = buscaAtributo(nombre);

    if(dir1 == -1)
    {
        printf("\nNo existe el atributo");
        return;
    }

    printf("Ingrese la nueva informacion: ");
    nvo = capturaAtributo();

    dir2 = buscaAtributo(nvo.nombre);

    if(!(strcmp(nvo.nombre, nombre) == 0 || dir2 == -1))
    {
        printf("\nNo se puede modificar porque ya existe uno con ese nombre");
        return;
    }

    // Contar PK actuales excluyendo el atributo que se va a modificar
    int pkActuales = 0;
    long cab = activa.atr;
    while(cab != -1)
    {
        Atributo aux = leeAtributo(cab);
        if(strcmp(aux.nombre, nombre) != 0 && (aux.iskp == 's' || aux.iskp == 'S'))
            pkActuales++;
        cab = aux.sig;
    }

    // Validar que quede exactamente una PK
    if(nvo.iskp == 's' || nvo.iskp == 'S')
    {
        if(pkActuales >= 1)
        {
            printf("\nError: ya existe una clave primaria. Solo se permite una.");
            return;
        }
    }
    

    dir3 = eliminaAtributo(nombre);
    reescribeAtributo(dir3, nvo);
    insertaAtributo(nvo, dir3);
    printf("\nAtributo modificado correctamente");
}

// ============================ BLOQUES / DATOS ============================

void CDiccionario::cargaAtributos()
{
    relacionAtributos.clear();
    nAtributos = 0;
    tambloque = sizeof(long);

    if(activa.atr == -1)
        return;

    long cab = activa.atr;
    int pkCount = 0;

    while(cab != -1)
    {
        Atributo aux = leeAtributo(cab);
        relacionAtributos.push_back(aux);

        if(aux.iskp == 's' || aux.iskp == 'S')
            pkCount++;

        cab = aux.sig;
    }

    if(pkCount != 1)
    {
        nAtributos = 0;
        tambloque = sizeof(long);
        return;
    }

    int pos = 0;

    // Primero la PK
    for(size_t i = 0; i < relacionAtributos.size(); i++)
    {
        if(relacionAtributos[i].iskp == 's' || relacionAtributos[i].iskp == 'S')
        {
            arrAtributos[pos++] = relacionAtributos[i];
            tambloque += relacionAtributos[i].tamano;
            break;
        }
    }

    // Luego los demás
    for(size_t i = 0; i < relacionAtributos.size(); i++)
    {
        if(!(relacionAtributos[i].iskp == 's' || relacionAtributos[i].iskp == 'S'))
        {
            arrAtributos[pos++] = relacionAtributos[i];
            tambloque += relacionAtributos[i].tamano;
        }
    }

    nAtributos = pos;
}

void *CDiccionario::capturaBloque()
{
    cargaAtributos();

    if(nAtributos == 0)
    {
        printf("\nError: la entidad debe tener exactamente una clave primaria.");
        return NULL;
    }

    void *bloque = malloc(tambloque);
    if(bloque == NULL)
        return NULL;

    memset(bloque, 0, tambloque);

    long desp = 0;
    *((long*)((char*)bloque + desp)) = -1;
    desp = sizeof(long);

    for(int i = 0; i < nAtributos; i++)
    {
        printf("\nIngrese el %s: ", arrAtributos[i].nombre);

        switch(arrAtributos[i].tipo)
        {
            case 1:
            {
                char texto[200];
                scanf(" %[^\n]", texto);
                strncpy((char*)bloque + desp, texto, arrAtributos[i].tamano);
                ((char*)bloque)[desp + arrAtributos[i].tamano - 1] = '\0';
                break;
            }

            case 2:
                scanf("%d", (int*)((char*)bloque + desp));
                break;

            case 3:
                scanf("%f", (float*)((char*)bloque + desp));
                break;

            case 4:
                scanf("%lf", (double*)((char*)bloque + desp));
                break;

            case 5:
                scanf("%ld", (long*)((char*)bloque + desp));
                break;

            default:
                printf("\nTipo no valido.");
                free(bloque);
                return NULL;
        }

        desp += arrAtributos[i].tamano;
    }

    return bloque;
}

int CDiccionario::comparaBloques(void *b1, void *b2)
{
    long desp = sizeof(long);   // se brinca el apuntador al siguiente bloque

    if(nAtributos == 0) // no hay atributos, entonces todos los bloques son iguales
        return 0;

    switch(arrAtributos[0].tipo) // se compara solo con base en la clave primaria, que es el primer atributo
    {
        case 1:
            return strcmp((char*)b1 + desp, (char*)b2 + desp);

        case 2:
            return *((int*)((char*)b1 + desp)) - *((int*)((char*)b2 + desp));

        case 3:
        {
            float x = *((float*)((char*)b1 + desp));
            float y = *((float*)((char*)b2 + desp));
            if(x < y) return -1;
            if(x > y) return 1;
            return 0;
        }

        case 4:
        {
            double x = *((double*)((char*)b1 + desp));
            double y = *((double*)((char*)b2 + desp));
            if(x < y) return -1;
            if(x > y) return 1;
            return 0;
        }

        case 5:
        {
            long x = *((long*)((char*)b1 + desp));
            long y = *((long*)((char*)b2 + desp));
            if(x < y) return -1;
            if(x > y) return 1;
            return 0;
        }
    }

    return 0;
}

long CDiccionario::buscaBloque(void *bloque)
{
    cargaAtributos();

    if(activa.data == -1)
        return -1;

    long cab = activa.data;

    while(cab != -1)
    {
        void *actual = leeBloque(cab);

        if(comparaBloques(bloque, actual) == 0)
        {
            free(actual);
            return cab;
        }

        cab = *((long*)((char*)actual + 0));
        free(actual);
    }

    return -1;
}

long CDiccionario::escribeBloque(void *bloque)
{
    long dir;
    fseek(archivo, 0, SEEK_END);
    dir = ftell(archivo);
    fwrite(bloque, tambloque, 1, archivo);
    return dir;
}

void CDiccionario::reescribeBloque(void *bloque, long dir)
{
    fseek(archivo, dir, SEEK_SET);
    fwrite(bloque, tambloque, 1, archivo);
}

void *CDiccionario::leeBloque(long dir)
{
    void *bloque = malloc(tambloque);
    if(bloque == NULL)
        return NULL;

    fseek(archivo, dir, SEEK_SET);
    fread(bloque, tambloque, 1, archivo);
    return bloque;
}

void CDiccionario::insertaBloque(void *nvo, long dirnvo)
{
    cargaAtributos();

    if(activa.data == -1) // no hay bloques, el nuevo bloque es el primero
    {
        activa.data = dirnvo;
        reescribeEntidad(diractiva, activa);
    }
    else // hay bloques, se inserta en orden
    {
        void *act = leeBloque(activa.data);

        if(comparaBloques(nvo, act) < 0) // se inserta antes del primero
        {
            *((long*)((char*)nvo + 0)) = activa.data;
            reescribeBloque(nvo, dirnvo);

            activa.data = dirnvo;
            reescribeEntidad(diractiva, activa);

            free(act);
        }
        else 
        {
            long cab = activa.data;

            while(cab != -1 && comparaBloques(nvo, act) > 0)
            {
                long dirant = cab;
                void *bloqueant = act;

                cab = *((long*)((char*)act + 0));

                if(cab != -1)
                    act = leeBloque(cab);
                else
                    act = NULL;

                if(cab == -1 || comparaBloques(nvo, act) < 0)
                {
                    *((long*)((char*)nvo + 0)) = cab;
                    reescribeBloque(nvo, dirnvo);

                    *((long*)((char*)bloqueant + 0)) = dirnvo;
                    reescribeBloque(bloqueant, dirant);

                    free(bloqueant);
                    if(act != NULL) free(act);
                    return;
                }

                free(bloqueant);
            }

            if(act != NULL)
                free(act);
        }
    }
}

long CDiccionario::eliminaBloque(void *bloque)
{
    cargaAtributos();

    long cab = activa.data;
    long dirant = -1;

    if(cab == -1)
        return -1;

    void *actual = leeBloque(cab);

    if(comparaBloques(bloque, actual) == 0)
    {
        activa.data = *((long*)((char*)actual + 0));
        reescribeEntidad(diractiva, activa);
        free(actual);
        return cab;
    }

    while(cab != -1 && comparaBloques(bloque, actual) != 0)
    {
        dirant = cab;
        void *ant = actual;

        cab = *((long*)((char*)actual + 0));

        if(cab != -1)
            actual = leeBloque(cab);
        else
            actual = NULL;

        if(cab != -1 && comparaBloques(bloque, actual) == 0)
        {
            *((long*)((char*)ant + 0)) = *((long*)((char*)actual + 0));
            reescribeBloque(ant, dirant);

            free(ant);
            free(actual);
            return cab;
        }

        free(ant);
    }

    if(actual != NULL)
        free(actual);

    return -1;
}

void CDiccionario::modificaBloque()
{
    cargaAtributos();

    if(nAtributos == 0)
    {
        printf("\nLa entidad no tiene atributos.");
        return;
    }

    if(activa.data == -1)
    {
        printf("\nNo hay bloques registrados.");
        return;
    }

    void *criterio = malloc(tambloque);
    if(criterio == NULL)
        return;

    memset(criterio, 0, tambloque);
    *((long*)((char*)criterio + 0)) = -1;

    long desp = sizeof(long);

    printf("\nIngrese el valor actual de %s: ", arrAtributos[0].nombre);

    switch(arrAtributos[0].tipo)
    {
        case 1:
        {
            char texto[200];
            scanf(" %[^\n]", texto);
            strncpy((char*)criterio + desp, texto, arrAtributos[0].tamano);
            ((char*)criterio)[desp + arrAtributos[0].tamano - 1] = '\0';
            break;
        }

        case 2:
            scanf("%d", (int*)((char*)criterio + desp));
            break;

        case 3:
            scanf("%f", (float*)((char*)criterio + desp));
            break;

        case 4:
            scanf("%lf", (double*)((char*)criterio + desp));
            break;

        case 5:
            scanf("%ld", (long*)((char*)criterio + desp));
            break;

        default:
            printf("\nTipo invalido.");
            free(criterio);
            return;
    }

    long dirOriginal = buscaBloque(criterio);

    if(dirOriginal == -1)
    {
        printf("\nNo existe el bloque.");
        free(criterio);
        return;
    }

    printf("\nIngrese la nueva informacion:");
    void *nuevo = capturaBloque();

    if(nuevo == NULL)
    {
        free(criterio);
        return;
    }

    long dirDuplicado = buscaBloque(nuevo);

    if(comparaBloques(criterio, nuevo) == 0 || dirDuplicado == -1)
    {
        long dir = eliminaBloque(criterio);
        reescribeBloque(nuevo, dir);
        insertaBloque(nuevo, dir);
        printf("\nBloque modificado correctamente.");
    }
    else
    {
        printf("\nNo se puede modificar porque ya existe un bloque con esa clave.");
    }

    free(criterio);
    free(nuevo);
}

void CDiccionario::altaBloque()
{
    void *nuevo = capturaBloque();
    long dir;

    if(nuevo == NULL)
        return;

    if(buscaBloque(nuevo) == -1)
    {
        dir = escribeBloque(nuevo);
        insertaBloque(nuevo, dir);
        printf("\nBloque insertado correctamente.");
    }
    else
    {
        printf("\nEl bloque ya existe.");
    }

    free(nuevo);
}

void CDiccionario::consultaBloques()
{
    cargaAtributos();

    if(nAtributos == 0)
    {
        printf("\nError: la entidad debe tener exactamente una clave primaria.\n");
        return;
    }

    printf("\n%-14s", "Ap.Siguiente");
    for(int i = 0; i < nAtributos; i++)
        printf("%-14s", arrAtributos[i].nombre);
    printf("\n");

    long cab = activa.data;

    if(cab == -1)
    {
        printf("\nNo hay bloques registrados.\n");
        return;
    }

    while(cab != -1)
    {
        void *bloque = leeBloque(cab);

        printf("%-14ld", *((long*)((char*)bloque + 0)));

        long desp = sizeof(long);

        for(int i = 0; i < nAtributos; i++)
        {
            switch(arrAtributos[i].tipo)
            {
                case 1:
                    printf("%-14s", (char*)bloque + desp);
                    break;
                case 2:
                    printf("%-14d", *((int*)((char*)bloque + desp)));
                    break;
                case 3:
                    printf("%-14.2f", *((float*)((char*)bloque + desp)));
                    break;
                case 4:
                    printf("%-14.2lf", *((double*)((char*)bloque + desp)));
                    break;
                case 5:
                    printf("%-14ld", *((long*)((char*)bloque + desp)));
                    break;
            }

            desp += arrAtributos[i].tamano;
        }

        printf("\n");
        cab = *((long*)((char*)bloque + 0));
        free(bloque);
    }
}

// ============================ MENU DATOS ============================

void CDiccionario::menuDatos()
{
    if (!pideEntidad()) return;

    int op;
    do
    {
        printf("\n1.Nuevo 2.Consultar 3.Eliminar 4.Modificar 5.Regresar\n");
        scanf("%d", &op);

        switch(op)
        {
            case 1: nuevoRegistro(); break;
            case 2: consultarRegistro(); break;
            case 3: eliminaRegistro(); break;
            case 4: modificaRegistro(); break;
            case 5: printf("\nRegresando..."); break;
            default: printf("\nOpcion no valida");
        }

    } while(op != 5);
}

// ============================ COMPATIBILIDAD MENU ============================

void CDiccionario::nuevoRegistro()
{
    altaBloque();
}

void CDiccionario::consultarRegistro()
{
    consultaBloques();
}

void CDiccionario::eliminaRegistro()
{
    cargaAtributos();

    if(nAtributos == 0)
    {
        printf("\nLa entidad no tiene atributos.");
        return;
    }

    if(activa.data == -1)
    {
        printf("\nNo hay bloques registrados.");
        return;
    }

    void *criterio = malloc(tambloque);
    if(criterio == NULL)
        return;

    memset(criterio, 0, tambloque);
    *((long*)((char*)criterio + 0)) = -1;

    long desp = sizeof(long);

    printf("\nIngrese el valor de %s del bloque a eliminar: ", arrAtributos[0].nombre);

    switch(arrAtributos[0].tipo)
    {
        case 1:
        {
            char texto[200];
            scanf(" %[^\n]", texto);
            strncpy((char*)criterio + desp, texto, arrAtributos[0].tamano);
            ((char*)criterio)[desp + arrAtributos[0].tamano - 1] = '\0';
            break;
        }

        case 2:
            scanf("%d", (int*)((char*)criterio + desp));
            break;

        case 3:
            scanf("%f", (float*)((char*)criterio + desp));
            break;

        case 4:
            scanf("%lf", (double*)((char*)criterio + desp));
            break;

        case 5:
            scanf("%ld", (long*)((char*)criterio + desp));
            break;
    }

    if(eliminaBloque(criterio) == -1)
        printf("\nNo existe el bloque.");
    else
        printf("\nBloque eliminado correctamente.");

    free(criterio);
}

void CDiccionario::modificaRegistro()
{
    modificaBloque();
}

