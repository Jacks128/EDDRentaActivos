#include "LCD.h"
#include <fstream>

void LCD::Insertar(Transaccion* tran) {
	NodoLCD* nuevo = new NodoLCD(tran);
	if (this->cabeza==nullptr) {
		this->cabeza = this->ultimo = nuevo;
		cabeza->anterior = ultimo;
		ultimo->siguiente = cabeza;
	}
	else {
		cabeza->anterior = nuevo;
		nuevo->siguiente = this->cabeza;
		this->cabeza = nuevo;
		this->cabeza->anterior = this->ultimo;
		this->ultimo->siguiente = this->cabeza;
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

void LCD::Graficar() {
	if (this->cabeza != 0)
	{
		ofstream archivo("LCD.dot");
		NodoLCD* aux = this->cabeza;
		archivo << "digraph G{" << endl;
		archivo << "rankdir = LR;" << endl;
		archivo << "node [shape = egg, color = purple];" << endl;
		archivo << "labelloc = \"t;\"label = \"REPORTE TRANSACCIONES\";\n";


		do
		{
			archivo << "x" << aux << "[dir=both label = \"ID Transaccion = " << aux->getTransaccion()->getIdA()  << "\\nID ActivoRentado = " << aux->getTransaccion()->getIdA() << "\\nDepartamento = " << aux->getTransaccion()->getDepartamento() << "\\nEmpresa = " << aux->getTransaccion()->getEmpresa()<<  "\"]" << endl;
			archivo << "x" << aux << "-> x" << aux->siguiente << endl;
			aux = aux->siguiente;
		} while (aux != cabeza);

		archivo << "}" << endl;
		archivo.close();

		system("C:\\\"Program Files (x86)\"\\Graphviz2.38\\bin\\dot.exe  -Tpng LCD.dot -o LCD.png");
		system("LCD.png &");
	}
}