#include<iostream>
#include<cstdlib>
#include <string.h>
#include "Gasto.h"

using namespace std;
/*
Gasto::Gasto(int nroGastador=0,float monto=0,int nroRegistro=0){
    _nroGatador=nroGastador;
    _monto=monto;
    _nroRegistro=nroRegistro;
}

Gasto::Gasto(const char* nombre,int nroGastador,float monto,int nroRegistro){
    _gastador=nombre;
    _nroGatador=nroGastador;
    _monto=monto;
    _nroRegistro=nroRegistro;
}
*/
//-----------SETTERS----------------------------
void Gasto::setGastador(const char* nombre){
    strcpy(_gastador, nombre);
}
void Gasto::setNroGastador(int numero){
    _nroGastador = numero;
}
void Gasto::setMonto(float numero){
    _monto = numero;
}
void Gasto::setNroRegistro(int numero){
    _nroRegistro = numero;
}

//----GETTERS----------------------------------
char * Gasto::getGastador(){
    return _gastador;
}
int Gasto::getNroGatador(){
    return _nroGastador;
}

float Gasto::getMonto(){
    return _monto;
}
int Gasto::getNroRegistro(){
    return _nroRegistro;
}

//------METODOS--------------------------------
void Gasto::cargarNombre(int nroGastador, int nroRegistro){
    cin.ignore();
    cout << "INGRESE NOMBRE DE LA PERSONA : ";
    cin.getline(_gastador,30);
    _nroGastador=nroGastador;
    _monto=0;
    _nroRegistro=nroRegistro;
    //cin.ignore();

}

void Gasto::cargar(){
    cout << "INGRESE NOMBRE DE LA PERSONA QUE REALIZO EL GASTO: ";
    cin.ignore();
    cin.ignore();
    cin.getline(_gastador,30);
    cin.ignore();
    cout << "INGRESE EL MONTO GASTADO: ";
    cin >> _monto;
    cout << "INGRESE EL NUMERO DE REGISTRO: ";
    cin >> _nroRegistro;
    cout << "---------------------------------------------------------- "<<endl;
    cin.ignore();
}

void Gasto::mostrar(){
    cout << "NOMBRE DE LA PERSONA QUE REALIZO EL GASTO: "<<_gastador<<endl;
    //cout << "INGRESE LA FECHA DEL TICKET:" <<_fechaTicket.mostrar();
    //cout << " HORA DEL TICKET:" << _horaTicket.mostrar();
    cout << "NUMERO : "<<_nroGastador<<endl;
    cout << "MONTO GASTADO: "<< _monto<<endl;
    cout << "NUMERO DE REGISTRO: "<< _nroRegistro <<endl;
    cout << "---------------------------------------------------------- "<<endl;
}

bool Gasto::grabarEnDisco(){
    FILE* p;
    p = fopen("gastosViaje.dat","ab");
    if (p == NULL) {
        return false;
    }

    if (fwrite(this, sizeof(GastoReunion), 1, p)) {
        fclose(p);
        return true;
    }
    else {
        fclose(p);
        return false;
    }
}

bool Gasto::leerDeDisco(int pos){
    FILE* p;
    p = fopen("gastosViaje.dat", "rb");
        if (p == NULL) {
        return false;
        }
    fseek(p, sizeof(Gasto) * pos, 0);

        if (fread(this, sizeof(Gasto), 1, p)){
            fclose(p);
            return true;
        }
        else {
        fclose(p);
        return false;
        }

}


///GASTO REUNION--------------------------------------------
void GastoReunion::setGastador(const char* nombre){
    strcpy(_gastador, nombre);
}


void GastoReunion::setMonto(float numero){
    _monto = numero;
}
void GastoReunion::setNroRegistro(int numero){
    _nroRegistro = numero;
}
void GastoReunion::setIDreunion(int numero){
    _IDreunion = numero;
}



char * GastoReunion::getGastador(){
    return _gastador;
}


float GastoReunion::getMonto(){
    return _monto;
}
int GastoReunion::getNroRegistro(){
    return _nroRegistro;
}

int GastoReunion::getIDreunion(){
    return _IDreunion;
}


void GastoReunion::mostrar(){
    cout << "NOMBRE DE LA PERSONA QUE REALIZO EL GASTO: "<<_gastador<<endl;
    //cout << "INGRESE LA FECHA DEL TICKET:" <<_fechaTicket.mostrar();
    //cout << " HORA DEL TICKET:" << _horaTicket.mostrar();
    //cout << "NUMERO DEL TICKET: "<<_nroTicket;
    cout << "MONTO GASTADO: "<< _monto<<endl;
   // cout << "NUMERO DE REGISTRO: ">> _nroRegistro<<endl;
    cout << "---------------------------------------------------------- "<<endl;
}




void GastoReunion::cargar(int nroReunion){

    cout << "INGRESE NOMBRE DE LA PERSONA QUE REALIZO EL GASTO: ";
    cin.ignore();
    cin.getline(_gastador, 30);
    cout << "INGRESE EL MONTO GASTADO: ";
    cin >> _monto;
    cout << "INGRESE EL NUMERO DE REGISTRO: ";
    cin >> _nroRegistro;
    _IDreunion = nroReunion;
    cout << "---------------------------------------------------------- "<<endl;
}

bool GastoReunion::grabarEnDisco(){
    FILE* p;
    p = fopen("gastosReunion.dat", "ab");
    if (p == NULL) {
        return false;
    }

    if (fwrite(this, sizeof(GastoReunion), 1, p)) {
        fclose(p);
        return true;
    }
    else {
        fclose(p);
        return false;
    }
}

bool GastoReunion::leerDeDisco(int pos){

    FILE* p;
    p = fopen("gastosReunion.dat", "rb");

    if (p == NULL) {
        return false;
    }

    fseek(p, sizeof(GastoReunion) * pos, 0);

    if (fread(this, sizeof(GastoReunion), 1, p))
    {
        fclose(p);
        return true;
    }
    else {
        fclose(p);
        return false;
    }

}







/*

void GastoReunion::cargar(){
    cout << "INGRESE NOMBRE DE LA PERSONA QUE REALIZO EL GASTO: ";
    cin.getline(_gastador, 30);
    cin.ignore();
    cout << "INGRESE LA FECHA DEL TICKET:" << endl;
    _fechaTicket.cargar();
    cout << "INGRESE LA HORA DEL TICKET:" << endl;
    _horaTicket.cargar();
    cout << "INGRESE EL NUMERO DEL TICKET: ";
    cin >> _nroTicket;
    cout << "INGRESE EL MONTO GASTADO: ";
    cin >> _monto;
    cout << "INGRESE EL NUMERO DE REGISTRO: ";
    cin >> _nroRegistro;
    cout << "INGRESE EL TIPO DE GASTO (1-EFECTIVO; 2-DEBITO): ";
    cin >> _tipoGasto;
    cout << "INGRESE QUE TIPO DE REUNION SE REALIZO: ";
    cin.getline(_reunion, 50);
    cin.ignore();
}

void GastoReunion::grabarEnDisco(){
    FILE *p;
    p=fopen("gastosReunion.dat", "ab");
    if (p==NULL){
        cout << "ERROR DE ARCHIVO";
        exit(1);
    }
    fwrite(this,sizeof(Gasto),1, p);
    fclose(p);
}
*/
