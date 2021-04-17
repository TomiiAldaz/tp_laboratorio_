#include <stdio.h>
#include <stdlib.h>



char menu(){

    char opcion;

    system("cls");
    printf("   >>> MENU CALCULADORA <<<\n\n");
    printf("   1. Ingresar 1er operando (A=x).\n");
    printf("   2. Ingresar 2do operando (B=y).\n");
    printf("   3. Calcular todas las operaciones.\n");
    printf("   4. Informar resultados.\n");
    printf("   5. Salir.\n\n");
    printf("   Introduzca opcion (1-5): ");
    fflush(stdin);
    scanf("%c", &opcion);

    return opcion;
}


int dividirRobusta(int a, int b, float* c){

    int todoOk = 0;

    if( b != 0 && c != NULL )
    {
        *c = (float) a / b;
        todoOk = 1;
    }


    return todoOk;
}

int factorial (int n)
{
    int fact = 1;
    int i;

    for(i=1; i<= n; i++)
    {

        fact *= i;

    }

    return fact;

}


int sumar(int a, int b){

    int resultado;

    resultado = a + b;

    return resultado;
}

int restar(int a, int b){

    int resultado;

    resultado = a - b;

    return resultado;
}

int multiplicar(int a, int b){

    int resultado;

    resultado = a * b;

    return resultado;
}


