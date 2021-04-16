#ifndef TOMAS_H_INCLUDED
#define TOMAS_H_INCLUDED




#endif // TOMAS_H_INCLUDED

/** \brief muestra el menu de la calculadora
 *
 * \return char devuelve la opcion seleccionada
 *
 */
char menu();

/** \brief realiza la division de dos enteros
 *
 * \param a int dividendo de la operacion
 * \param b int divisor de la operacion
 * \param c float* puntero
 * \return float devuelve el resultado de la division
 *
 */
int dividirRobusta(int a, int b, float* c);


/** \brief realiza el factorial de un entero, el entero debe ser menor a 17
 *
 * \param n int  entero a realizar la operacion
 * \return int devuelve el resultado del factorial del numero
 *
 */
int factorial(int n);

/** \brief realiza la suma de dos enteros
 *
 * \param a int primer entero a realizar la operacion
 * \param b int segundo entero a realizar la operacion
 * \return int devuelve el resultado de la suma
 *
 */
int sumar(int a, int b);



/** \brief realiza la resta de dos enteros
 *
 * \param a int minuendo de la operacion
 * \param b int sustraendo de la operacion
 * \return int devuelve el resultado de la resta
 *
 */
int restar(int a, int b);

/** \brief realiza la multiplicacion de dos enteros
 *
 * \param a int multiplicando de la operacion
 * \param b int multiplicador de la operacion
 * \return int devuelve el producto de la operacion
 *
 */
int multiplicar(int a, int b);
