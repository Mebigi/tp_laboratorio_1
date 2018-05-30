#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
#include <wchar.h>
#include <locale.h>
#define TAM_M 10





int main()
{
     EMovie listamovie[TAM_M];

     char seguir='s';
     int opcion;






    setlocale(LC_ALL, "");





    while(seguir=='s')
    {
        printf("1- Agregar película\n");
        printf("2- Borrar película\n");
        printf("3- modificar película\n");
        printf("4- Generar página web\n");
        printf("5- Salir\n");

        opcion = IngresarEntero("\nIngrese una OPCIóN", 1, 5);

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
