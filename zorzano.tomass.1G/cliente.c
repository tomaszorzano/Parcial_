
#include "funciones.h"
#include "alquileres.h"
#include "categoria.h"
#include "cliente.h"
#include "juego.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int funcion_opcionesClientes()
{
    int opcionIngresada;
    char auxOpcion[5];


    system("cls");
    printf("\n******* MENU DE OPCIONES ******* \n\n");
    printf(" 1- ALTA CLIENTE\n");
    printf(" 2- MODIFICAR DATOS DE UN CLIENTE\n");
    printf(" 3- BAJA DEL CLIENTE\n");
    printf(" 4- LISTAR\n");
    printf(" 5- SALIR\n");
    while(!funcion_getStringNumeros("Ingrese una opcion del 1-5 : ",auxOpcion))
    {
        printf("ERROR- La opcion tiene que ser solo numeros del 1 al 7\n\n");

        system("pause");
    }

    opcionIngresada=atoi(auxOpcion);


    return opcionIngresada;
}

void funcion_InicializarClientes(eClientes list[], int tam)
{

    for(int i=0; i < tam; i++)
    {

        list[i].isEmpty = 1;

    }

}
void funcion_MostrarCliente(eClientes list)
{

    printf("\nCODIGO:%d - NOMBRE:%s - SEXO:%s  - TELEFONO:%s\n\n", list.id, list.nombre, list.sexo, list.telefono);
}
void funcion_mostrarClientes(eClientes list[], int tam)
{

    system("cls");
    printf("\n CODIGO NOMBRE SEXO TELEFONO\n\n");

    for(int i=0; i < tam; i++)
    {

        if( list[i].isEmpty == 0)
        {
            funcion_MostrarCliente(list[i]);
        }
    }
    system("pause");
}
int funcion_BuscarClienteXID(eClientes list[], int tam, int id)
{


    for(int i=0; i < tam ; i++)
    {

        if( list[i].id == id && list[i].isEmpty == 0)
        {
            return i;
            break;
        }
    }
    return -1;



}
   int funcion_BuscarLugarVacioClientes(eClientes list[],int tam)
{
    int index = -1;
    for(int i=0; i< tam ; i++)
    {
        if( list[i].isEmpty == 1)
        {
            index = i ;
            break;
        }
    }
    return index ;
}


void funcion_OrdenarClienteXApellido(eClientes list[], int tam)
{
    eClientes auxClientes;
    char auxOpcion[3];
    int opcion;

    funcion_getStringNumeros("\nIngrese opcion 1 para ordenar de forma ascendente u opcion 2 para ordenar de forma descendente \n\n",auxOpcion);
    opcion=atoi(auxOpcion);
    switch (opcion)
    {
    case 1:
        for(int i=0; i<tam-1; i++)
        {
            for(int j= i+1; j < tam; j++)
            {

                if( list[i].nombre > list[j].nombre)
                {
                    auxClientes = list[i];
                    list[i] = list[j];
                    list[j] = auxClientes;

                }
            }
        }
        printf("Clientes oredenados de forma ascendente\n\n");
        system("pause");
        break;
    case 2:
        for(int i=0; i<tam-1; i++)
        {
            for(int j= i+1; j < tam; j++)
            {

                if( list[i].nombre < list[j].nombre)
                {
                    auxClientes = list[i];
                    list[i] = list[j];
                    list[j] = auxClientes;

                }
            }
        }
        printf("Clientes oredenados de forma descendente\n\n");
        system("pause");
        break;
    }




}
int funcion_AltaCliente(eClientes list[], int tam)
{
    eClientes nuevoCliente ;
    int returns;
    int index ;
    char auxNombre[51];
    char auxsexo[11];
    char auxtelefono[21] ;



    if(list != NULL && tam > 0)
    {
        system("cls");
        fflush(stdin);
        index = funcion_BuscarLugarVacioClientes(list,tam) ;
        printf("\n**** Nuevo Cliente****\n\n");

        if(index == -1)
        {
            printf("No hay lugar en el sistema. \n") ;
            returns = -1 ;
            system("pause");

        }
        else
        {


            printf("\n Nuevo cliente, ID numero %d \n",index) ;
            nuevoCliente.id = index ;
            if(!funcion_getStringLetras("Ingrese nombre: ",auxNombre))
            {
                printf("El nombre solo debe tener letras.\n\n") ;
                system("pause");
                system("cls");

            }
            else if(!funcion_getStringLetras("Ingrese sexo: ",auxsexo))
            {
                printf("El sexo debe tener solo letras.\n\n") ;
                system("pause");
                system("cls");

            }
            else if(!funcion_getStringtelefono("Ingrese el telefono: ",auxtelefono))
            {
                printf("**** Error ingrese solo numeros con un guion EJ:'4214-4589' ****\n\n");
                system("pause");
                system("cls");

            }
            else
            {
                strcpy(nuevoCliente.nombre,auxNombre) ;
                strcpy(nuevoCliente.sexo,auxsexo) ;
                strcpy(nuevoCliente.telefono,auxtelefono);

                nuevoCliente.isEmpty = 0;
                list[index] = nuevoCliente ;
                system("pause");
                system("cls");
                printf("\n\nNUEVO CLIENTE INGRESADO:\n\n");
                funcion_MostrarCliente(list[index]);
                printf("\n\n\n");
                system("pause");
                returns = 0 ;
            }
        }

    }
    else
    {
        returns = -1 ;
    }
    return returns;
}


int funcion_BajaCliente(eClientes list[], int tam, int id)
{

    int index;
    int returns ;
    char auxID[10] ;
    char seguir;

    if(list != NULL && tam > 0)
    {
        system("cls");
        printf("  *** BAJA CLIENTES ***\n\n");


        if(!funcion_getStringNumeros("Ingrese id: ",auxID))
        {
            printf("*** ERROR *** El ID debe contener solo numeros.\n\n");
            system("pause") ;
            system("cls");
        }
        else
        {
            id = atoi(auxID) ;

            index = funcion_BuscarClienteXID(list,tam,id) ;


            if(index == -1)
            {
                printf("No hay ningun cliente con ese id %d",id) ;
            }
            else
            {
                returns = 0;
                funcion_MostrarCliente(list[index]) ;
                printf("¿Seguro que quiere borrar cliente? S o N");
                scanf("%c",&seguir);
                if(seguir == 'n')
                {
                    printf("Baja cancelada\n\n");
                }
                else
                {

                    list[index].isEmpty = 1;
                    printf("Borrado exitoso\n\n");
                }
                system("pause");
            }
        }
    }
    return returns ;
}



void funcion_modificarCliente(eClientes list[], int tam)
{
    int id;
    int index;
    int opcion;
    char auxOpcion[3];
    char auxId[11];
    char newSexo[11];
    char newNombre[31] ;
    char newTelefono[31] ;


    system("cls");
    printf("  *** Modificar  Cliente ***\n\n");


    if(!funcion_getStringNumeros("Ingrese id: ",auxId))
    {
        printf("*** ERROR *** El id debe contener solo numeros.") ;
    }

    id = atoi(auxId) ;
    index = funcion_BuscarClienteXID(list, tam, id);


    if( index == -1)
    {
        printf("No hay ningun Cliente con ese id %d.\n\n", id);
        system("pause");
    }
    else
    {
char seguirModificando ='s';
do{
       system("cls");
        funcion_MostrarCliente(list[index]) ;


    if(!funcion_getStringNumeros("\n\nQue desea modificar?\n\n1 - Nombre\n2 - Sexo\n3 - Telefono\n4 - Salir\n\nOpcion:",auxOpcion))
    {
        printf("ERROR- INGRESE UN NUMERO");
    }

    opcion = atoi(auxOpcion);

    switch(opcion)
    {


       case 1:
        funcion_MostrarCliente(list[index]) ;
        printf("\n\n");
       //modificar nombre
        if(!funcion_getStringLetras("Ingrese nuevo nombre: ",newNombre))
            {
                printf("*** Error *** El nombre debe tener solo letras.");
            }else
            {
            strcpy(list[index].nombre,newNombre);
            printf("\n\n        ***Modificacion exitosa***\n\n");
            funcion_MostrarCliente(list[index]);
            system("pause");
            break ;
       }
    case 2:
// Modifica telefono
        funcion_MostrarCliente(list[index]) ;
        printf("\n\n");
        if(!funcion_getStringLetras("Ingrese nuevo telefono: ",newTelefono))
            {
                printf("*** ERROR *** El telefono debe tener solo 8 numero y un guion EJ:'4242-888'.\n\n");
            }else{

            strcpy(list[index].telefono,newTelefono);
            printf("\n\n        ***Modificacion exitosa***\n\n");
            funcion_MostrarCliente(list[index]);
            system("pause");
            }
        break ;
    case 3:
        // modifica sexo
        funcion_MostrarCliente(list[index]) ;
        printf("\n\n");
        if(!funcion_getStringLetras("Ingrese nuevo sexo: ",newSexo))
            {
                printf("*** ERROR *** El sexo debe contener solo letras.") ;
            }else{

            strcpy(list[index].sexo,newSexo);
            printf("\n\n        ***Modificacion exitosa***\n\n");
            funcion_MostrarCliente(list[index]);
            system("pause");
            }
            break ;

    case 4:
        seguirModificando='n';
        funcion_MostrarCliente(list[index]);
        break;
    default:
        printf("*** ERROR *** Debe ingresar un numero del 1 al 4.\n");
        system("pause");
        break;
        }
} while (seguirModificando =='s');
        }
    }



/*    void funcion_harcodeoClientes(eClientes list[])
{

    eClientes x[] = {
        {10,"Eliana","Masculino",2022-000},
        {23,"Pedro","Masculino",3055-0000},
        {29,"Juana","Femenino",1800-7890},
        {39,"Ana","Femenino",2000-9904},
        {34,"Sara","Femenino",3000-4870}
    };
    for(int i = 0; i< 5; i++)
    {
        list[i] = x[i];
    }
}*/
