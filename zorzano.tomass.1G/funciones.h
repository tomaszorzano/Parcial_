float funcion_Suma(float a, float b );
float funcion_Resta(float a, float b);
float funcion_Multiplicacion(float a,float b);
float funcion_Division(float a,float b);
int funcion_Factorial(int a);


int funcion_getInt();
float funcion_getFloat();
char funcion_getChar();


int funcion_ValidarNumero(char *str) ;
int funcion_ValidarTelefono(char *str);
int funcion_validarAlfaNumerico(char *str);
int funcion_validarSoloLetras(char *str);
int funcion_validarNumeroFlotante(char str[]);

void funcion_getString(char mensaje[],char input[]);

int funcion_getStringLetras(char mensaje[],char input[]);
int funcion_getStringNumeros(char mensaje[],char input[]);
int funcion_getStringNumerosFlotantes(char mensaje[],char input[]);
int funcion_getStringtelefono(char mensaje[],char input[]);

//****************************************************************************************************

typedef struct
{
    int id;
    char nombre[31];
    char lastName[31];
    float salary;
    char sector[31];
    int isEmpty;
} eEmpleado;


int funcion_opciones();
void funcion_Inicializar(eEmpleado list[], int tam);
void funcion_mostrarEmpleado(eEmpleado list);
void funcion_mostrarEmpleados(eEmpleado list[], int tam);
int funcion_BuscarEmpleadoXID(eEmpleado list[], int tam, int id);
int funcion_BuscarLugarVacio(eEmpleado list[],int tam);
void funcion_ordenarEmpleadosXlID(eEmpleado list[], int tam);
void funcion_ordenarEmpleadosXApellido(eEmpleado list[], int tam);
float funcion_Promedio(eEmpleado list[],int tam);
int funcion_AltaEmpleado(eEmpleado list[], int tam);
int funcion_BajaEmpleado(eEmpleado list[], int tam, int id);
void funcion_modificarEmpleado(eEmpleado list[], int tam);
void funcion_harcodeoEmployee(eEmpleado list[]);


