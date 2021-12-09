#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#include "Fecha.h"
#include "Hora.h"
#include "Gasto.h"
#include "Reunion.h"
#include "Viaje.h"
#include "Persona.h"
#include "rlutil.h"


void mostrarError();
void settearColor();
void submenuConsultas(Reunion, Gasto, Viaje);
void submenuMuestraListados(Reunion, Gasto, Viaje);
void submenuIngresoDatos(Reunion, Gasto, Viaje);
void cargarViaje(Viaje);
void menuPrincipal(Reunion, Gasto, Viaje);
void sumatoriaGastosTotales(const char *);


#endif // FUNCIONES_H_INCLUDED
