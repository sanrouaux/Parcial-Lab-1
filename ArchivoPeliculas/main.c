#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "peliculas.h"
#include "directores.h"
#include "menuOpciones.h"
#include "validaciones.h"

#define TAMANO_PELICULAS 1000
#define TAMANO_DIRECTORES 500


int main()
{
    ePelicula listaPeliculas[TAMANO_PELICULAS];
    inicializaListaPeliculas(listaPeliculas, TAMANO_PELICULAS);
    cargaInicialPeliculas(listaPeliculas);

    eDirector listaDirectores[TAMANO_DIRECTORES];
    inicializaListaDirectores(listaDirectores, TAMANO_DIRECTORES);
    cargaInicialDirectores(listaDirectores);


    int opcionMenuPrincipal;
    int opcionModificacion;
    char opcionListar;
    int bandera;

    int indicePelicula;
    int idPelicula;
    int indiceDirector;
    int idDirector;

    char auxNombreDirector[100];
    int contadorPeliculas;
    int mayorNumeroPeliculas;

    do
    {
        opcionMenuPrincipal = menuPrincipal();

        switch(opcionMenuPrincipal)
        {
        case 1:
            indicePelicula = buscaLugarLibrePelicula(listaPeliculas, TAMANO_PELICULAS);
            if(indicePelicula>=0)
            {
                pelicula_ingresaTitulo(listaPeliculas, indicePelicula);
                pelicula_ingresaAnio(listaPeliculas, indicePelicula);
                pelicula_ingresaNacionalidad(listaPeliculas, indicePelicula);
                mostrarListaDirectores(listaDirectores, TAMANO_DIRECTORES);
                idDirector = pelicula_ingresaIdDirector();

                while(validaExistenciaDirector(listaDirectores, idDirector, TAMANO_DIRECTORES)==0)
                {
                    puts("\nEL DIRECTOR NO EXISTE. INGRESE UN ID CORRECTO: \n");
                    mostrarListaDirectores(listaDirectores, TAMANO_DIRECTORES);
                    idDirector = pelicula_ingresaIdDirector();
                }

                listaPeliculas[indicePelicula].director = idDirector;
                pelicula_cargaId(listaPeliculas, TAMANO_PELICULAS, indicePelicula);
                listaPeliculas[indicePelicula].estado = OCUPADO;
                puts("\nSE DIO DE ALTA UNA PELICULA\n");
            }
            else
            {
                puts("\nNO HAY LUGAR PARA GUARDAR UNA NUEVA PELICULA\n");
            }
            break;

        case 2:
            mostrarListaPeliculas(listaPeliculas, TAMANO_PELICULAS);
            idPelicula = pideIdUsuario();
            indicePelicula = buscaPorIdDevuelveIndice(listaPeliculas, TAMANO_PELICULAS, idPelicula);
            if(indicePelicula>=0)
            {
                if(compruebaPeliculaEncontrada(listaPeliculas, indicePelicula)=='s')
                {
                    opcionModificacion = menuModificacion();

                    switch(opcionModificacion)
                    {
                    case 1:
                        pelicula_ingresaTitulo(listaPeliculas, indicePelicula);
                        puts("\nSE MODIFICO UNA PELICULAS\n");
                        break;

                    case 2:
                        pelicula_ingresaAnio(listaPeliculas, indicePelicula);
                        puts("\nSE MODIFICO UNA PELICULAS\n");
                        break;

                    case 3:
                        pelicula_ingresaNacionalidad(listaPeliculas, indicePelicula);
                        puts("\nSE MODIFICO UNA PELICULAS\n");
                        break;

                    case 4:
                        mostrarListaDirectores(listaDirectores, TAMANO_DIRECTORES);
                        idDirector = pelicula_ingresaIdDirector();

                        while(validaExistenciaDirector(listaDirectores, idDirector, TAMANO_DIRECTORES)==0)
                        {
                            puts("\nEL DIRECTOR NO EXISTE. INGRESE UN ID CORRECTO: \n");
                            mostrarListaDirectores(listaDirectores, TAMANO_DIRECTORES);
                            idDirector = pelicula_ingresaIdDirector(listaPeliculas, TAMANO_PELICULAS);
                        }

                        listaPeliculas[indicePelicula].director = idDirector;
                        puts("\nSE MODIFICO UNA PELICULAS\n");
                        break;

                    case 5:
                        puts("\nSECANCELO LA ACCION\n");
                        break;
                    }
                }
                else
                {
                    puts("\nSE CANCELO LA ACCION\n");
                }
            }
            else
            {
                puts("\nNO SE ENCONTRO EL FILM\n");
            }
            break;

        case 3:
            mostrarListaPeliculas(listaPeliculas, TAMANO_PELICULAS);
            idPelicula = pideIdUsuario();
            indicePelicula = buscaPorIdDevuelveIndice(listaPeliculas, TAMANO_PELICULAS, idPelicula);
            if(indicePelicula >= 0)
            {
                if(compruebaPeliculaEncontrada(listaPeliculas, indicePelicula)=='s')
                {
                    listaPeliculas[indicePelicula].estado = LIBRE;
                    puts("\nSE DIO DE BAJA UNA PELICULA\n");
                }
                else
                {
                    puts("\nACCION CANCELADA\n");
                }
            }
            else
            {
                puts("\nNO SE ENCONTRO EL FILM\n");
            }
            break;

        case 4:
            indiceDirector = buscaLugarLibreDirector(listaDirectores, TAMANO_DIRECTORES);
            if(indiceDirector >= 0)
            {
                director_ingresaNombre(listaDirectores, indiceDirector);

                if(validaNuevoDirector(listaDirectores, indiceDirector, TAMANO_DIRECTORES))
                {
                    director_ingresaFechaNacimiento(listaDirectores, indiceDirector);
                    director_ingresaPais(listaDirectores, indiceDirector);
                    director_cargaId(listaDirectores, TAMANO_DIRECTORES, indiceDirector);
                    listaDirectores[indiceDirector].estado = OCUPADO;
                }
                else
                {
                    puts("\nYA EXISTE UN DIRECTOR CON ESE NOMBRE\n");
                }
            }
            else
            {
                puts("\nNO HAY LUGAR PARA GUARDAR UN NUEVO DIRECTOR\n");
            }
            break;

        case 5:
            mostrarListaDirectores(listaDirectores, TAMANO_DIRECTORES);
            indiceDirector = buscaDirectorPorNombreDevuelveIndice(listaDirectores, TAMANO_DIRECTORES);
            if(indiceDirector>=0)
            {
                if(compruebaDirectorEncontrado(listaDirectores, indiceDirector)=='s')
                {
                    listaDirectores[indiceDirector].estado = LIBRE;
                    buscaPeliculaPorIdDirectorYBorra(listaPeliculas, idDirector, TAMANO_PELICULAS);
                    puts("\nSE DIO DE BAJA UN DIRECTOR\n");
                }
                else
                {
                    puts("\nSE CANCELO LA ACCION\n");
                }
            }
            else
            {
                puts("\nNO SE ENCONTRO EL DIRECTOR\n");
            }
            break;

        case 6:
            opcionListar = menuListado();
            switch(opcionListar)
            {
            case 'a':
                mostrarListaPeliculas(listaPeliculas, TAMANO_PELICULAS);
                break;

            case 'b':
                mostrarListaDirectores(listaDirectores, TAMANO_DIRECTORES);
                break;

            case 'c':
                peliculasMasViejas(listaPeliculas, TAMANO_PELICULAS);
                break;

            case 'd':
                puts("PELICULA            DIRECTOR");
                int i;
                for(i = 0; i < TAMANO_PELICULAS; i++)
                {
                    if(listaPeliculas[i].estado == OCUPADO)
                    {
                        imprimeTituloPelicula(listaPeliculas[i]);
                        idDirector = listaPeliculas[i].director;
                        imprimeNombreDirector(listaDirectores, idDirector, TAMANO_DIRECTORES);
                    }
                }
                break;

            case 'e':
                mostrarListaDirectores(listaDirectores, TAMANO_DIRECTORES);
                idDirector = buscaDirectorPorNombreDevuelveID(listaDirectores, TAMANO_DIRECTORES);
                if(idDirector>=0)
                {
                    buscaPeliculaPorIdDirectorEImprime(listaPeliculas, idDirector, TAMANO_PELICULAS);
                }
                else
                {
                    puts("\nNO SE ENCONTRO AL DIRECTOR\n");
                }
                break;

            case 'f':
                mostrarListaDirectores(listaDirectores, TAMANO_DIRECTORES);
                idDirector = buscaDirectorPorNombreDevuelveID(listaDirectores, TAMANO_DIRECTORES);
                if(idDirector>=0)
                {
                    contadorPeliculas = cuentaNumeroPeliculas(listaPeliculas, idDirector, TAMANO_PELICULAS);
                    printf("El director seleccionado dirigio %d peliculas", contadorPeliculas);
                }
                else
                {
                    puts("\nNO SE ENCONTRO AL DIRECTOR\n");
                }
                break;

            case 'g':
                bandera = 0;
                for(i=0; i<TAMANO_DIRECTORES; i++)
                {
                    if(listaDirectores[i].estado==OCUPADO)
                    {
                        contadorPeliculas = cuentaNumeroPeliculas(listaPeliculas, listaDirectores[i].id, TAMANO_PELICULAS);
                        if(bandera == 0)
                        {
                            mayorNumeroPeliculas = contadorPeliculas;
                            bandera = 1;
                        }
                        else
                        {
                            mayorNumeroPeliculas = contadorPeliculas;
                        }
                    }
                }

                puts("\nEl\Los director\es con mas peliculas es\son:");

                for(i=0; i<TAMANO_DIRECTORES; i++)
                {
                    contadorPeliculas = cuentaNumeroPeliculas(listaPeliculas, listaDirectores[i].id, TAMANO_PELICULAS);
                    if(listaDirectores[i].estado==OCUPADO && contadorPeliculas == mayorNumeroPeliculas)
                    {
                        imprimeNombreDirector(listaDirectores, listaDirectores[i].id, TAMANO_DIRECTORES);
                    }
                }
                break;

            default:
                puts("\nNO INGRESO UNA OPCION VALIDA\n");
            }
            break;

        case 7:
            puts("\nGRACIAS POR UTILIZAR EL ARCHIVO DE PELICULAS\n");
            break;

        default:
            puts("\nNO INGRESO UNA OPCION VALIDA\n");

        }
        printf("\n");
        system("pause");
        system("cls");

    }
    while(opcionMenuPrincipal != 7);

    return 0;


}


