#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>




void cargarDatosHardCode(EPersona lista[])
{
    long int dni[15]= {24083235,39457791,27775664,51789936,36896235,24083231,39457792,27775663,51789936,36896234,22083235,33457791,24775664,55789936,37896235};
    char nombre[15][50]= {"mercedes BIGI","Micaela Colella","Galo Matos","Martin Gerbasi","Paula Bigi","Facundo Musil","Gabriela Perez","Lucia Rodriguez","Adrian Alzaroli","Viviana Musil","Pablo Callejo","Alejandra Arrue", "Laura Lertora","Hugo Viere", "Aldo Liendo"};
    unsigned int edad[15]= {43,22,40,36,35,38,20,30,32,17,16,16,14,11,10};
    int estado[15]= {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1};

    for(int i=0; i<15; i++)
    {
        strcpy(lista[i].nombre, nombre[i]);
        lista[i].dni=dni[i];
        lista[i].edad=edad[i];
        lista[i].estado=estado[i];

    }
}


int obtenerEspacioLibre(EPersona lista[], int tam)
{
    int index = -1;

    for(int i=0; i<tam; i++)
    {
        if(lista[i].dni==0)
        {
            index=i;
            break;
        }
    }

    return index;
}



void cargarPersona(EPersona lista[], int index, int tam)
{
    int controlarDni;
    long int dni=0;
    char estexto;


    dni = IngresarDNI();


    controlarDni = buscarPorDni(lista, 20, dni);

    if (controlarDni != -1)
    {
        printf("El DNI ingresado ha sido resgistrado anteriormente");

    }
    if(controlarDni == -1 && dni > 0)
    {

        lista[index].dni=dni;

        fflush(stdin);


        printf("\nIngrese Nombre: ");
        gets(lista[index].nombre);
        estexto= esTexto(lista[index].nombre);

        while (estexto==0)
        {
            printf("\nReigrese Nombre: ");
            gets(lista[index].nombre);
            estexto= esTexto(lista[index].nombre);
        }




        fflush(stdin);
        printf("\nIngrese Edad: ");
        lista[index].edad=IngresarEntero(1,150); // segun Google 146 años el hombre mas viejo



        lista[index].estado = 1;


    }

}



void imprimirListadoPersonas (EPersona lista[], int tam)
{
    int i;
    int flag= 0;

    for(int i=0; i<tam; i++)
    {
       FormatoNombre(lista[i].nombre, tam);
    }

    ordenarListadoPersonas(lista, tam);




    printf("_______________________________________________________\n");



    for(i=0; i<tam; i++)
    {
        if(lista[i].estado==1)
        {

            printf("\n%s\t\t\%ld\t%d \n", lista[i].nombre, lista[i].dni, lista[i].edad);
            flag = 1;


        }
    }
    if(flag == 0)
    {
        printf("\nNo existen registros cargados\n");
    }

    printf("_______________________________________________________\n");

}




int buscarPorDni(EPersona lista[], int tam, long int dni)
{
    int index = -1;


    for(int i=0; i<tam; i++)
    {
        if(lista[i].dni==dni)
        {
            index = i;
        }
    }





    return index;


}

void ordenarListadoPersonas(EPersona lista[], int tam )
{
    EPersona aux[tam];



    for(int i=0; i<tam-1; i++)
    {

        for(int j=i+1; j<tam; j++)
        {
            if(lista[i].estado == 1)
            {

                if((strcmp(lista[i].nombre,lista[j].nombre))> 0)
                {
                    aux[i]= lista[i];
                    lista[i]=lista[j];
                    lista[j]=aux[i];

                }

            }

        }
    }

}


char* FormatoNombre(char nombre[], int tam)
{

    //transformar nombre apellido en min en Nombre Apellido
    int len;

    //strlwr(nombre);

    nombre[0]=toupper(nombre[0]);

    len = strlen(nombre);

    for(int i=1; i<len; i++)
    {

            nombre[i]=tolower(nombre[i]);

    }


    for(int j=1; j<len; j++)
    {
        //if (nombreyapellido[i-1] == ' ')
        if(isspace(nombre[j]))

        {
            nombre[j+1]=toupper(nombre[j+1]);
        }

    }
    return nombre;
}



void GraficoListadoPersonas (EPersona lista[], int tam )
{


    char grafico1[tam][2];
    char grafico2[tam][2];
    char grafico3[tam][2];
    int w=0;
    int j=0;
    int k=0;


    for(int i=0; i<=tam ; i++)
    {

        strcpy(grafico1[i]," ");

        strcpy(grafico2[i]," ");

        strcpy(grafico3[i]," ");

    }




    for(int i=0; i<tam ; i++)
    {
        if(lista[i].edad < 18 && lista[i].edad >0)
        {
            fflush(stdin);
            strcpy(grafico1[w],"*");
            w++;



        }

        if(lista[i].edad > 18 && lista[i].edad <=35)
        {
            fflush(stdin);
            strcpy(grafico2[k],"*");
            k++;



        }

        if(lista[i].edad > 35)
        {
            fflush(stdin);
            strcpy(grafico3[j],"*");
            j++;



        }




    }


    printf("\n");

    for(int i=tam; i>=0 ; i--)
    {
        if( (strcmp(grafico1[i],"*")==0) || (strcmp(grafico2[i],"*")==0) || (strcmp(grafico3[i],"*")==0)  )
        {
            printf("  %d-| %s      ", i+1, grafico1[i]);
            printf("%s       ", grafico2[i]);
            printf("%s\n", grafico3[i]);


        }


    }
    printf("  __|_________________________\n");
    printf("     <18   19-35    >35\n\n");
    printf("Gr%cfico para una estad%cstica de %d personas con edad menor a 18, %d personas con edades entre 19 y 35, y %d personas con edades mayores a 35.\n", 160,161,w,k,j);








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
        printf("Dato no v%clido reingresar: ", 160);
        scanf("%d", &dato);

    }

    return dato;

}











long int IngresarDNI()
{
    char numero[9];
    long int entero;
    int esnum=0;

    do
    {
        printf("Ingrese DNI: ");
        fflush(stdin);
        gets(numero);

        if(strlen(numero) >= 7 && strlen(numero) < 9)
        {
            esnum = esNumerolong(numero, 9);
        }
        else
        {

            printf("Error, ");
        }


    }
    while (esnum == 0);

    entero = atol(numero);

    return entero;
}


long int esNumerolong(char numero[], int tam)
{

    long int esnum = 0;

    int len = strlen(numero);

    for (int i=0; i<len; i++)
    {
        if (isdigit(numero[i]))
        {
            esnum = 1;
        }
        else
        {

            esnum = 0;
            break;

        }



    }

    return esnum;

}



int esTexto(char texto[])
{

    int estexto = 0;

    int len = strlen(texto);

    if(len > 1)
    {
        for (int i=0; i<len; i++)
        {
            if (isalpha(texto[i])|| isspace(texto[i]))
            {
                estexto = 1;
            }
            else
            {
                estexto = 0;
                break;
            }



        }
    }



    return estexto;

}


