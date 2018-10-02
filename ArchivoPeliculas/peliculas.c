#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "peliculas.h"



int inicializaLista(ePelicula lista[], int tamano)
{
    int i;
    for(i=0; i<tamano; i++)
    {
        lista[i].estado= LIBRE;
        lista[i].id = 0;
    }

    return 0;
}



int buscaLugarLibre(ePelicula lista[],int tamano)
{
    int retorno;
    int i;
    for(i=0; i<tamano; i++)
    {
        if(lista[i].estado == LIBRE)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}


int buscaIdSiguiente(ePelicula lista[],int tamano)
{
    int retorno = -1;
    int i;
    for(i=0; i<tamano; i++)
    {
        if(lista[i].estado == OCUPADO)
        {
            if(lista[i].id>retorno)
            {
                retorno=lista[i].id;
            }
        }
    }
    return retorno+1;
}


int altaPelicula(ePelicula lista[],int tamano)
{
    int indice;
    indice = buscaLugarLibre(lista, tamano);

    int id;
    id = buscaIdSiguiente(lista,tamano);


    if(indice < tamano)
    {
        puts("Ingrese titulo: ");
        fflush(stdin);
        gets(lista[indice].titulo);
        while(strlen(lista[indice].titulo) >= 100)
        {
            puts("Nombre demasiado largo. Ingrese otro: ");
            fflush(stdin);
            gets(lista[indice].titulo);
        }

        puts("Ingrese anio: ");
        fflush(stdin);
        scanf("%d", &lista[indice].anio);
        while(lista[indice].anio < 0 || lista[indice].anio > 2300)
        {
            puts("Anio fuera de rango. Ingrese otro: ");
            fflush(stdin);
            gets(lista[indice].anio);
        }

        puts("Ingrese nacionalidad");
        fflush(stdin);
        gets(lista[indice].nacionalidad);
        while(strlen(lista[indice].nacionalidad) >= 50)
        {
            puts("Nombre demasiado largo. Ingrese otro: ");
            fflush(stdin);
            gets(lista[indice].nacionalidad);
        }

        puts("Ingrese ID director: ");
        fflush(stdin);
        scanf("%d", &lista[indice].director);


        lista[indice].id = id;
        lista[indice].estado = OCUPADO;
    }
    else
    {
        puts("No hay mas espacio");
    }

    return 0;
}

int mostrarUno(ePelicula parametro)
{
    printf("\n%s - %d - %s - %d \n",parametro.titulo,parametro.anio,parametro.nacionalidad,parametro.director);
    return 0;
}

int mostrarLista(ePelicula lista[],int tamano)
{
    int i;
    for(i=0; i<tamano; i++)
    {
        if(lista[i].estado==OCUPADO)
        {
            mostrarUno(lista[i]);
        }
    }
    return 0;
}


int menuOpciones()
{
    int opcion;

    puts("1. Alta");
    puts("2. Modificar");
    puts("3. Baja");
    puts("4. ");
    puts("5. ");
    puts("6. Mostrar");
    puts("Ingrese una opcion");

    scanf("%d", &opcion);
    return opcion;
}


int buscarPorId(ePelicula lista[],int tamano)
{
    int retorno = -1;
    char comprobacion;

    int id;
    puts("Ingrese ID: ");
    scanf("%d", &id);

    int i;
    for(i=0; i<tamano; i++)
    {
        if(lista[i].estado == OCUPADO && lista[i].id == id)
        {
            retorno = i;
            break;
        }
    }

    return retorno;
}


int baja(ePelicula lista[], int tamano)
{
    int indice;
    indice = buscarPorId(lista, tamano);

    if(indice >= 0)
    {
        lista[indice].estado = LIBRE;
    }
    else
    {
        puts("No se encontro el ID");
    }

    return 0;
}


int modificacion(ePelicula lista[],int tamano)
{
    int opcion;
    int indice;
    indice = buscarPorId(lista, tamano);

    if(indice >= 0)
    {
        puts("\nQue dato desea modificar?");
        puts("1. Titulo");
        puts("2. Anio");
        puts("3. Nacionalidad");
        puts("4. Director");
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1:
            puts("Introduzca nuevo titulo: ");
            fflush(stdin);
            gets(lista[indice].titulo);
            break;

        case 2:
            puts("Introduzca nuevo anio: ");
            fflush(stdin);
            scanf("%d", &lista[indice].anio);
            break;

        case 3:
            puts("Introduzca nueva nacionalidad: ");
            fflush(stdin);
            gets(lista[indice].nacionalidad);
            break;

        case 4:
            puts("Introduzca nuevo director: ");
            fflush(stdin);
            scanf("%d", &lista[indice].director);
            break;

        }
    }
    else
    {
        puts("No se encontro el ID");
    }

    return 0;
}



int cargaDatos(ePelicula lista[],int tamano)
{

    char titulos[2][50] = {"La pistola desnuda", "norteamericana"};
    int anios[2] = {1987, 2000};
    char nacionalidades [2][50]= {"norteamericana", "norteamericana"};
    int directores[2
    ] = {3,5};

    int i;
    for(i = 0; i < tamano; i++)
    {
        strcpy(lista[i].titulo, titulos[i]);
        lista[i]. anio = anios[i];
        strcpy(lista[i].nacionalidad, nacionalidades[i]);
        lista[i].director = directores[i];
        lista[i].id = i+1;
        lista[i].estado = OCUPADO;
    }
    return 0;
}
