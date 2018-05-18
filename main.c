#include <stdio.h>
#include <stdlib.h>
#include "General.h"
#include "Menu.h"
#include "Moneda.h"
#include "Archivo.h"

#define MENU_MAIN_TITULO DEFINIR_MACRO_STRING(MENU MONEDAS)
#define MENU_MAIN_CANT 6
#define MENU_MAIN_DETALLE1 DEFINIR_MACRO_STRING(1. Alta Moneda)
#define MENU_MAIN_DETALLE2 DEFINIR_MACRO_STRING(2. Baja Moneda)
#define MENU_MAIN_DETALLE3 DEFINIR_MACRO_STRING(3. Modificacion Moneda)
#define MENU_MAIN_DETALLE4 DEFINIR_MACRO_STRING(4. Listado Moneda)
#define MENU_MAIN_DETALLE5 DEFINIR_MACRO_STRING(5. Guardar en Archivo)
#define MENU_MAIN_DETALLE6 DEFINIR_MACRO_STRING(6. )
#define MENU_MAIN_DETALLE7 DEFINIR_MACRO_STRING(7. )
#define MENU_MAIN_DETALLE8 DEFINIR_MACRO_STRING(8. )
#define MENU_MAIN_DETALLE9 DEFINIR_MACRO_STRING(9. )
#define MENU_MAIN_DETALLE10 DEFINIR_MACRO_STRING(10. )
#define MENU_MAIN_DETALLE0 DEFINIR_MACRO_STRING(0. Salir del programa)

int main()
{
    eMenu menuPrincipal = {/*cantidad de opciones*/MENU_MAIN_CANT,
                            /*codigos*/{1,2,3,4,5,0},
                            /*descripciones*/{MENU_MAIN_DETALLE1,MENU_MAIN_DETALLE2,MENU_MAIN_DETALLE3,MENU_MAIN_DETALLE4,MENU_MAIN_DETALLE5,MENU_MAIN_DETALLE0},
                            /*titulo del menu*/{MENU_MAIN_TITULO}};
    int opcion;
    char salirDelPrograma = 'N';
    char archivoRuta = "d:\\github\\Moneda\\listado.txt";

    //ARRAYS DE ESTRUCTURAS
    eMoneda listadoMonedas[MONEDA_CANT_MAX] = {};

    //INCIALIZAR
    eMoneda_init(listadoMonedas, MONEDA_CANT_MAX);

    //CARGAR DATOS POR HARDCODE PARA DEBUG
    eMoneda_initHardcode(listadoMonedas);

    do
    {
        ejecutarEnConsola(LIMPIAR_PANTALLA);
        opcion = pedirOpcion(&menuPrincipal);
        switch(opcion)
        {
            case 1:
                eMoneda_alta(listadoMonedas, MONEDA_CANT_MAX);
                break;
            case 2:
                eMoneda_baja(listadoMonedas, MONEDA_CANT_MAX);
                break;
            case 3:
                eMoneda_modificacion(listadoMonedas, MONEDA_CANT_MAX);
                break;
            case 4:
                eMoneda_mostrarListado(listadoMonedas, MONEDA_CANT_MAX);pausa();
                break;
            case 5:
                //archivoAbrirYEscribir(archivoRuta, listadoMonedas);
                printf("Listado guardado en: %s", archivoRuta);pausa();
                break;
            case 0:
                salirDelPrograma = pedirConfirmacion("Confirma que desea salir del programa?");
                break;
        }

    }
    while(salirDelPrograma == 'N');
    return 0;
}
