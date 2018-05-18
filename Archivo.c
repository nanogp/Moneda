#include "Archivo.h"
#include <stdio.h>

FILE* fp;

int archivoAbrir(char* nombreArchivo, char* modo)
{
    int retorno = -1;

    fp = fopen(nombreArchivo, modo);

    if(fp!=NULL)
    {
        retorno = 0;
    }
    return retorno;
}

int archivoEscribir(char* texto)
{
    return fprintf(fp, texto);
}

int archivoCerrar()
{
    return fclose(fp);
}

int archivoAbrirYEscribir(char* nombreArchivo, char* texto)
{
    int retorno;

    retorno = archivoAbrir(nombreArchivo, ARCHIVO_MODO_ESCRITURA);

    if(retorno == 0)
    {
        retorno = archivoEscribir(texto);

        if(retorno == 0)
        {
            retorno = archivoCerrar();
        }
    }
    return retorno;
}

int archivoLeer(char* texto, int limite)
{
    int retorno = -1;
    char buffer[limite];

    if(fgets(texto, limite, fp) != NULL)
    {
        while(!feof(fp))
        {
            fgets(buffer, limite, fp);
            texto = strcat(texto, buffer);
        }
        retorno = 0;
    }
    return retorno;
}


int archivoLeerYCerrar(char* nombreArchivo, char* texto, int limite)
{
    int retorno;

    retorno = archivoAbrir(nombreArchivo, ARCHIVO_MODO_LECTURA);

    if(retorno == 0)
    {
        retorno = archivoLeer(texto, limite);

        if(retorno == 0)
        {
            retorno = archivoCerrar();
        }
    }
    return retorno;
}
