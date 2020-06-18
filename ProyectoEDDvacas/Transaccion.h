#pragma once
#include <iostream>

using namespace std;

class Transaccion
{
public:
    string IDtran;
    string rentador;
    string IDa;
    string depa;
    string empresa;
    string fecha;
    string tiempoR;
    Transaccion(string idtran, string IDa, string renter, string departamento, string empresa, string date, string tiemporR);

    void setIdTran(string idtran) {
        this->IDtran =idtran;
    }
    void setIdA(string IDa) {
        this->IDa = IDa;
    }
    string setRentador(string renter) {
        this->rentador = renter;
    }

    void setDepa(string departamento) {
        this->depa = departamento;
    }
    void setEmpresa(string empresa) {
        this->empresa = empresa;
    }
    void setFecha(string fecha) {
        this->fecha = fecha;
    }
    void setTiempoR(string tiempoR) {
        this->tiempoR = tiempoR;
    }

    string getId() {
        return this->IDtran;
    }
    string getIdA() {
        return this->IDa;
    }

    string getRentador()
    {
        return this->rentador;
    }

    string getDepartamento() {
        return this->depa;
    }
    string getEmpresa() {
        return this->empresa;
    }
    string getDate() {
        return this->fecha;
    }
    string getTiempoR() {
        return this->tiempoR;
    }
};

