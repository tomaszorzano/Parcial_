
typedef struct
{
    int id;
    char nombre[52];
    char sexo[11];
    char telefono[22];
    int isEmpty;

} eClientes;

int funcion_opcionesClientes();
void funcion_InicializarClientes(eClientes list[], int tam);
void funcion_MostrarCliente(eClientes list);
void funcion_mostrarClientes(eClientes list[], int tam);
int funcion_BuscarClienteXID(eClientes list[], int tam, int id);
int funcion_BuscarLugarVacioClientes(eClientes list[],int tam);
void funcion_OrdenarClienteXApellido(eClientes list[], int tam);
int funcion_AltaCliente(eClientes list[], int tam);
int funcion_BajaCliente(eClientes list[], int tam, int id);
void funcion_modificarCliente(eClientes list[], int tam);
//void funcion_harcodeoClientes(eClientes list[]);
