#ifndef REUNION_H_INCLUDED
#define REUNION_H_INCLUDED
#include "Fecha.h"
#include "Hora.h"
#include "Gasto.h"

class Reunion{
    private:
        char _motivo[50];
        char _lugar[50];
        Fecha _fechaReunion;
        int _grupo; // 1= AMIGOS / 2= FAMILIA / 3= TRABAJO / 4= PAREJA
        int  _nroReunion; // N° de reunion se genera automaticamente con un contador.
        int _cantPersonaReunion; // Cantidad de personas de la reunion

        ///Gasto *_gastoParticipante;

    public:
        Reunion ( const char* motivo="Vacio",const char* lugar="vacio",int nroReunion=0,int cantcantPersonaReunion=0){
        //
        }
        void cargarParticipantes(int);
        Reunion(int cantPersonaReunion);
        void setMotivo(const char*);
        void setLugar(const char*);
        void setFechaReunion(Fecha fechaReunion);
        void setGrupo(int grupo);
        void setNroReunion(int nroReunion);
        void setCantPersonaReunion(int nroReunion);

        char * getMotivo();
        char * getLugar();
        Fecha getFechaReunion();
        int getGrupo(); // 1= AMIGOS / 2= FAMILIA / 3= TRABAJO / 4= PAREJA
        int getNroReunion();
        int getCantPersonaReunion();

        // Metodos----------------------
        void cargarReunion();
        void mostrar();
        void saldar();
        bool grabarEnDisco();
        bool leerDeDisco(int );
        int CantidadDeRegistros();
        int generarCodigoReunion();
        void mostrarListado();
        void consultaMiembrosDeReunion();
        //reportes
        //mostrar reunion
};


#endif // REUNION_H_INCLUDED
