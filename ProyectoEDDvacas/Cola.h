#pragma once
#include <iostream>
#include <string>
#include <conio.h>
#include <fstream>

using namespace std;

class NodoCola
{
private:
	string id;
	string depa;
	string empre;
	//  int cant;
	NodoCola* siguiente;

public:
	NodoCola(string id, string empre, string depa)
	{
		this->siguiente = 0;
		this->id = id;
		this->empre = empre;
		this->depa = depa;
		//this->cant=cant;
	}
	void setSiguiente(NodoCola* nuevo) {
		this->siguiente = nuevo;
	}
	void setID(string id) {
		this->id = id;
	}
	void setEmpre(string empre) {
		this->empre = empre;
	}
	void setDepa(string depa) {
		this->depa = depa;
	}


	NodoCola* getSiguiente() {
		return this->siguiente;
	}
	string getID() {
		return this->id;
	}
	string getEmpre() {
		return this->empre;
	}
	string getDepa() {
		return this->depa;
	}
};

class Cola
{

private:
	NodoCola* primero;
	NodoCola* ultimo;
public:
	void push(string id, string empre, string depa);
	// void pop();
	void mostrar();
	bool empty();
	void graficar();
	NodoCola* pop();

protected:



};
