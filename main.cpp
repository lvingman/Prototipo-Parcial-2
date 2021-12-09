#include <iostream>
#include <windows.h>
#include "Reunion.h"
#include "Gasto.h"
#include "Viaje.h"
#include "rlutil.h"
#include "Funciones.h"

using namespace std;


int main()
{

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
 ///   int x=10,y=10;
    Reunion a;
    Viaje b;
    Gasto c;



/*while(salir){
        rlutil::setBackgroundColor(rlutil::BROWN);
        rlutil::setColor(rlutil::YELLOW);
        system("cls");
*/
        menuPrincipal(a, c, b);
/*
    cout <<"------------------GASTOS COMPARTIDOS-------------------"<<endl;
    cout <<">> Ingresar opcion"<<endl;
    cout <<">> Opcion 1: Ingresar Reunion. "<<endl;
    cout <<">> Opcion 2: Ingresar Viaje. "<<endl;
    cout <<">> Opcion 3: Cargar gastos. "<<endl;
    cout <<">> Opcion 4: Mostrar listado de reuniones. "<<endl;
    cout <<">> Opcion 5: Mostrar listado de viaje. "<<endl;
    cout <<">> Opcion 6: Mostrar listado de gastos comunes. "<<endl;
    cout <<">> Opcion 7: Mostrar miembros de una reunion. "<<endl;
    cout <<">> Opcion 8: Mostrar miembros de un viaje. "<<endl;
    cout <<">> Opcion 9: Mostrar gastos comunes de una persona. "<<endl;
    cout <<">> Opcion 0 salir del programa. "<<endl<<endl<<endl;
    //rlutil::locate(1,9);
    cout <<" Opcion : ";
    rlutil::locate(12,14);
        cin>>opc;
        cin.ignore();
        switch(opc) {
            case 1:{
                rlutil::cls();
                //system("pause");
                cout<<" CARGAR REUNION "<<endl<<endl;
                a.cargarReunion();
                //a.grabarEnDisco();
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
                                //b.cargarViaje();
                                //b.grabarEnDisco();
                                Reunion a("vacio","vacio",0,0);
                                a.grabarEnDisco();
                            break;
                            }
                            default:{
                                rlutil::setColor(rlutil::RED);
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
            case 3:{

                system("cls");
                cout <<" CARGAR GASTO "<<endl;
                cout <<"-----------------------------------------------------------------------:"<<endl;
                c.cargar();
                system("pause");
                salir2=1;
            break;
            }
            case 4:{

                system("cls");
                cout <<" Listado de Reuniones "<<endl;
                cout <<"-----------------------------------------------------------------------:"<<endl;
                a.mostrarListado();
                system("pause");
                salir2=1;
            break;
            }
            case 5:{
                system("cls");
                cout <<" Listado de Viajes "<<endl;
                cout <<"-----------------------------------------------------------------------:"<<endl;
                b.mostrarListado();
                system("pause");
                salir2=1;
            }
            break;
            case 6:{
                system("cls");
                cout <<" Listado de Gastos Comunes "<<endl;
                cout <<"-----------------------------------------------------------------------:"<<endl;
                c.mostrarListadoGastosComunes();
                system("pause");
                salir2=1;
            break;
            }
            case 7:{
                system("cls");
                cout <<" Miembros de una Reunion "<<endl;
                cout <<"-----------------------------------------------------------------------:"<<endl;
                a.consultaMiembrosDeReunion();

                system("pause");
                salir2=1;
            break;
            }
            case 8:{
                system("cls");
                cout <<" Miembros de un viaje "<<endl;
                cout <<"-----------------------------------------------------------------------:"<<endl;
                b.consultaMiembrosDeViaje();

                system("pause");
                salir2=1;
            break;
            }
            case 9:{
                system("cls");
                cout << " Gastos de una persona especifica " << endl;
                char aBuscar[30];
                cout << " Inserte usuario cuyos gastos se van a buscar: ";
                cin.getline(aBuscar,30);
                cout <<"-----------------------------------------------------------------------:"<<endl;
                c.mostrarListadoGastosIndividuo(aBuscar);
                system("pause");
                salir2=1;
                break;
            }

            case 0:{
                cout<<" CHAU  123!! "<<endl;
                salir=0;
            break;
            }
            default:{
                rlutil::setColor(rlutil::RED);
                rlutil::locate(1,40);
                cout<<" ERROR - VUELVA A INGRESAR LA OPCION"<<endl;
                rlutil::anykey();
                salir=1;
            break;
            }

        }
*/
 //       system("cls");
/*
}
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


