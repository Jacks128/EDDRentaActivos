#include "AVL.h"
#include <fstream>
#include <string>

string juntadoralv1;
AVL::AVL() {
	this->root == nullptr;
	this->indice = 0;
}
void NodoAVL::add(Activos* acti) {
	NodoAVL* nActivos = new NodoAVL(acti);
	if (nActivos->getActive()->getID().compare(acti->getID())<0)
	{
		if (left == nullptr)
		{
			left = new NodoAVL(acti);
		}
		else 
		{
			left->add(acti);
		}
	}
	else if (nActivos->getActive()->getID().compare(acti->getID()) > 0) {
		if (right == nullptr)
		{
			right = new NodoAVL(acti);
		}
		else
		{
			right->add(acti);
		}
	}
	else 
	{
		cout << " No se permiten los valores duplicados :";
	}

}

void AVL::inOrder(NodoAVL* a) 
{
	if (a != nullptr) {
		
		inOrder(a->left);
		cout << "ID ->" + a->getActive()->getID() + " Nombre: "+ a->getActive()->getNombreActivo() +  " Descripcion: "+ a->getActive()->getDescripcion() +" \n";
		inOrder(a->right);
	}
}

void AVL::preOrder(NodoAVL* a)
{
	if (a != nullptr) {

		cout << "ID ->" + a->getActive()->getID() + " Nombre: " + a->getActive()->getNombreActivo() + " Descripcion: " + a->getActive()->getDescripcion() + " \n";
		preOrder(a->left);
		preOrder(a->right);
	}
}

/*void AVL::inOrder(NodoAVL* a)
{
	if (a == nullptr)
	{
	return;
	}
		inOrder(a->left);
		cout << "Nodo ->" + a->getActive()->getID() + " , ";
		inOrder(a->right);
	
}*/
void AVL::preOrder() {
	cout << "Recorrido PREORDER del arbol binario de búsqueda: \n\n";
	preOrder(root);
}

void AVL::inOrder() {
	cout << "Recorrido inorden de Activos: \n\n";
	inOrder(root);
}

/*void AVL::insertar(Activos* act) {
	NodoAVL* flu = new NodoAVL(act);
	
		root = insertarN(act, root);
	cout << "nodo->" + flu->getActive()->getID() + " ";
}*/

void AVL::deleter(string id) {
	//NodoAVL* flu = new NodoAVL(act);
	root = deleteNode(root, id);

}

void AVL::modificar(string id) {
	//NodoAVL* flu = new NodoAVL(act);
	root = searchNode(root, id);

}

void AVL::insertar(Activos* activos) {
	NodoAVL* aux = new NodoAVL(activos);
	if(root==nullptr){
		root=aux;
	}
	else {
		root = insertarN(activos, root);
		
	}
	cout << "nodo->" + aux->getActive()->getID() + " \n";
	}
	




NodoAVL* AVL::insertarN(Activos* activos, NodoAVL* flu) 
{
	NodoAVL* nAlv = flu;
	if (flu->getActive()->getID()>(activos->getID()) ) {
		if (flu->left == nullptr)
		{
			flu->left = new NodoAVL(activos);
		}
		else 
		{
			flu->left = insertarN(activos, flu->left);
			if ((altura(flu->left) - altura(flu->right)) == 2)
			{
				if (activos->getID() < flu->left->getActive()->getID())
				{
					nAlv = leftleft(flu);
				}
				else
				{
					nAlv = leftright(flu);
				}
			}

		}
	}
	else if (flu->getActive()->getID()<(activos->getID()))
	{
		if (flu->right == nullptr)
		{
			flu->right = new NodoAVL(activos);
		}
		else
		{
		flu->right = insertarN(activos, flu->right);
		if (altura(flu->right) - altura(flu->left) == 2)
		{
			if (activos->getID() > flu->right->getActive()->getID())
			{
				nAlv = rightright(flu);
				//insertarN(activos, root);
			}
			else
			{
				nAlv = rightleft(flu);
				//insertarN(activos, root);
			}
		}
	    }
	}

	else
	{
		cout << "Nodo insertado";
	
	}
	flu->altura = mayor(altura(flu->left), altura(flu->right)) + 1;
	return nAlv;
	inOrder(nAlv);
}


/*NodoAVL* AVL::insertarN(Activos* activos, NodoAVL* flu)

{
	NodoAVL* nAlv = flu;
	if (flu->left == nullptr)
		{
			flu->left = new NodoAVL(activos);
		}
		else
		{

	if (flu->getActive()->getID().compare(activos->getID()) > 0)
	{
		
			flu->left = insertarN(activos, flu->left);
			if (altura(flu->right) - altura(flu->left) == -2)
			{
				if (activos->getID() < flu->left->getActive()->getID()) {
					nAlv = leftleft(flu);
				}
				else
				{
					nAlv = leftright(flu);
				}
			}

		
	}
	else if (flu->getActive()->getID().compare(activos->getID()) < 0)
	{
		flu->right = insertarN(activos, flu->right);
		if (altura(flu->right) - altura(flu->left) == 2)
		{
			if (activos->getID() > flu->right->getActive()->getID())
			{
				nAlv = rightright(flu);
				//insertarN(activos, root);
			}
			else
			{
				nAlv = rightleft(flu);
				//insertarN(activos, root);
			}
		}
	}
	else
	{
		cout << "No se permiten los valores duplicados:";
		//flu->altura = mayor(altura(flu->left), altura(flu->right)) + 1;
		//return flu;
	}
	}
	return nAlv;
}*/

int AVL::altura(NodoAVL* nodo)
{
	if (nodo==nullptr)
	{
		return 0;
	}
	else
	{
		return nodo->altura;
	}
}

int AVL::mayor(int n1, int n2)
{
	if (n1 > n2)
	{
		return n1;
	}
	else
	{
		return n2;
	}
}
//* Rotación simple izquierda izquierda
NodoAVL* AVL::leftleft(NodoAVL* n1)
{
	NodoAVL* n2 = n1->left;
	n1->left = n2->right;
	n2->right = n1; 
	n1->altura = mayor(altura(n1->left), altura(n1->right)+ 1) ;
	n2->altura = mayor(altura(n2->left), n1->altura+ 1) ;
	return n2;
}

//* Rotación simple derecha


NodoAVL* AVL::rightright(NodoAVL* n1)
{
	NodoAVL* n2 = n1->right;
	n1->right = n2->left;
	n2->left = n1;
	n1->altura = mayor(altura(n1->left), altura(n1->right)+ 1) ;
	n2->altura = mayor(altura(n2->right), altura(n1->right) + 1);
	return n2;
}

//Rotación doble izuquierda derecha
NodoAVL* AVL::leftright(NodoAVL* n1) 
{
	NodoAVL* aux;
	n1->left = rightright(n1->left);
	aux = leftleft(n1);
	return aux;
}
//Rotación doble derecha izquierda 
NodoAVL* AVL::rightleft(NodoAVL* n1)
{
	n1->right = leftleft(n1->right);
	return rightright(n1);
}

NodoAVL* AVL::searchNode(NodoAVL* node, string ID) {
	if (node == nullptr) {
		cout << "No existe ese activo, o el arbol esta vacio \n";
		return 0;
	}
	else if (node->getActive()->getID()==ID)
	{
		string des;
		//node->getActive();
		cout << "El activo a modificar es ID ->" + node->getActive()->getID() + " Nombre: "+ node->getActive()->getNombreActivo() +  " Descripcion : "+ node->getActive()->getDescripcion() +" \n";
		cout << "Ingrese la nueva descripcion: \n";
		cin >> des;
		node->getActive()->setDescripcion(des);
		cout << " \nEl activo modificado es: ID ->" + node->getActive()->getID() + " Nombre: " + node->getActive()->getNombreActivo() + " Descripcion : " + node->getActive()->getDescripcion() + " \n";
		return node;
		//return node;
	}
	else if (ID.compare(node->getActive()->getID())==-1) {
		return searchNode(node->left, ID);
	}
	else
	{
		return searchNode(node->right, ID);
	}
}
NodoAVL* AVL::deleteNode(NodoAVL* node, string ID) {
	if (!node) {
		return nullptr;
	}
	if (ID == node->getActive()->getID())
	{
		if (node->right == nullptr)
		{
			NodoAVL* temp = node;
			node = node->left;
			delete (temp);
			return node;
		}
		else {
			NodoAVL* temp = node->right;
			while (temp->left)
			{
				temp=temp->left;
			}
			node->getActive()->getID() = temp->getActive()->getID();
			node->right = deleteNode(node->right, temp->getActive()->getID());
			
		}
	}
	else if (ID < node->getActive()->getID())
	{
		node->left = deleteNode(node->left,ID);
	}
	else
	{
		node->right = deleteNode(node->right, ID);
	} 
	
	//node->altura = mayor();
	node->altura = mayor(altura(node->left), altura(node->right)) + 1;
	if (altura(node->right) - altura(node->left) == 2)
	{
		if (altura(node->right->right) >= altura(node->right->left))
		{
			node = leftleft(node);
		}
		else {
			node = rightleft(node);
		}
	}
	else if (altura(node->left) - altura(node->right)==2) {
		if (altura(node->left->left) >= altura(node->left->right))
		{
			node = rightright(node);
		}
		else {
			node = leftright(node);
		}
	}
	else {
		cout << "Activo Eliminado \n";
	}


	return node;
}




void AVL::graficaravl() {

	ofstream archivo("AVL.dot");

	archivo << "digraph D { \n node [shape = egg, color = purple];\n";
	archivo << "labelloc = \"t;\"label = \"REPORTE AVL DE CATEGORIAS ++\";\n";
	if (root != nullptr)
	{
		AVL::indice = 0;
		archivo << ejecucion(root);
	}
	archivo << "}";
	archivo.close();

	system("C:\\\"Program Files (x86)\"\\Graphviz2.38\\bin\\dot.exe  -Tpng AVL.dot -o AVL.png");
	system("AVL.png &");
}

string AVL::ejecucion(NodoAVL* eje) {
	string text = "";
	
	int indexRaiz;
	indexRaiz=indice;
	//text+="\n\tN"+ to_string(indice) + std::string("[label = \"") + " ID: "+ eje->getActive()->getID() + "\\nNombre: " + eje->getActive()->getNombreActivo() + "\"];\n";
	if (eje->left != nullptr)
	{
		text += "\""+eje->getActive()->getID() + "\" [label =\"" + " ID: " + eje->getActive()->getID() + "\\nNombre: " + eje->getActive()->getNombreActivo() + " \" ] \n" ;
		text += "\""+eje->getActive()->getID()+"\" -> "+ "\""+eje->left->getActive()->getID()+"\"\n";
		text += ejecucion(eje->left);
	}
	else 
	{
		text += "\"" + eje->getActive()->getID() + "\" [label =\"" + " ID: "  + eje->getActive()->getID() + "\\nNombre: " + eje->getActive()->getNombreActivo() + " \" ]\n ";
		//text += to_string(indice) ;
		text += "\"" + eje->getActive()->getID() + "\" -> "+ to_string(indice) +" [label = 0] \n" ;
		indice++;


	}

	if (eje->right != nullptr)
	{
		text += "\"" + eje->getActive()->getID() + "\" [label =\"" + " ID: "  + eje->getActive()->getID() + "\\nNombre: " + eje->getActive()->getNombreActivo() + " \" ] \n";
		text += "\"" + eje->getActive()->getID() + "\" -> " + "\"" + eje->right->getActive()->getID() + "\" \n";
		text += ejecucion(eje->right);
	}
	else
	{
		text += "\"" + eje->getActive()->getID() + "\" [label =\"" + " ID: "  + eje->getActive()->getID() + "\\nNombre: " + eje->getActive()->getNombreActivo() + " \" ] \n";
		//text += to_string(indice) ;
		text += "\"" + eje->getActive()->getID() + "\" -> " + to_string(indice) + " [label = 0]\n";
		indice++;


	}
	return text;
}

void AVL::addNode(NodoAVL* nodo) {
	if (nodo != 0)
	{
		juntadoralv1 += "Nodo" + nodo->getActive()->getID();
		juntadoralv1 += " [ label = \"" + nodo->getActive()->getID() + "\"  ]; \n";
		AVL::addNode(nodo->left);
		AVL::addNode(nodo->right);
	}
}

void AVL::caca(NodoAVL* tree) {
	//NodoAVL u = new NodoAVL();
	if (tree != 0)
	{
		
		if (tree->left != nullptr)
		{
		//	AVL::caca(tree->left);
			juntadoralv1 += "Nodo" + tree->getActive()->getID();
			juntadoralv1 += "-> Nodo" + tree->left->getActive()->getID()+ "; \n";
		}
		if (tree->right != 0)
		{
			juntadoralv1 += "Nodo" + tree->getActive()->getID();
			juntadoralv1 += "-> Nodo" + tree->right->getActive()->getID()+"; \n";
		}

		AVL::caca(tree->left);
		AVL::caca(tree->right);
	}
}