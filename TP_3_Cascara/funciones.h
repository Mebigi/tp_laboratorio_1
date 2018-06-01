#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{

char titulo[20];
char genero[20];
int duracion;
char descripcion[500];
int puntaje;
char linkimage[50];
int idmovie;


}EMovie;



int IngresarEntero(char [], int, int);

/** \brief valida un numero entero ingresado se encuatre dentro de un rango
 * \param minimo valor entero
 * \param maximo valor entero
 * \return un entero validado
 *
 */

int validarEntero (int, int, int);

/**
 * \brief Solicita un número entero usuario que el mismo ingresa como un strnig
 * \param mensaje Es el mensaje a ser mostrado
 * \param el valor minimo para ese entero
  * \param el valor maximo para ese entero
 * \return El número ingresado por el usuario tipo entero
 *
 */



int validarRangoEntero (int , int , int );

/** \brief lee una cadena de caracteres que debe tener un tamanaña mini y maximo y un mensaje para la carga de la misma
 *
* \param mensaje Es el mensaje a ser mostrado
* \param texto ingresado
* \param el valor minimo para longitud texto
* \param el valor maximo para para longitud texto
* \return
*
 */



void getString(char [],char [], int , int );


/** \brief lee una cadena de caracteres que debe tener un tamanaña mini y maximo y un mensaje para la carga de la misma
llama a validacion que sean solo letras.
 *
* \param mensaje Es el mensaje a ser mostrado
* \param texto ingresado
* \param el valor minimo para longitud texto
* \param el valor maximo para para longitud texto
* \return
*
 */


void getStringletras(char [],char [], int , int );

 /**
 * Obtiene el primer indice sin datos del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */

int obtenerEspacioLibre(EMovie *);

/** \brief lee una cadena de caracteres  validacion que sean solo letras.
 *

* \param texto ingresado

* \return
*
 */

int esTexto(char []);

/** \brief lee una cadena de caracteres  validacion que sean solo numeros.
 *

* \param texto ingresado

* \return
*
 */

int esNumero(char []);

/** \brief confirmacion s/n
 *
* \param texto ingresado tipo char

* \return entero 0 si no confirma 1 si confirma
*
 */

int Confirmacion(char []);


/** \brief lee una cadena de caracteres que debe tener un tamanaña mini y maximo y un mensaje, admite  letras o numeros.
 *
* \param mensaje Es el mensaje a ser mostrado
* \param texto ingresado
* \param el valor minimo para longitud texto
* \param el valor maximo para para longitud texto
* \return
*
 */


void getStringEntero(char [],char [], int , int );

/**
 *  Asinar datos a variables estructuradas EMovie
 *  @param movie la estructura donde se ingresan los datos
 *  @return
 */


void cargarMovie(EMovie *);

/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */

int agregarPelicula(EMovie);


/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula(EMovie *movie);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */

void generarPagina(EMovie *, char []);

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */

int modificarPelicula(EMovie *);

/**
 *  Modifica una pelicula del archivo binario
 *  @param ARRAY estructura a ser MODIFICADA al archivo
 *  @param tamaño ARRAY
 *  @return retorna 1 o 0 de acuerdo a si pudo modificar la pelicula o no
 */

int  mostrarListaMovie(EMovie [], int );

/**
 *  busca una pelicula del archivo binario
 *  @param entero id clave primaria
 *  @return retorna -1 si no encuetra el id o en indice donde encontro el id
 */

int BuscarMovie(EMovie *, int );

/**
 *  genera una lista de paliculas a partir de datos cargados en una archivo binario que tiene guardada datos del tipo de datos EMovie
 *  @param puntero de la estructura EMovie
 *  @return retorna 0 si pudo abiri el archivo con los datos,1 si crea el archivo porque no existia previeamente
 *          2 si no puede crear el archivo y tampoco existia
  */

int cargarDesdeArchivo(EMovie *x);

/**
 *  Guarda una lista de paliculas a en una archivo binario que tiene guardada datos del tipo de datos EMovie
 *  @param puntero de la estructura EMovie
 *  @return retorna 0 si pudo guardar el archivo con los datos,1 si no pudo
 *
  */


int GuadarListaArchivo(EMovie *x);

/**
 *  A partir de un numero ingresado en un a opcion copia un texto en una cadena de caracteres
 *  @param cadena de caracteres
  *  @param el entero ingresado
 *  @return cadena de texto
  */


char* traerGenero(int, char [] );



#endif // FUNCIONES_H_INCLUDED
