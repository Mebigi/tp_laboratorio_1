#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define MAXFLOAT 9999999.000000
#define MINFLOAT -9999999.000000
#define MAX_MENU 9
#define MIN_MENU 1



int main()
{
    char seguir='s';
    int opcion=0;
    float numeroUno=0;
    float numeroDos=0;
    float resultado;
    int flag1 = 0;
    int flag2 = 0;
    long long int resultadofactorizar;






    while(seguir=='s')
    {
        printf("\nCALCULADORA\n");
        if (flag1 == 1)
        {
            printf("1- Ingresar 1er operando (A=%f)\n", numeroUno);

        }
        else
        {
            printf("1- Ingresar 1er operando (A=X)\n");
        }

        if (flag2 == 1)
        {
            printf("2- Ingresar 2do operando (B=%f)\n", numeroDos);
        }
        else
        {
            printf("2- Ingresar 2do operando (B=Y)\n");
        }


        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la divisi%cn (A/B)\n", 162);
        printf("6- Calcular la multiplicaci%cn (A*B)\n", 162);
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operaciones\n");
        printf("9- Salir\n\n");

        printf("\nElegir Opci%cn del Men%c de 1 al 9\nOpci%cn: ", 162,163,162);

        opcion = IngresarEntero(MIN_MENU, MAX_MENU);



        switch(opcion)
        {
        case 1:

            printf("\nIngresar 1er operando: ");

            numeroUno = IngresarFlotante(MINFLOAT, MAXFLOAT);
            flag1 = 1;
            break;

        case 2:
            printf("\nIngresar 2do operando: ");
            numeroDos = IngresarFlotante(MINFLOAT, MAXFLOAT);
            flag2 = 1;
            break;


        case 3:

            if (flag1 == 1 && flag2 == 1)
            {
            resultado = sumar(numeroUno, numeroDos);
            printf("---------------------------------------------------\n");
            printf("%f + %f= %f\n", numeroUno, numeroDos, resultado);
            printf("---------------------------------------------------\n");

            }
            else {
                 printf("No es posible realizar la operaci%cn: Falta por lo menos 1 operando", 162);

            }



            break;



        case 4:



            if (flag1 == 1 && flag2 == 1)
            {
            resultado = restar(numeroUno, numeroDos);

            printf("---------------------------------------------------\n");
            printf("%f - %f= %f\n", numeroUno, numeroDos, resultado);
            printf("---------------------------------------------------\n");

            }
            else {
                 printf("No es posible realizar la operaci%cn: Falta por lo menos 1 operando", 162);

            }


            break;

        case 5:

            if (flag1 == 1 && flag2 == 1 && numeroDos != 0)
            {

            resultado = dividir(numeroUno, numeroDos);

            printf("---------------------------------------------------\n");
            printf("%f / %f= %f\n", numeroUno, numeroDos, resultado);
            printf("---------------------------------------------------\n");

            }
            else {

                printf("La operaci%cn no pudo realizarse porque falta algun operador y/o el denominador debe ser distinto de cero", 162);

            }



            break;

        case 6:

            resultado = multiplicar(numeroUno, numeroDos);
            printf("---------------------------------------------------\n");
            printf("%f * %f= %f\n", numeroUno, numeroDos, resultado);
            printf("---------------------------------------------------\n");
            break;

        case 7:

            if((int)numeroUno == numeroUno && numeroUno <=20 && numeroUno>=0 && flag1 == 1)
            {
            resultadofactorizar = factorizar((int)numeroUno);
            printf("---------------------------------------------------\n");
            printf("(%d!)= %lld\n", (int)numeroUno, resultadofactorizar);
            printf("---------------------------------------------------\n");

            }

            else {

             printf("\nCon esta Calculadora, solo es posible calcular el factorial (A!) de n%cmeros \nenteros comprendidos ente 0 y 20\n", 163);

            }
            break;

        case 8:
            printf("\nCalcular todas las operaciones\n");

            resultado = sumar(numeroUno, numeroDos);

            printf("---------------------------------------------------\n");
            printf("%f + %f= %f\n", numeroUno, numeroDos, resultado);
            printf("---------------------------------------------------\n");

            resultado = restar(numeroUno, numeroDos);

            printf("---------------------------------------------------\n");
            printf("%f - %f= %f\n", numeroUno, numeroDos, resultado);
            printf("---------------------------------------------------\n");


            if (numeroDos == 0 || flag2 == 0)
            {
                printf("No es posible dividir por cero\n");


            }
            else {

            resultado = dividir(numeroUno, numeroDos);

            printf("---------------------------------------------------\n");
            printf("%f / %f= %f\n", numeroUno, numeroDos, resultado);
            printf("---------------------------------------------------\n");


            }

            resultado = multiplicar(numeroUno, numeroDos);
            printf("---------------------------------------------------\n");
            printf("%f * %f= %f\n", numeroUno, numeroDos, resultado);
            printf("---------------------------------------------------\n");

            if((int)numeroUno == numeroUno && numeroUno <=20 && numeroUno>=0 )
            {
            resultadofactorizar = factorizar((int)numeroUno);
            printf("---------------------------------------------------\n");
            printf("(%d!)= %lld\n", (int)numeroUno, resultadofactorizar);
            printf("---------------------------------------------------\n");

            }

            else {

            printf("\nCon esta Calculadora, solo es posible calcular el factorial (A!) de n%cmeros \nenteros comprendidos ente 0 y 20\n", 163);

            }






            break;

            case 9:
            printf("Salir\n");
            seguir = 'n';
            break;
        }



    printf("\n\n");
    system("pause");
    system("cls");


    }



    return 0;

}
















