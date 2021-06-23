#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"


Employee* employee_new()
{
    Employee* nuevoEmpleado = (Employee*) malloc(sizeof(Employee));

    if(nuevoEmpleado != NULL)
    {
        nuevoEmpleado->legajo = 0;
        strcpy(nuevoEmpleado->nombre, "");
        nuevoEmpleado->sexo = ' ';
        nuevoEmpleado->sueldo = 0;
    }

    return nuevoEmpleado;
}
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
    Employee* nuevoEmpleado = newEmpleado();

    if(nuevoEmpleado != NULL)
    {
        if(!(employee_setId(nuevoEmpleado, atoi(idStr)) &&
           employee_setNombre(nuevoEmpleado, nombreStr) &&
           employee_setHorasTrabajadas(nuevoEmpleado, atoi(horasTrabajadasStr) &&
           employee_setSueldo(nuevoEmpleado, atoi(sueldoStr)))
           ){
                employee_delete(nuevoEmpleado);
                nuevoEmpleado = NULL;
        }
    }
    return nuevoEmpleado;
}
void employee_delete(Employee* p)
{
    free(p);
}

int employee_setId(Employee* e,int id)
{
    int todoOk = 0;
    if(e != NULL && id > 0)
    {
        e->id = id;
        todoOk = 1;
    }

    return todoOk;
}
int employee_getId(Employee* e,int* id)
{
    int todoOk = 0;
    if(e != NULL && id != NULL)
    {
        *id = e->id;
        todoOk = 1;
    }

    return todoOk;
}

int employee_setNombre(Employee* e,char* nombre)
{
    int todoOk = 0;
    if(e != NULL && nombre != NULL && strlen(nombre) < 128 && strlen(nombre) > 2)
    {
        strcpy(e->nombre, nombre);
        todoOk = 1;
    }

    return todoOk;
}
int employee_getNombre(Employee* e,char* nombre)
{
    int todoOk = 0;
    if(e != NULL && pNombre != NULL)
    {
        strcpy(pNombre, e->nombre);
        todoOk = 1;
    }

    return todoOk;
}

int employee_setHorasTrabajadas(Employee* e,int horasTrabajadas)
{
    int todoOk = 0;
    if(e != NULL && horasTrabajadas > -1)
    {
        e->horasTrabajadas = horasTrabajadas;
        todoOk = 1;
    }

    return todoOk;
}
int employee_getHorasTrabajadas(Employee* e,int* horasTrabajadas)
{
    int todoOk = 0;
    if(e != NULL && horasTrabajadas != NULL)
    {
        *horasTrabajadas = e->horasTrabajadas;
        todoOk = 1;
    }

    return todoOk;
}

int employee_setSueldo(Employee* e,int sueldo)
{
    int todoOk = 0;
    if(e != NULL && sueldo > 0)
    {
        e->sueldo = sueldo;
        todoOk = 1;
    }

    return todoOk;
}
int employee_getSueldo(Employee* e,int* sueldo)
{
    int todoOk = 0;
    if(e != NULL && sueldo != NULL)
    {
        *sueldo = e->sueldo;
        todoOk = 1;
    }

    return todoOk;
}

int mostrarEmployee(LinkedList* lista)
{
    int todoOk = 0;
    Employee* auxEmpleado;
    if(lista != NULL)
    {
        printf("  ID  Nombre   HsTrabajadas  Sueldo\n\n");
        for(int i=0; i < ll_len(lista); i++)
        {
            auxEmpleado = (Employee*) ll_get(lista, i);
            mostrarEmpleado(auxEmpleado));
        }
        printf("\n\n");
        todoOk = 1;
    }

    return todoOk;
}

int mostrarEmpleado(Employee* p)
{
    int todoOk = 0;
    int id;
    char nombre[20];
    int horasTrabajadas;
    int sueldo;

    if(p != NULL
       && employee_getId(p, &id)
       && employee_getNombre(p, nombre)
       && employee_getHorasTrabajadas(p, &horasTrabajadas)
       && employee_getSueldo(p, &sueldo)
       )
    {
        printf("  %d    %-10s %d   %d\n",
            id,
            nombre,
            horasTrabajadas,
            sueldo);

        todoOk = 1;
    }
    return todoOk;
}

int buscarMayorId(LinkedList* lista, int* id)
{
    int todoOk = 0;
    Employee* auxEmpleado = NULL;
    int mayor;

    if(lista != NULL)
    {
        for(int i=0; i < ll_len(lista); i++)
        {
            auxEmpleado = (Employee*) ll_get(lista, i);
            if(i == 0 || auxEmpleado->id > mayor)
            {
                mayor = auxEmpleado->id;
            }
        }
        *id = mayor + 1;
        todoOk = 1;
    }

    return todoOk;
}
