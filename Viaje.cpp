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
#include "rlutil.h"
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


        cout << "NUMERO DE ID DE LA VIAJE: ";

        _nroViaje=GenerarCodigo();
        cout<<_nroViaje;
        //cin >> _nroViaje;
        cin.ignore();
        cout << "INGRESE LUGAR DEL VIAJE: ";
        cin.getline(_lugar, 50);
        //cin.ignore();
        //cin.ignore();
        cout << "INGRESE DESCRIPCION DEL VIAJE: ";
        cin.getline(_descripcion, 50);
        //cin.ignore();
        //cin.ignore();
        cout << "INGRESE LA FECHA DEL VIAJE:" << endl;
        _fechaViaje.cargar();
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
    system("cls");
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
    float(*vSaldo)[3];

    vSaldo = new float [getCantPersonaViaje()][3];

    pos=0;
    rlutil::locate(0,1);
    cout<<"MONTO TOTAL: $" <<total;
    rlutil::locate(1,2);
    cout<<"----------------------------------";

    for(int i=0;i<getCantPersonaViaje(); i++){

        vSaldo[i][0]=Participantes[i].getGasto();
        vSaldo[i][1]=vSaldo[pos][0]-(total/getCantPersonaViaje());
        vSaldo[i][2]=i;

        rlutil::locate(1,4+pos);
        cout << Participantes[i].getNombre() << " gasto $" << vSaldo[i][0];
        rlutil::locate(40,4+pos);
        cout << "y ";

        if(vSaldo[i][1]==0){ cout<<Participantes[i].getNombre()<<" no tiene que poner plata"<<endl;}
        if(vSaldo[i][1]<0) { cout<<Participantes[i].getNombre()<<" tiene que PONER $: "<<vSaldo[i][1]*-1<<endl;}
        if(vSaldo[i][1]>0) { cout<<Participantes[i].getNombre()<<" tiene que RECIBIR $: "<<vSaldo[i][1]<<endl;}
        pos++;
        }









}

int Viaje::CantidadDeRegistros(){
 int bytes, cant;
    FILE *p;
    p=fopen("Viajes.dat","rb");
        if(p==NULL){
            return false;
        }
    fseek(p,0,SEEK_END);
    bytes=ftell(p);
    fclose(p);
    cant=bytes/sizeof(Viaje);
    return cant;
}

int Viaje::GenerarCodigo(){
    int cant=CantidadDeRegistros();
        if(cant==false){
        cant=1;
        return cant;
    }
    else{
        cant++;
        return cant;
    }
}

void Viaje::mostrarListado(){
    int pos=0;
    rlutil::locate(1,2);
    cout<<"-----------------------------------------------------------------------------------------------------------------------";
    rlutil::locate(4,3);
    cout<<"Nro de Viaje ";
     rlutil::locate(29,3);
    cout<<"Fecha ";
    rlutil::locate(54,3);
    cout<<"Lugar ";
    rlutil::locate(79,3);
    cout<<"Descripcion ";
    rlutil::locate(104,3);
    cout<<"Cant de Personas";
    rlutil::locate(1,4);
    cout<<"-----------------------------------------------------------------------------------------------------------------------";


    while(leerDeDisco(pos)){
        rlutil::locate(5,5+pos);
        cout <<getNroViaje();
        rlutil::locate(30,5+pos);
        _fechaViaje.mostrar();
        rlutil::locate(55,5+pos);
        cout<<getLugar();
        rlutil::locate(80,5+pos);
        cout<<getDescripcion();
        rlutil::locate(105,5+pos);
        cout<<getCantPersonaViaje();
        pos++;
    }

    cout<<endl<<endl<<endl<<endl<<endl;
}

void Viaje::consultaMiembrosDeViaje(){
int pasajero;
int nro=0,pos=0,cont=1,suma=0;
    rlutil::locate(15,2);
    cout<<">>>>>>Ingrese en Numero de viaje que quiere Buscar<<<<<<<<< "<<endl;
    rlutil::locate(1,3);
    cout<<"Nro Viaje: ";
    rlutil::locate(13,3);
    cin>>nro;

    rlutil::locate(1,6);
    cout<< "Nro Participante";
    rlutil::locate(20,6);
    cout<< "Nombre ";
    rlutil::locate(40,6);
    cout<< "Monto ";
    rlutil::locate(60,6);
    cout << "A deber";
    rlutil::locate(80,6);
    cout << "A recibir";
    cout<<endl<<"--------------------------------------------------------------------------------------------------"<<endl;
    IntegranteViaje reg;
    int cont2=0;

    while(reg.leerDeDisco(pos)){
        if (reg.getNroViaje()==nro){
            suma+=reg.getGasto();
            cont2++;
            }
        pos++;
    }
    pos = 0;

    while(reg.leerDeDisco(pos)){
        if (reg.getNroViaje()==nro){
            pasajero = reg.getGasto() - (suma/cont2);
            rlutil::locate(3,7+cont);
            cout<<cont;
            rlutil::locate(20,7+cont);
            cout<<reg.getNombre();
            rlutil::locate(40,7+cont);
            cout<<"$ "<<reg.getGasto();
            rlutil::locate(60,7+cont);
            if(pasajero<0){cout<< -pasajero;}
            else{cout << "---";}
            rlutil::locate(80,7+cont);
            if(pasajero>0){cout<< pasajero;}
            else{cout << "---";}
            cont++;
            }
        pos++;
    }
    cout<<endl<<"--------------------------------------------------------------------------------------------------"<<endl;
    rlutil::locate(80, 8+cont);
    cout<<"TOTAL:    $"<<suma ;
    cout<<endl<<endl<<endl;
}
