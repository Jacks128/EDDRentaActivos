#pragma once
#include <iostream>
class Usuarios
{
public:
    std::string usuario;
    std::string contra;
    std::string nombre;
    Usuarios(std::string usuario, std::string contra, std::string nombre);


    void setUsuario(std::string usuario)
    {
        this->usuario = usuario;
    }
    void setContra(std::string contra)
    {
        this->contra = contra;
    }
    void setNombre(std::string nombre)
    {
        this->nombre = nombre;
    }
    std::string getUsuario()
    {
        return this->usuario;
    }
    std::string getContra()
    {
        return this->contra;
    }
    std::string getNombre()
    {
        return this->nombre;
    }
};

