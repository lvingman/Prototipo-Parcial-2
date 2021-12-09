#ifndef GASTO_H_INCLUDED
#define GASTO_H_INCLUDED
#include "Fecha.h"
#include "Hora.h"


/////////////////////////////////////////////
///void CargarGastosDeReunion();

////////////////////////////////////////////
///PREGUNTAR COMO REALIZAR UN ARCHIVO EN EL QUE SE PUEDAN LEER LOS VIAJES Y REUNIONES
///CUANDO ESTOS PUEDEN TENER TAMAÑO VARIADO

///COMPROBANTES CONTENDRIA:

class Gasto{
    private:
        /// PARA LOS CLASES HECHAS EN VIAJE int _IDViaje;
        char _gastador[30];
        char _descripcion[50];
        int _nroGastador;
        float _monto;
        Fecha _fecha;
    public:
        //Gasto(int nroGastador,float monto,int nroRegistro);
       // Gasto(const char* ,int nroGastador,float monto,int nroRegistro);

        //-------SETTERS--------------------
        void setGastador(const char *);
        void setDescripcion(const char *);
        void setNroGastador(int);
        void setMonto(float);
        void setFecha(Fecha);
        //------GETTERS--------------------
        char * getGastador();
        char * getDescripcion();
        int getNroGatador();
        int getNroTicket();
        float getMonto();
        Fecha getFecha();
        //------METODOS--------------------
        void cargar();
        void cargarNombre(int nroGastador);
        void mostrar();
        bool grabarEnDisco();
        bool leerDeDisco(int);
        void mostrarListado(); ///METODO 1
        bool grabarEnDiscoGastosComunes(); ///METODO 2
        bool leerDeDiscoGastosComunes(int); ///METODO 3
        int CantidadDeRegistrosGastosComunes(); ///METODO 4
        void mostrarListadoGastosComunes(); ///METODO 5
        void compararTodosGastosComunes(int); ///METODO 6
        void consultaGastosComunesMonto(float); ///METODO 7
        void consultaGastosComunesFecha(Fecha); ///METODO 8
        void mostrarListadoGastosIndividuo(const char *); ///METODO 9

};
/*
class Viaje{
    private:
        char _lugar[50];
        char _descripcion[200];
    public:
        void setLugar(const char*);
        void setDescripcion(const char*);
        char * getLugar();
        char * getDescripcion();
        void cargar();
        void grabarEnDisco();

};
*/

class GastoReunion
{
    private:
        int _IDreunion;
        char _gastador[30];
        float _monto;
        int _nroRegistro;
    public:
        //SETTERS----------------------
        void setIDreunion(int);
        void setGastador(const char *);
        void setMonto(float);
        void setNroRegistro(int);
        //GETTERS----------------------
        int getIDreunion();
        char * getGastador();
        int getNroTicket();
        float getMonto();
        int getNroRegistro();
        //METODOS----------------------
        void cargar(int);
        void mostrar();

        bool grabarEnDisco();
        bool leerDeDisco(int);
        //METODOS PARA VIAJE-----------
        int cargarGastosviaje();
        void mostrarListado();

};


#endif // GASTO_H_INCLUDED
