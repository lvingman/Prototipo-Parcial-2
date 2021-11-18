#include <iostream>
#include "Reunion.h"
#include "Gasto.h"
#include "Viaje.h"

using namespace std;

int main()
{
    bool salir=1,salir2=1;
    int opc=0;
    /*
    GastoReunion reg;
    while(reg.leerDeDisco(pos)){
        reg.mostrar();
        pos++;
    };

    GastoReunion test;
    test.cargar();
    test.grabarEnDisco();
*/

    Reunion a(2);
cout <<" Ingresar opcion 1 Reunion / Opcion 2 Viaje"<<endl;
while(salir){
        cin>>opc;
        cin.ignore();
        switch(opc) {
            case 1:{
                a.cargarReunion();
                system("cls");
                cout<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl<<endl<<endl;
                a.saldar();
                cout<<endl<<endl<<endl<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl<<endl<<endl;
                a.mostrar();
                salir=1;
                system("pause");
            break;
            }
            case 2: {
                    Viaje b;
                    //Gasto c;

                    int opc2;
                    salir2=1;
                while(salir2==true){
                    cout<<endl<<"OPCION 1 CREAR VIAJE / 2 CARGAR GASTOS DEL VIAJE / 3 SALDAR / 0 PARA SALIR DE VIAJE "<<endl;
                        cin>>opc2;
                        cin.ignore();
                        switch(opc2){
                            case 1: {
                                b.cargarViaje();
                                //c.cargar();
                                //c.grabarEnDisco();
                                salir2=1;
                            break;
                            }
                            case 2:{
                                b.cargarGastosViaje();
                                //c.grabarEnDisco();
                                salir2=1;
                            break;
                            }
                            case 3:{
                                int viajeASaldar;
                                cout<<"Ingresar Viaje a SALDAR : ";
                                cin>>viajeASaldar;
                                b.saldar(viajeASaldar);
                                salir2=1;
                            break;
                            }
                            case 123456:{ //inicializa el contador de Nro de Registros
                                cout<<"Es oculto y es para inicializar el contador de registro del archivo ";
                                cout<<"Solo se utiliza una vez para poner el contador de registros en 0";
                                cout<<"Luego se utiliza el ingreso normal";
                                b.cargarViaje();
                                b.grabarEnDisco();
                            break;
                            }
                            default:{
                                cout<<" ERROR - VUELVA A INGRESAR LA OPCION"<<endl;
                                salir2=1;
                            break;
                            }
                            case 0:{
                                 cout<<"SALIO DE VIAJES"<<endl;
                                 salir2=0;
                                 system("cls");
                            break;
                            }
                        }

                    }
                    salir=1;

                    break;
            }
            case 0:{
                cout<<" CHAU  123!! "<<endl;
                salir=0;
            break;
            }
            default:{
                cout<<" ERROR - VUELVA A INGRESAR LA OPCION"<<endl;
                salir=1;
            break;
            }

        }
}
/*
    cantPart=a.getCantPesonaReunion();
    cout<<cantPart<<endl;
    Gasto *b=new Gasto[cantPart];
    for(int i=0;i<cantPart;i++)
    {
        b[i].cargar();
    }
    int i;
    b[i].getMonto();
*/

    return 0;
}
