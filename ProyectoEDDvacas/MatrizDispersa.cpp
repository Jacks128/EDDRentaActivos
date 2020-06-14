#include "MatrizDispersa.h"
#include <fstream>
//#include <string>
using namespace std;

string juntadoralv;

void MatrizDispersa::Insertar(Usuarios* rentador, string company, string depart) //cambiar usauruari a nidi
{
    nRentador = new Nodo(rentador);
    Nodo* nDepartamento;
    Nodo* nEmpresa;

    nDepartamento = searchDepartment(depart, header); //devuelvo el ultimo nodo de departamentos
    nEmpresa = searchCompany(company, header);        //devuelvo el utlimonodo de empresa

    //revisar si existe departamento y empresa,sino crearlos
    if (nDepartamento == NULL)
    {
        nDepartamento = createDepartment(depart);
    }
    if (nEmpresa == NULL)
    {
        nEmpresa = createCompany(company);
    }

    /********INSERTANDO A UN DEPARTAMENTO*********/
//insertar en nodo departamento
    /**insertando al inicio**/
    if (nDepartamento->down == NULL)//si abajo de x cabecera dep, no hay nada
    {
        nDepartamento->down = nRentador;  //creo mi nodo usuario abajo
        nRentador->up = nDepartamento;    //y el nodo usuario apunta a hacia el departamento
    }
    /**insertando al final**/
    else if (nEmpresa->down == NULL)    //si abajo de x cabacera empresa no hay nada
    {
        Nodo* aux = nDepartamento->down;  //Creo un nodo auxiliar, con lo que esta abajo de mi nodo departamento
        while (aux->down != NULL)       //mientras lo que esta abajo de mi nodo aux sea diferente a nulo
        {
            aux = aux->down;              //sigo bajando
        }
        if (!isCompany(company, aux, nRentador)) //si llego al final con mi nodo aux. verifico si debe ir encima, sino
        {
            aux->down = nRentador;        //el abajo de mi nodo auxiliar debe ser mi usuario
            nRentador->up = aux;          //el arriba de mi usuario debe ser auxiliar
        }
    }
    /**insertando en medio*/
    else
    {
        Nodo* aux = nDepartamento;    //creo un nodo axuliar departamento
        do                          //se hace esto mientras el abajo de mi axuliar no sea nulo, y el arriba de mi usuario sea nulo
        {
            aux = aux->down;          //se recorre hacia abajo
            if (!isCompany(company, aux, nRentador))   //si no debe insertar en nodo z
            {
                Nodo* auxCo = aux->left;              //creo un nodo aux de empresa que apunte a mi anterior
                while (auxCo->left != NULL)         //mientras elanterior del aux no sea nulo
                {
                    auxCo = auxCo->left;              //recorro hacia atras en mi nodo empresa
                }
                while (auxCo->up !=  NULL)           ////mientras el arriba del auxiliar sea distinto de nulo
                {
                    if (aux->nombreN == company)       //si el auxiliar es la compañia
                    {
                        nRentador->down = aux;           //el abajo de mi nodo usuario sera el auxiliar
                        nRentador->up = aux->up;          //y el arriba de mi nodo usuario sera el arriba de auxiliar

                        aux->up->down = nRentador; //el abajo del que esta arriba del aux sera mi nodo usuario
                        aux->up = nRentador;      // y el arriba de mi auxiliar el nodo usuario
                        break;
                    }
                    auxCo = auxCo->up;    //sino el arriba del auxiliar es nulo sigo recorriendo
                }
            }

        } while (aux->down != NULL && nRentador->up == NULL);

        if (nRentador->up == NULL && nRentador->above == NULL) //si el arriba del usuario es igual a nulo y el encima es igual a nulo
        {
            aux->down = nRentador;    //el abajo de mi nodo auxilar es el nodo usuario
            nRentador->up = aux;      //el arriba de mi nodo usuario es el aux
        }

    }
    if (nRentador->above != NULL)
    {
        return;
    }
    /**%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
    //insertar en nodo empresa
    /****insertando al inicio****/
    if (nEmpresa->right == NULL)
    {
        nEmpresa->right = nRentador;
        nRentador->left = nEmpresa;
    }
    /**insertando al final**/
    else if (nDepartamento->right == NULL)
    {
        Nodo* aux = nEmpresa->right;
        while (aux->right != NULL)
        {
            aux = aux->right;
        }
        if (!isDepartament(depart, aux, nRentador))
        {
            aux->right = nRentador;
            nRentador->left = aux;
        }

        /**nInsertando En Medio***/
    }
    else
    {
        Nodo* aux = nEmpresa;
        do
        {
            aux = aux->right;
            if (!isDepartament(depart, aux, nRentador))
            {
                Nodo* auxDep = aux->up;
                while (auxDep->up != NULL)
                {
                    auxDep = auxDep->up;
                }
                while (auxDep->left != NULL)
                {
                    if (auxDep->nombreN == depart)
                    {
                        nRentador->right = aux;
                        nRentador->left = aux->left;

                        aux->left->right = nRentador;
                        aux->left = nRentador;
                        break;
                    }
                    auxDep = auxDep->left;
                }
            }
        } while (aux->right != NULL && nRentador->left == NULL);

        if (nRentador->left == NULL && nRentador->above == NULL)
        {
            aux->right = nRentador;
            nRentador->left = aux;
        }
    }

}


/**BUSCANDO***/
/*Para ver si existe la cabecera*/
Nodo* MatrizDispersa::searchCompany(string company, Nodo* first)
{
    Nodo* aux = first;            //crear un nodo auxiliar que sea mi inicio
    while (aux != NULL)         //mientras eñ auxiliar sea distinto a nulo
    {
        if (aux->nombreN == company)   //si el nombre del auxiliar es el mismo al de la comñia
        {
            return aux;             //retorna a la compañia
        }
        aux = aux->down;              //sino sigue bajando hasta hallarlo
    }
    return nullptr;             //retorna nulo si no encuntre a la compñia
}


Nodo* MatrizDispersa::searchDepartment(string depart, Nodo* first)
{
    Nodo* aux = first;    //creo nodo auxiliar cabecera
    while (aux != NULL) //mientras mi nodo axualiar sea distitno de nulo
    {
        if (aux->nombreN == depart)    //si el axiliar es igual a mi departamento
        {
            return aux;             //retorno el aux
        }
        aux = aux->right;             //sino sigo avanzando
    }
    return nullptr;     //sino encuentra nada, retorno nulo
}



/**CREANDO**/
Nodo* MatrizDispersa::createCompany(string company)
{
    Nodo* co = new Nodo(company);//creo un nodo compañia
    Nodo* aux = header;           //creo un auxiliar cabecera
    while (aux->down != NULL)   //mientras que el down de auxiliar sea diferente de nulo
    {
        aux = aux->down;          //va seguir bajando
    }
    aux->down = co;               //si el down del aux es null, quiere decir que ahi insertamons la compañia
    co->up = aux;                 //y la compañia debe apuntar al aux
    return co;                  //y retornamos la compañia

}
Nodo* MatrizDispersa::createDepartment(string depart)
{
    Nodo* dep = new Nodo(depart); //creo un nodo departamento
    Nodo* aux = header;           //creo un auxiliar cabecera
    while (aux->right != NULL)  //mientras que el siguiente de aux sea distinto a nulo
    {
        aux = aux->right;         //va seguir avanzando
    }
    aux->right = dep;             //si el down del aux apunta a nulo, ahi creo mi nodo depa
    dep->left = aux;              //y el nodo depa debe apuntas al aux.
    return dep;                 //y retorno el departamento

}

/**VERIFICANDO*/

bool MatrizDispersa::isCompany(string company, Nodo* first, Nodo* rentador)
{
    Nodo* auxCo = first->left;    //creo un nodo auxiliar de empresa que sea lo anterior en mi actual o al primicpio de mi lista
    while (auxCo->left != NULL) //mientras que mi anterior de nodo empresa no sea nulo //*
    {
        auxCo = auxCo->left;      //sigo retrocediendo mientras sea diferente de nulo
    }
    if (auxCo->nombreN == company) //si mi nodo empreesa encuentra a la compañia
    {
        while (first->below != NULL)    //mientras el debajo de mi actual sea sistinto de nulo
        {
            first = first->below;         //mi actual va seguir recorriendo en z
        }
        first->below = rentador;          //cuando mi actual sea nulo, asigno el nuuevo rentador
        rentador->above = first;          //y mi rentador encima va ser igual a actual
        return true;                    //retorno true

    }
    return false;                   //pero retorno false sino debe ir encima
}

bool MatrizDispersa::isDepartament(string depart, Nodo* first, Nodo* rentador)
{
    Nodo* auxDep = first->up;     //creo un nodo departamento que sea el arriba de actual
    while (auxDep->up != NULL)  //mientras el arriba del aux sea diferente de nulo
    {
        auxDep = auxDep->up;      //sigo subiendo
    }
    if (auxDep->nombreN == depart) //si mi nodo auxiloar es igual al departamento
    {
        while (first->below != NULL) //mientras el debajo de mi actual sea distinto de nulo
        {
            first = first->below; //sigo recorriendo el eje x
        }
        first->below = rentador;  //el debajo de miactual apunta a mi usuario
        rentador->above = first;  //y mi encima usuario apunta a actual
        return true;

    }
    return false;
}

Nodo* MatrizDispersa::searchUsuario(string rentador, string company, string department)
{
    Nodo* usuario=nullptr;
    Nodo* empre;
    Nodo* depa;

    empre = searchCompany(company, header); //Buscamos a la empresa
    depa = searchDepartment(department, header);    //Buscamos el departamento
    if (empre != nullptr && depa != nullptr)        //verificamos si que la empresa y el departamento tengan algo
    {
        Nodo* Bempre = empre->right;    //creamos un nodo que sea el siguiente de la empresa
        while (Bempre != nullptr)       //mientras ese nodo tenga algo
        {
            Nodo* Bdepa = Bempre->up;   //el nodo depa es el arriba de empresa
            while (Bdepa->up != nullptr)    //mientras sea distinto de nulo recorremos
            {
                Bdepa = Bdepa->up;      //pa arriba
            }
            if (Bdepa->nombreN == department) //si encuentra el departamento que buscaba
            {
                Nodo* Busu = Bempre;            //creamos un nodo temporal de usuario
                if (Busu->getUsuario()->getUsuario() == rentador) //si el nombre de usuario es el mismo que el de los parametros
                {
                    cout << "Pos si esta we" << endl;
                    return Busu;
                }
                while (Busu->above != nullptr) {    //tambien erificamos si hay mas en esa misma posicion
                    Busu = Busu->above;
                    if (Busu->getUsuario()->getUsuario() == rentador) //y sisi pos retorna el usuario
                    {
                        cout << "Pos si esta we" << endl;
                        return Busu;
                    }
                }
            }
            Bempre = Bempre->right; //todo eso recorriendo a la derecha, cada que encuentra el departamento
        }
    }
    return usuario;
}

Nodo* MatrizDispersa::toGraphic(string department, string compan) 
{
    Nodo* ren = nullptr;
    Nodo* depHelper = header;
    Nodo* empHelper = header;
    Nodo* caca = nullptr;
    while (depHelper->right != NULL)
    {
        depHelper = depHelper->right;
        if (depHelper->nombreN == department)
        {
            caca = depHelper;
            while (empHelper->down != NULL)
            {
                empHelper = empHelper->down;
                caca = caca->down;

                if (empHelper->nombreN == compan || caca->down == NULL)
                {
                    ren = caca;
                    return ren;
                }
            }
        }
    }


    return nullptr;
}


void MatrizDispersa::graficar() 
{
    
    ofstream archivo("Catalogo.dot");
    archivo<< "digraph G{\n rankdir = TB\n node [shape = egg, color = purple];\n";
    archivo << "graph[nodesep = 0.5];\n";
    archivo<< "node0 [label=" << "\""<<header->nombreN << "\"" << "];" << endl;
    

    magia();
    archivo << juntadoralv;
   // juntadoralv += "}\n";
    archivo.close();
       
    system("C:\\\"Program Files (x86)\"\\Graphviz2.38\\bin\\dot.exe  -Tpng Catalogo.dot -o Catalogo.png");
    system("Catalogo.png    &");
    }

void MatrizDispersa::magia() 
{
    Nodo* helper = header;
    helper = helper->right;
    /*Columnas*/
    while (helper->right != NULL)
    {
        juntadoralv+=helper->nombreN + "[label = \"" + helper->nombreN + "\" ]; \n";
        helper = helper->right;
    }
    juntadoralv += helper->nombreN + "[label = \"" + helper->nombreN + "\" ]; \n";
    if (header->right != NULL)
    {
        helper = header->right;
        juntadoralv += "node0->" + helper->nombreN + "[dir=both];  \n";
    }
    helper = header->right;
    while (helper->right != NULL)
    {
        juntadoralv += helper->right->left->nombreN + "->" + helper->right->nombreN + "[dir=both];  \n";
        helper = helper->right;
    }

    /*FILAS*/
    helper = header;
    helper = helper->down;
    while (helper->down != NULL)
    {
        juntadoralv += helper->nombreN + "[label = \"" + helper->nombreN + "\" ]\n";
        helper = helper->down;
    }
    juntadoralv += helper->nombreN + "[label = \"" + helper->nombreN + "\" ]\n";
    if (header->down != NULL)
    {
        helper = header->down;
        juntadoralv += "node0->" + helper->nombreN + "[dir=both];\n";
    }
    helper = header->down;
    while (helper->down != NULL)
    {
        juntadoralv += helper->down->up->nombreN + "->" + helper->down->nombreN + "[dir=both];\n";
        helper = helper->down;
    }
    /*usuarios*/
   
    Nodo* depHelper = header;
    Nodo* empHelper = header;
    Nodo* aux = nullptr;
    string array[100];
    while (depHelper->right != NULL)
    {
        depHelper = depHelper->right;
        while (empHelper->down != NULL)
        {
            empHelper = empHelper->down;
            aux = toGraphic(depHelper->nombreN, empHelper->nombreN);

            if (aux != nullptr)
            {
                juntadoralv += aux->getUsuario()->getNombre() + "[label=\"" + aux->getUsuario()->getNombre() + "\"]\n";
               
            }
        }
        empHelper = header;
    }


    /*rank*/
    juntadoralv += "{rank=same; node0; ";
    Nodo* rank = header;
    rank = rank->right;
    while (rank->right != NULL) {
        juntadoralv += rank->nombreN + "; ";
        rank = rank->right;
    }
    juntadoralv += rank->nombreN + ";}";
    juntadoralv+= "}";  


    //juntadoralv = "";
    
}




