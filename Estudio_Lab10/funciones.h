/* 
 * File:   funciones.h
 * Author: miama
 *
 * Created on June 27, 2025, 5:52 PM
 */

#ifndef FUNCIONES_H
#define FUNCIONES_H

#include "estructuras.h"

using namespace std;

void leerEmpresas(const char* nomArch, NodoEmpresa *&listaEmpresas);
void leerInfracciones(const char* nomArch, NodoInfraccion*& listaInfracciones);
void leerPlacas(const char*nomArch, NodoEmpresa*& listaEmpresas);

NodoEmpresa *hallarNodo(NodoEmpresa* listaEmpresas, int dni);

void insertarEmpresaOrdenada(NodoEmpresa *&listaEmpresas, Empresas empresaInfo);
void insertarInfraccionOrdenada(NodoInfraccion*& listaInfracciones, Infracciones infraccionInfo);

char *leerCadenaExacta(ifstream& datos, char lim); // IMPORTANTE

void generarReporte(const char*nomArch,NodoEmpresa *listaEmpresas,NodoInfraccion* listaInfracciones);

void errorDeApuertura(ofstream& reporte, const char* nomArch);
void errorDeLectura(ifstream& datos, const char* nomArch);


#endif /* FUNCIONES_H */

