#include <stdio.h>
#include <stdlib.h>
#include "menuOpciones.h"


/** \brief
 *
 * \return int
 *
 */
int menuPrincipal()
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
    fflush(stdin);
    scanf("%d", &opcion);
    return opcion;
}


/** \brief
 *
 * \return int
 *
 */
int menuModificacion()
{
    int opcion;
    puts("\nQue dato desea modificar?");
    puts("1. Titulo");
    puts("2. Anio");
    puts("3. Nacionalidad");
    puts("4. Director");
    puts("5. Cancelar");
    fflush(stdin);
    scanf("%d", &opcion);
    return opcion;
}




/** \brief
 *
 * \return char
 *
 */
char menuListado()
{
    char opcion;
    puts("a. Peliculas");
    puts("b. Directores");
    puts("c. Pelicula/as mas vieja/as");
    puts("d. Peliculas con su director");
    puts("e. Peliculas por director");
    puts("f. Numero de peliculas dirigidas por director");
    puts("g. El director con mas peliculas");
    fflush(stdin);
    opcion = getchar();
    return opcion;
}








