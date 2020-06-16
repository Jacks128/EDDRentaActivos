#include "AVL.h"
#include <fstream>

string juntadoralv1;
AVL::AVL() {
	this->root == nullptr;
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
//	int x = 1;
	if (a != nullptr) {
		
		inOrder(a->left);
		cout << "ID ->" + a->getActive()->getID() + " Nombre: "+ a->getActive()->getNombreActivo() +  " Descripcion: "+ a->getActive()->getDescripcion() +" \n";
		inOrder(a->right);
		//x++;
	}
	//	return;
	
	
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


void AVL::inOrder() {
	cout << "Recorrido inorden del árbol binario de búsqueda: \n";
	inOrder(root);

}

/*void AVL::insertar(Activos* act) {
	NodoAVL* flu = new NodoAVL(act);
	
		root = insertarN(act, root);
	cout << "nodo->" + flu->getActive()->getID() + " ";
}*/


void AVL::insertar(Activos* activos) {
	NodoAVL* flu = new NodoAVL(activos);
	if(root==nullptr){
		root=flu;
	}
	else {
		root = insertarN(activos, root);
		
	}
	cout << "nodo->" + flu->getActive()->getID() + " \n";
	}
	




NodoAVL* AVL::insertarN(Activos* activos, NodoAVL* flu) 
{
	NodoAVL* nAlv = flu;
	if (flu->getActive()->getID().compare(activos->getID()) > 0) {
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
	else if (flu->getActive()->getID().compare(activos->getID()) < 0)
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
		root->altura = mayor(altura(root->left), altura(root->right)) + 1;
		return flu;
	}
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
		return -1;
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
	n2->right = n1;//va xd
	//no me dejo correrlo xdxdxdxd
	//me 
	//toy viendo xd
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



void AVL::graficaravl() {

	ofstream archivo("AVL.dot");

	archivo << "digraph G{ \n node [shape = egg, color = purple];\n";
	addNode(this->root);
	archivo << juntadoralv1;
	juntadoralv1 = "";
	AVL::caca(root);
	archivo << juntadoralv1;
	juntadoralv1 = "";
	archivo << "}";
	archivo.close();

	system("C:\\\"Program Files (x86)\"\\Graphviz2.38\\bin\\dot.exe  -Tpng AVL.dot -o AVL.png");
	system("AVL.png &");
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