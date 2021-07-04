#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr);
void employee_delete(Empleado* p);

int employee_setId(Employee* e,int id);
int employee_getId(Employee* e,int* id);

int employee_setNombre(Employee* e,char* nombre);
int employee_getNombre(Employee* e,char* nombre);

int employee_setHorasTrabajadas(Employee* e,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* e,int* horasTrabajadas);

int employee_setSueldo(Employee* e,int sueldo);
int employee_getSueldo(Employee* e,int* sueldo);

int mostrarEmployee(LinkedList* lista);
int mostrarEmpleado(Employee* p);
int buscarMayorId(LinkedList* lista, int* id);
#endif // employee_H_INCLUDED
