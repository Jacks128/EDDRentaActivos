#include "Usuarios.h"
Usuarios::Usuarios(std::string usuario, std::string contra, std::string nombre)
{   
    this->usuario = usuario;
    this->contra = contra;
    this->nombre = nombre;
    avlAct = new AVL();
}
