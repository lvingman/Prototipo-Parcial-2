//Materia:
//Nombre:
//TP N°:
//Ej N°:
//Comentario:
//____________________________________

#include <iostream>
#include <cstdlib>
#include <string.h>
#include "Gasto.h"
#include "Fecha.h"
#include "Viaje.h"
#include "Persona.h"

using namespace std;




//Setters----------------------------------------


void Viaje::setLugar(const char* lugar){
    strcpy(_lugar,lugar);
}
void Viaje::setDescripcion(const char* descripcion){
    strcpy(_descripcion,descripcion);
}
void Viaje::setFechaViaje(Fecha fechaViaje){
    _fechaViaje = fechaViaje;
}
void Viaje::setNroViaje(int nroViaje){
    _nroViaje =nroViaje;
}
void Viaje::setCantPersonaViaje(int cantPersonaViaje){
    _cantPersonaViaje = cantPersonaViaje;
}
//Getters-----------------------------------------
char * Viaje::getLugar(){
    return _lugar;
}
char * Viaje::getDescripcion(){
    return _descripcion;
}
Fecha Viaje::getFechaViaje(){
    return _fechaViaje;
}
int Viaje::getNroViaje(){
    return _nroViaje;
}
int Viaje::getCantPersonaViaje(){
    return _cantPersonaViaje;
}
bool Viaje::getSaldado(){
    return _saldado;
}
//FUNCIONES DE LA CLASE------------------------------
void Viaje::cargarViaje(){
    if (_saldado == false){
        cout << "INGRESE NUMERO DE ID DE LA VIAJE: ";
        cin >> _nroViaje;
        cin.ignore();
        cin.ignore();
        cout << "INGRESE LUJAR DEL VIAJE: ";
        cin.getline(_lugar, 50);
        //cin.ignore();
        //cin.ignore();
        cout << "INGRESE DESCRIPCION DEL VIAJE: ";
        cin.getline(_descripcion, 50);
        //cin.ignore();
        //cin.ignore();
        cout << "INGRESE LA FECHA DEL VIAJE:" << endl;
        _fechaViaje.cargar();
        cin.ignore();
        cout << "INGRESE EL NUMERO DE PARTICIPANTES: ";
        cin >> _cantPersonaViaje;
        cin.ignore();
        //generarCodigo();
        cout << "________________________________________________"<<endl;
        grabarEnDisco();
        cargarParticipantes();
    }
    else{
        cout << "NO SE PUEDE CARGAR UN VIAJE MIENTRAS SE ESTA TRABAJANDO CON OTRO." << endl;
        cout << "SALDE EL VIAJE CON EL QUE ESTA TRABAJANDO PRIMERO." << endl;
    }
}

void Viaje::cargarParticipantes(){

        IntegranteViaje *Participante;
        Participante =new IntegranteViaje[getCantPersonaViaje()];

        int pos=0;
        while(pos<getCantPersonaViaje()){

            Participante[pos].cargar(_nroViaje);
            Participante[pos].grabarEnDisco();
            cin.ignore();
            Participante[pos].mostrar();
            pos++;
        }
        delete Participante;

}

void Viaje::cargarPersonas(int nroViaje,int cantPersonaViaje){
int pos=0;
IntegranteViaje integrantes;
    while(pos<cantPersonaViaje){
        integrantes.cargar(nroViaje);
        pos++;
    }
}

void Viaje::cargarGastosViaje(){
        char nombre[30];
        float gastubi;

        cout << "INGRESE EL NOMBRE AL QUE CORRESPONDEN LOS SIGUIENTES GASTOS: ";
        cin.getline(nombre, 30);
        cin.ignore();
        IntegranteViaje reg;
        int pos=0;
        while(reg.leerDeDisco(pos)){
            if (((strcmp(nombre, reg.getNombre())) == 0) && (_nroViaje == reg.getNroViaje())){
                cout << "INGRESE EL MONTO GASTADO: ";
                cin >> gastubi;
                reg.setGasto(gastubi+reg.getGasto());
                reg.modificarRegistro(pos);
                break;
            }
            pos++;
        }
}

void Viaje::grabarEnDisco(){
FILE *p;
    p=fopen("Viajes.dat", "ab");
    if (p==NULL){
        cout << "ERROR DE ARCHIVO";
        exit(1);
    }
    fwrite(this,sizeof(Viaje),1, p);
    fclose(p);
}


int Viaje::CantidadDeRegistrosViaje(){
    int bytes, cant;
    FILE *p;
    p=fopen("Viajes.dat","rb");
        if(p==NULL){
            cout<<"EL ARCHIVO Viajes.dat NO SE PUDO ABRIR"<<endl;
            return false;
        }
    fseek(p,0,SEEK_END);
    bytes=ftell(p);
    fclose(p);
    cant=bytes/sizeof(Viaje);
    return cant;
}

bool Viaje::leerDeDisco(int cant){

    FILE *p;
    p=fopen("Viajes.dat","rb");
        if(p==NULL){
            cout<<"EL ARCHIVO Viajes.dat NO SE PUDO ABRIR"<<endl;
            return false;
        }
    fseek(p,cant*sizeof(Viaje),SEEK_SET);
    bool ok;
    ok=fread(this,sizeof(Viaje),1,p);
    fclose(p);
    return ok;
}


void Viaje::saldar(int nroViaje){
int pos=0;
    //cout<<cant<<endl;

    IntegranteViaje *Participantes;
    Participantes = new IntegranteViaje[getCantPersonaViaje()];
    int contador = 0;
    float total = 0;
    IntegranteViaje reg;

    while(reg.leerDeDisco(pos)){
        if(reg.getNroViaje() == _nroViaje){
            Participantes[contador] = reg;
            total += Participantes[contador].getGasto();
            contador++;
        }
        pos++;
    }


    pos=0;

    float(*vSaldo)[3];

    vSaldo = new float [getCantPersonaViaje()][3];

    pos=0;

    for(int i=0;i<getCantPersonaViaje(); i++){
        vSaldo[i][0]=Participantes[i].getGasto();
        vSaldo[i][1]=vSaldo[pos][0]-(total/getCantPersonaViaje());
        vSaldo[i][2]=i;
        if(vSaldo[i][1]==0){ cout<<Participantes[i].getNombre()<<" No Tiene que poner plata $: "<<vSaldo[i][1]<<endl;}
        if(vSaldo[i][1]<0) { cout<<Participantes[i].getNombre()<<" Tiene que PONER $: "<<vSaldo[i][1]*-1<<endl;}
        if(vSaldo[i][1]>0) { cout<<Participantes[i].getNombre()<<" Tiene que RECIBIR $: "<<vSaldo[i][1]<<endl;}
        pos++;
        }


}
