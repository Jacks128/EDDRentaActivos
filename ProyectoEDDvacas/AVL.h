#pragma once
#include <iostream>
#include "Activos.h"

using namespace std;

class NodoAVL
{
private:
public:
    NodoAVL* left;
    NodoAVL* right;
    Activos* active;
    NodoAVL(Activos* act)
    {
        this->left = nullptr;
        this->right = nullptr;
        active = act;
    }

    Activos* getActivos()
    {
        return this->active;
    }

};

class AVL
{
public:


protected:

private:
    bool first;
    //void AddToCompare(Activos* activos, NodoAVL* temp);
    //void Remove(Activos* activos, NodoAVL* root);
    //void
public:
    NodoAVL* root;
    NodoAVL* get() {
        return this->root;
    }
    void Add(Activos* activos);
    void AddNodo(NodoAVL* nodo);
    //AVL();
    void buscar(NodoAVL* nodo, Activos activos);
    Activos* buscarAVL(NodoAVL* nodo, Activos activos);
    void InOrder(NodoAVL* root);
    void PreOrder(NodoAVL* root);
    void PostOrder(NodoAVL* root);

};

