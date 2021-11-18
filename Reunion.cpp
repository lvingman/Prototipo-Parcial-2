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
    cout << "INGRESE NUMERO DE ID DE LA REUNION: ";
    cin >> _nroReunion;
    cin.ignore();
    cout << "INGRESE MOTIVO DE LA REUNION: ";
    cin.getline(_motivo, 50);
    cin.ignore();
    cout << "INGRESE LUGAR DE LA REUNION: ";
    cin.getline(_lugar, 50);
    cin.ignore();
    cout << "INGRESE LA FECHA DEL REUNION:" << endl;
    _fechaReunion.cargar();
    cout << "INGRESE GRUPO (1= AMIGOS / 2= FAMILIA / 3= TRABAJO / 4= PAREJAS POLIAMOR): ";
    cin >> _grupo;
    cout << "INGRESE EL NUMERO DE PARTICIPANTES: ";
    cin >> _cantPersonaReunion;
    //generarCodigo();
    cout << "________________________________________________"<<endl;
    cargarParticipantes(_cantPersonaReunion);
}

void Reunion::cargarParticipantes(int cantPersonaReunion){
        GastoReunion *gastoParticipante;
        gastoParticipante=new GastoReunion[getCantPersonaReunion()];
        int pos=0;
        while(pos<getCantPersonaReunion()){
            gastoParticipante[pos].cargar(_nroReunion);
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

        while(pos<cant){
            vSaldo[pos][1]=vSaldo[pos][0]-(total/cant);
            vSaldo[pos][2]=pos;
            if(vSaldo[pos][1]==0){ cout<<registros[pos].getGastador()<<" No Tiene que poner plata $: "<<vSaldo[pos][1]<<endl;}
            if(vSaldo[pos][1]<0) { cout<<registros[pos].getGastador()<<" Tiene que PONER $: "<<vSaldo[pos][1]*-1<<endl;}
            if(vSaldo[pos][1]>0) { cout<<registros[pos].getGastador()<<" Tiene que RECIBIR $: "<<vSaldo[pos][1]<<endl;}
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


int Reunion::generarCodigo(){
    int nroReunion;
    cin>>nroReunion;
    return nroReunion;

}
///////////////////////////////////////////////////////////////
void CargarGastosDeReunion(int cant){
    /*
    float *pesos;
    char *integrantes;
    pesos=new float[][cant]
    integrantes=new char[cant];
    if(pesos==NULL){
        cout<<"Error de asignación de memoria"<<endl;
        system("pause");
        return;

    }
    FILE *pv;
    Venta reg;
    float (*mVentas)[12];
    int cantreg;
    cantreg=contarRegistros();
    mVentas=new float[cantreg][12];
    if(mVentas==NULL){
        cout<<"Error de asignación de memoria"<<endl;
        system("pause");
        return;
    }

    int pos=0;
    while(pos++<cant){
        cin.getline(integrante,50,pos);
        cin.ignore();
        cin>>pesos[pos];
    }
*/
}



//////////////////////////////////////////////////////////////////
