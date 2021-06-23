#include <stdio.h>
#include <stdlib.h>
#include <Controller.h>
#include "LinkedList.h"
#include "Employee.h"



int controller_loadFromText(char path[50] , LinkedList* pArrayListEmployee)
{
     int cant;
    char confirma;
    int todoOk;
    int flag = 0;
    Employee* auxEmpleado;
    FILE* f;

    if(path!= NULL && pArrayListEmployee != NULL)
    {
        printf("Ingrese Path: ");
        fflush(stdin);
        gets(path);

        f = fopen(path, "r");

        if(f != NULL)
        {
            printf(" No se pudo abrir el archivo\n");
        }else
        {
            if(ll_len(*pArrayListEmployee) > 0)
            {
                printf("Cuidado se van a sobre escribir los empleados.\n\n Confirma? ");
                fflush(stdin);
                scanf("%c", &confirma);
            }

            if( ll_len == 0 || confirma == 's')
            {
                ll_clear(*pArrayListEmployee);
                parser_EmployeeFromText(f, pArrayListEmployee);
            }

        }
        fclose(f);


    }

    return todoOk;
}


int controller_loadFromBinary(char path[50] , LinkedList* pArrayListEmployee)
{
    int cant;
    char confirma;
    int todoOk;
    int flag = 0;
    Employee* auxEmpleado;
    FILE* f;

    if(path!= NULL && pArrayListEmployee != NULL)
    {
        printf("Ingrese Path: ");
        fflush(stdin);
        gets(path);

        f = fopen(path, "rb");

        if(f != NULL)
        {
            printf(" No se pudo abrir el archivo\n");
        }else
        {
            if(ll_len(*pArrayListEmployee) > 0)
            {
                printf("Cuidado se van a sobre escribir los empleados.\n\n Confirma? ");
                fflush(stdin);
                scanf("%c", &confirma);
            }

            if( ll_len == 0 || confirma == 's')
            {
                ll_clear(*pArrayListEmployee);
                parser_EmployeeFromBinary(f, pArrayListEmployee);
            }

        }
        fclose(f);


    }

    return todoOk;
}


int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}


int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}


int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}


int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}


int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    return 1;
}


int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int cant;
    char confirma = 's';
    int todoOk = 0;
    Employee* auxEmpleado;
    FILE* f;

    if(path!= NULL && pArrayListEmployee != NULL)
    {
        printf("Ingrese Path: ");
        fflush(stdin);
        gets(path);

        f = fopen(path, "r");

        if(f != NULL)
        {
            printf(" Cuidado, el archivo existe y se va a sobrescribir\n\n Confirma? ");
            fflush(stdin);
            scanf("%c", &confirma);

        }

        fclose(f);

        if(confirma == 's')
        {
            f = fopen(path, "wb");
             if(f != NULL)
            {
                printf(" No se pudo abrir el archivo\n");
            }else
            {
                for(int i=0; i < ll_len(*pArrayListEmployee); i++)
                {
                    auxEmpleado = (Employee*) ll_get(*pArrayListEmployee, i);
                    cant = fprintf(f, "%d", x);

                    if(cant != 0)
                    {
                        printf("Se guardaron los datos correctamente\n\n");
                    }else
                    {
                        printf("Ocurrio un problema al guardar los datos\n\n");
                    }
                }
            }

            fclose(f);

        }else
        {
            printf("Ingrese un Path nuevo: ");
            fflush(stdin);
            gets(path);

            f = fopen(path, "wb");
             if(f != NULL)
            {
                printf(" No se pudo abrir el archivo\n");
            }else
            {
                for(int i=0; i < ll_len(*pArrayListEmployee); i++)
                {
                    auxEmpleado = (Employee*) ll_get(*pArrayListEmployee, i);
                    if(fwrite(pArrayListEmployee, sizeof(Employee), ll_le, f) == TAM)

                }
            }

            fclose(f);
        }

    }
    return todoOk;
}


int controller_saveAsBinary(char path[50] , LinkedList* pArrayListEmployee)
{
    int cant;
    char confirma = 's';
    int todoOk = 0;
    Employee* auxEmpleado;
    FILE* f;

    if(path!= NULL && pArrayListEmployee != NULL)
    {
        printf("Ingrese Path: ");
        fflush(stdin);
        gets(path);

        f = fopen(path, "rb");

        if(f != NULL)
        {
            printf(" Cuidado, el archivo existe y se va a sobrescribir\n\n Confirma? ");
            fflush(stdin);
            scanf("%c", &confirma);

        }

        fclose(f);

        if(confirma == 's')
        {
            f = fopen(path, "wb");
             if(f != NULL)
            {
                printf(" No se pudo abrir el archivo\n");
            }else
            {
                for(int i=0; i < ll_len(*pArrayListEmployee); i++)
                {
                    auxEmpleado = (Employee*) ll_get(*pArrayListEmployee, i);

                    if(fwrite(auxEmpleado, sizeof(Employee), 1, f) == 1)
                    {
                        printf("Se guardaron los datos con exito!\n");
                        todoOk = 1;
                    }else
                    {
                        printf("Hubo un problema al guardar los datos\n");
                    }

                }
            }

            fclose(f);

        }else
        {
            printf("Ingrese un Path nuevo: ");
            fflush(stdin);
            gets(path);

            f = fopen(path, "wb");
             if(f != NULL)
            {
                printf(" No se pudo abrir el archivo\n");
            }else
            {
                for(int i=0; i < ll_len(*pArrayListEmployee); i++)
                {
                    auxEmpleado = (Employee*) ll_get(*pArrayListEmployee, i);

                    if(fwrite(auxEmpleado, sizeof(Employee), 1, f) == 1)
                    {
                        printf("Se guardaron los datos con exito!\n");
                        todoOk = 1;
                    }else
                    {
                        printf("Hubo un problema al guardar los datos\n");
                    }

                }
            }

            fclose(f);
        }

    }
    return todoOk;
}

