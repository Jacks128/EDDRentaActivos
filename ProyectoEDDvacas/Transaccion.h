#pragma once
#include <iostream>
#include "Usuarios.h"

using namespace std;

class Transaccion
{
public:
    int ID;
    Usuarios* rentador;
    string depa;
    string empresa;
    string fecha;
    string tiempoR;
    Transaccion(int id, Usuarios* renter, string departamento, string empresa, string date, string tiemporR);


};

