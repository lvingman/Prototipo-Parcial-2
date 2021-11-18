#ifndef HORA_H_INCLUDED
#define HORA_H_INCLUDED

class Hora{
    private:
        int _hora;
        int _minutos;
    public:
        void setHora(int);
        void setMinutos(int);
        int getHora();
        int getMinutos();
        void cargar();
};


#endif // HORA_H_INCLUDED
