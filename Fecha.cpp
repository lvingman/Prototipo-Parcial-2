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
void Fecha::cargar(){
    int a, b, c;
    cout << "INGRESE NUMERO DE DIA: ";
    cin >> a;
    cin.ignore();
    _dia = a;

    cout << "INGRESE NUMERO DE MES: ";
    cin >> b;
    cin.ignore();
    _mes = b;

    cout << "INGRESE ANIO: ";
    cin >> c;
    cin.ignore();
    _anio = c;

}
