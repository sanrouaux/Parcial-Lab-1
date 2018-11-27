#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"

/** \brief valida el largo de una cadena de caracteres
 *
 * \param cadena[] char Cadena a ser medida
 * \param largoMaximo int Largo maximo que puede tener la cadena, incluyendo al caracter de cierre
 * \return int retorna 1 si el largo es valido, y 0 si el largo no es valido, y -1 si no se introdujeron caracteres
 *
 */
int validaLargoCadena(char* cadena, int largoMaximo)
{
    int retorno = 1;
    if(strlen(cadena) >= largoMaximo)
    {
        retorno = 0;
    }
    else if(strlen(cadena) == 0)
    {
        retorno = -1;
    }
    return retorno;
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


/** \brief comprueba si una cadena de caracteres tiene todos sus elementos alfabeticos
 *
 * \param char[] cadena a ser evaluada
 * \return int devuelve '1' si la comprobacion es positiva; '0' si es negativa
 *
 */
int validaSoloLetras(char* cadena)
{

    int retorno = 1;

    int largo;
    largo = strlen(cadena);

    int i;
    for(i=0; i<largo; i++)
    {
        if((cadena[i] < 'a' || cadena[i] > 'z') && (cadena[i] < 'A' || cadena[i] > 'Z') && cadena[i] != ' '
           && cadena[i] != ',')
        {
            retorno = 0;
            break;
        }
    }
    return retorno;
}




/** \brief
 *
 * \param cadena[] char
 * \param mensaje[] char
 * \param largo int
 * \return int
 *
 */
int ingresaCadenaSoloLetras(char cadena[], char mensaje[], int largo)
{
    char buffer[1024];
    int validacionLargo;
    int validacionCaracteres;

    puts(mensaje);
    fflush(stdin);
    gets(buffer);

    validacionLargo = validaLargoCadena(buffer, largo);
    validacionCaracteres = validaSoloLetras(buffer);

    while(validacionLargo != 1 || validacionCaracteres != 1)
    {
        if(validacionLargo == 0)
        {
            puts("Demasiados carcateres");
        }

        if(validacionLargo == -1)
        {
            puts("No ingreso ningun caracter");
        }

        if(validacionCaracteres == 0)
        {
            puts("Ingreso caracteres invalidos");
        }

        puts("Ingrese nuevamente: ");
        fflush(stdin);
        gets(buffer);
        validacionLargo = validaLargoCadena(buffer, largo);
        validacionCaracteres = validaSoloLetras(buffer);
    }

    strcpy(cadena, buffer);
    return 0;
}
