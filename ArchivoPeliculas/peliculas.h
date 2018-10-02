#define OCUPADO 1
#define LIBRE 0

//ESTRUCTURA DE DATOS
typedef struct
{
    int dia;
    int mes;
    int anio;
}eFechaNacimiento;


typedef struct
{
    char nombre[50];
    eFechaNacimiento nacimiento;
    char pais[50];
}eDirector;


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
int inicializaLista(ePelicula[], int);
int buscaLugarLibre(ePelicula [],int);
int buscaIdSiguiente(ePelicula [],int);
int altaPelicula(ePelicula [],int);
int mostrarLista(ePelicula[],int);
int mostrarUno(ePelicula parametro);
int menuOpciones();
int buscarPorId(ePelicula [],int );
int baja(ePelicula [], int );
int modificacion(ePelicula [],int );
int cargaDatos(ePelicula[], int);




