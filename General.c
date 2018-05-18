#include "General.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void ejecutarEnConsola(char* lineaDeComando)
{
    printf("\n");
    system(lineaDeComando);
}

char pedirConfirmacion(char* mensajeAlUsuario)
{
    char retorno;

    printf("\n%s (S/N): ", mensajeAlUsuario);
    fflush(stdin);
    scanf("%c", &retorno);

    do
    {
        switch(retorno)
        {
            case 'S':
            case 's':
                retorno = 'S';
                break;
            case 'N':
            case 'n':
                retorno = 'N';
                break;
            default:
                printf("\nPor favor ingrese 'S' o 'N': ");
                fflush(stdin);
                scanf("%c", &retorno);
                break;
        }
    }
    while(retorno != 'S' && retorno != 'N');

    return retorno;
}

int pedirInt(char* mensajeIngreso)
{
    int retorno;

    printf("%s", mensajeIngreso);
    fflush(stdin);
    scanf("%d", &retorno);


    return retorno;
}

int pedirIntValido(char* mensajeIngreso, char* mensajeReingreso, int limiteInferior, int limiteSuperior)
{
    int retorno;

    retorno = pedirInt(mensajeIngreso);

    while(retorno < limiteInferior || retorno > limiteSuperior)
    {
        retorno = pedirFloat(mensajeReingreso);
    }

    return retorno;
}

float pedirFloat(char* mensajeIngreso)
{
    float retorno;

    printf("%s", mensajeIngreso);
    fflush(stdin);
    scanf("%f", &retorno);


    return retorno;
}

float pedirFloatValido(char* mensajeIngreso, char* mensajeReingreso, float limiteInferior, float limiteSuperior)
{
    float retorno;

    retorno = pedirFloat(mensajeIngreso);

    while(retorno < limiteInferior || retorno > limiteSuperior)
    {
        retorno = pedirFloat(mensajeReingreso);
    }

    return retorno;
}

void pedirString(char retorno[], char* mensajeIngreso)
{
    printf("%s", mensajeIngreso);
    fflush(stdin);
    gets(retorno);
}

void pedirStringValido(char retorno[], char* mensajeIngreso, char* mensajeReingreso, int limite)
{
    char stringIngresado[STRING_LARGO_MAX];

    pedirString(stringIngresado, mensajeIngreso);

    while(strlen(stringIngresado) > limite)
    {
        printf("\nEl texto ingresado supera el l¡mite de %d caracteres establecido.", limite);
        pedirString(stringIngresado, mensajeIngreso);
    }

    strcpy(retorno, stringIngresado);
}

float calcularPromedio(float numero1, float numero2)
{
    float retorno;

    retorno = (numero1 + numero2) / 2;

    return retorno;
}

int buscarEnArrayInt(int array[], int limite, int buscar)
{
    int retorno = -1;
    int i;

    for(i=0 ; i<limite ; i++)
    {
        if(array[i] == buscar)
        {
            retorno = i;
            break;
        }
    }

    return retorno;
}

void imprimirEnPantalla(char texto[])
{
    printf("%s", texto);
}

void generarTitulo(char texto[])
{
    int i;
    char nuevoTitulo[TITULO_LARGO_MAX] = "| ";

    strcat(nuevoTitulo, texto);
    strcat(nuevoTitulo, " |");

    strcpy(texto, "\n+");
    for(i=0 ; i<strlen(nuevoTitulo)-2 ; i++)
    {
        strcat(texto, "-");
    }
    strcat(texto, "+\n");

    strcat(texto, nuevoTitulo);

    strcat(texto, "\n+");
    for(i=0 ; i<strlen(nuevoTitulo)-2 ; i++)
    {
        strcat(texto, "-");
    }
    strcat(texto, "+");

}

void imprimirTitulo(char texto[])
{
    char titulo[TITULO_LARGO_MAX];
    strcpy(titulo, texto);
    generarTitulo(titulo);
    imprimirEnPantalla(titulo);
}

void limpiarPantallaYMostrarTitulo(char texto[])
{
    ejecutarEnConsola(LIMPIAR_PANTALLA);
    imprimirTitulo(texto);
}

void pausa()
{
    ejecutarEnConsola(HACER_PAUSA);
}

void limpiarPantalla()
{
    ejecutarEnConsola(LIMPIAR_PANTALLA);
}
