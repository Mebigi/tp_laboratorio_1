#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>


//INGRESO Y VALIDAR DATOS INGRESADOS

float IngresarFlotante(float min, float max)
{
    float numero;

    scanf("%f", &numero);
    numero = validarFlotante(numero, min, max);

    return numero;
}


float validarFlotante(float datoflot, float min, float max)
{
    while(datoflot < min || datoflot > max)
    {

        fflush(stdin);
        printf("Dato no v%clido reingresar (valores entre %.f y %.f):\n", 160, min, max);
        scanf("%f", &datoflot);


    }

    return datoflot;
}


int IngresarEntero(int min, int max)
{
    int entero;

    fflush(stdin);
    scanf("%d",&entero);
    entero = validarEntero(entero, min, max);

    return entero;
}




int validarEntero (int dato, int min, int max)
{
    while(dato < min || dato > max)
    {

        fflush(stdin);
        printf("Dato no v%clido reingresar:\n", 160);
        scanf("%d", &dato);

    }

    return dato;

}


//OPERACIONES


float sumar(float numero1, float numero2)
{
    float resultado;
    resultado = numero1 + numero2;
    return resultado;
}

float restar(float numero1, float numero2)
{
    float resultado;
    resultado = numero1 - numero2;
    return resultado;
}


float dividir(float numero1, float numero2)
{
    float resultado;
    resultado = numero1/numero2;
    return resultado;
}


float multiplicar(float numero1, float numero2)
{
    float resultado;
    resultado = numero1*numero2;
    return resultado;
}

long long int factorizar(int numero)
{

    long long int factorial = 1;
    for (int i=1;i<=numero;i++)
    {
        factorial = factorial * i;
    }
    return factorial;

}

