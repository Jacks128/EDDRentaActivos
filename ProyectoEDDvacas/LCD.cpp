#include "LCD.h"

void LCD::Insertar(Transaccion* tran) {
	NodoLCD* nuevo = new NodoLCD(tran);
	if (tam == 0) {
		cabeza = nuevo;
		cabeza->siguiente = nuevo;
		cabeza->anterior = nuevo;
		tam += 1;
	}
	else {
		NodoLCD* ultimo = cabeza->anterior;
		nuevo->siguiente = cabeza;
		nuevo->anterior = ultimo;
		ultimo->siguiente = nuevo;
		cabeza->anterior = nuevo;
		ultimo = nuevo;
		tam += 1;
	}
}

void LCD::Mostrar() {
	if (cabeza != 0)
	{
		NodoLCD* aux = this->cabeza;

		do
		{
			cout << "[ " << aux->getTransaccion()->getId() << " ]" << "-->" << endl;
			aux = aux->siguiente;
		} while (aux != cabeza);
	}
	else
	{
		cout << "La lista doble se encuentra vacia" << endl;
	}
}