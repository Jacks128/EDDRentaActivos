#include "Transaccion.h"
Transaccion::Transaccion(int id, Usuarios* renter, string departamento, string empresa, string date, string tiemporR)
{
    this->ID = id;
    this->rentador = renter;
    this->depa = departamento;
    this->empresa = empresa;
    this->fecha = date;
    this->tiempoR = tiemporR;
}

