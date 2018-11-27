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
int director_ingresaNombre(eDirector lista[], int indice);
int director_ingresaFechaNacimiento(eDirector[], int);
int director_ingresaPais(eDirector[], int);
int director_cargaId(eDirector lista[], int tamano, int indice);
int validaNuevoDirector(eDirector lista[], int indice, int tamano);
int bajaDirector(eDirector[], int);
int buscaDirectorPorNombreDevuelveIndice(eDirector[], int);
int buscaDirectorPorNombreDevuelveID(eDirector lista[], int tamano);
int mostrarUnDirector(eDirector);
int imprimeNombreDirector(eDirector[], int, int);
int mostrarListaDirectores(eDirector[],int);
int validaExistenciaDirector(eDirector[], int, int);
char compruebaDirectorEncontrado(eDirector lista[], int indice);

