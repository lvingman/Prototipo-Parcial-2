#include<iostream>
#include<cstdlib>
#include <string.h>
#include "Persona.h"

using namespace std;

void Persona::setNombre(const char* nombre){
    strcpy(_nombre, nombre);
}
void Persona::setNroRegistro(int numero){
    _nroRegistro = numero;
}
/*
void Persona::setEdad(int numero){
    _edad = numero;
}
void Persona::setGastado(float numero){
    _gastado = numero;
}
void Persona::setADeber(float numero){
    _aDeber = numero;
}
void Persona::setARecibir(float numero){
    _aRecibir = numero;
}
*/
char * Persona::getNombre(){
    return _nombre;
}
int Persona::getNroRegistro(){
    return _nroRegistro;
}
/*
int Persona::getEdad(){
    return _edad;
}
float Persona::getGastado(){
    return _gastado;
}
float Persona::getADeber(){
    return _aDeber;
}
float Persona::getARecibir(){
    return _aRecibir;
}
*/
void Persona::cargar(int NroRegViaje,int pos){
    cout << "INGRESE NOMBRE DE LA PERSONA: ";
    cin.getline(_nombre, 30);
    cin.ignore();

    _nroDeOrden=pos;
    _nroRegistro=NroRegViaje;
    grabarEnDisco();
    //cout << "INGRESE LA EDAD DE LA PERSONA: ";
    //cin >> edad;
}
//-----------
void Persona::grabarEnDisco(){
FILE *p;
    p=fopen("Persona.dat", "ab");
    if (p==NULL){
        cout << "ERROR DE ARCHIVO";
        exit(1);
    }
    fwrite(this,sizeof(Persona),1, p);
    fclose(p);
}

///INTEGRANTES VIAJE------------------------------------------------------------------------------
///-----------------------------------------------------------------------------------------------

void IntegranteViaje::setNombre(const char * nombre){strcpy(_nombre, nombre);}
void IntegranteViaje::setNroViaje(int numero){_nroViaje = numero;}
float IntegranteViaje::setGasto(float numero){_gasto = numero;}
///GETS
char * IntegranteViaje::getNombre(){return _nombre;}
int IntegranteViaje::getNroViaje(){return _nroViaje;}
float IntegranteViaje::getGasto(){return _gasto;}


void IntegranteViaje::cargar(int numero){
    cout << "INGRESE NOMBRE DE LA PERSONA QUE REALIZO EL GASTO: ";

    cin.getline(_nombre,30);

    cout << "INGRESE EL MONTO GASTADO: ";
    cin >> _gasto;
    cin.ignore();
    _nroViaje = numero;

}

void IntegranteViaje::mostrar(){
    cout << "NOMBRE: " << _nombre << endl;
    cout << "MONTO GASTADO: " << _gasto << endl;
    cout << "NUMERO DE VIAJE: " << _nroViaje << endl;
}


bool IntegranteViaje::grabarEnDisco(){

    FILE* p;
    p = fopen("integranteViaje.dat", "ab");
    if (p == NULL) {
        return false;
    }

    if (fwrite(this, sizeof(IntegranteViaje), 1, p)) {
        fclose(p);
        return true;
    }
    else {
        fclose(p);
        return false;
    }

}

bool IntegranteViaje::leerDeDisco(int pos)
{
    FILE* p;
    p = fopen("integranteViaje.dat", "rb");

    if (p == NULL) {
        return false;
    }

    fseek(p, sizeof(IntegranteViaje) * pos, 0);

    if (fread(this, sizeof(IntegranteViaje), 1, p))
    {
        fclose(p);
        return true;
    }
    else {
        fclose(p);
        return false;
    }
}

bool IntegranteViaje::modificarRegistro(int pos)
{
    FILE *t;
    t = fopen("integranteViaje.dat", "rb+");

    if (t == NULL){
        return false;
    }

    bool ok;

    fseek(t, sizeof(IntegranteViaje) * pos , SEEK_SET);

    ok = fwrite(this, sizeof(IntegranteViaje), 1, t);

    fclose(t);

    return ok;
}


/*
bool Video::grabarEnDiscoPos(int pos){
    FILE *t;
    t = fopen("integranteViaje.dat", "rb+");
    if (t == NULL){
        return false;
    }
    bool ok;
    fseek(t, sizeof(IntegranteViaje) * pos , SEEK_SET);
    ok = fwrite(this, sizeof(IntegranteViaje), 1, t);
    fclose(t);
    return ok;
}

*/
