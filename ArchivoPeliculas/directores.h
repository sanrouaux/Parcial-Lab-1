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
    int id;
    char nombre[100];
    eFechaNacimiento nacimiento;
    char pais[50];
    int estado;
}eDirector;


//FUNCIONES
int inicializaListaDirectores(eDirector[], int);
int cargaInicialDirectores(eDirector[]);
int buscaLugarLibreDirector(eDirector[],int);
int buscaIdSiguienteDirector(eDirector[],int);
int altaDirector(eDirector[],int);
int validaNuevoDirector(eDirector[], char[], int);
int bajaDirector(eDirector[], int);
