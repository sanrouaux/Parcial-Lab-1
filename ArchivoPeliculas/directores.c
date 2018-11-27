#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "directores.h"
#include "validaciones.h"




/** \brief
 *
 * \param lista[] eDirector
 * \param tamano int
 * \return int
 *
 */
int inicializaListaDirectores(eDirector lista[], int tamano)
{
    int i;
    for(i = 0; i < tamano; i++)
    {
        lista[i].estado= LIBRE;
        lista[i].id = 0;
    }
    return 0;
}


/** \brief
 *
 * \param lista[] eDirector
 * \return int
 *
 */
int cargaInicialDirectores(eDirector lista[])
{

    char nombres[4][100] = {"Martin Scorcese", "David Lynch", "Pedro Rodriguez", "Juan Perez"};
    char paises[4][50] = {"EEUU", "EEUU", "Argentina", "Francia"};
    int dias [4] = {2,5,7,23};
    int meses[4] = {12,5, 11,2};
    int anios[4] = {1960, 1954, 1980, 1976};

    int i;
    for(i = 0; i < 4; i++)
    {
        strcpy(lista[i].nombre, nombres[i]);
        strcpy(lista[i].pais, paises[i]);
        lista[i].nacimiento.dia = dias[i];
        lista[i].nacimiento.mes = meses[i];
        lista[i].nacimiento.anio = anios[i];
        lista[i].id = i+1;
        lista[i].estado = OCUPADO;
    }
    return 0;
}



/** \brief
 *
 * \param lista[] eDirector
 * \param tamano int
 * \return int
 *
 */
int buscaLugarLibreDirector(eDirector lista[],int tamano)
{
    int indice = -1;
    int i;
    for(i = 0; i < tamano; i++)
    {
        if(lista[i].estado == LIBRE)
        {
            indice = i;
            break;
        }
    }
    return indice;
}


/** \brief
 *
 * \param lista[] eDirector
 * \param tamano int
 * \return int
 *
 */
int buscaIdSiguienteDirector(eDirector lista[],int tamano)
{
    int id_mayor;
    int bandera = 0;
    int i;
    for(i = 0; i < tamano; i++)
    {
        if(lista[i].estado == OCUPADO)
        {
            if(bandera == 0)
            {
                id_mayor = lista[i].id;
                bandera = 1;
            }

            if(lista[i].id > id_mayor)
            {
                id_mayor = lista[i].id;
            }
        }
    }
    return id_mayor + 1;
}


/** \brief
 *
 * \param listaPeliculas[] ePelicula
 * \param indice int
 * \return int
 *
 */
int director_ingresaNombre(eDirector lista[], int indice)
{
    char auxNombre[100];
    ingresaCadenaSoloLetras(auxNombre, "Ingrese el nombre del director", 100);
    strcpy(lista[indice].nombre, auxNombre);
    return 0;
}


/** \brief
 *
 * \param listaPeliculas[] ePelicula
 * \param indice int
 * \return int
 *
 */
int director_ingresaFechaNacimiento(eDirector lista[], int indice)
{
    puts("Ingrese dia de nacimiento: ");
    fflush(stdin);
    scanf("%d", &lista[indice].nacimiento.dia);
    lista[indice].nacimiento.dia = validaRango(lista[indice].nacimiento.dia, 31, 1);
    puts("Ingrese mes de nacimiento: ");
    fflush(stdin);
    scanf("%d", &lista[indice].nacimiento.mes);
    lista[indice].nacimiento.mes = validaRango(lista[indice].nacimiento.mes, 12, 1);
    puts("Ingrese anio de nacimiento: ");
    fflush(stdin);
    scanf("%d", &lista[indice].nacimiento.anio);
    lista[indice].nacimiento.anio = validaRango(lista[indice].nacimiento.anio, 2018, 1900);
    return 0;
}


/** \brief
 *
 * \param listaPeliculas[] ePelicula
 * \param indice int
 * \return int
 *
 */
int director_ingresaPais(eDirector lista[], int indice)
{
    char buffer[1024];
    ingresaCadenaSoloLetras(buffer, "Ingrese pais de origen: ", 50);
    strcpy(lista[indice].pais, buffer);
    return 0;
}


/** \brief
 *
 * \param lista[] eDirector
 * \param tamano int
 * \param indice int
 * \return int
 *
 */
int director_cargaId(eDirector lista[], int tamano, int indice)
{
    int retorno = -1;
    if(lista != NULL && tamano > 0)
    {
        retorno = 1;
        lista[indice].id = buscaIdSiguienteDirector(lista, tamano);
    }
    return retorno;
}

/** \brief
 *
 * \param lista[] eDirector
 * \param nombre[] char
 * \param tamano int
 * \return int
 *
 */
int validaNuevoDirector(eDirector lista[], int indice, int tamano)
{
    int retorno = 1;
    int i;
    for(i = 0; i < tamano; i++)
    {
        if(lista[i].estado == OCUPADO && stricmp(lista[indice].nombre, lista[i].nombre)==0)
        {
            retorno = 0;
            break;
        }
    }
    return retorno;
}


/** \brief
 *
 * \param lista[] eDirector
 * \param nombre[] char
 * \param tamano int
 * \return int
 *
 */
int buscaDirectorPorNombreDevuelveIndice(eDirector lista[], int tamano)
{
    int indice = -1;

    char nombre[1024];
    puts("Ingrese el nombre del director: ");
    gets(nombre);

    int i;
    for(i = 0; i < tamano; i++)
    {
        if(stricmp(lista[i].nombre, nombre)==0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

/** \brief
 *
 * \param lista[] eDirector
 * \param nombre[] char
 * \param tamano int
 * \return int
 *
 */
int buscaDirectorPorNombreDevuelveID(eDirector lista[], int tamano)
{
    int id = -1;

    char nombre[100];
    ingresaCadenaSoloLetras(nombre, "Introduzca el nombre del director:", 100);

    int i;
    for(i = 0; i < tamano; i++)
    {
        if(stricmp(lista[i].nombre, nombre)==0)
        {
            id = lista[i].id;
            break;
        }
    }
    return id;
}

/** \brief
 *
 * \param parametro eDirector
 * \return int
 *
 */
int mostrarUnDirector(eDirector parametro)
{
    printf("%d - %s - %d-%d-%d - %s \n",parametro.id, parametro.nombre, parametro.nacimiento.dia, parametro.nacimiento.mes,
           parametro.nacimiento.anio, parametro.pais);
    return 0;
}

/** \brief
 *
 * \param lista[] eDirector
 * \param tamano int
 * \return int
 *
 */
int mostrarListaDirectores(eDirector lista[],int tamano)
{
    puts("\n---------LISTADO DE DIRECTORES-------------\n");
    puts("ID - NOMBRE - FECHA DE NACIMIENTO - PAIS\n");

    int i;
    for(i = 0; i < tamano; i++)
    {
        if(lista[i].estado==OCUPADO)
        {
            mostrarUnDirector(lista[i]);
        }
    }
    return 0;
}

/** \brief
 *
 * \param lista[] eDirector
 * \param id int
 * \param tamano int
 * \return int
 *
 */
int validaExistenciaDirector(eDirector lista[], int id, int tamano)
{
    int retorno = 0;
    int i;
    for(i = 0; i < tamano; i++)
    {
        if(lista[i].estado == OCUPADO && lista[i].id == id)
        {
            retorno = 1;
            break;
        }
    }
    return retorno;
}


/** \brief
 *
 * \param eDirector[]
 * \param int
 * \param int
 * \return int
 *
 */
int imprimeNombreDirector(eDirector listaDirectores[], int id, int tamanoDirectores)
{
    int i;
    for(i=0; i<tamanoDirectores; i++)
    {
        if(listaDirectores[i].id == id)
        {
            printf("%s\n", listaDirectores[i].nombre);
            break;
        }
    }
    return 0;
}

/** \brief
 *
 * \param listaPeliculas[] ePelicula
 * \param indice int
 * \return int
 *
 */
char compruebaDirectorEncontrado(eDirector lista[], int indice)
{
    char confirma = 'n';
    printf("Se encontro al director: ");
    mostrarUnDirector(lista[indice]);
    puts("Es correcto? s/n");
    confirma = pideYValidaSiNo();

    return confirma;
}
