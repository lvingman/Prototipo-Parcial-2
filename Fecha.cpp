#include<iostream>
#include<cstdlib>
#include "Fecha.h"

using namespace std;

void Fecha::setDia(int numero){
    _dia = numero;
}
void Fecha::setMes(int numero){
    _mes = numero;
}
void Fecha::setAnio(int numero){
    _anio = numero;
}
int Fecha::getDia(){
    return _dia;
}
int Fecha::getMes(){
    return _mes;
}
int Fecha::getAnio(){
    return _anio;
}
void Fecha::mostrar(){
    if (_dia < 10){
        cout << "0";
    }
    cout << _dia << "/";
    if (_mes < 10){
        cout << "0";
    }
    cout << _mes << "/";
    cout <<_anio << endl;
}

void Fecha::cargar(){
    int dia,mes,anio;
    int _calendario [12];
    bool sale=0;


    _calendario [0]=31;_calendario [1]=28;_calendario [2]=31;_calendario [3]=30;_calendario [4]=31;_calendario [5]=30;
    _calendario [6]=31;_calendario [7]=31;_calendario [8]=30;_calendario [9]=31;_calendario [10]=30;_calendario [11]=31;
    //int _ene=31,_feb=28,_mar=31,_abr=30,_may=31,_jun=30,_jul=31,_ago=31,_sep=30,_oct=31,_nov=30,_dic=31;
    //cout <<_dia<<"/"<<_mes<<"/"<<_ano;


    while(sale==0){
    cout<<"ANIO: ";
    cin>>anio;
    cout<<"MES: ";
    cin>>mes;
    cout<<"DIA: ";
    cin>>dia;

    if ((anio % 4) == 0){_calendario[1]=29;}

    //para detiemar si es una fecha correcta
                while(anio<1000 || anio>4000){
                    cout << "Se ingreso un valor de anio invalido, por favor, intentelo de nuevo" << endl;
                    cout << "ANIO: ";
                    cin >> anio;
                    }
                while( mes<1 || mes>12) {
                    cout << "Se ingreso un valor de mes invalido, por favor, intentelo de nuevo" << endl;
                    cout << "MES: ";
                    cin >> mes;
                }
                while(dia<1 || dia > _calendario[mes-1]) {
                    cout << "Se ingreso un valor de dia invalido, por favor, intentelo de nuevo" << endl;
                    cout << "DIA: ";
                    cin >> dia;
                }
                _anio=anio;
                _mes=mes;
                _dia=dia;
                sale=1;



            }

}

