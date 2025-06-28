#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "funciones.h"
#include "estructuras.h"

using namespace std;

void leerEmpresas(const char* nomArch, NodoEmpresa *&listaEmpresas){
    ifstream datos(nomArch);
    errorDeLectura(datos, nomArch);
    Empresas empresaInfo{};
    while(true){
        datos>>empresaInfo.dni;
        if(datos.eof()) break;
        datos.get();
        empresaInfo.nombre=leerCadenaExacta(datos, ',');
        empresaInfo.distrito=leerCadenaExacta(datos, '\n');
        insertarEmpresaOrdenada(listaEmpresas, empresaInfo);
    }
}
void insertarEmpresaOrdenada(NodoEmpresa *&listaEmpresas, Empresas empresaInfo){
    NodoEmpresa *nuevoNodo, *aux=listaEmpresas, *antAux=nullptr;
    nuevoNodo = new NodoEmpresa;
    nuevoNodo->datosEmp=empresaInfo;
    while(aux){
        if(aux->datosEmp.dni < empresaInfo.dni) break;
        antAux = aux;
        aux = aux->siguiente;
    }
    nuevoNodo->siguiente = aux;
    if(antAux == nullptr) listaEmpresas=nuevoNodo;
    else antAux->siguiente = nuevoNodo;
}
void leerInfracciones(const char* nomArch, NodoInfraccion*& listaInfracciones){
    ifstream datos(nomArch);
    errorDeLectura(datos, nomArch);
    Infracciones infraccionInfo;
    while(true){
        infraccionInfo.codigo=leerCadenaExacta(datos, ',');
        if(datos.eof()) break;
        datos>>infraccionInfo.multa;
        datos.get();
        infraccionInfo.descripcion=leerCadenaExacta(datos, '\n');
        insertarInfraccionOrdenada(listaInfracciones, infraccionInfo);
    }
}
void insertarInfraccionOrdenada(NodoInfraccion*& listaInfracciones, Infracciones infraccionInfo){
    NodoInfraccion *nuevoNodo, *aux=listaInfracciones, *antAux=nullptr;
    nuevoNodo = new NodoInfraccion;
    nuevoNodo->datosInf = infraccionInfo;
    while(aux){
        if(strcmp(aux->datosInf.codigo, infraccionInfo.codigo)>0) break;
        antAux = aux;
        aux = aux->siguiente;
    }
    nuevoNodo->siguiente = aux;
    if(antAux == nullptr) listaInfracciones=nuevoNodo;
    else antAux->siguiente = nuevoNodo;
}
void leerPlacas(const char*nomArch, NodoEmpresa*& listaEmpresas){
    ifstream datos(nomArch);
    errorDeLectura(datos, nomArch);
    NodoEmpresa *nodoHallado;
    int dni;
    char placa[10];
    while(true){
        datos>>dni;
        if(datos.eof()) break;
        datos>>placa;
        nodoHallado=hallarNodo(listaEmpresas, dni);
        if(nodoHallado!=nullptr){
            nodoHallado->datosEmp.placas[nodoHallado->datosEmp.numPlacas]=new char[strlen(placa)+1];
            strcpy(nodoHallado->datosEmp.placas[nodoHallado->datosEmp.numPlacas], placa);
            nodoHallado->datosEmp.numPlacas++;
        }
    }
}
NodoEmpresa *hallarNodo(NodoEmpresa* listaEmpresas, int dni){
    NodoEmpresa *aux=listaEmpresas;
    while(aux){
        if(aux->datosEmp.dni==dni) return aux;
        aux = aux->siguiente;
    }
    return nullptr;
}
char *leerCadenaExacta(ifstream& datos, char lim){
    char texto[200], *cadena;
    datos.getline(texto, 200, lim);
    if(datos.eof()) return nullptr;
    cadena = new char[strlen(texto)+1];
    strcpy(cadena, texto);
    return cadena;
}
void generarReporte(const char*nomArch,NodoEmpresa *listaEmpresas,NodoInfraccion* listaInfracciones){
    ofstream reporte(nomArch);
    errorDeApuertura(reporte, nomArch);
    reporte<<fixed<<setprecision(2);
    int i;
    while(listaEmpresas){
        reporte<<left<<setw(10)<<listaEmpresas->datosEmp.dni<<setw(40)
                <<listaEmpresas->datosEmp.nombre<<setw(26)<<listaEmpresas->datosEmp.distrito;
        for(i=0; i<listaEmpresas->datosEmp.numPlacas; i++){
            reporte<<listaEmpresas->datosEmp.placas[i]<<" ";
        }
        reporte<<setw(48-i*9)<<" ";
        reporte<<right<<setw(8)<<listaEmpresas->datosEmp.totalPagado<<setw(8)
                <<listaEmpresas->datosEmp.totalAdeudado<<setw(6)
                <<listaEmpresas->datosEmp.cantidadDeFaltas<<endl;
        listaEmpresas=listaEmpresas->siguiente;
    }
    reporte<<endl;
    while(listaInfracciones){
        reporte<<left<<setw(5)<<listaInfracciones->datosInf.codigo<<right<<setw(8)
                <<listaInfracciones->datosInf.multa<<"  "
                <<listaInfracciones->datosInf.descripcion<<endl;
        listaInfracciones=listaInfracciones->siguiente;
    }
}
void errorDeApuertura(ofstream& reporte, const char* nomArch){
    if(not reporte.is_open()){
        cout<<"Error al abrir "<<nomArch<<endl;
        exit(1);
    }
}
void errorDeLectura(ifstream& datos, const char* nomArch){
    if(not datos.is_open()){
        cout<<"Error al abrir "<<nomArch<<endl;
        exit(1);
    }
}