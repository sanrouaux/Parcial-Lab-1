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


//FUNCIONES
int inicializaListaPeliculas(ePelicula[], int);
int buscaLugarLibrePelicula(ePelicula [],int);
int buscaIdSiguientePelicula(ePelicula [],int);
int altaPelicula(ePelicula [],int);
int mostrarLista(ePelicula[],int);
int mostrarUno(ePelicula parametro);
int menuOpciones();
int buscarPorId(ePelicula [],int );
int bajaPelicula(ePelicula [], int );
int modificacion(ePelicula [],int );
int cargaInicialPeliculas(ePelicula[]);

int validaLargoCadena(char[], int);
int validaRango(int, int, int);
char pideYValidaSiNo();




