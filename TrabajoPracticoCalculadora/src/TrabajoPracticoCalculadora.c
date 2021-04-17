
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include "tomas.h"

int main(void) {

		setbuf(stdout, NULL);
		char salir ='n';
	    int numero1;
	    int numero2;
	    int flagNum1 = 0;
	    int flagNum2 = 0;
	    int flagOperaciones = 0;
	    int resultadoSuma;
	    int resultadoResta;
	    float resultadoDivision;
	    int resultadoMultiplicacion;
	    int resultadoFactorial;
	    int resultadoFactorial2;
	    int OkDivision;



	    do
	    {


	        switch(menu())
	        {

	        case '1':
	            printf("\n   Introduzca el 1er operando A =  ");
	            scanf("%d", &numero1);
	            printf("\n   El numero se cargo con exito A = %d \n", numero1);
	            flagNum1 = 1;
	            printf("\n");
	           // system("pause");
	            break;

	        case '2':
	            if( flagNum1 )
	            {
	                printf("\n   Introduzca el 2do operando B =  ");
	                scanf("%d", &numero2);
	                printf("\n   El numero se cargo con exito B = %d \n", numero2);
	                flagNum2 = 1;
	            }
	            else
	            {
	                printf("\n   Antes de introducir el 2do operando, ingresar el 1ero.\n");

	            }
	            printf("\n");
	           // system("pause");
	            break;

	        case '3':
	            if( !flagNum2 && flagNum1)
	            {
	                printf("\n   Antes de calcular las operaciones deberias ingresar el 2do operando.\n");
	            }
	            else if( flagNum1 && flagNum2)
	            {
	                printf("\n   Calculando las operaciones...\n");
	                resultadoSuma = sumar(numero1, numero2);
	                resultadoResta = restar(numero1, numero2);
	                OkDivision = dividirRobusta(numero1, numero2, &resultadoDivision);
	                resultadoMultiplicacion = multiplicar(numero1, numero2);
	                resultadoFactorial = factorial(numero1);
	                resultadoFactorial2 = factorial(numero2);
	                printf("\n   Listo.\n");

	                flagOperaciones = 1;
	            }
	            else
	            {
	                printf("\n   Antes de calcular las operaciones deberias ingresar el 1er operando.\n");
	            }
	            printf("\n");
	          //  system("pause");
	            break;

	        case '4':
	            if(flagNum1 && flagNum2 && flagOperaciones)
	            {
	                printf("\n   Mostrando Resultados.\n");
	                printf("\n   El resultado de A+B es: %d.\n", resultadoSuma);
	                printf("\n   El resultado de A-B es: %d.\n", resultadoResta);
	                if (OkDivision)
	                {
	                    printf("\n   El resultado de A/B es: %.2f", resultadoDivision);

	                }else
	                {
	                    printf("\n   No es posible dividir por cero.\n");
	                }
	                printf("\n   El resultado de A*B es: %d.\n", resultadoMultiplicacion);
	                if (numero2 < 0 && numero1 > 0)
	                {
	                            printf("\n   El factorial de A es: %d . No se puede hacer el factorial de B, ya que B es un numero negativo.", resultadoFactorial);
	                }else if (numero2 > 0 && numero1 < 0)
	                {
	                    printf("\n   El factorial de B es: %d . No se puede hacer el factorial de A, ya que A es un numero negativo.", resultadoFactorial2);
	                }else if (numero1 > 0 && numero2 > 0 )
	                {
	                    printf("\n   El factorial de A es: %d y el factorial de B es: %d\n", resultadoFactorial, resultadoFactorial2);

	                }else
	                {
	                    printf("\n   No es posible hacer el factorial de A y de B ya que ambas tienen asignado un numero negativo\n");
	                }

	            }
	            else
	            {
	                printf("\n   Antes de mostrar los resultados deberias calcularlos.\n");
	            }
	            printf("\n");
	        //    system("pause");
	            break;

	        case '5':

	            printf("\n   Confirma salida?: ");
	            fflush(stdin);
	            salir = getchar();
	            break;

	        default:
	            printf("\n   Opcion Invalida!\n");
	            fflush(stdin);
	            printf("\n");
	       //     system("pause");

	        }


	    }
	    while(salir == 'n');




	    return EXIT_SUCCESS;

}
