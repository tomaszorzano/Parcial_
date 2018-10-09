
#include "funciones.h"
#include "alquileres.h"
#include "categoria.h"
#include "cliente.h"
#include "juego.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#define TAM 111
int main()
{
    char seguir='s';
    eClientes cliente[TAM];

   // funcion_harcodeoClientes(cliente);


    funcion_opcionesClientes();
    funcion_InicializarClientes(cliente,TAM);




    do
    {
        switch(funcion_opciones())
        {

        case 1:
            funcion_AltaCliente(cliente,TAM);
            system("pause");
            break;
        case 2:
            funcion_modificarCliente(cliente,TAM);
            system("pause");
            break;
        case 3:
            funcion_BajaCliente(cliente,TAM,0);
            system("pause");
            break;
        case 4:
            funcion_OrdenarClienteXApellido(cliente,TAM);
            funcion_mostrarClientes(cliente,TAM);
            system("pause");
            break;
        case 5:
              printf(" ***Saliendo***\n\n");
              seguir = 'n';
              system("pause");
            break;
    default :
            printf("Opcion no valida, reingrese una opcion del 1 al 5 \n\n");
            system("pause");

            break;


        }

    }while(seguir=='s');

    return 0;
}
