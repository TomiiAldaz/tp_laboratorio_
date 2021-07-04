#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"


int menu();

int main()
{

    char salir = 'n';
    int nextId = 1;
    int flagE = 0;

    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
        switch(menu())
        {
            case 1:
                controller_loadFromText("data.csv",listaEmpleados);
                break;
            case 2:
                controller_loadFromBinary(".bin",listaEmpleados);
                break;
            case 3:
                if(nextId )
                {
                    printf("\nAlta exitosa.\n");
                }else
                {
                    printf("Hubo un problema al realizar el alta.\n\n");
                }
                flagE = 1;
                break;
            case 4:
                if(flagE)
                {
                    if( )
                    {
                        printf("Modificacion exitosa.\n");
                    }else
                    {
                        printf("Hubo un problema al realizar la modificacion.\n\n");
                    }
                }
                else
                {
                    printf("\nAntes de modificar un empleado, primero debes dar de alta un empleado\n\n");
                }
                break;
            case 5:
                if(flagE)
                {
                    if()
                    {
                        printf("\nBaja exitosa.\n");
                    }
                    else
                    {
                        printf("Hubo un problema al realizar la baja.\n\n");
                    }
                }
                else
                {
                    printf("\nAntes de dar de baja un empleado, primero debes dar de alta un empleado\n\n");
                }
                break;
            case 6:
                if(flagE)
                {
                    system("cls");
                    if()
                    {
                        printf("\n\n Listado exitoso\n");
                    }else
                    {
                        printf("\n\n Hubo un problema al realizar el listado\n\n");
                    }
                }
                else
                {
                    printf("\nAntes de dar listar un empleado, primero debes dar de alta un empleado\n\n");
                }
                break;
            case 7:
                if(flagE)
                {
                    system("cls");
                    if()
                    {
                        printf("\n\n Ordenado exitoso\n");
                    }else
                    {
                        printf("\n\n Hubo un problema al realizar el ordenado\n\n");
                    }
                }
                else
                {
                    printf("\nAntes de ordenar una lista de empleados, primero debes dar de alta un empleado\n\n");
                }
                break;
            case 8:
                controller_saveAsText(".csv",listaEmpleados);
                break;
            case 9:
                controller_saveAsBinary(".bin",listaEmpleados);
                break;
            case 10:
                printf("\n   Confirma salida?: ");
                fflush(stdin);
                salir = getchar();
                break;
            default:
                printf("\n   Opcion Invalida!\n");
                fflush(stdin);
                printf("\n");
        }
        printf("\n");
        system("pause");
    }while(salir == 'n');

    return 0;
}

int menu(){

    int opcion;

    system("cls");
    printf("      Menu de Opciones\n\n");
    printf("   1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("   2. Cargar los datos de los empleados desde el archivo data.bin (modo binario).\n");
    printf("   3. Alta del empleado.\n");
    printf("   4. Modificar datos del empleado.\n");
    printf("   5. Baja del empleado.\n");
    printf("   6. Listar empleados.\n");
    printf("   7. Ordenar empleados.\n");
    printf("   8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("   9. Guardar los datos de los empleados en el archivo data.bin (modo binario).\n");
    printf("   10. Salir\n");
    printf("   Introduzca opcion (1-10): ");
    fflush(stdin);

    scanf("%d", &opcion);


    return opcion;
}
