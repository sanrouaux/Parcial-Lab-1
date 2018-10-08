#include <stdio.h>
#include <stdlib.h>
#include "peliculas.h"
#include "directores.h"

#define TAMANO_PELICULAS 1000
#define TAMANO_DIRECTORES 500


int main()
{
    int opcionMenu;
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
            altaPelicula(listaPeliculas, TAMANO_PELICULAS);
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
            mostrarLista(listaPeliculas, TAMANO_PELICULAS);
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


