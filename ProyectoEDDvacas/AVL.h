#pragma once
#include <iostream>
#include "Activos.h"

using namespace std;

class NodoAVL
{
private:
    int correlativo = 1;
    int id;

public:
    NodoAVL* left;
    NodoAVL* right;
    Activos* active;
    int altura=0;
    void add(Activos* act);

    Activos* getActive() {
        return this->active;
    }

    NodoAVL(Activos* act)
    {
        this->left = nullptr;
        this->right = nullptr;
        this->id = correlativo++;
        active = act;
    }


};

class AVL
{
private:
    
    NodoAVL* insertarN(Activos *activos, NodoAVL* root);
    int altura(NodoAVL* nodo);
    int mayor(int n1, int n2);
    NodoAVL* leftleft(NodoAVL* n1);
    NodoAVL* rightright(NodoAVL* n2);
    NodoAVL* leftright(NodoAVL* n1);
    NodoAVL* rightleft(NodoAVL* n2);
    void inOrder(NodoAVL* a);
public:
    NodoAVL* root;
    AVL() {
        root == nullptr;
    }
    void insertar(Activos* activos);
    void inOrder();



};

