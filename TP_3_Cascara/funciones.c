#include "funciones.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>
#define TAM_M 10


//1 cargar

void cargarMovie(EMovie *lista)
{
    int index;

    for(int i=0; i<TAM_M; i++)
    {

        (lista+i)->estado=0;
        (lista+i)->idmovie=0;

    }

    cargarDesdeArchivo(lista);

    index = obtenerEspacioLibre(lista);

    printf("Lista\n");

    mostrarListaMovie(lista, TAM_M);


    if (index!=-1)
    {
        getString("\nTITULO:",(lista+index)->titulo, 3,19);
        (lista+index)->duracion=IngresarEntero("DURACION en minutos:", 15, 300);
        getString("Ingrese Descripcion:",(lista+index)->descripcion, 10, 49);
        (lista+index)->puntaje=IngresarEntero("Puntaje:", 1, 10);
        getString("URL imagen:",(lista+index)->linkimage, 3, 49);
        (lista+index)->idmovie = index+1;
        (lista+index)->estado = 1;

        if (Confirmacion("confirma"))
        {
            GuadarListaArchivo(lista);

        }

    }else

    {
        printf("\nNo hay espacio en la lista\n");

    }

}

//2 borrar

int borrarPelicula(EMovie *lista)
{

    EMovie aux= {0};
    int baja;
    int index;
    int retorno=0;


    cargarDesdeArchivo(lista);

    if(lista != NULL)
    {

    //arbiir archivo y gnenerar lista

    mostrarListaMovie(lista, TAM_M);

    baja = IngresarEntero("\nID Pelicula: ", 1, 1000);

    index=BuscarMovie(lista,baja);

    if(index!=-1 && lista[index].estado == 1)
    {

        {
            printf("\n\n+++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
            printf("\tPelicula: %s", lista[index].titulo);



        }


        if(Confirmacion("Confirma la Baja?"))
        {
            lista[index].estado=aux.estado;
            GuadarListaArchivo(lista);



        }


    }




    else
    {
        printf("Pelicula no encontrada");
        retorno=-1;

    }

    } else
    {
         printf("\nNo hay peliculas cargadas\n\n");
    }


     return retorno;

}
 //3 modificar

int modificarPelicula(EMovie *lista)
{

    EMovie aux= {0};
    int modificar;
    int index;
    int retorno=0;


    cargarDesdeArchivo(lista);

    if(lista != NULL)
    {

    //arbiir archivo y gnenerar lista

    mostrarListaMovie(lista, TAM_M);

    modificar = IngresarEntero("\nID Pelicula: ", 1, 10);

    index=BuscarMovie(lista,modificar);

    if(index!=-1)
    {

        {

        printf("\tPelicula: %s", (lista+index)->titulo);

        printf("\n\n+++++++++++++++++++++++++++++++++++++++++++++++++++++\n");
        getString("\nTITULO:",aux.titulo, 3,19);
        aux.duracion=IngresarEntero("DURACION en minutos:", 15, 300);
        getString("Ingrese Descripcion:",aux.descripcion, 10, 49);
        aux.puntaje=IngresarEntero("Puntaje:", 1, 10);
        getString("URL imagen:",aux.linkimage, 3, 49);
        aux.estado = (lista+index)->estado;
        aux.idmovie = (lista+index)->idmovie;
        }


        if(Confirmacion("Confirma los cambios?"))
        {
            lista[index]=aux;
            GuadarListaArchivo(lista);



        }


    }




    else
    {
        printf("Pelicula no encontrada");
        retorno=-1;

    }

    } else
    {
         printf("\nNo hay peliculas cargadas\n\n");
    }


     return retorno;

}
 //generear html

 void generarPagina(EMovie *lista, char nombrearchivo[])
 {


  FILE* archivoHTML;

  cargarDesdeArchivo(lista);

  char buffer[5000]= {};
  strcat(buffer,"<!DOCTYPE html>"
            "<!-- Template by Quackit.com -->"
            "<html lang='en'>"
            "<head>"
                "<meta charset='utf-8'>"
                "<meta http-equiv='X-UA-Compatible' content='IE=edge'>"
                "<meta name='viewport' content='width=device-width, initial-scale=1'>"
                "<!-- The above 3 meta tags *must* come first in the head; any other head content must come *after* these tags -->"
                "<title>Lista peliculas</title>"
                "<!-- Bootstrap Core CSS -->"
                "<link href='css/bootstrap.min.css' rel='stylesheet'>"
                "<!-- Custom CSS: You can use this stylesheet to override any Bootstrap styles and/or apply your own styles -->"
                "<link href='css/custom.css' rel='stylesheet'>"
                "<!-- HTML5 Shim and Respond.js IE8 support of HTML5 elements and media queries -->"
                "<!-- WARNING: Respond.js doesn't work if you view the page via file:// -->"
                "<!--[if lt IE 9]>"
                    "<script src='https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js'></script>"
                    "<script src='https://oss.maxcdn.com/libs/respond.js/1.4.2/respond.min.js'></script>"
                "<![endif]-->"
            "</head>"
           " <body>"
                "<div class='container'>"
                    "<div class='row'>");

                        for (int i=0; i<TAM_M; i++)
                        {
                            if ((lista+i)->idmovie!=0)
                            {

                                strcat(buffer,"<!-- Repetir esto para cada pelicula -->"
                        "<article class='col-md-4 article-intro'>"
                            "<a href='#'>"
                                "<img class='img-responsive img-rounded' src='http://ia.media-imdb.com/images/M/MV5BMjA5NTYzMDMyM15BMl5BanBnXkFtZTgwNjU3NDU2MTE@._V1_UX182_CR0,0,182,268_AL_.jpg' alt=''>"
                            "</a>"
                            "<h3>"
                                "<a href='#'>Back to the future</a>"
                            "</h3>"
                            "<ul>"
                                "<li>G�nero:Aventura</li>"
                                "<li>Puntaje:86</li>"
                                "<li>Duraci�n:116</li>"
                            "</ul>"
                            "<p>A young man is accidentally sent thirty years into the past in a time-traveling DeLorean invented by his friend, Dr. Emmett Brown, and"
                             "must make sure his high-school-age parents unite in order to save his own existence.</p>"
                        "</article>"
                        "<!-- Repetir esto para cada pelicula -->");

                            }
                        }





                        strcat(buffer,"</div>"
                "<!-- /.row -->"
                "</div>"
               " <!-- /.container -->"
                "<!-- jQuery -->"
                "<script src='js/jquery-1.11.3.min.js'></script>"
                "<!-- Bootstrap Core JavaScript -->"
                "<script src='js/bootstrap.min.js'></script>"
               "<!-- IE10 viewport bug workaround -->"
               " <script src='js/ie10-viewport-bug-workaround.js'></script>"
                "<!-- Placeholder Images -->"
                "<script src='js/holder.min.js'></script>"
            "</body>"
            "</html>");



    archivoHTML = fopen(nombrearchivo,"w");


    fprintf(archivoHTML,buffer);

    fclose(archivoHTML);

    return 0;




 }

int cargarDesdeArchivo(EMovie *x)
{

	FILE *f;
	int retorno=0;
	int bandera=0;


	f=fopen("listamovie.dat", "rb");
	if(f==NULL)
	{
		f= fopen("listamovie.dat", "wb");
		bandera=1;



		if(f==NULL)
		{
			retorno=1;
		}

	}


	if(bandera==0)
	{
     while(!feof(f))
     {

      fread(x,sizeof(EMovie),TAM_M,f);


    }
	}

	fclose(f);

	return retorno;

}


int GuadarListaArchivo(EMovie *x)
{

	FILE *f;
	int retorno=0;

	f=fopen("listamovie.dat", "wb");
	if(f==NULL)
	{

			retorno=1;
    }


	if(retorno ==0)
	{

      fwrite(x,sizeof(EMovie),TAM_M,f);


     }

	fclose(f);

	return retorno;

}

int obtenerEspacioLibre(EMovie *lista)
{
    int index = -1;

    for(int i=0; i<TAM_M; i++)
    {
        if((lista+i)->estado==0)
        {
            index=i;
            break;
        }
    }

    return index;
}


int IngresarEntero(char mensaje[], int min, int max)
{
    int entero;
    puts(mensaje);
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

void getString(char mensaje[],char input[], int min, int max)
{
    int len;
    int valido=0;

    do
    {
    printf("%s",mensaje);
    fflush(stdin);
    gets(input);

    len = strlen(input);
    if(len < min || len > max)
    {
        printf("Error,");
    }
    else
    {
       valido =1 ;

    }
    }
    while(valido ==0);

}


void getStringletras(char mensaje[],char input[], int min, int max)
{
        int estex=0;
        do
        {
        getString(mensaje, input, min,max);

        estex = esTexto(input);

        if (estex == 0)
        {
            printf("Error, ingresar %cnicamente letras", 163);
        }

        }
        while (estex == 0);
}


void getStringEntero(char mensaje[],char input[], int min, int max)
{
        int esnum=0;
        do
        {
        getString(mensaje, input, min,max);

        esnum = esNumero(input);

        if (esnum == 0)
        {
            printf("Error, ingresar %cnicamente n%cmeros", 163, 163);
        }

        }
        while (esnum == 0);
}

int esTexto(char texto[])
{
    int estexto = 0;

    int len = strlen(texto);

    for (int i=0; i<len; i++)
    {
        if (isalpha(texto[i]) || isspace(texto[i]))
        {
            estexto = 1;
        }
        else
        {

            estexto = 0;
            break;

        }

    }

    return estexto;

}




int esNumero(char numero[])
{

    int esnum = 0;

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

int Confirmacion(char mensaje[])
{
     char confirma;
     int retorno=0;

      printf("\n.....................................................");

     printf("\n%s s/n: ", mensaje);

     confirma= getche();
     confirma= tolower(confirma);

     if(confirma == 's')
     {
         retorno=1;

     }

     return retorno;

}


void  mostrarListaMovie(EMovie lista[], int tam)
{

    if(lista != NULL)
    {
    printf("\nID\tTitulo\tDescripcion");
    printf("\n--------------------------------------------------------------------");
    for(int i=0; i<tam; i++)
    {


        if(lista[i].estado==1)


        {

            printf("\n%d\t\t%s\t\t%s\t\t",lista[i].idmovie,lista[i].titulo,lista[i].descripcion);


        }

    }

    printf("\n--------------------------------------------------------------------");

    }


}



int BuscarMovie(EMovie *lista, int id)
{
    int index = -1;

    for(int i=0; i<TAM_M; i++)
    {
        if((lista+i)->idmovie==id && lista != NULL)
        {
            index=i;
            break;
        }
    }

    return index;
}

int* pedirmemoriaEntero()
{
    int* entero;
    entero = malloc(sizeof(int));
}

EMovie* pedirmemoriaEmovie()
{
    EMovie* dato;
    dato = malloc(sizeof(EMovie));
}