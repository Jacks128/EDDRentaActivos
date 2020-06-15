#include "AVL.h"
#include <fstream>


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

/*void AVL::inOrder(NodoAVL* a) 
{
	if (a == nullptr)
	{
		return;
	}
	
		inOrder(a->left);
		cout << "Nodo ->"+ a->getActive()->getID() + " , ";
		inOrder(a->right);
}

void AVL::inOrder() {
	cout << "Recorrido inorden del árbol binario de búsqueda: \n";
	inOrder(root);

}*/

void AVL::insertar(Activos* act) {
	NodoAVL* flu = new NodoAVL(act);
	
	if (root == nullptr) {
		root = flu;
	}
	else {
		root = insertarN(act, root);

	}
	cout << "nodo->" + flu->getActive()->getID() + " ";
}

/*NodoAVL* AVL::insertarN(Activos *activos, NodoAVL* root)
{
	if (root == nullptr)
	{
		this->root = new NodoAVL(activos);
	}
	else 
	{
		if (activos->getID().compare(root->getActive()->getID()) < 0)
		{
			root->left = insertarN(activos, root->left);
			if (altura(root->right) - altura(root->left) == -2)
			{
				if (activos->getID().compare(root->left->getActive()->getID()) < 0) {
					root = leftleft(root);
				}
				else
				{
					root = leftright(root);
				}
			}
		}
		else if (activos->getID().compare(root->getActive()->getID()) > 0)
		{
			root->right = insertarN(activos, root->right);
			if (altura(root->right) - altura(root->left) == 2)
			{
				if (activos->getID().compare(root->right->getActive()->getID()) > 0)
				{
					root = rightright(root);
					//insertarN(activos, root);
				}
				else
				{
					root = rightleft(root);
					//insertarN(activos, root);
				}
			}
		}
		else
		{
			cout << "No se permiten los valores duplicados:";
			root->altura = mayor(altura(root->left), altura(root->right)) + 1;
			return root;
		}

	}
	
}*/

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
			if (altura(root->right) - altura(root->left) == 2)
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
	else
	{
	//	cout << "No se permiten los valores duplicados:";
		root->altura = mayor(altura(root->left), altura(root->right)) + 1;
		return root;
	}
}

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
	n2->right = n1;
	n1->altura = mayor(altura(n1->left), altura(n1->right)) + 1;
	n2->altura = mayor(altura(n2->left), n1->altura) + 1;
	return n2;
}

//* Rotación simple derecha


NodoAVL* AVL::rightright(NodoAVL* n1)
{
	NodoAVL* n2 = n1->right;
	n1->right = n2->left;
	n2->left = n1;
	n1->altura = mayor(altura(n1->left), altura(n1->right)) + 1;
	n2->altura = mayor(altura(n2->right), n1->altura) + 1;
	return n2;
}

//Rotación doble izuquierda derecha
NodoAVL* AVL::leftright(NodoAVL* n1) 
{
	n1->left = rightright(n1->left);
	return leftleft(n1);
}
//Rotación doble derecha izquierda 
NodoAVL* AVL::rightleft(NodoAVL* n1)
{
	n1->right = leftleft(n1->right);
	return rightright(n1);
}





