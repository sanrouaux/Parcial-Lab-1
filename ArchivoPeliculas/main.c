#include <stdio.h>
#include <stdlib.h>
#include "peliculas.h"

#define TAMANO 2


int main()
{
    int opcionMenu;
    ePelicula listaPeliculas[TAMANO];
    inicializaLista(listaPeliculas, TAMANO);

    cargaDatos(listaPeliculas, TAMANO);

    do
    {
        opcionMenu = menuOpciones();

        switch(opcionMenu)
        {
        case 1:
            altaPelicula(listaPeliculas, TAMANO);
            break;

        case 2:
            modificacion(listaPeliculas, TAMANO);
            break;

        case 3:
             baja(listaPeliculas, TAMANO);
            break;

        case 4:

            break;

        case 5:
            break;

        case 6:
            mostrarLista(listaPeliculas, TAMANO);
            break;

        }
    system("pause");
    system("cls");

    }
    while(opcionMenu != 5);




    return 0;
}


