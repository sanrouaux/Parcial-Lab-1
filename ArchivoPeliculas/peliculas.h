#ifndef PELICULAS_H_INCLUDED
#define PELICULAS_H_INCLUDED

#define OCUPADO 1
#define LIBRE 0


typedef struct
{
    char titulo[100];
    int anio;
    char nacionalidad[50];
    int director;
    int id;
    int estado;
}ePelicula;


int inicializaListaPeliculas(ePelicula[], int);
int cargaInicialPeliculas(ePelicula[]);
int buscaLugarLibrePelicula(ePelicula [],int);
int buscaIdSiguientePelicula(ePelicula [],int);
int pelicula_ingresaTitulo(ePelicula[], int);
int pelicula_ingresaAnio(ePelicula[], int);
int pelicula_ingresaNacionalidad(ePelicula[], int);
int pelicula_ingresaIdDirector();
int mostrarUnaPelicula(ePelicula parametro);
int mostrarListaPeliculas(ePelicula[],int);
int pideIdUsuario();
int buscaPorIdDevuelveIndice(ePelicula[],int, int);
int compruebaPeliculaEncontrada(ePelicula[], int);
int bajaPelicula(ePelicula[], int );
int peliculasMasViejas(ePelicula[], int);
int buscaPeliculaPorDirectorEImprime(ePelicula[], int, int);
int buscaPeliculaPorIdDirectorYBorra(ePelicula[], int, int);
int cuentaNumeroPeliculas(ePelicula[], int, int);
int buscaDirectorPorIndicePelicula(ePelicula[], int);
int imprimeTituloPelicula(ePelicula);

#endif // PELICULAS_H_INCLUDED

