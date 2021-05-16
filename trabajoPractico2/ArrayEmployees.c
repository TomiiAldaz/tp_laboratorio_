#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"

int initEmployees(Employee list[], int len)
{
    int todoOk = -1;

    if( list != NULL && len > 0)
    {
        for(int i=0; i < len; i++)
        {
            list[i].isEmpty = 1;
            todoOk = 0;
        }
    }
    return todoOk;
}
int addEmployee(Employee list[], int len, int* pId){

    int todoOk = -1;
    int i;

    Employee auxEmpleado;

    system("cls");
    printf("    Alta Empleado\n\n");
    if( list != NULL && len > 0 && pId != NULL)
    {
        i = initEmployees(list, len);

        if(i == -1)
        {
            printf("No hay lugar en el sistema\n");
        }
        else
        {
            printf("Ingrese nombre: ");
            fflush(stdin);
            gets(auxEmpleado.name);

            printf("Ingrese apellido: ");
            fflush(stdin);
            gets(auxEmpleado.lastName);

            printf("Ingrese sueldo: ");
            scanf("%f", &auxEmpleado.salary);

            printf("Ingrese sector: ");
            scanf("%d", &auxEmpleado.sector);

            auxEmpleado.isEmpty = 0;

            auxEmpleado.id = *pId;
            *pId = *pId + 1;

            list[i] = auxEmpleado;
            todoOk = 0;
        }
    }
    return todoOk;
}


int findEmployeeById(Employee list[], int len, int id)
{
    int indice = -1;

    if( list != NULL && len > 0 && id > 0 && id < 1000)
    for(int i=0; i < len; i++)
    {
        if(list[i].id == id && list[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }

    return indice;
}

int removeEmployee(Employee list[], int len, int id){

    int todoOk = -1;
    int indice;
    char confirma;

    if( list != NULL && len > 0 && id > 0 && id < 1000)
    {
        system("cls");
        printf("    Baja de Empleado\n\n");
        printEmployees(list, len);
        printf("Ingrese el ID del empleado que desea dar de baja: ");
        scanf("%d", &id);
        printf("\n");

        indice = findEmployeeById(list, len, id);

        if( indice == -1)
        {
            printf("No hay ningun empleado registrado con el id: %d\n", id);
        }
        else
        {
            printEmployee(list[indice]);
            printf("\nConfirma baja?: ");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma == 's')
            {
                list[indice].isEmpty = 1;
                todoOk = 1;
            }
            else
            {
                printf("Baja cancelada por el usuario\n");
            }

        }
    }else
    {
        printf("Hubo un error. Verifique que el id que ingreso sea mayor a 0 y menor a mil");
    }
    return todoOk;
}

int printEmployee(Employee oneEmployee){


    printf("%d   %10s %10s   %9.2f    %d\n"
            , oneEmployee.id
            , oneEmployee.name
            , oneEmployee.lastName
            , oneEmployee.salary
            , oneEmployee.sector
            );

    return 0;
}

int printEmployees(Employee list[], int len){

    if( list != NULL && len > 0)
    {

        int estado = 1;
        printf("\t         *** Listado de Empleados***\n");
        printf("------------------------------------------------------------------------------\n");
        printf("ID    Nombre  Apellido Sueldo  Sector\n");
        printf("------------------------------------------------------------------------------\n\n");
        for(int i=0; i < len; i++)
        {
            if(!list[i].isEmpty)
            {
                printEmployee(list[i]);
                estado = 0;
            }
        }
        if(estado)
        {
            printf("    No hay empleados que mostrar.");
        }
    }
    printf("\n\n");

    return 0;
}


int sortEmployees(Employee list[], int len, int order){

    int todoOk = -1;

    if(list != NULL && len > 0 && order > 0 && order < 4)
    {
        Employee auxEmpleado;

        for(int i=0; i <len-1; i++)
        {
            for(int j=i +1; j<len; j++)
            {
                char salir = 'n';

                system("cls");
                printf("   >>> ORDENAR EMPLEADOS <<<\n\n");
                printf("   1. Ordenar de Manera Ascendente.\n");
                printf("   2. Ordenar de Manera Descendente.\n");
                printf("   3. Salir.\n");
                printf("   Introduzca opcion (1-3): ");
                fflush(stdin);
                scanf("%d", &order);

                do
                {
                    switch(order)
                    {
                    case 1:
                        if ( list[i].sector > list[j].sector ||
                                ( list[i].sector == list[j].sector
                                  && strcmp(list[i].lastName, list[j].lastName) > 0))
                        {
                            auxEmpleado = list[i];
                            list[i] = list[j];
                            list[j] = auxEmpleado;
                        }
                        break;
                    case 2:
                        if ( list[i].sector < list[j].sector ||
                                ( list[i].sector == list[j].sector
                                  && strcmp(list[i].lastName, list[j].lastName) < 0))
                        {
                            auxEmpleado = list[i];
                            list[i] = list[j];
                            list[j] = auxEmpleado;
                        }
                        break;
                    case 3:
                        printf("\n   Confirma salida?: ");
                        fflush(stdin);
                        salir = getchar();
                        break;
                    default:
                        printf("\n   Opcion Invalida!\n");
                        fflush(stdin);
                        printf("\n");
                        system("pause");

                    }

                }
                while(salir == 'n');

            }
        }
    }
    return todoOk;
}

int modifyEmployee(Employee list[], int len){

    int todoOk = -1;
    int menuModificar;
    int id;
    int indice;

    if( list != NULL && len > 0)
    {
        system("cls");
        printf("    Baja de Empleado\n\n");
        printEmployees(list, len);
        printf("Ingrese el ID del empleado que desea dar de baja: ");
        scanf("%d", &id);
        do{
            printf("ID invalido. Reingrese el ID: ");
            scanf("%d", &id);

        }while(!(id > 0 && id < 1000));
        printf("\n");

        indice = findEmployeeById(list, len, id);

        if( indice == -1)
        {
            printf("No hay ningun empleado registrado con el id: %d\n", id);
        }
        else
        {
            char salir = 'n';
            todoOk = 0;

            system("cls");
            printf("   >>> MODIFICAR EMPLEADO <<<\n\n");
            printf("   1. Modificar nombre.\n");
            printf("   2. Modificar apellido.\n");
            printf("   3. Modificar salario.\n");
            printf("   4. Modificar sector.\n");
            printf("   5. Salir.\n");
            printf("   Introduzca opcion (1-5): ");
            fflush(stdin);
            scanf("%d", &menuModificar);

            do
            {
                switch(menuModificar)
                {
                case 1:
                    printf("Ingrese nuevo nombre: ");
                    fflush(stdin);
                    gets(list[indice].name);
                    break;
                case 2:
                    printf("Ingrese nuevo apellido: ");
                    fflush(stdin);
                    gets(list[indice].lastName);
                    break;
                case 3:
                    printf("Ingrese nuevo sueldo: ");
                    scanf("%f", &list[indice].salary);
                    break;
                case 4:
                    printf("Ingrese nuevo sector: ");
                    scanf("%d", &list[indice].sector);
                    break;
                case 5:
                    printf("\n   Confirma salida?: ");
                    fflush(stdin);
                    salir = getchar();
                    break;
                default:
                    printf("\n   Opcion Invalida!\n");
                    fflush(stdin);
                    printf("\n");
                    system("pause");

                }

            }while(salir == 'n');
        }
    }else
    {
        printf("Hubo un error. Verifique que el id que ingreso sea mayor a 0 y menor a mil");
    }
    return todoOk;

}

int totalYPromedioSalarios(Employee list[], int len){

    int idSector;
    int indice;
    int todoOk = 0;
    float totalSueldos = 0;
    int contador = 0;
    float promedios;
    int contadorEmpleadosMayorSalario = 0;

    if(list != NULL && len > 0)
    {
        for(int i=0; i < len; i++)
        {
            if(list[i].isEmpty == 0)
            {
                totalSueldos = list[i].salary + totalSueldos;
                contador++;
                todoOk = 1;
            }
        }

        promedios = totalSueldos / contador;
        if(totalSueldos > promedios)
        {
            contadorEmpleadosMayorSalario++;
        }


        printf(" Total Salarios: $ %.2f\n", totalSueldos);
        printf(" Promedio de los Salarios: $ %.2f\n", promedios);
        printf(" Empleados que superan el salario promedio: $ %d\n", contadorEmpleadosMayorSalario);
    }

    return todoOk;
}

int switchOpciones(Employee list[], int len){

    char salir = 'n';
    do
    {
        switch(menu())
        {

        case 1:
            if(!sortEmployees(list, len, 1))
            {
                printf("Ordenado exitoso.\n");
            }else
            {
                printf("Hubo un problema al realizar el ordenado.\n");
            }
            break;
        case 2:
            if(!totalYPromedioSalarios(list, len))
            {
                printf("Calculo exitoso.\n");
            }else
            {
                printf("Hubo un problema al realizar el calculo.\n");
            }
            break;
        case 3:
            printf("\n   Confirma salida?: ");
            fflush(stdin);
            salir = getchar();
            break;
        default:
            printf("\n   Opcion Invalida!\n");
            fflush(stdin);
            printf("\n");
            system("pause");

        }
        system("pause");

    }
    while(salir == 'n');
}
