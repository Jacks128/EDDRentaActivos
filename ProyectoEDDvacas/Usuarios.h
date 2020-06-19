#pragma once
#include <iostream>
#include "AVL.h"
#include "LCD.h"
#include "Cola.h"
class Usuarios
{
public:
    std::string usuario;
    std::string contra;
    std::string nombre;
    AVL* avlAct;
    Cola* colita;
    LCD* lista;
    Usuarios(std::string usuario, std::string contra, std::string nombre);

    void setLista(LCD* lista) {
        this->lista = lista;
    }
    void setCola(Cola* id) {
        this->colita = id;
    }
    void setAvlAct(AVL* avlAct) {
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
        return nombre;
    }
    AVL* getAvlAct()
    {
        return this->avlAct;
    }

    LCD* getLCD()
    {
        return this->lista;
    }
    Cola* getCola()
    {
        return this->colita;
    }

};

