#pragma once
#include <iostream>

using namespace std;
class Activos
{
public:
    string id;
    string nombreActivo;
    string descripcion;
    Activos(string id, string nombreActivo, string descripcion);


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

