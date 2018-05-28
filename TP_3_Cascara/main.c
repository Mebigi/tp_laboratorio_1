#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#define TAM_M 10


int main()
{
     EMovie listamovie[TAM_M];


    char seguir='s';
    int opcion;


    while(seguir=='s')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Generar pagina web\n");
        printf("4- Salir\n");

        opcion = IngresarEntero("\nIngrese una OPCION", 1, 5);

        switch(opcion)
        {
            case 1:
                cargarMovie(listamovie);
                //agregarPelicula(listamovie);
                mostrarListaMovie(listamovie, TAM_M);
                break;
            case 2:
                borrarPelicula(listamovie);
                break;
            case 3:
               break;
            case 4:
                seguir = 'n';
                break;
        }
    }

    return 0;
}
