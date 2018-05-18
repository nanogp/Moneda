#pragma once
#ifndef ARCHIVO_H_INCLUDED
#define ARCHIVO_H_INCLUDED

#define ARCHIVO_MODO_ESCRITURA "w"
#define ARCHIVO_MODO_LECTURA "r"

int archivoAbrir(char* nombreArchivo, char* modo);
int archivoEscribir(char* texto);
int archivoCerrar();
int archivoAbrirYEscribir(char* nombreArchivo, char* texto);
int archivoLeer(char* texto, int limite);
int archivoLeerYCerrar(char* nombreArchivo, char* texto, int limite);
#endif // ARCHIVO_H_INCLUDED
