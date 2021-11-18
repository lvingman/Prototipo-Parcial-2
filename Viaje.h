#ifndef VIAJE_H_INCLUDED
#define VIAJE_H_INCLUDED
#include "Fecha.h"
#include "Gasto.h"

using namespace std;

///SOLO SE PUEDE TRABAJAR CON UN VIAJE A LA VEZ
///NO SE PUEDE ABRIR UN VIAJE CUANDO YA HAY UNO ABIERTO

///GASTOS EN VIAJE SERAN LA SUMA TOTAL DE LOS GASTOS DE CADA USUARIO
///NO SE REGISTRAN GASTOS INDIVIDUALES

///REGISTRAR LOS GASTOS DE CADA INTEGRANTE DE VIAJE INDIVIDUALMENTE

///ARREGLAR "SALDAR"
class Viaje{
    private:
        //ATRIBUTOS-----------------------------------
        char _lugar[50];
        char _descripcion[200];
        Fecha _fechaViaje;
        int  _nroViaje;
        int _cantPersonaViaje;
        bool _saldado = false;
    public:
        //SETTETS-------------------------------------
        void setLugar(const char* );
        void setDescripcion(const char*);
        void setFechaViaje(Fecha fechaViaje);
        void setNroViaje(int nroViaje);

        void setCantPersonaViaje(int cantPersonaVije);
        void setSaldado(int nroViaje);
        //GETTERS-------------------------------------
        char * getLugar();
        char * getDescripcion();
        Fecha getFechaViaje();
        int getNroViaje();
        int getCantPersonaViaje();
        bool getSaldado();
        //METODOS-----------------------------------
        void cargarGastosViaje();
        void cargarViaje();
        void mostrar();
        void grabarEnDisco();
        int CantidadDeRegistrosViaje();
        bool leerDeDisco(int cant);
        void saldar(int saldado);
        void cargarPersonas(int nviaje ,int cant);
        void cargarParticipantes();
        //void saldado(int saldado);


};

#endif // VIAJE_H_INCLUDED
