#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

/** \brief Suma de dos numeros flotantes.
    \param Valor asignado a variable "a".
    \param valor asignado a variable "b".
    \return Devuelve el resultado de la suma de las dos variables.
*/


float funcion_Suma(float a , float b)

{
    float resSuma;
    resSuma = a + b;
    return resSuma;
};

/** \brief Resta de dos numeros flotant
    \param Valor asignado a variable "a".
    \param Valor asignado a variable "b".
    \return Devuelve el resultado de la resta de las dos variables.
*/


float funcion_Resta(float a,float b)
{
    float resResta;
    resResta= a - b;
    return resResta;

};


/** \brief Multiplicacion de dos numeros flotantes.
    \param Valor asignado a variable "a".
    \param Valor asignado a variable "b".
    \return Devuelve el resultado de la multiplicacion de las dos variables.
*/



float funcion_Multiplicacion(float a,float b)
{
    float resMultiplicacion;
    resMultiplicacion= a * b;
    return resMultiplicacion;

};


/** \brief Division de dos numeros flotantes
    \param Valor asignado a variable "a".
    \param Valor asignado a variable "b".
    \return Devuelve el resultado de la division de las dos variables.
*/


float funcion_Division(float a,float b)
{
    float resDivision;

    if(b ==0)
    {

        return -1;

    }
    else
    {
        resDivision=a/b;
        return resDivision;
    }


};


/** \brief Factoriza un numero entero
    \param Valor asignado a variable "a".
    \return Devuelve el resultado de la factorial de la variable.
*/



int funcion_Factorial(int a)
{
    int valor;
    if(a==0)
    {
        return 1;
    }
    valor=a*funcion_Factorial(a-1);
    return valor;
};

/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
float funcion_getFloat(char* mensaje)
{
    float auxiliar;
    printf("%s",mensaje);
    scanf("%f",&auxiliar);
    return auxiliar;
}


/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
int funcion_getInt(char* mensaje)
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);
    return auxiliar;
}


/**
 * \brief Solicita un caracter al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El caracter ingresado por el usuario
 *
 */
char funcion_getChar(char* mensaje)
{
    char auxiliar;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%c",&auxiliar);
    return auxiliar;
}


/**
 * \brief Verifica si el valor recibido es numérico aceptando flotantes
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */

int funcion_validarNumeroFlotante(char str[])
{
   int i=0;
   int cantidadPuntos=0;
   while(str[i] != '\0')
   {
       if (str[i] == '.' && cantidadPuntos == 0)
       {
           cantidadPuntos++;
           i++;
           continue;

       }
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}

/**
 * \brief Verifica si el valor recibido es numérico
 * \param str Array con la cadena a ser analizada
 * \return 1 si es númerico y 0 si no lo es
 *
 */

int funcion_ValidarNumero(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if(str[i] < '0' || str[i] > '9')
           return 0;
       i++;
   }
   return 1;
}

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int funcion_validarSoloLetras(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
           return 0;
       i++;
   }
   return 1;
}


/**
 * \brief Verifica si el valor recibido contiene solo letras y números
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y números, y 0 si no lo es
 *
 */
int funcion_validarAlfaNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
           return 0;
       i++;
   }
   return 1;
}


/**
 * \brief Verifica si el valor recibido contiene solo números, + y -
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo numeros, espacios y un guion.
 *
 */
int funcion_ValidarTelefono(char str[])
{
   int i=0;
   int contadorGuiones=0;
   while(str[i] != '\0')
   {
       if((str[i] != ' ') && (str[i] != '-') && (str[i] < '0' || str[i] > '9'))
           return 0;
       if(str[i] == '-')
            contadorGuiones++;
       i++;
   }
   if(contadorGuiones==1) // debe tener un guion
        return 1;

    return 0;
}
/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */
void funcion_getString(char mensaje[],char input[])
{
    printf("%s",mensaje);
    gets(input);
}

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int funcion_getStringLetras(char mensaje[],char input[])
{
    char aux[256];
    funcion_getString(mensaje,aux);
    if(funcion_validarSoloLetras(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

/**
 * \brief Solicita un texto numérico al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int funcion_getStringNumeros(char mensaje[],char input[])
{
    char aux[256];
    funcion_getString(mensaje,aux);
    if(funcion_ValidarNumero(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}


/**
 * \brief Solicita un texto numérico al usuario y lo devuelve (acepta flotantes)
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo números
 */
int funcion_getStringNumerosFlotantes(char mensaje[],char input[])
{
    char aux[256];
    funcion_getString(mensaje,aux);
    if(funcion_validarNumeroFlotante(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}
int funcion_getStringtelefono(char mensaje[],char input[])
{
    char aux[256];
    funcion_getString(mensaje,aux);
    if(funcion_ValidarTelefono(aux))
    {
        strcpy(input,aux);
        return 1;
    }
    return 0;
}

//********************************************************************************************************

int funcion_opciones()
{
    int opcionIngresada;
    char auxOpcion[5];


    system("cls");
    printf("\n******* MENU DE OPCIONES ******* \n\n");
    printf(" 1- ALTA \n");
    printf(" 2- MODIFICAR \n");
    printf(" 3- BAJA \n");
    printf(" 4- INFORMAR \n");
    printf(" 5- SALIR \n ");
    while(!funcion_getStringNumeros("Ingrese una opcion del 1-5 : ",auxOpcion))
    {
        printf("ERROR- La opcion tiene que ser solo numeros del 1 al 5\n\n");

        system("pause");
    }

    opcionIngresada=atoi(auxOpcion);


    return opcionIngresada;
}

void funcion_Inicializar(eEmpleado list[], int tam)
{

    for(int i=0; i < tam; i++)
    {

        list[i].isEmpty = 1;

    }

}


void funcion_mostrarEmpleado(eEmpleado list)
{

    printf("\nID:%d - NOMBRE:%s - APELLIDO:%s - SECTOR:%s - SALARIO:%.2f \n\n", list.id, list.nombre, list.lastName, list.sector, list.salary);
}
void funcion_mostrarEmpleados(eEmpleado list[], int tam)
{

    system("cls");
    printf("\n ID NOMBRE APELLIDO SECTOR SALARIO\n\n");

    for(int i=0; i < tam; i++)
    {

        if( list[i].isEmpty == 0)
        {
            funcion_mostrarEmpleado(list[i]);
        }
    }
    system("pause");
}
int funcion_BuscarEmpleadoXID(eEmpleado list[], int tam, int id)
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

int funcion_BuscarLugarVacio(eEmpleado list[],int tam)
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




void funcion_ordenarEmpleadosXlID(eEmpleado list[], int tam)
{
    eEmpleado auxEmpleado;
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

                if( list[i].id > list[j].id)
                {
                    auxEmpleado = list[i];
                    list[i] = list[j];
                    list[j] = auxEmpleado;

                }
            }
        }
        printf("Empleados oredenados de forma ascendente\n\n");
        break;
    case 2:
        for(int i=0; i<tam-1; i++)
        {
            for(int j= i+1; j < tam; j++)
            {

                if( list[i].id < list[j].id)
                {
                    auxEmpleado = list[i];
                    list[i] = list[j];
                    list[j] = auxEmpleado;

                }
            }
        }
        printf("Empleados oredenados de forma descendente\n\n");
        break;
    }




}
void funcion_ordenarEmpleadosXApellido(eEmpleado list[], int tam)
{
    eEmpleado auxEmpleado;
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

                if( list[i].lastName > list[j].lastName)
                {
                    auxEmpleado = list[i];
                    list[i] = list[j];
                    list[j] = auxEmpleado;

                }
            }
        }
        printf("Empleados oredenados de forma ascendente\n\n");
        break;
    case 2:
        for(int i=0; i<tam-1; i++)
        {
            for(int j= i+1; j < tam; j++)
            {

                if( list[i].lastName < list[j].lastName)
                {
                    auxEmpleado = list[i];
                    list[i] = list[j];
                    list[j] = auxEmpleado;

                }
            }
        }
        printf("Empleados oredenados de forma descendente\n\n");
        break;
    }




}
float funcion_Promedio(eEmpleado list[],int tam)
{
    float acumSalario = 0;
    int contSalario = 0;
    float promedio;
    for(int i = 0; i < tam; i++ )
    {

        if(list[i].isEmpty == 0)
        {
            acumSalario = acumSalario + list[i].salary ;
            contSalario++;

        }
    }

    promedio = (acumSalario / contSalario);

    return promedio;
}
int funcion_AltaEmpleado(eEmpleado list[], int tam)
{
    eEmpleado nuevoEmpleado ;
    int returns;
    int index ;
    char auxNombre[31];
    char auxApellido[31];
    char auxSalary[11] ;
    char auxSector[11] ;


    if(list != NULL && tam > 0)
    {
        system("cls");
        fflush(stdin);
        index = funcion_BuscarLugarVacio(list,tam) ;
        printf("\n**** Nuevo Empleado ****\n\n");

        if(index == -1)
        {
            printf("No hay lugar en el sistema. \n") ;
            returns = -1 ;
            system("pause");

        }
        else
        {


            printf("\n Nuevo empleado, ID numero %d \n",index) ;
            nuevoEmpleado.id = index ;
            if(!funcion_getStringLetras("Ingrese nombre: ",auxNombre))
            {
                printf("El nombre solo debe tener letras.\n\n") ;
                system("pause");
                system("cls");

            }
            else if(!funcion_getStringLetras("Ingrese apellido: ",auxApellido))
            {
                printf("El apellido debe tener solo letras.\n\n") ;
                system("pause");
                system("cls");

            }
            else if(!funcion_getStringNumerosFlotantes("Ingrese el salario: ",auxSalary) && auxSalary > 0)
            {
                printf("**** Error ****\n\n");
                system("pause");
                system("cls");

            }
            else if(!funcion_getStringLetras("Ingrese el sector: ",auxSector))
            {
                printf("Error el sector debe tener solo letras.\n\n");
                system("pause");
                system("cls");
            }
            else
            {
                strcpy(nuevoEmpleado.nombre,auxNombre) ;
                strcpy(nuevoEmpleado.lastName,auxApellido) ;
                strcpy(nuevoEmpleado.sector,auxSector) ;
                nuevoEmpleado.salary = atof(auxSalary) ;
                nuevoEmpleado.isEmpty = 0;
                list[index] = nuevoEmpleado ;
                system("pause");
                system("cls");
                printf("\n\nNUEVO EMPLEADO INGRESADO:\n\n");
                funcion_mostrarEmpleado(list[index]);
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

void funcion_modificarEmpleado(eEmpleado list[], int tam)
{
    int id;
    int index;
    int opcion;
    char auxOpcion[3];
    char auxId[11];
    char newSalary[11];
    char newSector[11];
    char newNombre[31] ;
    char newLastName[31] ;


    system("cls");
    printf("  *** Modificar  empleado ***\n\n");


    if(!funcion_getStringNumeros("Ingrese id: ",auxId))
    {
        printf("*** ERROR *** El id debe contener solo numeros.") ;
    }

    id = atoi(auxId) ;
    index = funcion_BuscarEmpleadoXID(list, tam, id);


    if( index == -1)
    {
        printf("No hay ningun empleado con ese id %d.\n\n", id);
        system("pause");
    }
    else
    {
char seguirModificando ='s';
do{
       system("cls");
        funcion_mostrarEmpleado(list[index]) ;


    if(!funcion_getStringNumeros("\n\nQue desea modificar?\n\n1 - Nombre\n2 - Apellido\n3 - Sueldo\n4 - Sector\n5 - Salir\n\nOpcion:",auxOpcion))
    {
        printf("ERROR- INGRESE UN NUMERO");
    }

    opcion = atoi(auxOpcion);

    switch(opcion)
    {


       case 1:
        funcion_mostrarEmpleado(list[index]) ;
        printf("\n\n");
       //modificar nombre
        if(!funcion_getStringLetras("Ingrese nuevo nombre: ",newNombre))
            {
                printf("*** Error *** El nombre debe tener solo letras.");
            }else
            {
            strcpy(list[index].nombre,newNombre);
            printf("\n\n        ***Modificacion exitosa***\n\n");
            funcion_mostrarEmpleado(list[index]);
            system("pause");
            break ;
       }
    case 2:
// Modifica apellido
        funcion_mostrarEmpleado(list[index]) ;
        printf("\n\n");
        if(!funcion_getStringLetras("Ingrese nuevo apellido: ",newLastName))
            {
                printf("*** ERROR *** El apellido debe tener solo letras.\n\n");
            }else{

            strcpy(list[index].lastName,newLastName);
            printf("\n\n        ***Modificacion exitosa***\n\n");
            funcion_mostrarEmpleado(list[index]);
            system("pause");
            }
        break ;
    case 3:
        // modifica sueldo
        funcion_mostrarEmpleado(list[index]) ;
        printf("\n\n");
        if(!funcion_getStringNumerosFlotantes("Ingrese nuevo sueldo: ",newSalary))
            {
                printf("*** ERROR *** El salario debe contener solo numeros.") ;
            }else{

            list[index].salary = atof(newSalary);
            printf("\n\n        ***Modificacion exitosa***\n\n");
            funcion_mostrarEmpleado(list[index]);
            system("pause");
            }
            break ;
    case 4:
        // MODIFICA SECTOR
        funcion_mostrarEmpleado(list[index]) ;
        printf("\n\n");
        if(!funcion_getStringNumeros("Ingrese nuevo sector: ",newSector))
            {
                printf("*** ERROR *** El sector tiene que ser un numero") ;
            }

            strcpy(list[index].sector,newSector);

            printf("\n\n        ***Modificacion exitosa***\n\n");
            funcion_mostrarEmpleado(list[index]);
            system("pause");
            system("cls") ;
            break ;
    case 5:
        seguirModificando='n';
        funcion_mostrarEmpleado(list[index]);
        break;
    default:
        printf("*** ERROR *** Debe ingresar un numero del 1 al 4.\n");
        system("pause");
        break;
        }
} while (seguirModificando =='s');
        }
    }
int funcion_BajaEmpleado(eEmpleado list[], int tam, int id)
{

    int index;
    int returns ;
    char auxID[10] ;
    char seguir;

    if(list != NULL && tam > 0)
    {
        system("cls");
        printf("  *** BAJA EMPLEADO ***\n\n");


        if(!funcion_getStringNumeros("Ingrese id: ",auxID))
        {
            printf("*** ERROR *** El ID debe contener solo numeros.\n\n");
            system("pause") ;
            system("cls");
        }
        else
        {
            id = atoi(auxID) ;

            index = funcion_BuscarEmpleadoXID(list,tam,id) ;


            if(index == -1)
            {
                printf("No hay ningun empleado con ese id %d",id) ;
            }
            else
            {
                returns = 0;
                funcion_mostrarEmpleado(list[index]) ;
                printf("¿Seguro que quiere borrar empleado? S o N");
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
void funcion_harcodeoEmployee(eEmpleado list[])
{

    eEmpleado x[] = {
        {10,"Eliana","Perez",20000, "rrhh"},
        {23,"Pedro","Picas",30000, "it"},
        {29,"Juana","Luquez",18000, "ff"},
        {39,"Ana","Puertas",20000, "rt"},
        {34,"Sara","Casas",30000, "as"}
    };
    for(int i = 0; i< 5; i++)
    {
        list[i] = x[i];
    }
}

