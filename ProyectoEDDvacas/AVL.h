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
    int altura=1;
   
    void add(Activos* act);
    string caca();
    string grafiquita();
    

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
    NodoAVL* deleteNode(NodoAVL* node, string ID);
    NodoAVL* searchNode(NodoAVL* node, string ID);
    int altura(NodoAVL* nodo);
    int mayor(int n1, int n2);
    int indice;
    NodoAVL* leftleft(NodoAVL* n1);
    NodoAVL* rightright(NodoAVL* n2);
    NodoAVL* leftright(NodoAVL* n1);
    NodoAVL* rightleft(NodoAVL* n2);
    void inOrder(NodoAVL* a);
    void preOrder(NodoAVL* a);
    string ejecucion(NodoAVL* eje);
    
public:
   
    NodoAVL* root;
    NodoAVL* get() {
        return this->root;
    }
    AVL();
    void modificar(string id);
    void insertar(Activos* activos);
    void deleter(string id);
    void inOrder();
    void preOrder();
    void graficaravl();
    void caca(NodoAVL* node);
    void addNode(NodoAVL* node);
   ;
   


};

