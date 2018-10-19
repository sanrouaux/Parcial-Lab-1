#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"

/** \brief
 *
 * \param cadena[] char
 * \param largoMaximo int
 * \return int
 *
 */
int validaLargoCadena(char cadena[], int largoMaximo)
{
    while(strlen(cadena) >= largoMaximo || strlen(cadena) == 0)
    {
        if(strlen(cadena) == 0)
        {
            puts("No ingreso ningun caracter. Ingrese nuevamente: ");
            fflush(stdin);
            gets(cadena);
        }
        else
        {
            puts("Nombre demasiado largo. Ingrese otro: ");
            fflush(stdin);
            gets(cadena);
        }
    }
    return 0;
}



/** \brief
 *
 * \param numero int
 * \param max int
 * \param min int
 * \return int
 *
 */
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


/** \brief
 *
 * \return char
 *
 */
char pideYValidaSiNo()
{
    char letra;
    fflush(stdin);
    letra = getchar();

    while(letra != 's' && letra != 'n')
    {
        puts("Ingrese una opcion correcta: s/n");
        fflush(stdin);
        letra = getchar();
    }
    return letra;
}


/** \brief
 *
 * \param cadena[] char
 * \return int
 *
 */
int validaSoloNumero(char cadena[])
{
    int numeroValido;
    int caracterInvalido;
    int largoCadena;

    do
    {
        caracterInvalido = 0;
        largoCadena = strlen(cadena);
        int i;
        for(i=0; i<largoCadena; i++)
        {
            if(cadena[i] < 48 || cadena[i] > 57)
            {
                caracterInvalido = 1;
            }
        }

        if(caracterInvalido == 1)
        {
            puts("\nIngreso un caracter invalido. Ingrese el numero nuevamente: ");
            fflush(stdin);
            gets(cadena);
        }
    }
    while(caracterInvalido == 1);
    numeroValido = atoi(cadena);
    return numeroValido;
}


/** \brief
 *
 * \param cadena[] char
 * \param largoMaximo int
 * \return int
 *
 */
int validaSoloLetras(char cadena[], int largoMaximo)
{

    int largoCadena;
    int caracterInvalido;
    int i;
    do
    {
        caracterInvalido = 0;
        largoCadena = strlen(cadena);

                      for(i=0; i<largoCadena; i++)
        {
            if((cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < 'A' || cadena[i] > 'Z') && cadena[i] != ' ')
            {
                caracterInvalido = 1;
                break;
            }
        }

        if(caracterInvalido == 1)
        {
            puts("Ingreso un caracter invalido. Ingrese la cadena nuevamente:");
            fflush(stdin);
            gets(cadena);
            validaLargoCadena(cadena, largoMaximo);
        }
    }
    while(caracterInvalido == 1);

    return 0;
}
