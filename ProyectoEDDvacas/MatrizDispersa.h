#pragma once
#include <iostream>
#include "Usuarios.h"
#include "AVL.h"

using namespace std;

class Nodo
{
public:

    Nodo* right;
    Nodo* left;
    Nodo* up;
    Nodo* down;
    Nodo* above;
    Nodo* below;

    string nombreN;
    Usuarios* miUsu;

    

    //miUsu=new Usuarios(string username, string pass, string name);
    Nodo(string qSoy)
    {
        this->right = nullptr;
        this->left = nullptr;
        this->up = nullptr;
        this->down = nullptr;
        this->above = nullptr;
        this->below = nullptr;


        this->nombreN = qSoy;
    }
    Nodo(Usuarios* User)
    {
        this->right = nullptr;
        this->left = nullptr;
        this->up = nullptr;
        this->down = nullptr;
        this->above = nullptr;

        miUsu = User;
    }
    Usuarios* getUsuario()
    {
        return miUsu;
    }

protected:

private:
};

class MatrizDispersa
{
public:
    Nodo* header;
    Nodo* nRentador;
    AVL* arbolavl;
    MatrizDispersa()
    {
        Usuarios* admin = new Usuarios("Admin", "admin", "jacky");
        header = new Nodo(admin);
    }
    void Insertar(Usuarios* rentador, string empresa, string depa);
    Nodo* getHeader()
    {
        return this->header;
    }
    Nodo* getnRentador()
    {
        return this->nRentador;
    }

    //Nodo* getnRentador();
    void graficar();
    void asignActives(Activos* activo, Nodo* rentador);
    Nodo* createCompany(string empresa);
    Nodo* createDepartment(string depa);
    Nodo* searchCompany(string empresa, Nodo* first);
    Nodo* searchDepartment(string depa, Nodo* first);
    bool isCompany(string empresa, Nodo* first, Nodo* rentador);
    bool isDepartament(string depa, Nodo* first, Nodo* rentador);
    Nodo* searchUsuario(string rentador, string company, string department); 
    Nodo* toGraphic(string department, string company);
    string getNodo();
    string getConexion();
    
   
    void magia();

};

