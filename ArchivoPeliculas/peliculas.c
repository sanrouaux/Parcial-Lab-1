#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "peliculas.h"
#include "validaciones.h"

/** \brief
 *
 * \param listaPeliculas[] ePelicula
 * \param tamanoPeliculas int
 * \return int
 *
 */
int inicializaListaPeliculas(ePelicula listaPeliculas[], int tamanoPeliculas)
{
    int i;
    for(i=0; i<tamanoPeliculas; i++)
    {
        listaPeliculas[i].estado= LIBRE;
        listaPeliculas[i].id = 0;
    }

    return 0;
}


/** \brief
 *
 * \param listaPeliculas[] ePelicula
 * \return int
 *
 */
int cargaInicialPeliculas(ePelicula listaPeliculas[])
{

    char titulos[4][50] = {"La pistola desnuda", "Hulk", "Volver al futuro", "Jurassic Park"};
    int anios[4] = {1987, 2008, 1985, 2000};
    char nacionalidades [4][50]= {"EEUU", "EEUU", "EEUU", "EEUU"};
    int directores[4] = {1,2,3,4};

    int i;
    for(i = 0; i < 4; i++)
    {
        strcpy(listaPeliculas[i].titulo, titulos[i]);
        listaPeliculas[i].anio = anios[i];
        strcpy(listaPeliculas[i].nacionalidad, nacionalidades[i]);
        listaPeliculas[i].director = directores[i];
        listaPeliculas[i].id = i+1;
        listaPeliculas[i].estado = OCUPADO;
    }
    return 0;
}


/** \brief
 *
 * \param listaPeliculas[] ePelicula
 * \param tamanoPeliculas int
 * \return int
 *
 */
int buscaLugarLibrePelicula(ePelicula listaPeliculas[],int tamanoPeliculas)
{
    int indiceLibre = -1;

    if(listaPeliculas != NULL && tamanoPeliculas > 0)
    {
        int i;
        for(i = 0; i < tamanoPeliculas; i++)
        {
            if(listaPeliculas[i].estado == LIBRE)
            {
                indiceLibre = i;
                break;
            }
        }
    }
    return indiceLibre;
}


/** \brief
 *
 * \param listaPeliculas[] ePelicula
 * \param tamanoPeliculas int
 * \return int
 *
 */
int buscaIdSiguientePelicula(ePelicula listaPeliculas[],int tamanoPeliculas)
{
    int bandera = 0;
    int retorno;
    int i;
    for(i = 0; i < tamanoPeliculas; i++)
    {
        if(listaPeliculas[i].estado == OCUPADO)
        {
            if(bandera==0)
            {
                retorno = listaPeliculas[i].id;
                bandera=1;
            }

            if(listaPeliculas[i].id > retorno)
            {
                retorno = listaPeliculas[i].id;
            }
        }
    }
    return retorno + 1;
}


/** \brief
 *
 * \param listaPeliculas[] ePelicula
 * \param indice int
 * \return int
 *
 */
int pelicula_ingresaTitulo(ePelicula listaPeliculas[], int indice)
{
    char buffer[1024];
    ingresaCadenaSoloLetras(buffer, "Ingrese titulo: ", 100);
    strcpy(listaPeliculas[indice].titulo, buffer);
    return 0;
}

/** \brief
 *
 * \param listaPeliculas[] ePelicula
 * \param indice int
 * \return int
 *
 */
int pelicula_ingresaAnio(ePelicula listaPeliculas[], int indice)
{
    int anio;
    puts("Ingrese anio: ");
    fflush(stdin);
    scanf("%d", &anio);
    anio = validaRango(anio, 2100, 1800);
    listaPeliculas[indice].anio = anio;
    return 0;
}

/** \brief
 *
 * \param listaPeliculas[] ePelicula
 * \param indice int
 * \return int
 *
 */
int pelicula_ingresaNacionalidad(ePelicula listaPeliculas[], int indice)
{
    char buffer[1024];
    ingresaCadenaSoloLetras(buffer, "Ingrese nacionalidad de la pelicula", 50);
    strcpy(listaPeliculas[indice].nacionalidad, buffer);
    return 0;
}

/** \brief
 *
 * \param listaPeliculas[] ePelicula
 * \param indice int
 * \return int
 *
 */
int pelicula_ingresaIdDirector()
{
    int id;
    puts("Ingrese ID del director: ");
    fflush(stdin);
    scanf("%d", &id);
    return id;
}

/** \brief
 *
 * \param lista[] ePelicula
 * \param tamano int
 * \param indice int
 * \return int
 *
 */
int pelicula_cargaId(ePelicula lista[], int tamano, int indice)
{
    lista[indice].id = buscaIdSiguientePelicula(lista, tamano);
    return 1;
}

/** \brief
 *
 * \param parametro ePelicula
 * \return int
 *
 */
int mostrarUnaPelicula(ePelicula parametro)
{
    printf("%d - %s - %d - %s - %d \n",parametro.id, parametro.titulo,parametro.anio, parametro.nacionalidad, parametro.director);
    return 0;
}

/** \brief
 *
 * \param listaPeliculas[] ePelicula
 * \param tamanoPeliculas int
 * \return int
 *
 */
int mostrarListaPeliculas(ePelicula listaPeliculas[],int tamanoPeliculas)
{
    puts("\n---------LISTADO DE PELICULAS-------------\n");
    puts("ID - TITULO - ANIO - NACIONALIDAD - DIRECTOR\n");

    int i;
    for(i=0; i<tamanoPeliculas; i++)
    {
        if(listaPeliculas[i].estado==OCUPADO)
        {
            mostrarUnaPelicula(listaPeliculas[i]);
        }
    }
    return 0;
}


/** \brief
 *
 * \return int
 *
 */
int pideIdUsuario()
{
    int id;
    puts("\nIngrese el ID de la pelicula: ");
    fflush(stdin);
    scanf("%d", &id);
    return id;
}


/** \brief
 *
 * \param listaPeliculas[] ePelicula
 * \param tamanoPeliculas int
 * \param id int
 * \return int
 *
 */
int buscaPorIdDevuelveIndice(ePelicula listaPeliculas[],int tamanoPeliculas, int id)
{
    int indice = -1;

    int i;
    for(i = 0; i < tamanoPeliculas; i++)
    {
        if(listaPeliculas[i].estado == OCUPADO && listaPeliculas[i].id == id)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

/** \brief
 *
 * \param listaPeliculas[] ePelicula
 * \param indice int
 * \return int
 *
 */
char compruebaPeliculaEncontrada(ePelicula listaPeliculas[], int indice)
{
    char confirma = 'n';
    printf("Se encontro la pelicula: %s\n", listaPeliculas[indice].titulo);
    puts("Es correcto? s/n");
    confirma = pideYValidaSiNo();

    return confirma;
}


/** \brief
 *
 * \param listaPeliculas[] ePelicula
 * \param tamanoPeliculas int
 * \return int
 *
 */
int peliculasMasViejas(ePelicula listaPeliculas[], int tamanoPeliculas)
{
    int anioMenor;
    int bandera = 0;
    int i;
    for(i = 0; i < tamanoPeliculas; i++)
    {
        if(listaPeliculas[i].estado==OCUPADO && bandera==0)
        {
            anioMenor = listaPeliculas[i].anio;
            bandera = 1;
        }

        if(listaPeliculas[i].estado == OCUPADO && listaPeliculas[i].anio < anioMenor)
        {
            anioMenor = listaPeliculas[i].anio;
        }
    }

    for(i = 0; i < tamanoPeliculas ; i++)
    {
        if(listaPeliculas[i].estado == OCUPADO && listaPeliculas[i].anio == anioMenor)
        {
            mostrarUnaPelicula(listaPeliculas[i]);
        }
    }
    return 0;
}


/** \brief
 *
 * \param listaPeliculas[] ePelicula
 * \param idDirector int
 * \param tamanoPeliculas int
 * \return int
 *
 */
int buscaPeliculaPorIdDirectorEImprime(ePelicula listaPeliculas[], int idDirector, int tamanoPeliculas)
{
    int bandera = 0;
    int i;
    for(i = 0; i < tamanoPeliculas; i++)
    {
        if(listaPeliculas[i].estado == OCUPADO && listaPeliculas[i].director == idDirector)
        {
            printf("%d- %s\n", i+1, listaPeliculas[i].titulo);
            bandera = 1;
        }
    }
    if(bandera==0)
    {
        puts("\nNO HAY PELICULAS PARA MOSTRAR\n");
    }
    return 0;
}


/** \brief
 *
 * \param listaPeliculas[] ePelicula
 * \param idDirector int
 * \param tamanoPeliculas int
 * \return int
 *
 */
int buscaPeliculaPorIdDirectorYBorra(ePelicula listaPeliculas[], int idDirector, int tamanoPeliculas)
{
    int i;
    for(i=0; i<tamanoPeliculas; i++)
    {
        if(listaPeliculas[i].estado == OCUPADO && listaPeliculas[i].director == idDirector)
        {
            listaPeliculas[i].estado = LIBRE;
        }
    }
    return 0;
}


/** \brief
 *
 * \param listaPeliculas[] ePelicula
 * \param idDirector int
 * \param tamanoPeliculas int
 * \return int
 *
 */
int cuentaNumeroPeliculas(ePelicula listaPeliculas[], int idDirector, int tamanoPeliculas)
{
    int contador = 0;
    int i;
    for(i = 0; i < tamanoPeliculas; i++)
    {
        if(listaPeliculas[i].estado == OCUPADO && listaPeliculas[i].director == idDirector)
        {
            contador++;
        }
    }
    return contador;
}


/** \brief
 *
 * \param listaPeliculas[] ePelicula
 * \param indice int
 * \return int
 *
 */
int buscaDirectorPorIndicePelicula(ePelicula listaPeliculas[], int indice)
{
    int idDirector;
    idDirector = listaPeliculas[indice].director;
    return idDirector;
}


/** \brief
 *
 * \param pelicula ePelicula
 * \return int
 *
 */
int imprimeTituloPelicula(ePelicula pelicula)
{
    printf("%-20s", pelicula.titulo);
    return 0;
}
