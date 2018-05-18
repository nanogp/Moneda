#pragma once
#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

//limites
#define MENU_LARGO_DESCRIPCION 100
#define MENU_LARGO_TITULO 100
#define MENU_CANT_MAX 20

//constantes

//titulos

//mensajes

//listados

//orden

//menus
//#define CLASE_MENU_ACCION_TITULO DEFINIR_MACRO_STRING(Que desea modificar?)
//#define CLASE_MENU_ACCION_CANT 2
//#define CLASE_MENU_ACCION_DETALLE1 DEFINIR_MACRO_STRING(1. accion)
//#define CLASE_MENU_ACCION_DETALLE0 DEFINIR_MACRO_STRING(0. Cancelar)

typedef struct
{
    int limiteOpciones;
    int codigos[MENU_CANT_MAX];
    char descripciones[MENU_CANT_MAX][MENU_LARGO_DESCRIPCION];
    char titulo[MENU_LARGO_TITULO];
} eMenu;

/** \brief muestra en pantalla un tipo de dato menu
 *
 * \param menu  eMenu*: el menu a mostrar
 * \return void
 *
 */
void mostrarMenu(eMenu* menu);


/** \brief pide al usuario que elija una opcion de menu recibido como parametro
 *
 * \param menu  eMenu*: el menu de opciones a mostrar al usuario para pedir y validar la opcion seleccionada
 * \return int: el numero de opcion validada
 *
 */
int pedirOpcion(eMenu* menu);

#endif // MENU_H_INCLUDED
