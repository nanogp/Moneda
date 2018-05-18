#pragma once
#ifndef GENERAL_H_INCLUDED
#define GENERAL_H_INCLUDED

//macro para definir macros string
#define DEFINIR_MACRO_STRING(nombre_macro) #nombre_macro

//macros
#define LIMPIAR_PANTALLA DEFINIR_MACRO_STRING(cls)
#define HACER_PAUSA DEFINIR_MACRO_STRING(pause)

//limites
#define TITULO_LARGO_MAX 1000
#define STRING_LARGO_MAX 1000

//constantes
#define OCUPADO 1
#define LIBRE 0


//titulos

//mensajes
#define MSJ_CONFIRMA_CORRECTOS DEFINIR_MACRO_STRING(Confirma que los datos ingresados son correctos?)
#define MSJ_CANCELO_GESTION DEFINIR_MACRO_STRING(\nSe cancelo la gestion)
#define MSJ_MODIFICANDO_REGISTRO DEFINIR_MACRO_STRING(MODIFICANDO REGISTRO)
#define MSJ_DATOS_A_MODIFICAR DEFINIR_MACRO_STRING(\n\nDatos a modificar:\n)

//listados

//orden

//menus

/** \brief corre comandos en la consola del sistema operativo
 *
 * \param  lineaDeComando  char*: el string del comando
 * \return void
 *
 */
void ejecutarEnConsola(char*);


/** \brief pide confirmacion por S o N al usuario y devuelve la letra validada
 *
 * \param  mensajeAlUsuario  char*: mensaje al usuario
 * \return char: S o N validado
 *
 */
char pedirConfirmacion(char*);


/** \brief pide que se ingrese un numero entero
 *
 * \param mensajeIngreso char* : el mensaje al usuario
 * \return int: el numero entero
 *
 */
int pedirInt(char*);


/** \brief pide que se ingrese un numero int y lo valida
 *
  * \param mensajeIngreso char* : el mensaje al usuario
  * \param mensajeReingreso char* : el mensaje al usuario en caso de error
 * \param limiteInferior  int: valor inferior válido
 * \param limiteSuperior  int: valor superior válido
 * \return int: el número validado
 *
 */
int pedirIntValido(char*, char*, int, int);


/** \brief pide que se ingrese un numero float
 *
 * \param mensajeIngreso char* : el mensaje al usuario
 * \return float: el numero float
 *
 */
float pedirFloat(char*);


/** \brief pide que se ingrese un numero float y lo valida
 *
  * \param mensajeIngreso char* : el mensaje al usuario
  * \param mensajeReingreso char* : el mensaje al usuario en caso de error
 * \param limiteInferior  float: valor inferior válido
 * \param limiteSuperior  float: valor superior válido
 * \return float: el número validado
 *
 */
float pedirFloatValido(char*, char*, float, float);


/** \brief pide que se ingrese una cadena de texto y la asigna a una variable
 *
 * \param retorno char*: la variable donde se retorna la cadena ingresada
 * \param mensajeIngreso char* : el mensaje al usuario
 * \return void
 *
 */
void pedirString(char*, char*);


/** \brief pide que se ingrese una cadena de texto, valida su tamaño y la asigna a una variable
 *
 * \param retorno char*: la variable donde se retorna la cadena ingresada
 * \param mensajeIngreso char* : el mensaje al usuario
 * \param mensajeReingreso char* : el mensaje al usuario en caso de error
 * \param limite int: el límite para la cantidad de caracteres
 * \return void
 *
 */
void pedirStringValido(char*, char*, char*, int limite);


/** \brief calcula el promedio entre dos numeros float
 *
 * \param numero1 float: el primer numero
 * \param numero2 float: el segundo numero
 * \return float: el promedio entre ambos numeros
 *
 */
float calcularPromedio(float, float);


/** \brief busca coincidencia de un valor entero dentro de un array
 *
 * \param array int*: el array donde buscar
 * \param limite int: la cantidad de elementos del array
 * \param buscar int: el numero entero a buscar
 * \return int la posicion del elemento buscado. -1 en caso de no encontrarlo
 *
 */
int buscarEnArrayInt(int*, int, int);


/** \brief escribe el texto recibido con un printf
 *
 * \param texto  char*: la cadena de texto a mostrar
 * \return void
 *
 */
void imprimirEnPantalla(char*);


/** \brief Recibe un texto y lo decora como título
 *
 * \param  char*: el texto a decorar
 * \return void
 *
 */
void generarTitulo(char*);


/** \brief Recibe un texto y lo muestra decorado como título
 *
 * \param   char*: el texto a mostrar
 * \return void
 *
 */
void imprimirTitulo(char*);


/** \brief hace una pausa y pide al usuario que presione cualquier tecla para continuar
 *
 * \return void
 *
 */
void pausa();


/** \brief limpia el contenido de la pantalla
 *
 * \return void
 *
 */
void limpiarPantalla();


/** \brief limpia la pantalla y muestra un mensaje con formato de titulo
 *
 * \param char*: el texto a utilizar en el titulo
 * \return void
 *
 */
void limpiarPantallaYMostrarTitulo(char*);

#endif // GENERAL_H_INCLUDED
