#define OCUPADO 1;
#define LIBRE 0;

typedef struct
{
    int dia;
    int mes;
    int anio;
}sFechaNacimiento;


typedef struct
{
    char nombre[21];
    sFechaNacimiento nacimiento;
    char pais[21];
}sDirector;

typedef struct
{
    char titulo[21];
    int anio;
    char nacionalidad[21];
    sDirector director;
    int id;
    int estado;
}sPelicula;



int inicializaLista(sPelicula[])



