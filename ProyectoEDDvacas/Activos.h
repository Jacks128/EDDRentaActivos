#pragma once
#include <iostream>


using namespace std;
class Activos
{
public:
    string id;
    string nombreActivo;
    string descripcion;
    bool bandera;

    Activos(string id, string nombreActivo, string descripcion, bool bandera);

    bool getBandera() {
        return this->bandera;
    }
    void setBandera(bool bandera) {
        this->bandera = bandera;
    }
    void setID(string id)
    {
        this->id = id;
    }

    void setNombreActivo(string nombreActivo)
    {
        this->nombreActivo = nombreActivo;
    }

    void setDescripcion(string descripcion)
    {
        this->descripcion = descripcion;
    }

    string getID()
    {
        return this->id;
    }

    string getNombreActivo()
    {
        return this->nombreActivo;
    }

    string getDescripcion()
    {
        return this->descripcion;
    }

protected:

};

