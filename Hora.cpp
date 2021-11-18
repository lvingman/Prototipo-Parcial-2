#include<iostream>
#include<cstdlib>
#include "Hora.h"

using namespace std;

void Hora::setHora(int numero){
    _hora = numero;
}
void Hora::setMinutos(int numero){
    _minutos = numero;
}
int Hora::getHora(){
    return _hora;
}
int Hora::getMinutos(){
    return _minutos;
}

void Hora::cargar(){
    int a, b;
    cout << "INGRESE HORA: ";
    cin >> a;
    _hora = a;

    cout << "INGRESE MINUTOS: ";
    cin >> b;
    _minutos = b;
}
