#define OCUPADO 1
#define LIBRE 0


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


int inicializaListaDirectores(eDirector[], int);
int cargaInicialDirectores(eDirector[]);
int buscaLugarLibreDirector(eDirector[],int);
int buscaIdSiguienteDirector(eDirector[],int);
int director_ingresaNombre(char[]);
int director_ingresaFechaNacimiento(eDirector[], int);
int director_ingresaPais(eDirector[], int);
int validaNuevoDirector(eDirector[], char[], int);
int bajaDirector(eDirector[], int);
int buscaDirectorPorNombreDevuelveIndice(eDirector[], char[], int);
int buscaDirectorPorNombreDevuelveID(eDirector[], char[], int);
int mostrarUnDirector(eDirector);
int imprimeNombreDirector(eDirector[], int, int);
int mostrarListaDirectores(eDirector[],int);
int validaExistenciaDirector(eDirector[], int, int);

