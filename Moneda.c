#include "Moneda.h"
#include <stdio.h>
#include <string.h>

void eMoneda_initHardcode(eMoneda* listadoMonedas)
{
    //                           nombre,Pais,ID,estado
    char paises[3][10] = {"Argentina","Brasil","EEUU"};
    char nombres[3][10] = {"Peso","Real","Dolar"};

    for(int i = 0; i<3 ; i++)
    {
        strcpy(&((listadoMonedas+i)->pais),(paises+i));
        strcpy(&((listadoMonedas+i)->nombre),(nombres+i));
        (listadoMonedas+i)->idMoneda = i+1;
        (listadoMonedas+i)->estado = OCUPADO;
    }

}

int eMoneda_init(eMoneda* listadoMonedas, int limiteMonedas)
{
    int retorno = -1;
    int i;

    if(listadoMonedas != NULL && limiteMonedas > 0)
    {
        retorno = 0;
        for(i=0 ; i<limiteMonedas ; i++)
        {
            (listadoMonedas+i)->estado= LIBRE;
            (listadoMonedas+i)->idMoneda= 0;
        }
    }
    return retorno;
}

int eMoneda_buscarLugarLibre(eMoneda* listadoMonedas, int limiteMonedas)
{
    int retorno = -1;
    int i;

    if(listadoMonedas != NULL && limiteMonedas > 0)
    {
        retorno = -2;
        for(i=0 ; i<limiteMonedas ; i++)
        {
            if((listadoMonedas+i)->estado == LIBRE)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int eMoneda_siguienteId(eMoneda* listadoMonedas, int limiteMonedas)
{
    int retorno = -1;
    int i;

    if(listadoMonedas != NULL && limiteMonedas > 0)
    {
        retorno = 0;
        for(i=0; i<limiteMonedas; i++)
        {
            if((listadoMonedas+i)->estado == OCUPADO)
            {
                if((listadoMonedas+i)->idMoneda > retorno)
                {
                     retorno = (listadoMonedas+i)->idMoneda + 1;
                }
            }
        }
    }
    return retorno;
}

int eMoneda_estaVacio(eMoneda* listadoMonedas, int limiteMonedas)
{
    int retorno = -1;
    int i;

    if(listadoMonedas != NULL && limiteMonedas > 0)
    {
        retorno = 1;
        for(i=0 ; i<limiteMonedas ; i++)
        {
            if((listadoMonedas+i)->estado == OCUPADO)
            {
                retorno = 0;
                break;//con el primer ocupado ya se que no esta vacio
            }
        }
    }
    return retorno;
}

int eMoneda_informarListadoVacio(eMoneda* listadoMonedas, int limiteMonedas)
{
    int retorno;

    if(listadoMonedas != NULL && limiteMonedas > 0)
    {
        retorno = eMoneda_estaVacio(listadoMonedas, limiteMonedas);
        if(retorno == 1)
        {
            imprimirEnPantalla(MONEDA_MSJ_LISTA_VACIA);
        }
    }
    return retorno;
}

int eMoneda_buscarPorId(eMoneda* listadoMonedas, int limiteMonedas, int idMoneda)
{
    int retorno = -1;
    int i;

    if(listadoMonedas != NULL && limiteMonedas > 0)
    {
        retorno = -2;
        for(i=0 ; i<limiteMonedas ; i++)
        {
            if((listadoMonedas+i)->estado == OCUPADO && (listadoMonedas+i)->idMoneda == idMoneda)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

void eMoneda_pedirNombre(char* retorno)
{
    pedirStringValido(retorno, MONEDA_MSJ_INGRESE_NOMBRE, MONEDA_MSJ_REINGRESE_NOMBRE, MONEDA_LARGO_NOMBRE);
}

void eMoneda_pedirPais(char* retorno)
{
    pedirStringValido(retorno, MONEDA_MSJ_INGRESE_PAIS, MONEDA_MSJ_REINGRESE_PAIS, MONEDA_LARGO_PAIS);
}

eMoneda eMoneda_pedirIngreso(eMoneda* listadoMonedas, int limiteMonedas)
{
    eMoneda retorno;

    retorno.idMoneda = eMoneda_siguienteId(listadoMonedas, limiteMonedas);

    eMoneda_pedirNombre((char *)&(retorno.nombre));

    eMoneda_pedirPais((char *)&(retorno.pais));

    retorno.estado = OCUPADO;

    return retorno;
}


int eMoneda_mostrarUno(eMoneda* propietario)
{
     int retorno = -1;

     if(propietario != NULL)
     {
        retorno = 0;
        printf(MONEDA_MOSTRAR_UNO_MASCARA, propietario->idMoneda, propietario->nombre, propietario->pais);
     }
     return retorno;
}

int eMoneda_mostrarListado(eMoneda* listadoMonedas, int limiteMonedas)
{
    int retorno = -1;
    int i;

    if(listadoMonedas != NULL && limiteMonedas > 0)
    {
        retorno = 0;
        limpiarPantallaYMostrarTitulo(MONEDA_LISTADO_TITULO);

        if(eMoneda_informarListadoVacio(listadoMonedas, limiteMonedas) == 0)
        {
            imprimirEnPantalla(MONEDA_MOSTRAR_UNO_CABECERA);

            for(i=0 ; i<limiteMonedas ; i++)
            {
                if((listadoMonedas+i)->estado == OCUPADO)
                {
                    eMoneda_mostrarUno(listadoMonedas+i);
                }
            }
        }
    }
    return retorno;
}

int eMoneda_alta(eMoneda* listadoMonedas, int limiteMonedas)
{
    int retorno = -1;
    eMoneda registro;
    char confirmacion;
    int posicion;

    if(listadoMonedas != NULL && limiteMonedas > 0)
    {
        retorno = 0;
        limpiarPantalla();
        imprimirTitulo(MONEDA_ALTA_TITULO);

        posicion = eMoneda_buscarLugarLibre(listadoMonedas, limiteMonedas);
        if(posicion < -1)
        {
            imprimirEnPantalla(MONEDA_MSJ_NO_MAS_LUGAR);
        }
        else if(posicion < 0)
        {
            retorno = posicion;
        }
        else
        {
            registro = eMoneda_pedirIngreso(listadoMonedas, limiteMonedas);

            imprimirEnPantalla(MONEDA_MOSTRAR_UNO_CABECERA);
            eMoneda_mostrarUno(&registro);

            confirmacion = pedirConfirmacion(MSJ_CONFIRMA_CORRECTOS);

            if(confirmacion == 'S')
            {
                *(listadoMonedas+posicion) = registro;
                eMoneda_ordenar(listadoMonedas, limiteMonedas, MONEDA_ORDEN_NOMBRE);
                imprimirEnPantalla(MONEDA_MSJ_ALTA_OK);
            }
            else
            {
                imprimirEnPantalla(MSJ_CANCELO_GESTION);
            }
        }
        pausa();
    }
    return retorno;
}

int eMoneda_ordenar(eMoneda* listadoMonedas, int limiteMonedas, char* orden)
{
    int retorno = -1;
    int i;
    int j;
    eMoneda aux;

    if(listadoMonedas != NULL && limiteMonedas > 0)
    {
        retorno = 0;
        if(strcmp(orden, "idAsc") == 0)
        {
            for(i=0 ; i<limiteMonedas-1 ; i++)
            {
                for(j=i+1 ; j<limiteMonedas ; j++)
                {
                    if((listadoMonedas+i)->idMoneda > (listadoMonedas+j)->idMoneda)
                    {
                        aux = *(listadoMonedas+i);
                        *(listadoMonedas+i) = *(listadoMonedas+j);
                        *(listadoMonedas+j) = aux;
                    }
                }
            }
        }
        else if(strcmp(orden, "idDesc") == 0)
        {
            for(i=0 ; i<limiteMonedas-1 ; i++)
            {
                for(j=i+1 ; j<limiteMonedas ; j++)
                {
                    if((listadoMonedas+i)->idMoneda < (listadoMonedas+j)->idMoneda)
                    {
                        aux = *(listadoMonedas+i);
                        *(listadoMonedas+i) = *(listadoMonedas+j);
                        *(listadoMonedas+j) = aux;
                    }
                }
            }
        }
        else if(strcmp(orden, "nombreAsc") == 0)
        {
            for(i=0 ; i<limiteMonedas-1 ; i++)
            {
                for(j=i+1 ; j<limiteMonedas ; j++)
                {
                    if(strcmpi((listadoMonedas+i)->nombre, (listadoMonedas+j)->nombre) > 0)
                    {
                        aux = *(listadoMonedas+i);
                        *(listadoMonedas+i) = *(listadoMonedas+j);
                        *(listadoMonedas+j) = aux;
                    }
                }
            }
        }
        else if(strcmp(orden, "nombreDesc") == 0)
        {
            for(i=0 ; i<limiteMonedas-1 ; i++)
            {
                for(j=i+1 ; j<limiteMonedas ; j++)
                {
                    if(strcmpi((listadoMonedas+i)->nombre, (listadoMonedas+j)->nombre) < 0)
                    {
                        aux = *(listadoMonedas+i);
                        *(listadoMonedas+i) = *(listadoMonedas+j);
                        *(listadoMonedas+j) = aux;
                    }
                }
            }
        }
    }
    return retorno;
}

int eMoneda_modificarUno(eMoneda* registro)
{
    int retorno = -1;
    eMenu menuModificar = {/*cantidad de opciones*/MONEDA_MENU_MODIFICAR_UNO_CANT,
                            /*codigos*/{1,2,0},
                            /*descripciones*/{MONEDA_MENU_MODIFICAR_UNO_DETALLE1,MONEDA_MENU_MODIFICAR_UNO_DETALLE2,MONEDA_MENU_MODIFICAR_UNO_DETALLE0},
                            /*titulo del menu*/{MONEDA_MENU_MODIFICAR_UNO_TITULO}};
    int opcion;

    if(registro != NULL)
    {
        retorno = 1;
        ejecutarEnConsola(LIMPIAR_PANTALLA);
        imprimirTitulo(MSJ_MODIFICANDO_REGISTRO);
        imprimirEnPantalla(MSJ_DATOS_A_MODIFICAR);
        imprimirEnPantalla(MONEDA_MOSTRAR_UNO_CABECERA);

        eMoneda_mostrarUno(registro);

        opcion = pedirOpcion(&menuModificar);
        switch(opcion)
        {
            case 1:
                eMoneda_pedirNombre((char *)&registro->nombre);
                break;
            case 2:
                eMoneda_pedirPais((char *)&registro->pais);
                break;
            case 0:
                retorno = 0;
                break;
        }
    }
    return retorno;
}

int eMoneda_pedirIdYBuscar(eMoneda* listadoMonedas, int limiteMonedas)
{
    int retorno;
    int idMoneda;

    do
    {
        eMoneda_mostrarListado(listadoMonedas, limiteMonedas);
        idMoneda = pedirIntValido(MONEDA_MSJ_INGRESE_ID, MONEDA_MSJ_REINGRESE_ID, MONEDA_ID_MIN, MONEDA_ID_MAX);
        retorno = eMoneda_buscarPorId(listadoMonedas, limiteMonedas, idMoneda);
        if(retorno < 0)
        {
            imprimirEnPantalla(MONEDA_MSJ_ID_NO_EXISTE);
            pausa();
        }
    }
    while(retorno < 0);

    return retorno;
}

int eMoneda_modificacion(eMoneda* listadoMonedas, int limiteMonedas)
{
    eMoneda registro;
    char confirmacion;
    int posicion;
    int huboCambios;

    ejecutarEnConsola(LIMPIAR_PANTALLA);
    imprimirTitulo(MONEDA_MODIFICACION_TITULO);

    if(eMoneda_estaVacio(listadoMonedas, limiteMonedas) == 1)
    {
        imprimirEnPantalla(MONEDA_MSJ_LISTA_VACIA);
    }
    else
    {
        posicion = eMoneda_pedirIdYBuscar(listadoMonedas, limiteMonedas);
        //traigo el registro del id elegido para no pisar directo sobre el listadoMonedas
        registro = listadoMonedas[posicion];

        huboCambios = eMoneda_modificarUno(&registro);
        if(huboCambios == 1)
        {
            /*if(aca se pregunta si hubo cambios que requieran reprocesar)
            {
                se recalcularian promedios por ej->
            }*/

            ejecutarEnConsola(LIMPIAR_PANTALLA);
            imprimirTitulo(MONEDA_MODIFICACION_TITULO);

            imprimirEnPantalla(MONEDA_MSJ_REGISTRO_ACTUAL);
            eMoneda_mostrarUno(listadoMonedas+posicion);

            imprimirEnPantalla(MONEDA_MSJ_REGISTRO_MODIFICADO);
            eMoneda_mostrarUno(&registro);

            confirmacion = pedirConfirmacion(MSJ_CONFIRMA_CORRECTOS);
        }
        else
        {
            confirmacion = 'N';
        }

        if(confirmacion == 'S')
        {
            listadoMonedas[posicion] = registro;
            eMoneda_ordenar(listadoMonedas, limiteMonedas, MONEDA_ORDEN_ID);


            imprimirEnPantalla(MONEDA_MSJ_MODIFICACION_OK);
        }
        else
        {
            imprimirEnPantalla(MSJ_CANCELO_GESTION);
        }
    }

    ejecutarEnConsola(HACER_PAUSA);
}

int eMoneda_baja(eMoneda* listadoMonedas, int limiteMonedas)
{
    char confirmacion;
    int posicion;
    int idMoneda;

    ejecutarEnConsola(LIMPIAR_PANTALLA);
    imprimirTitulo(MONEDA_BAJA_TITULO);

    if(eMoneda_estaVacio(listadoMonedas, limiteMonedas) == 1)
    {
        imprimirEnPantalla(MONEDA_MSJ_LISTA_VACIA);
    }
    else
    {
        ejecutarEnConsola(LIMPIAR_PANTALLA);
        imprimirTitulo(MONEDA_BAJA_TITULO);

        posicion = eMoneda_pedirIdYBuscar(listadoMonedas, limiteMonedas);

        imprimirEnPantalla(MONEDA_MOSTRAR_UNO_CABECERA);
        eMoneda_mostrarUno(listadoMonedas+posicion);

        confirmacion = pedirConfirmacion(MONEDA_MSJ_CONFIRMAR_BAJA);

        if(confirmacion == 'S')
        {
            idMoneda = (listadoMonedas+posicion)->idMoneda;
            (listadoMonedas+posicion)->estado = LIBRE;
            imprimirEnPantalla(MONEDA_MSJ_BAJA_OK);
        }
        else
        {
            imprimirEnPantalla(MSJ_CANCELO_GESTION);
        }
    }

    ejecutarEnConsola(HACER_PAUSA);
    return idMoneda;
}
