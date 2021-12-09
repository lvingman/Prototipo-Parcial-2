#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

class Fecha{
    private:
        int _dia;
        int _mes;
        int _anio;
    public:
        void setDia(int);
        void setMes(int);
        void setAnio(int);
        int getDia();
        int getMes();
        int getAnio();

        void cargar();
        void mostrar();
};


#endif // FECHA_H_INCLUDED
