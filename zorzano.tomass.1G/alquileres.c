
#include "funciones.h"
#include "alquileres.h"
#include "categoria.h"
#include "cliente.h"
#include "juego.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void funcion_InicializarAlquileres(eAlquileres list[], int tam)
{

    for(int i=0; i < tam; i++)
    {

        list[i].isEmpty = 1;

    }

}

/*void funcion_MostrarAlquiler(eAlquileres list)
{

    printf("\nCODIGO ALQUILER:%d - CODIGO DE JUEGO:%s - CODIGO DE CLIENTE:%s  - FECHA:%s\n\n", list.id, list.nombre, list.sexo, list.telefono);
}*/
