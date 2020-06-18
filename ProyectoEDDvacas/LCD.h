#pragma once
#include <iostream>
#include <string>
#include <conio.h>
#include "Transaccion.h"


using namespace std;


class NodoLCD { /*CLASE NODO*/

public:
	NodoLCD* siguiente;
	NodoLCD* anterior;
	Transaccion* misTran;

	Transaccion* getTransaccion() {
		return this->misTran;
	}
	NodoLCD(Transaccion* misTran) {
		this->misTran = misTran;
		anterior = nullptr;
		siguiente = nullptr;
	}
};

class LCD /*CLASE LISTA*/
{
public:
		NodoLCD* cabeza;
		int tam;
		//NodoLCD* ultimo;
		LCD() {
			this->cabeza = nullptr;
			this->tam = 0;
		}
	void Insertar(Transaccion* transaccion);
	bool buscar(Transaccion* transaccion);
	void Mostrar();
	



};
