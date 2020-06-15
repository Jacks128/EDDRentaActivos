#pragma once
#include <iostream>
#include "AVL.h"
class Usuarios
{
public:
    std::string usuario;
    std::string contra;
    std::string nombre;
    AVL* avlAct;
    Usuarios(std::string usuario, std::string contra, std::string nombre, AVL* avlAct);

    void setAvlAct(AVL* avlAct)
    {
        this->avlAct = avlAct;
    }
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
    AVL* getAvlAct()
    {
        return this->avlAct;
    }
};

