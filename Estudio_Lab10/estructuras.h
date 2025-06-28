#ifndef ESTRUCTURAS_H
#define ESTRUCTURAS_H

#include "estructuras.h"

struct Infracciones{
    char *codigo;
    double multa;
    char *descripcion;
};
struct Fecha{
    int dd;
    int mm;
    int aa;
    int fecha;
};
struct Empresas{
    int dni;
    char *nombre;
    char *distrito;
    char *placas[10];
    int numPlacas;
    Fecha fechaDeInfraccion;
    Fecha fechaDePago;
    double totalDeMultas;
    double totalPagado;
    double totalAdeudado;
    int cantidadDeFaltas;
};
struct NodoEmpresa{
    Empresas datosEmp;
    NodoEmpresa *siguiente;
};
struct NodoInfraccion{
    Infracciones datosInf;
    NodoInfraccion *siguiente;
};

#endif /* ESTRUCTURAS_H */

