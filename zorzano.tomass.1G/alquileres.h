
typedef struct
{
   char dia[3];
   char mes[3];
   char anio[5];

} efechas;


typedef struct
{
    int codigoAlquiler;
    char codigoDeJuego[11];
    char codigoDeCliente[11];
    efechas  fecha;
    int isEmpty;
} eAlquileres;

void funcion_InicializarAlquileres(eAlquileres list[], int tam);
