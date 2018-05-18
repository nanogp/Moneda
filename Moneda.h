#pragma once
#ifndef MONEDA_H_INCLUDED
#define MONEDA_H_INCLUDED

#include "General.h"
#include "Menu.h"

//limites
#define MONEDA_CANT_MAX 10
#define MONEDA_LARGO_NOMBRE 10
#define MONEDA_LARGO_PAIS 10
#define MONEDA_ID_MIN 1
#define MONEDA_ID_MAX 1000000

//titulos
#define MONEDA_ALTA_TITULO DEFINIR_MACRO_STRING(ALTA DE MONEDA)
#define MONEDA_MODIFICACION_TITULO DEFINIR_MACRO_STRING(MODIFICACION DE MONEDA)
#define MONEDA_BAJA_TITULO DEFINIR_MACRO_STRING(BAJA DE MONEDA)
#define MONEDA_LISTADO_TITULO DEFINIR_MACRO_STRING(LISTADO DE MONEDAS)

//mensajes
#define MONEDA_MSJ_INGRESE_ID DEFINIR_MACRO_STRING(\n\nIngrese el ID de Moneda: \0)
#define MONEDA_MSJ_REINGRESE_ID DEFINIR_MACRO_STRING(\nEl ID debe ser un numero mayor que cero. Reingrese un ID valido: \0)
#define MONEDA_MSJ_ID_NO_EXISTE DEFINIR_MACRO_STRING(\nEl ID de Moneda ingresado no existe)
#define MONEDA_MSJ_LISTA_VACIA DEFINIR_MACRO_STRING(\n\nLa lista de Monedas esta vacia o todos los registros se dieron de baja)
#define MONEDA_MSJ_NO_MAS_LUGAR DEFINIR_MACRO_STRING(\nNo hay mas lugares disponibles para altas de Moneda)
#define MONEDA_MSJ_INGRESE_NOMBRE DEFINIR_MACRO_STRING(\nIngrese Nombre Moneda: \0)
#define MONEDA_MSJ_REINGRESE_NOMBRE DEFINIR_MACRO_STRING(\nNombre muy largo. Reingrese por favor: \0)
#define MONEDA_MSJ_INGRESE_PAIS DEFINIR_MACRO_STRING(\nIngrese Pais: \0)
#define MONEDA_MSJ_REINGRESE_PAIS DEFINIR_MACRO_STRING(\nPais muy larga. Reingrese por favor: \0)
#define MONEDA_MSJ_INGRESE_TARJETA DEFINIR_MACRO_STRING(\nIngrese numero de tarjeta: \0)
#define MONEDA_MSJ_REINGRESE_TARJETA DEFINIR_MACRO_STRING(\nNumero de tarjeta no valido. Reingrese por favor: \0)
#define MONEDA_MSJ_ALTA_OK DEFINIR_MACRO_STRING(\nEl Moneda se dio de alta)
#define MONEDA_MSJ_CONFIRMAR_BAJA DEFINIR_MACRO_STRING(Confirma que desea dar de baja dicho Moneda?)
#define MONEDA_MSJ_BAJA_OK DEFINIR_MACRO_STRING(\nEl Moneda se dio de baja)
#define MONEDA_MSJ_REGISTRO_ACTUAL DEFINIR_MACRO_STRING(\n\nMoneda actual: \0)
#define MONEDA_MSJ_REGISTRO_MODIFICADO DEFINIR_MACRO_STRING(\n\nMoneda modificado: \0)
#define MONEDA_MSJ_MODIFICACION_OK DEFINIR_MACRO_STRING(\nEl Moneda se modifico)

//listados
#define MONEDA_MOSTRAR_UNO_MASCARA DEFINIR_MACRO_STRING(\n%d - %-10s - %-10s)
#define MONEDA_MOSTRAR_UNO_CABECERA DEFINIR_MACRO_STRING(\nID - NOMBRE - PAIS)

//orden
#define MONEDA_ORDEN_NOMBRE DEFINIR_MACRO_STRING(nombreAsc)
#define MONEDA_ORDEN_ID DEFINIR_MACRO_STRING(idAsc)

//menus
#define MONEDA_MENU_MODIFICAR_UNO_TITULO DEFINIR_MACRO_STRING(Que desea modificar?)
#define MONEDA_MENU_MODIFICAR_UNO_CANT 3
#define MONEDA_MENU_MODIFICAR_UNO_DETALLE1 DEFINIR_MACRO_STRING(1. Nombre)
#define MONEDA_MENU_MODIFICAR_UNO_DETALLE2 DEFINIR_MACRO_STRING(2. Pais)
#define MONEDA_MENU_MODIFICAR_UNO_DETALLE0 DEFINIR_MACRO_STRING(0. Cancelar)



typedef struct
{
    char nombre[MONEDA_LARGO_NOMBRE];
    char pais[MONEDA_LARGO_PAIS];
    //------------
    int idMoneda;
    int estado;
}eMoneda;

void eMoneda_initHardcode(eMoneda* listadoMonedas);
int eMoneda_init(eMoneda* listadoMonedas, int limiteMonedas);
int eMoneda_buscarLugarLibre(eMoneda* listadoMonedas, int limiteMonedas);
int eMoneda_siguienteId(eMoneda* listadoMonedas, int limiteMonedas);
int eMoneda_buscarPorId(eMoneda* listadoMonedas, int limiteMonedas, int idMoneda);
int eMoneda_pedirIdYBuscar(eMoneda* listadoMonedas, int limiteMonedas);
int eMoneda_estaVacio(eMoneda* listadoMonedas, int limiteMonedas);
int eMoneda_informarListadoVacio(eMoneda* listadoMonedas, int limiteMonedas);

void eMoneda_pedirNombre(char* retorno);
void eMoneda_pedirPais(char* retorno);
eMoneda eMoneda_pedirIngreso(eMoneda* listadoMonedas, int limiteMonedas);
int eMoneda_mostrarUno(eMoneda* propietario);
int eMoneda_mostrarListado(eMoneda* listadoMonedas, int limiteMonedas);
int eMoneda_alta(eMoneda* listadoMonedas, int limiteMonedas);
int eMoneda_modificacion(eMoneda* listadoMonedas, int limiteMonedas);
int eMoneda_baja(eMoneda* listadoMonedas, int limiteMonedas);
int eMoneda_ordenar(eMoneda* listado, int limiteMonedas, char* orden);

#endif // MONEDA_H_INCLUDED
