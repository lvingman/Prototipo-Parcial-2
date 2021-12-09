//////////////7
//Materia:
//Nombre:
//TP N°:
//Ej N°:
//Comentario:
//____________________________________


#include <iostream>
#include <cstdlib>
#include <string.h>
#include "Reunion.h"
#include "Gasto.h"
#include "Fecha.h"
#include "rlutil.h"
using namespace std;


// Funciones de la Clase Reunion:

Reunion::Reunion(int cantPersonaReunion=0){
    _cantPersonaReunion=cantPersonaReunion;
}
//SETTERS---------------------
void Reunion::setMotivo(const char* motivo){
    strcpy(_motivo,motivo);
}
void Reunion::setLugar(const char* lugar){
    strcpy(_lugar,lugar);
}
void Reunion::setFechaReunion(Fecha fechaReunion){
    _fechaReunion = fechaReunion;
}
void Reunion::setGrupo(int grupo){
    _grupo = grupo;
}
void Reunion::setNroReunion(int nroReunion){
    _nroReunion = nroReunion;
}
void Reunion::setCantPersonaReunion(int cantPersonaReunion){
    _cantPersonaReunion = cantPersonaReunion;
}

//GETTERS---------------------

char * Reunion::getMotivo(){
    return _motivo;
}

char * Reunion::getLugar(){
    return _lugar;
}

Fecha Reunion::getFechaReunion(){
    return _fechaReunion;
}

int Reunion::getGrupo(){ // 1= AMIGOS / 2= FAMILIA / 3= TRABAJO / 4= PAREJA
    return _grupo;
}

int Reunion::getNroReunion(){
    return _nroReunion;
}

int Reunion::getCantPersonaReunion(){
    return _cantPersonaReunion;
}

//Funciones de carga de Reunion
///ARREGLAR CIN EN LUGAR DE LA REUNION

//Funciones de carga de Reunion
void Reunion::cargarReunion(){
    int cant=CantidadDeRegistros();
    cout << "NUMERO DE ID DE LA REUNION: ";
    _nroReunion=cant+1;
    cout<<_nroReunion<<endl;
    //cin>>_nroReunion;
    cout << "INGRESE MOTIVO DE LA REUNION: ";
    cin.getline(_motivo, 50);

    cout << "INGRESE LUGAR DE LA REUNION: ";
    cin.getline(_lugar, 50);
    cout << "INGRESE LA FECHA DEL REUNION:" << endl;
    _fechaReunion.cargar();
    cout << "INGRESE GRUPO (1= AMIGOS / 2= FAMILIA / 3= TRABAJO / 4= PAREJAS POLIAMOR): ";
    cin >> _grupo;
    cout << "INGRESE EL NUMERO DE PARTICIPANTES: ";
    cin >> _cantPersonaReunion;
    //generarCodigo();
    cout << "________________________________________________"<<endl;
    grabarEnDisco();//==false){cout<<"Reunion Ingresada"<<endl;};
    cout << "________________________________________________"<<endl;
    cargarParticipantes(_cantPersonaReunion);
}

void Reunion::cargarParticipantes(int cantPersonaReunion){
        GastoReunion *gastoParticipante;
        gastoParticipante=new GastoReunion[getCantPersonaReunion()];
        int pos=0;
        while(pos<getCantPersonaReunion()){
            gastoParticipante[pos].cargar(_nroReunion);
            gastoParticipante[pos].setNroRegistro(pos);
            gastoParticipante[pos].grabarEnDisco();
            pos++;
        }
        delete gastoParticipante;
}


//Metodo para saldar la reunion------------------------------
void Reunion::saldar(){
    int pos=0,cant=getCantPersonaReunion();
    float(*vSaldo)[3];
    float total=0;
    vSaldo = new float [cant][3];

    GastoReunion *registros;
    registros =new GastoReunion[cant];

    GastoReunion reg;
    int cont=0;


    while(reg.leerDeDisco(pos)){
        if (reg.getIDreunion() == _nroReunion){
            vSaldo[cont][0] = reg.getMonto();
            total += reg.getMonto();
            registros[cont] = reg;
            cont++;
        }
        pos++;
    }


        pos=0;
system ("cls");
rlutil::locate(0,0);
cout<<"MONTO TOTAL: $" <<total<<endl;
rlutil::locate(0,1);
cout<<"----------------------------------" <<endl;
        while(pos<cant){
            rlutil::locate(1,4+pos);
            cout << registros[pos].getGastador() << " gasto $" << vSaldo[pos][0];
            rlutil::locate(40,4+pos);
            cout << "y";
            vSaldo[pos][1]=vSaldo[pos][0]-(total/cant);
            vSaldo[pos][2]=pos;
            if(vSaldo[pos][1]==0){ cout<<" no tiene que poner plata" <<endl;}
            if(vSaldo[pos][1]<0) { cout<<" tiene que PONER $: "<<vSaldo[pos][1]*-1<<endl;}
            if(vSaldo[pos][1]>0) { cout<<" tiene que RECIBIR $: "<<vSaldo[pos][1]<<endl;}
            pos++;
        }


}

//Funcion Mostrar Reunion-------------------------------------
void Reunion::mostrar(){
    cout << "MOTIVO DE LA REUNION: " << getMotivo()<<endl;
    cout << "LUGAR DE LA REUNION: " << getLugar() <<endl;
    cout<< getFechaReunion().getDia()<<"/"<<getFechaReunion().getMes()<<"/"<<getFechaReunion().getAnio()<<endl;
    cout << "GRUPO (1= AMIGOS / 2= FAMILIA / 3= TRABAJO / 4= PAREJAS POLIAMOR): "<<getGrupo()<<endl;
    cout << "NRO DE PARTICIPANTES: "<< getCantPersonaReunion()<<endl;
    //generarCodigo();
    cout << "________________________________________________"<<endl;
    //_gastoParticipante=new Gasto[getCantPesonaReunion()];
    int cont = 0;
    int pos = 0;

    GastoReunion reg;
    while(reg.leerDeDisco(pos)){
        if (reg.getIDreunion() == _nroReunion){
            reg.mostrar();
            cont++;
        }
        if (cont == _cantPersonaReunion){
            break;
        }
        pos++;

    }

}


int Reunion::generarCodigoReunion(){
    int cant=CantidadDeRegistros();
    if(cant==false){
       cant=1;
    }
    else{
    //cout<<cant<<endl;
    cant=cant++;
    //cout<<cant<<endl;

    }
    return cant;
}


bool Reunion::grabarEnDisco(){
    FILE* p;
    p = fopen("Reunion.dat","ab");
    if (p == NULL) {
        return false;
    }

    if (fwrite(this, sizeof(Reunion), 1, p)) {
        fclose(p);
        return true;
        //cout<<"GRabado"<<endl;
    }
    else {
        fclose(p);
        return false;
    }
}

bool Reunion::leerDeDisco(int pos){
    FILE* p;
    p = fopen("Reunion.dat","rb");
        if (p == NULL) {
        return false;
        }
    fseek(p, sizeof(Reunion) * pos, 0);

        if (fread(this, sizeof(Reunion), 1, p)){
            fclose(p);
            return true;
        }
        else {
        fclose(p);
        return false;
        }

}

int Reunion::CantidadDeRegistros(){
    int bytes, cant;
    FILE *p;
    p=fopen("Reunion.dat","rb");
        if(p==NULL){
            //cout<<"EL ARCHIVO Reunion.dat NO SE PUDO ABRIR &%$"<<endl;
            return 0;
        }
    fseek(p,0,SEEK_END);
    bytes=ftell(p);
    fclose(p);
    cant=bytes/sizeof(Reunion);
    return cant;
}


void Reunion::mostrarListado(){
    int pos=0;
    char v[4][10]={{"AMIGOS"},{"FAMILIA"},{"TRABAJO"},{"PAREJAS"}};
    while(leerDeDisco(pos)){

    cout <<"NRO: "<<getNroReunion() << endl;
    cout << "FECHA: " <<getFechaReunion().getDia()<<"/"<<getFechaReunion().getMes()<<"/"<<getFechaReunion().getAnio()<< endl;
    cout <<"MOTIVO DE LA REUNION: " << getMotivo()<< endl;
    cout << "LUGAR DE LA REUNION: " << getLugar() << endl;
    cout << "NRO DE PARTICIPANTES: "<< getCantPersonaReunion()<< endl;
    cout << "TIPO DE REUNION: ";
    for(int i=0;i<10;i++){cout<<v[getGrupo()-1][i];}
    cout<<endl<< endl <<endl;
    pos++;
    }

}

void Reunion::consultaMiembrosDeReunion(){
    int nro=0,pos=0,cont=1,suma=0;
    rlutil::locate(15,2);
    cout<<">>>>>>Ingrese en Numero de Reunion que quiere Buscar<<<<<<<<< "<<endl;
    rlutil::locate(1,3);
    cout<<"Nro Reunion: ";
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
    GastoReunion reg;
    int cont2=0;

    while(reg.leerDeDisco(pos)){
        if (reg.getIDreunion()==nro){
            suma+=reg.getMonto();
            cont2++;
            }
        pos++;
    }
    pos = 0;
    float pasajero;
        while(reg.leerDeDisco(pos)){
        if (reg.getIDreunion()==nro){
            pasajero = reg.getMonto() - (suma/cont2);
            rlutil::locate(3,7+cont);
            cout<<cont;
            rlutil::locate(20,7+cont);
            cout<<reg.getGastador();
            rlutil::locate(40,7+cont);
            cout<<"$ "<<reg.getMonto();
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
///////////////////////////////////////////////////////////////




//////////////////////////////////////////////////////////////////
