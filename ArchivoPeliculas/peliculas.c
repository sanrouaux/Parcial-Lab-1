#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "peliculas.h"
#include "directores.h"


int inicializaListaPeliculas(ePelicula lista[], int tamano)
{
    int i;
    for(i=0; i<tamano; i++)
    {
        lista[i].estado= LIBRE;
        lista[i].id = 0;
    }

    return 0;
}


int buscaLugarLibrePelicula(ePelicula lista[],int tamano)
{
    int retorno = -1;
    int i;
    for(i = 0; i < tamano; i++)
    {
        if(lista[i].estado == LIBRE)
        {
            retorno = i;
            break;
        }
    }
    return retorno;
}


int buscaIdSiguientePelicula(ePelicula lista[],int tamano)
{
    int retorno;
    int i;
    for(i = 0; i < tamano; i++)
    {
        if(lista[i].estado == OCUPADO)
        {
            if(lista[i].id > retorno)
            {
                retorno = lista[i].id;
            }
        }
    }
    return retorno + 1;
}


int altaPelicula(ePelicula lista[], int tamano)
{
    int indice;
    indice = buscaLugarLibrePelicula(lista, tamano);

    int id;
    id = buscaIdSiguientePelicula(lista,tamano);


    if(indice >= 0)
    {
        char buffer[1024];

        puts("Ingrese titulo: ");
        fflush(stdin);
        gets(buffer);
        validaLargoCadena(buffer, 100);
        strcpy(lista[indice].titulo, buffer);

        puts("Ingrese anio: ");
        fflush(stdin);
        scanf("%d", &lista[indice].anio);
        lista[indice].anio = validaRango(lista[indice].anio, 2100, 1800);

        puts("Ingrese nacionalidad: ");
        fflush(stdin);
        gets(buffer);
        validaLargoCadena(buffer, 50);
        strcpy(lista[indice].nacionalidad, buffer);

        puts("Ingrese ID director: ");
        fflush(stdin);
        scanf("%d", &lista[indice].director);
        lista[indice].director = validaRango(lista[indice].director, 500, 1);

        lista[indice].id = id;
        lista[indice].estado = OCUPADO;
    }
    else
    {
        puts("No hay mas espacio");
    }

    return indice;
}


int mostrarUno(ePelicula parametro)
{
    printf("%d - %s - %d - %s - %d \n",parametro.id, parametro.titulo,parametro.anio,
           parametro.nacionalidad,parametro.director);
    return 0;
}

int mostrarLista(ePelicula lista[],int tamano)
{
    puts("\n---------LISTADO DE PELICULAS-------------\n");
    puts("ID - TITULO - ANIO - NACIONALIDAD - DIRECTOR\n");

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
    puts("4. Nuevo director");
    puts("5. Eliminar director");
    puts("6. Mostrar");
    puts("7. Salir");
    puts("Ingrese una opcion: ");

    scanf("%d", &opcion);
    return opcion;
}

char menuListado()
{
    char opcion;

    puts("a. Peliculas");
    puts("b. Directores");
    puts("c. Pelicula/as mas vieja/as");
    puts("d. Peliculas con su director");
    puts("e. Peliculas por director");
    puts("f. Numero de peliculas dirigidas");
    fflush(stdin);
    opcion = getchar();
    return opcion;
}

int buscarPorId(ePelicula lista[],int tamano)
{
    int indice = -1;

    int id;
    puts("\nIngrese el ID de la pelicula que desea modificar: ");
    scanf("%d", &id);

    int i;
    for(i = 0; i < tamano; i++)
    {
        if(lista[i].estado == OCUPADO && lista[i].id == id)
        {
            indice = i;
            break;
        }
    }


    if(indice >= 0)
    {
        char comprobacion;
        printf("Se encontro la pelicula: %s\n", lista[indice].titulo);
        puts("Es correcto? s/n");
        comprobacion = pideYValidaSiNo();

        if(comprobacion == 'n')
        {
            indice = -2;
        }
    }
    return indice;
}


int bajaPelicula(ePelicula lista[], int tamano)
{
    mostrarLista(lista, tamano);

    int indice;
    indice = buscarPorId(lista, tamano);

    if(indice >= 0)
    {
        char comprobacion;
        printf("Se borrara la pelicula: %s. Desea continuar? s/n\n", lista[indice].titulo);
        comprobacion = pideYValidaSiNo();
        if(comprobacion == 's')
        {
            lista[indice].estado = LIBRE;
            puts("Se dio de baja la pelicula seleccionada");
        }
        else
        {
            puts("Accion cancelada");
        }
    }
    else if(indice == -1)
    {
        puts("No se encontro el ID");
    }

    return 0;
}


int modificacion(ePelicula lista[],int tamano)
{
    mostrarLista(lista, tamano);

    int indice;
    indice = buscarPorId(lista, tamano);

    if(indice >= 0)
    {
        int opcion;
        puts("\nQue dato desea modificar?");
        puts("1. Titulo");
        puts("2. Anio");
        puts("3. Nacionalidad");
        puts("4. Director");
        puts("5. Cancelar");
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1:
            puts("Introduzca nuevo titulo: ");
            fflush(stdin);
            gets(lista[indice].titulo);
            printf("Se modifico el titulo de la pelicula cuyo ID es: %d", lista[indice].id);
            break;

        case 2:
            puts("Introduzca nuevo anio: ");
            fflush(stdin);
            scanf("%d", &lista[indice].anio);
            printf("Se modifico el anio de la pelicula cuyo ID es: %d", lista[indice].id);
            break;

        case 3:
            puts("Introduzca nueva nacionalidad: ");
            fflush(stdin);
            gets(lista[indice].nacionalidad);
            printf("Se modifico la nacionalidad de la pelicula cuyo ID es: %d", lista[indice].id);
            break;

        case 4:
            puts("Introduzca nuevo director: ");
            fflush(stdin);
            scanf("%d", &lista[indice].director);
            printf("Se modifico el director de la pelicula cuyo ID es: %d", lista[indice].id);
            break;

        case 5:
            break;

        default:
            puts("No ingreso una opcion valida");

        }
    }
    else if(indice == -1)
    {
        puts("No se encontro el ID");
    }

    return 0;
}



int cargaInicialPeliculas(ePelicula lista[])
{

    char titulos[4][50] = {"La pistola desnuda", "Hulk", "Volver al futuro", "Jurassic Park"};
    int anios[4] = {1987, 2008, 1985, 2000};
    char nacionalidades [4][50]= {"EEUU", "EEUU", "EEUU", "EEUU"};
    int directores[4] = {1,2,3,4};

    int i;
    for(i = 0; i < 4; i++)
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




int validaLargoCadena(char cadena[], int largo)
{
    while(strlen(cadena) >= largo)
    {
        puts("Nombre demasiado largo. Ingrese otro: ");
        fflush(stdin);
        gets(cadena);
    }
    return 0;
}


int validaRango(int numero, int max, int min)
{
    while(numero < min || numero > max)
    {
        puts("Fuera de rango. Ingrese nuevamente: ");
        fflush(stdin);
        scanf("%d", &numero);
    }
    return numero;
}


char pideYValidaSiNo()
{
    char letra;
    fflush(stdin);
    letra = getchar();

    while(letra != 's' && letra != 'n')
    {
        puts("Ingrese una opcion correcta: s/n");
        letra = getchar();
    }
    return letra;
}


int peliculasMasViejas(ePelicula lista[], int tamano)
{
    int anioMenor = 3000;
    int i;
    for(i = 0; i < tamano; i++)
    {
        if(lista[i].estado == OCUPADO && lista[i].anio < anioMenor)
        {
            anioMenor = lista[i].anio;
        }
    }

    for(i = 0; i < tamano ; i++)
    {
        if(lista[i].estado == OCUPADO && lista[i].anio == anioMenor)
        {
            mostrarUno(lista[i]);
        }
    }
    return 0;
}

int buscaPeliculaPorDirectorEImprime(ePelicula lista[], int idDirector, int tamano)
{
    int bandera = 0;
    int i;
    for(i = 0; i < tamano; i++)
    {
        if(lista[i].estado == OCUPADO && lista[i].director == idDirector)
        {
            printf("%s \n", lista[i].titulo);
            bandera = 1;
        }
    }
    if(bandera==0)
    {
        puts("No hay peliculas que mostrar");
    }
    return 0;
}


int cuentaNumeroPeliculas(ePelicula lista[], int idDirector, int tamano)
{
    int contador = 0;
    int i;
    for(i = 0; i < tamano; i++)
    {
        if(lista[i].estado == OCUPADO && lista[i].director == idDirector)
        {
            contador++;
        }
    }
    return contador;
}


int buscaDirectorPorIndicePelicula(ePelicula lista[], int indice)
{
    int idDirector;
    idDirector = lista[indice].director;
    return idDirector;
}


