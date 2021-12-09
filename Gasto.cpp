#include<iostream>
#include<cstdlib>
#include <string.h>
#include "Gasto.h"
#include "rlutil.h"

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
void Gasto::setDescripcion(const char* nombre){
    strcpy(_descripcion, nombre);
}
void Gasto::setNroGastador(int numero){
    _nroGastador = numero;
}
void Gasto::setMonto(float numero){
    _monto = numero;
}

void Gasto::setFecha(Fecha fechubi){
    _fecha = fechubi;
}

//----GETTERS----------------------------------
char * Gasto::getGastador(){
    return _gastador;
}
char * Gasto::getDescripcion(){
    return _descripcion;
}
int Gasto::getNroGatador(){
    return _nroGastador;
}

float Gasto::getMonto(){
    return _monto;
}

Fecha Gasto::getFecha(){
    return _fecha;
}

//------METODOS--------------------------------
void Gasto::cargarNombre(int nroGastador){
    cin.ignore();
    cout << "INGRESE NOMBRE DE LA PERSONA : ";
    cin.getline(_gastador,30);
    _nroGastador=nroGastador;
    _monto=0;
    //cin.ignore();

}

void Gasto::cargar(){
    int cant=CantidadDeRegistrosGastosComunes();
    cout << "NUMERO DE GASTO: ";
    _nroGastador=cant+1;
    cout<<_nroGastador<<endl;
    cout << "INGRESE NOMBRE DE LA PERSONA QUE REALIZO EL GASTO: ";
    cin.getline(_gastador,30);
    cout << "INGRESE DESCRIPCION DEL GASTO: ";
    cin.getline(_descripcion,50);
    cout << "INGRESE EL MONTO GASTADO: ";
    cin >> _monto;
    cout << "---------------------------------------------------------- "<<endl;
    cout << "INGRESE FECHA DEL GASTO: " << endl;
    _fecha.cargar();

    grabarEnDiscoGastosComunes();
}



void Gasto::mostrar(){
    cout << "NOMBRE DE LA PERSONA QUE REALIZO EL GASTO: "<<_gastador<<endl;
    //cout << "INGRESE LA FECHA DEL TICKET:" <<_fechaTicket.mostrar();
    //cout << " HORA DEL TICKET:" << _horaTicket.mostrar();
    cout << "NUMERO: "<<_nroGastador<<endl;
    cout << "DESCRIPCION: " << _descripcion << endl;
    cout << "MONTO GASTADO: "<< _monto<<endl;
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

///METODO 1

void Gasto::mostrarListado(){

    int pos=0;
    rlutil::locate(1,2);
    cout<<"-----------------------------------------------------------------------------------------------------";
    rlutil::locate(2,3);
    cout<<"Nro de Gasto ";
     rlutil::locate(20,3);
    cout<<"Nombre ";
    rlutil::locate(40,3);
    cout<<"Descripcion ";
    rlutil::locate(60,3);
    cout<<"Monto ";
    rlutil::locate(80,3);
    cout << "Fecha";
    rlutil::locate(1,4);
    cout<<"------------------------------------------------------------------------------------------------------";


    while(leerDeDisco(pos)){
        rlutil::locate(2,5+pos);
        cout <<getNroGatador();
        rlutil::locate(20,5+pos);
        cout<<getGastador();
        rlutil::locate(40,5+pos);
        cout<<getDescripcion();
        rlutil::locate(60,5+pos);
        cout<<getMonto();
        rlutil::locate(80,5+pos);
        getFecha().mostrar();

        pos++;
    }

    cout<<endl<<endl<<endl<<endl<<endl;
}

///METODO 2

bool Gasto::grabarEnDiscoGastosComunes(){
    FILE* p;
    p = fopen("gastosComunes.dat","ab");
    if (p == NULL) {
        return false;
    }

    if (fwrite(this, sizeof(Gasto), 1, p)) {
        fclose(p);
        return true;
    }
    else {
        fclose(p);
        return false;
    }
}

///METODO 3

bool Gasto::leerDeDiscoGastosComunes(int pos){
    FILE* p;
    p = fopen("gastosComunes.dat", "rb");
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

///METODO 4

int Gasto::CantidadDeRegistrosGastosComunes(){
 int bytes, cant;
    FILE *p;
    p=fopen("gastosComunes.dat","rb");
        if(p==NULL){
            //cout<<"EL ARCHIVO gastoscomunes.dat NO SE PUDO ABRIR"<<endl;
            return 0;
        }
    fseek(p,0,SEEK_END);
    bytes=ftell(p);
    fclose(p);
    cant=bytes/sizeof(Gasto);
    return cant;
}

///METODO 5

void Gasto::mostrarListadoGastosComunes(){

    int pos=0;
    rlutil::locate(1,2);
    cout<<"--------------------------------------------------------------------------------------------------------------";
    rlutil::locate(2,3);
    cout<<"Nro de Gasto ";
     rlutil::locate(20,3);
    cout<<"Nombre ";
    rlutil::locate(40,3);
    cout<<"Descripcion ";
    rlutil::locate(60,3);
    cout<<"Monto ";
    rlutil::locate(80,3);
    cout << "Fecha";

    rlutil::locate(1,4);
    cout<<"----------------------------------------------------------------------------------------------------------------";

    while(leerDeDiscoGastosComunes(pos)){
        rlutil::locate(2,5+pos);
        cout <<getNroGatador();
        rlutil::locate(20,5+pos);
        cout<<getGastador();
        rlutil::locate(40,5+pos);
        cout<<getDescripcion();
        rlutil::locate(60,5+pos);
        cout<<getMonto();
        rlutil::locate(80,5+pos);
        getFecha().mostrar();
        pos++;
    }

    cout<<endl<<endl<<endl<<endl<<endl;
}

///METODO 6

void Gasto::compararTodosGastosComunes(int numero){

    float (*dineroTotal)[2];
    dineroTotal = new float[numero][2];

    char **nombres;
    nombres = new char *[numero];

    float total = 0;
    for (int i=0;i<numero;i++){
        int pos = 0;
        nombres[i] = new char[30];
        cout << "INGRESE UN NOMBRE: ";
        cin.getline(nombres[i],30);
        while(leerDeDiscoGastosComunes(pos)){
            if (strcmp(_gastador,nombres[i]) == 0){
                dineroTotal[i][0] += _monto;
                total += _monto;
            }
            pos++;
        }
    }

    system("cls");

    for (int i=0;i<numero;i++){
        dineroTotal[i][1] = (dineroTotal[i][0] - total/numero);

        rlutil::locate(1,4+i);
        cout << nombres[i] << " gasto $" << dineroTotal[i][0];
        rlutil::locate(40,4+i);
        cout << " y";
        if(dineroTotal[i][1]==0){ cout<<" no tiene que poner plata" <<endl;}
        if(dineroTotal[i][1]<0) { cout<<" tiene que PONER $: "<<dineroTotal[i][1]*-1<<endl;}
        if(dineroTotal[i][1]>0) { cout<<" tiene que RECIBIR $: "<<dineroTotal[i][1]<<endl;}


    }





}

///METODO 7

void Gasto::consultaGastosComunesMonto(float dinero){
    int opc;
    cout << "DESEA BUSCAR GASTOS MAYORES [1], MENORES [2], O IDENTICOS AL MONTO INGRESADO?[3]: ";
    cin >> opc;
    system("cls");

    switch(opc){
        case 1:{

            int pos=0;
            rlutil::locate(40,1);
            cout << "GASTOS MAS COSTOSOS QUE: " << dinero;
            rlutil::locate(1,2);
            cout<<"--------------------------------------------------------------------------------------------------------------";
            rlutil::locate(2,3);
            cout<<"Nro de Gasto ";
            rlutil::locate(20,3);
            cout<<"Nombre ";
            rlutil::locate(40,3);
            cout<<"Descripcion ";
            rlutil::locate(60,3);
            cout<<"Monto ";
            rlutil::locate(80,3);
            cout << "Fecha";

            rlutil::locate(1,4);
            cout<<"----------------------------------------------------------------------------------------------------------------";

            int cont=0;
            while(leerDeDiscoGastosComunes(pos)){
                if (_monto > dinero){
                    rlutil::locate(2,5+cont);
                    cout <<getNroGatador();
                    rlutil::locate(20,5+cont);
                    cout<<getGastador();
                    rlutil::locate(40,5+cont);
                    cout<<getDescripcion();
                    rlutil::locate(60,5+cont);
                    cout<<getMonto();
                    rlutil::locate(80,5+cont);
                    getFecha().mostrar();
                }
                pos++;
            }
            cout << endl << endl;
            break;
        }

        case 2:{
            int pos=0;
            rlutil::locate(40,1);
            cout << "GASTOS MENOS COSTOSOS QUE: " << dinero;
            rlutil::locate(1,2);
            cout<<"--------------------------------------------------------------------------------------------------------------";
            rlutil::locate(2,3);
            cout<<"Nro de Gasto ";
            rlutil::locate(20,3);
            cout<<"Nombre ";
            rlutil::locate(40,3);
            cout<<"Descripcion ";
            rlutil::locate(60,3);
            cout<<"Monto ";
            rlutil::locate(80,3);
            cout << "Fecha";

            rlutil::locate(1,4);
            cout<<"----------------------------------------------------------------------------------------------------------------";

            int cont=0;
            while(leerDeDiscoGastosComunes(pos)){
                if (_monto < dinero){
                    rlutil::locate(2,5+cont);
                    cout <<getNroGatador();
                    rlutil::locate(20,5+cont);
                    cout<<getGastador();
                    rlutil::locate(40,5+cont);
                    cout<<getDescripcion();
                    rlutil::locate(60,5+cont);
                    cout<<getMonto();
                    rlutil::locate(80,5+cont);
                    getFecha().mostrar();
                    cont++;
                }
                pos++;
            }
            cout << endl << endl;

            break;
        }

        case 3:{
            int pos=0;
            rlutil::locate(40,1);
            cout << "GASTOS IGUAL DE COSTOSOS A : " << dinero;
            rlutil::locate(1,2);
            cout<<"--------------------------------------------------------------------------------------------------------------";
            rlutil::locate(2,3);
            cout<<"Nro de Gasto ";
            rlutil::locate(20,3);
            cout<<"Nombre ";
            rlutil::locate(40,3);
            cout<<"Descripcion ";
            rlutil::locate(60,3);
            cout<<"Monto ";
            rlutil::locate(80,3);
            cout << "Fecha";
            rlutil::locate(1,4);
            cout<<"----------------------------------------------------------------------------------------------------------------";

            int cont=0;
            while(leerDeDiscoGastosComunes(pos)){
                if (_monto == dinero){
                    rlutil::locate(2,5+cont);
                    cout <<getNroGatador();
                    rlutil::locate(20,5+cont);
                    cout<<getGastador();
                    rlutil::locate(40,5+cont);
                    cout<<getDescripcion();
                    rlutil::locate(60,5+cont);
                    getFecha().mostrar();

                    cont++;
                }
                pos++;
            }
            cout << endl << endl;

            break;
        }

    }

}

///METODO 8

void Gasto::consultaGastosComunesFecha(Fecha aLeer){
    int opc;
    cout << "DESEA BUSCAR GASTOS ANTERIORES [1], POSTERIORES [2], O EXACTAMENTE EN LA FECHA INGRESADA?[3]: ";
    cin >> opc;
    system("cls");

    switch(opc){
        case 1:{

            int pos=0;
            rlutil::locate(40,1);
            cout << "GASTOS ANTERIORES A LA FECHA: ";
            aLeer.mostrar();
            rlutil::locate(1,2);
            cout<<"--------------------------------------------------------------------------------------------------------------";
            rlutil::locate(2,3);
            cout<<"Nro de Gasto ";
            rlutil::locate(20,3);
            cout<<"Nombre ";
            rlutil::locate(40,3);
            cout<<"Descripcion ";
            rlutil::locate(60,3);
            cout<<"Monto ";
            rlutil::locate(80,3);
            cout << "Fecha";

            rlutil::locate(1,4);
            cout<<"----------------------------------------------------------------------------------------------------------------";

            int cont=0;
            while(leerDeDiscoGastosComunes(pos)){
                if ((_fecha.getDia()+ _fecha.getMes()*30 + _fecha.getAnio()*365) < (aLeer.getDia() + aLeer.getMes()*30 + aLeer.getAnio()*365)){
                    rlutil::locate(2,5+cont);
                    cout <<getNroGatador();
                    rlutil::locate(20,5+cont);
                    cout<<getGastador();
                    rlutil::locate(40,5+cont);
                    cout<<getDescripcion();
                    rlutil::locate(60,5+cont);
                    cout<<getMonto();
                    rlutil::locate(80,5+cont);
                    getFecha().mostrar();
                }
                pos++;
            }
            cout << endl << endl;
            break;
        }

        case 2:{
            int pos=0;
            rlutil::locate(40,1);
            cout << "GASTOS POSTERIORES A LA FECHA: ";
            aLeer.mostrar();
            rlutil::locate(1,2);
            cout<<"--------------------------------------------------------------------------------------------------------------";
            rlutil::locate(2,3);
            cout<<"Nro de Gasto ";
            rlutil::locate(20,3);
            cout<<"Nombre ";
            rlutil::locate(40,3);
            cout<<"Descripcion ";
            rlutil::locate(60,3);
            cout<<"Monto ";
            rlutil::locate(80,3);
            cout << "Fecha";

            rlutil::locate(1,4);
            cout<<"----------------------------------------------------------------------------------------------------------------";

            int cont=0;
            while(leerDeDiscoGastosComunes(pos)){
                if ((_fecha.getDia()+ _fecha.getMes()*30 + _fecha.getAnio()*365) > (aLeer.getDia() + aLeer.getMes()*30 + aLeer.getAnio()*365)){
                    rlutil::locate(2,5+cont);
                    cout <<getNroGatador();
                    rlutil::locate(20,5+cont);
                    cout<<getGastador();
                    rlutil::locate(40,5+cont);
                    cout<<getDescripcion();
                    rlutil::locate(60,5+cont);
                    cout<<getMonto();
                    rlutil::locate(80,5+cont);
                    getFecha().mostrar();
                    cont++;
                }
                pos++;
            }
            cout << endl << endl;

            break;
        }

        case 3:{
            int pos=0;
            rlutil::locate(40,1);
            cout << "GASTOS OCURRIDOS EN LA FECHA: ";
            aLeer.mostrar();
            rlutil::locate(1,2);
            cout<<"--------------------------------------------------------------------------------------------------------------";
            rlutil::locate(2,3);
            cout<<"Nro de Gasto ";
            rlutil::locate(20,3);
            cout<<"Nombre ";
            rlutil::locate(40,3);
            cout<<"Descripcion ";
            rlutil::locate(60,3);
            cout<<"Monto ";
            rlutil::locate(1,4);
            cout<<"----------------------------------------------------------------------------------------------------------------";

            int cont=0;
            while(leerDeDiscoGastosComunes(pos)){
                if ((_fecha.getDia()+ _fecha.getMes()*30 + _fecha.getAnio()*365) == (aLeer.getDia() + aLeer.getMes()*30 + aLeer.getAnio()*365)){
                    rlutil::locate(2,5+cont);
                    cout <<getNroGatador();
                    rlutil::locate(20,5+cont);
                    cout<<getGastador();
                    rlutil::locate(40,5+cont);
                    cout<<getDescripcion();
                    rlutil::locate(60,5+cont);
                    cout<<getMonto();
                    cont++;
                }
                pos++;
            }
            cout << endl << endl;

            break;
        }

    }

}

///METODO 9

void Gasto::mostrarListadoGastosIndividuo(const char * nombre){
    system("cls");
    cout << "GASTOS DEL USUARIO: " << nombre;
    int pos=0;
    rlutil::locate(1,2);
    cout<<"-----------------------------------------------------------------------------------------------------";
    rlutil::locate(2,3);
    cout<<"Nro de Gasto ";
     rlutil::locate(20,3);
    cout<<"Descripcion ";
    rlutil::locate(40,3);
    cout<<"Monto ";
    rlutil::locate(60,3);
    cout << "Fecha";
    rlutil::locate(1,4);
    cout<<"------------------------------------------------------------------------------------------------------";

    int cont=0;
    while(leerDeDiscoGastosComunes(pos)){
        if (strcmp(nombre,getGastador()) == 0){
            rlutil::locate(2,5+cont);
            cout <<getNroGatador();
            rlutil::locate(20,5+cont);
            cout<<getDescripcion();
            rlutil::locate(40,5+cont);
            cout<<getMonto();
            rlutil::locate(60,5+cont);
            getFecha().mostrar();
            rlutil::locate(80,5+cont);
            cont++;
        }
        pos++;
    }

    cout<<endl<<endl<<endl<<endl<<endl;
}



///GASTO REUNION---------------------------------------------------------------------------------
///----------------------------------------------------------------------------------------------
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
