#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define TAM_M 10


int main()
{
     EMovie listamovie[TAM_M];

     int* d;

     d = pedirmemoriaEntero();
     *d = 5;
     printf("d= %d\n", *d);


     /*EMovie* estructura;

     estructura = pedirmemoriaEmovie();

     printf("d= %p\n", *estructura);
     */




    char seguir='s';
    int opcion;


    while(seguir=='s')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");

        opcion = IngresarEntero("\nIngrese una OPCION", 1, 5);

        switch(opcion)
        {
            case 1:
                cargarMovie(listamovie);
                //agregarPelicula(listamovie);
                //mostrarListaMovie(listamovie, TAM_M);
                break;
            case 2:
                borrarPelicula(listamovie);
                break;
            case 3:
               modificarPelicula(listamovie);
               break;
            case 4:
               generarPagina(listamovie, "listaPeliculas.html");
               break;
            case 5:
                seguir = 'n';
                break;
        }

         printf("\n\n");
        system("pause");
        system("cls");
    }



    return 0;
}
