#ifndef PERSONA_H_INCLUDED
#define PERSONA_H_INCLUDED

///INFORME: GASTO COMPARANDO 2 O MAS PERSONAS
///INFORME: GASTOS TOTALES DE UNA PERSONA
///LISTADO: GASTOS EN UN PLAZO DE TIEMPO

///LISTADO: MOSTRAR PERSONAS QUE ESTUVIERON EN UN VIAJE

class Persona{
    private:
        char _nombre[30];
        int _nroRegistro;   //Para Guardarlo en Nro de Viaje
        int _nroDeOrden;      // Para usarlo en saldar y mostrar el gasto
        //int _edad;
        //float _gastado = 0;
        //float _aDeber = 0;
        //float _aRecibir = 0;
    public:
        void setNombre(const char*);
        void setNroRegistro(int);
        //void setEdad(int);
        //void setGastado(float);
        //void setADeber(float);
        //void setARecibir(float);

        char * getNombre();
        int getNroRegistro();
        //int getEdad();
        //float getGastado();
        //float getADeber();
        //float getARecibir();

        void cargar(int NroRegViaje, int pos);
        void grabarEnDisco();

};

class IntegranteViaje{
    private:
        char _nombre[30];
        int _nroViaje;
        float _gasto;
    public:
        ///SETS
        void setNombre(const char *);
        void setNroViaje(int);
        float setGasto(float);
        ///GETS
        char * getNombre();
        int getNroViaje();
        float getGasto();
        ///METODOS
        void cargar(int);
        void mostrar();
        bool grabarEnDisco();
        bool leerDeDisco(int);
        bool modificarRegistro(int);
};

#endif // PERSONA_H_INCLUDED
