#include "Cola.h"
bool Cola::empty()
{
    if (this->primero == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Cola::push(string id, string empre, string depa)
{
    NodoCola* nuevo = new NodoCola(id,empre,depa);
    //nuevo->siguiente=0;
    if (this->primero == 0)
    {
        this->primero = nuevo;
        //this->ultimo=nuevo;
    }
    else
    {
        ultimo->setSiguiente(nuevo);

    }
    ultimo = nuevo;

}

NodoCola* Cola::pop()
{
    if (this->primero != 0)
    {
        NodoCola* nodo = primero;
        primero = primero->getSiguiente();
        return nodo;
    }
    return nullptr;
}

void Cola::mostrar()
{
    cout << "Fichas Disponibles:" << endl;
    if (this->primero != 0)
    {
        NodoCola* aux = this->primero;
        while (aux != 0)
        {

            cout <<"ID: " << aux->getID() << endl;

            aux = aux->getSiguiente();
        }

    }
    else
    {
        cout << "La cola Esta Vacia" << endl;
    }


}
void Cola::graficar()
{
    if (this->primero != 0)

    {
        ofstream archivo1("MisRentas.dot");

        archivo1 << "digraph G{" << endl;
        //archivo1 << "rankdir = LR;" << endl;
        archivo1 << "node [shape = egg, color = purple];" << endl;
        archivo1 << "\label = \"REPORTE ACTIVOS QUE TENGO RENTADO\";\n";
        NodoCola* aux = primero;
        //int contador = 0;
        while (aux != 0)
        {
            archivo1 << "x" << aux << "\[label =\"" << " ID: " << aux->getID() << "\\nDepartamento: " + aux->getDepa() << "\\nEmpresa: " + aux->getEmpre() + " \" ] \n";
            archivo1 << "x" << aux << "-> x" << aux->getSiguiente() << endl;
            aux = aux->getSiguiente();
        }



        archivo1 << "}" << endl;
        archivo1.close();

        system("C:\\\"Program Files (x86)\"\\Graphviz2.38\\bin\\dot.exe  -Tpng MisRentas.dot -o MisRentas.png");
        system("MisRentas.png &");


    }
    else
    {
        cout << "No se puede we" << endl;
    }

}