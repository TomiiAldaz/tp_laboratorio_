#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

typedef struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
}Employee;


#endif // ARRAYEMPLOYEES_H_INCLUDED

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list[] Employee array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL array] - (0) if Ok
 *
 */
int initEmployees(Employee list[], int len);


/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list[] employee
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL array or without
free space] - (0) if Ok
 *
 */
int addEmployee(Employee list[], int len, int* pId);



/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list[] Employee
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
array received or employee not found]
 *
 */
int findEmployeeById(Employee list[], int len, int id);



/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list[] Employee
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL array or if can't
find a employee] - (0) if Ok
 *
 */
int removeEmployee(Employee list[], int len, int id);


/** \brief print the content of employees array
 *
 * \param list[] Employee
 * \param len int
 * \return int
 *
 */
int printEmployees(Employee list[], int len);

/** \brief print the content of  only one employee
 *
 * \param list[] Employee
 * \return int
 *
 */
int printEmployee(Employee oneEmployee);

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list[] Employee
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL array] - (0) if Ok
 *
 */
int sortEmployees(Employee list[], int len, int order);


/** \brief Modify one element in the array of employees
 *
 * \param list[] Employee
 * \param len int
 * \param id int
 * \return int Return (-1) if Error - (0) if Ok
 *
 */
int modifyEmployee(Employee list[], int len);

/** \brief Reports menu
 *
 * \param list[] Employee
 * \param len int
 * \return int Return (-1) if Error - (0) if Ok
 *
 */
int totalYPromedioSalarios(Employee list[], int len);


/** \brief switch of reports menu
 *
 * \return int 0
 *
 */
int switchOpciones(Employee list[], int len);
