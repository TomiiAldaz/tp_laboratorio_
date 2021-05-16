#include <stdio.h>
#include <stdlib.h>
#include "ArrayEmployees.h"

#define ELEMENTS 2

int menu();
int switchOpciones();
int menuInformes();

int main()
{

    Employee roster[ELEMENTS];

    int nextId = 200;
    initEmployees(roster, ELEMENTS);

    char salir = 'n';
    do
    {
        switch(menu())
        {

        case 1:
            if(!addEmployee(roster, ELEMENTS, &nextId))
            {
                printf("Alta exitosa.\n");
            }else
            {
                printf("Hubo un problema al realizar el alta.\n");
            }
            break;
        case 2:
            if(!modifyEmployee(roster, ELEMENTS))
            {
                printf("Alta exitosa.\n");
            }else
            {
                printf("Hubo un problema al realizar el alta.\n");
            }
            break;
        case 3:
            if(!removeEmployee(roster, ELEMENTS, 201))
            {
                printf("Baja exitosa.\n");
            }else
            {
                printf("Hubo un problema al realizar la baja.\n");
            }
            break;
        case 4:
            system("cls");
            printf("   Informes\n\n");
            switchOpciones(roster, ELEMENTS);
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
        system("pause");

    }
    while(salir == 'n');

    return 0;
}

int menu(){

    int opcion;
    system("cls");
    printf("   >>> ABM EMPLEADOS <<<\n\n");
    printf("   1. Alta empleado.\n");
    printf("   2. Baja empleado.\n");
    printf("   3. Modificar empleado.\n");
    //printf("   4. Ordenar empleados.\n");
    printf("   4. Informes.\n");
    printf("   Introduzca opcion (1-4): ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}


int menuInformes(){

    int opcion2;
    printf("   1. Ordenar empleados.\n");
    printf("   2. Total y Promedio de los salarios.\n");
    printf("   3. Salir.\n");
    printf("   Introduzca opcion (1-3): ");
    fflush(stdin);
    scanf("%d", &opcion2);

    return opcion2;
}
