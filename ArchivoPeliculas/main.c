#include <stdio.h>
#include <stdlib.h>
#include "peliculas.h"
#include "directores.h"

#define TAMANO_PELICULAS 1000
#define TAMANO_DIRECTORES 500


int main()
{
    int opcionMenu;
    char opcionListado;
    int indice;
    int idDirector;
    int existenciaDirector;
    char nombreDirector[100];
    int contadorPeliculas;


    ePelicula listaPeliculas[TAMANO_PELICULAS];
    inicializaListaPeliculas(listaPeliculas, TAMANO_PELICULAS);
    cargaInicialPeliculas(listaPeliculas);

    eDirector listaDirectores[TAMANO_DIRECTORES];
    inicializaListaDirectores(listaDirectores, TAMANO_DIRECTORES);
    cargaInicialDirectores(listaDirectores);


    do
    {
        opcionMenu = menuOpciones();

        switch(opcionMenu)
        {
        case 1:
            indice = altaPelicula(listaPeliculas, TAMANO_PELICULAS);
            idDirector = buscaDirectorPorIndicePelicula(listaPeliculas, indice);
            existenciaDirector = buscaDirectorPorId(listaDirectores, idDirector, TAMANO_DIRECTORES);
            if(existenciaDirector == 0)
            {
                puts("El director no existe");
                listaPeliculas[indice].estado = LIBRE;
            }
            else
            {
                puts("Se dio de alta la pelicula");
            }
        break;

    case 2:
        modificacion(listaPeliculas, TAMANO_PELICULAS);
        break;

    case 3:
        bajaPelicula(listaPeliculas, TAMANO_PELICULAS);
        break;

    case 4:
        altaDirector(listaDirectores, TAMANO_DIRECTORES);
        break;

    case 5:
        bajaDirector(listaDirectores, TAMANO_DIRECTORES);
        break;

    case 6:
        opcionListado = menuListado();
        if(opcionListado == 'a')
        {
            mostrarLista(listaPeliculas, TAMANO_PELICULAS);
        }
        else if(opcionListado == 'b')
        {
            mostrarListaDirectores(listaDirectores, TAMANO_DIRECTORES);
        }
        else if(opcionListado == 'c')
        {
            peliculasMasViejas(listaPeliculas, TAMANO_PELICULAS);
        }
        else if(opcionListado == 'd')
        {
            puts("PELICULA   -   DIRECTOR");

            int i;
            for(i = 0; i < TAMANO_PELICULAS; i++)
            {
                if(listaPeliculas[i].estado == OCUPADO)
                {
                    printf("%s   -   ", listaPeliculas[i].titulo);
                    idDirector = listaPeliculas[i].director;
                    int j;
                    for(j = 0; j < TAMANO_DIRECTORES; j++)
                    {
                        if(listaDirectores[j].id == idDirector)
                        {
                            printf("%s \n", listaDirectores[j].nombre);
                            break;
                        }
                    }
                }
            }
        }
        else if(opcionListado == 'e')
        {
            puts("Introduzca el nombre del director:");
            fflush(stdin);
            gets(nombreDirector);
            idDirector = buscaDirectorPorNombreDevuelveID(listaDirectores, nombreDirector, TAMANO_DIRECTORES);
            if(idDirector==-1)
            {
                puts("No se encontro el director");
            }
            else
            {
                buscaPeliculaPorDirectorEImprime(listaPeliculas, idDirector, TAMANO_PELICULAS);
            }


        }
        else if(opcionListado=='f')
        {
            puts("Introduzca el nombre del director:");
            fflush(stdin);
            gets(nombreDirector);
            idDirector = buscaDirectorPorNombreDevuelveID(listaDirectores, nombreDirector, TAMANO_DIRECTORES);
            if(idDirector==-1)
            {
                puts("No se encontro el director");
            }
            else
            {
                contadorPeliculas = cuentaNumeroPeliculas(listaPeliculas, idDirector, TAMANO_PELICULAS);
                printf("El director dirigio %d peliculas", contadorPeliculas);
            }
        }
        else
        {
            puts("No ingreso una opcion valida");
        }
        break;

    case 7:
        break;

    default:
        puts("No ingreso una opcion valida");

    }
    printf("\n");
    system("pause");
    system("cls");

}
while(opcionMenu != 7);




return 0;
}


