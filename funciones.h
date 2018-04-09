#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

/** \brief Suma dos numeros flotantes
 *
 * \param un primer flotante
 * \param un segundo flotante
 * \return un flotante resultado de la suma de dos flotantes
 *
 */

float sumar(float numero1, float numero2);

/** \brief Resta dos flotantes
 *
 * \param un primer flotante
 * \param un segundo flotante
 * \return un flotante resultado de la resta de dos flotantes
 *
 */
float restar(float numero1, float numero2);

/** \brief Dividir dos flotantes
 *
 * \param un numero flotante numerador
 * \param un segundo flotante denominador distinto de cero
 * \return un flotante resultado de la division
 *
 */

float dividir(float numero1, float numero2);

/** \brief multiplicar dos flotantes
 *
 * \param un pimer flotante
 * \param un segundo flotante
 * \return un flotante resultado de la multiplicacion
 *
 */

float multiplicar(float numero1, float numero2);

/** \brief factorizar numero entero hasta 20
 *
 * \param un entero
 * \return un resultado de factorizar un entero (long long int)
 *
 */

long long int factorizar(int numero);




 /** \brief lee un numero ingresado flotante
  *

  * \param valor mininimo flotante a ingresar
  * \param valor maximo flotante a ingresar
  * \return un numero flotante
  *
  */


float IngresarFlotante(float, float);

 /** \brief valida numero flotante entre un minimo y un maximo
  *

  * \param valor mininimo a ingresar
  * \param valor maximo a ingresar
  * \return un numero flotante validado
  *
  */

float validarFlotante( float, float, float);

/** \brief leer un numero entero ingresado comprendido entre el minimo valor y el maximo valor

 * \param minimo valor
 * \param maximo valor
 * \return un entrero
 *
 */

int IngresarEntero(int, int);

/** \brief valida un numero entero ingresado se encuatre dentro de un rango
 * \param minimo valor entero
 * \param maximo valor entero
 * \return un entero validado
 *
 */

int validarEntero (int, int, int);









#endif // FUNCIONES_H_INCLUDED
