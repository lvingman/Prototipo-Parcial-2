#include<iostream>
#include<cstdlib>
#include "Funciones.h"

using namespace std;


void mostrarError(){
    rlutil::setColor(rlutil::RED);
    rlutil::locate(1,40);
    cout<<" ERROR - VUELVA A INGRESAR LA OPCION"<<endl;
    rlutil::anykey();
}

void settearColor(){
    rlutil::setBackgroundColor(rlutil::BROWN);
    rlutil::setColor(rlutil::YELLOW);
}

void submenuConsultas(Reunion X, Gasto Y, Viaje Z){
    int key2 = 1;
    int opc;
    while(key2 != 0){
        settearColor();
        cout <<"------------------CONSULTAS E INFORMES-------------------"<<endl;
        cout <<">> Opcion 1: Mostrar miembros de una reunion. "<<endl;
        cout <<">> Opcion 2: Mostrar miembros de un viaje. "<<endl;
        cout <<">> Opcion 3: Mostrar gastos comunes de una persona. "<<endl;
        cout <<">> Opcion 4: Mostrar gastos ocurridos en cierta fecha. "<<endl;
        cout <<">> Opcion 5: Mostrar gastos respecto a cierto monto. " << endl;
        cout <<">> Opcion 6: Comparar los gastos comunes entre ciertas personas. " << endl;
        cout <<">> Opcion 7: Contar todos los gastos de una persona. " << endl;
        cout <<">> Opcion 0: Volver al menu principal " << endl;
        cout <<" Ingrese su comando: ";
        cin >> opc;
        system("cls");
        switch(opc){
            case 1:{
                cout <<" Miembros de una Reunion "<<endl;
                cout <<"-----------------------------------------------------------------------:"<<endl;
                X.consultaMiembrosDeReunion();
            break;
            }
            case 2:{
                cout <<" Miembros de un viaje "<<endl;
                cout <<"-----------------------------------------------------------------------:"<<endl;
                Z.consultaMiembrosDeViaje();
            break;
            }
            case 3:{
                cout << " Gastos de una persona especifica " << endl;
                char aBuscar[30];
                cout << " Inserte usuario cuyos gastos se van a buscar: ";
                cin.getline(aBuscar,30);
                cout <<"-----------------------------------------------------------------------:"<<endl;
                Y.mostrarListadoGastosIndividuo(aBuscar);
                break;
            case 4:{
                cout << " Gastos ocurridos en cierta fecha " << endl;
                Fecha aCargar;
                cout << "Ingrese la fecha con la que se trabajara: " << endl;
                aCargar.cargar();
                Y.consultaGastosComunesFecha(aCargar);
                break;
            }
            case 5:{
                cout << " Gastos respecto a cierto monto " << endl;
                float aIngresar;
                cout << " Ingrese el monto con el que se trabajara: ";
                cin >> aIngresar;
                Y.consultaGastosComunesMonto(aIngresar);
                break;
            }
            case 6:{
                cout << "Comparasion de gastos comunes entre personas " << endl;
                int aIngresar;
                cout << " Ingrese la cantidad de personas que desea comparar: ";
                cin >> aIngresar;
                cin.ignore();
                Y.compararTodosGastosComunes(aIngresar);
                break;
                }
            case 7:{
                cout << " Sumatoria de todos los gastos de una persona " << endl;
                char aIngresar[30];
                cout << " Ingrese la persona cuyos gastos se quieren contar: ";
                cin.ignore();
                cin.getline(aIngresar,30);
                sumatoriaGastosTotales(aIngresar);
                break;
            }
            case 0:
                cout<<"Saliendo del menu de ingreso de datos"<<endl;
                key2=0;
                break;
            }
            default:{
                mostrarError();
                break;
                }
        }
        system("pause");
        system("cls");
    }
}

void submenuMuestraListados(Reunion X, Gasto Y, Viaje Z){
    int key2 = 1;
    int opc;
    while(key2 != 0){
        settearColor();
        cout <<"------------------MUESTRA DE LISTADOS-------------------"<<endl;
        cout <<">> Opcion 1: Mostrar listado de reuniones. "<<endl;
        cout <<">> Opcion 2: Mostrar listado de viaje. "<<endl;
        cout <<">> Opcion 3: Mostrar listado de gastos comunes. "<<endl;
        cout <<">> Opcion 0: Volver al menu principal. " << endl;
        cout <<" Ingrese su comando: ";
        cin >> opc;
        system("cls");
        cin.ignore();
        switch(opc){
             case 1:{
                cout <<" Listado de Reuniones "<<endl;
                cout <<"-----------------------------------------------------------------------:"<<endl;
                X.mostrarListado();
                break;
                }
            case 2:{
                cout <<" Listado de Viajes "<<endl;
                cout <<"-----------------------------------------------------------------------:"<<endl;
                Z.mostrarListado();
                }
                break;
            case 3:{
                cout <<" Listado de Gastos Comunes "<<endl;
                cout <<"-----------------------------------------------------------------------:"<<endl;
                Y.mostrarListadoGastosComunes();
                break;
                }
            case 0:
                cout<<"Saliendo del menu de ingreso de datos"<<endl;
                key2=0;
                break;
            default:{
                mostrarError();
                break;
                }
        }
        system("pause");
        system("cls");
    }
}

void cargarViaje(Viaje Z){
    int opc2;
    int key3 = 1;
    while(key3!=0){
        cout<<endl<<"OPCION 1 CREAR VIAJE / 2 CARGAR GASTOS DEL VIAJE / 3 SALDAR / 0 PARA SALIR DE VIAJE "<<endl;
        cin>>opc2;
        system("cls");
        cin.ignore();
        switch(opc2){
            case 1: {
                Z.cargarViaje();
                break;
                }
                case 2:{
                    Z.cargarGastosViaje();
                break;
                }
                case 3:{
                    int viajeASaldar;
                    cout<<"Ingresar Viaje a SALDAR : ";
                    cin>>viajeASaldar;
                    Z.saldar(viajeASaldar);
                break;
                }

                case 123456:{ //inicializa el contador de Nro de Registros
                    cout<<"Es oculto y es para inicializar el contador de registro del archivo ";
                    cout<<"Solo se utiliza una vez para poner el contador de registros en 0";
                    cout<<"Luego se utiliza el ingreso normal";
                    //b.cargarViaje();
                    //b.grabarEnDisco();
                    Reunion X("vacio","vacio",0,0);
                    X.grabarEnDisco();
                break;
                }
                default:{
                    rlutil::setColor(rlutil::RED);
                    cout<<" ERROR - VUELVA A INGRESAR LA OPCION"<<endl;
                break;
                }
                case 0:{
                     cout<<"SALIO DE VIAJES"<<endl;
                     key3=0;
                     system("cls");
                break;
                }
        }
    }
}

void submenuIngresoDatos(Reunion X, Gasto Y, Viaje Z){
    int key2 = 1;
    int opc;

        while(key2!=0){
            settearColor();
            cout <<"------------------INGRESO DE DATOS-------------------"<<endl;
            cout <<">> Opcion 1: Ingresar Reunion. "<<endl;
            cout <<">> Opcion 2: Ingresar Viaje. "<<endl;
            cout <<">> Opcion 3: Cargar gastos. "<<endl;
            cout <<">> Opcion 0: Volver al menu principal. "<<endl;
            cout <<" Ingrese su comando: ";
            cin >> opc;
            cin.ignore();
            system("cls");
            switch(opc){
                case 1:{
                    cout<<" CARGAR REUNION "<<endl<<endl;
                    X.cargarReunion();
                    //a.grabarEnDisco();
                    cout<<endl;
                    X.saldar();
                    cout<<endl<<"<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<"<<endl<<endl;
                    X.mostrar();
                    break;
                }
                case 2:{
                    cargarViaje(Z);
                    break;}
                case 3:
                    cout <<" CARGAR GASTO "<<endl;
                    cout <<"-----------------------------------------------------------------------:"<<endl;
                    Y.cargar();
                    break;
                case 0:
                    cout<<"Saliendo del menu de ingreso de datos"<<endl;
                    key2=0;
                    break;
                default:{
                    mostrarError();
                    break;
                    }
        }
        system("pause");
        system("cls");
    }
}


void menuPrincipal(Reunion abc, Gasto def, Viaje ghi){
    int opc;
    int key1 = 1;
    while(key1!=0){

    settearColor();
    system("cls");

    cout <<"------------------GASTOS COMPARTIDOS-------------------"<<endl;
    cout <<">> Ingresar opcion"<<endl;
    cout <<">> Opcion 1: Ingresar Datos. " << endl;
    cout <<">> Opcion 2: Mostrar listados. " << endl;
    cout <<">> Opcion 3: Realizar una consulta. " << endl;
    cout <<">> Opcion 0 salir del programa. "<<endl<<endl<<endl;
    cout << " Ingrese su comando: ";
    cin >> opc;
    system("cls");
    switch(opc){
        case 1:
            submenuIngresoDatos(abc, def, ghi);
            break;
        case 2:
            submenuMuestraListados(abc, def, ghi);
            break;
        case 3:
            submenuConsultas(abc, def, ghi);
            break;
        case 0:{
            cout<<" CHAU  123!! "<<endl;
            key1 = 0;
            break;
            }
        default:{
            mostrarError();
            break;
            }
        }
    }
}

void sumatoriaGastosTotales(const char * nombre){
    Gasto reg;
    IntegranteViaje reg2;
    GastoReunion reg3;

    int pos=0;
    float total=0;
    while(reg2.leerDeDisco(pos)){
        if(strcmp(nombre, reg2.getNombre()) == 0){
            total += reg2.getGasto();
        }
        pos++;
    }

    pos=0;
    while(reg.leerDeDiscoGastosComunes(pos)){
        if(strcmp(nombre,reg.getGastador()) == 0){
            total += reg.getMonto();
        }

        pos++;
    }

    pos=0;
    while(reg3.leerDeDisco(pos)){
        if(strcmp(nombre, reg.getGastador()) == 0){
            total += reg.getMonto();
        }
        pos++;

    }
    system("cls");

    cout << endl << "El gasto total de " << nombre << ", es de: $" << total <<endl;


}
