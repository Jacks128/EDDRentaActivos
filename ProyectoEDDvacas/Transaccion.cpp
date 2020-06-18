#include "Transaccion.h"
Transaccion::Transaccion(string idt, string IDa, string renter, string departamento, string empresa, string date, string tiemporR)
{
    this->IDtran = idt;
    this->rentador = renter;
    this->IDa = IDa;
    this->depa = departamento;
    this->empresa = empresa;
    this->fecha = date;
    this->tiempoR = tiemporR;
}

