/* 
 * File:   main.cpp
 * Author: miama
 *
 * Created on June 27, 2025, 5:52 PM
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include "funciones.h"
#include "estructuras.h"

using namespace std;

int main(int argc, char** argv) {
    NodoEmpresa *listaEmpresas{};
    leerEmpresas("EmpresasRegistradas.csv", listaEmpresas);
    
    NodoInfraccion *listaInfracciones{};
    leerInfracciones("TablaDeInfracciones.csv", listaInfracciones);
    
    leerPlacas("PlacasRegistradas.txt", listaEmpresas);
    
    generarReporte("reporte.txt", listaEmpresas, listaInfracciones);
    
    return 0;
}

