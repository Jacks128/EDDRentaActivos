#include "MatrizDispersa.h"

using namespace std;


void MatrizDispersa::Insertar(Usuarios* rentador, string company, string depart) //cambiar usauruari a nidi
{
    nRentador = new Nodo(rentador);
    Nodo* nDepartamento;
    Nodo* nEmpresa;

    nDepartamento = searchDepartment(depart, header); //devuelvo el ultimo nodo de departamentos
    nEmpresa = searchCompany(company, header);        //devuelvo el utlimonodo de empresa

    //revisar si existe departamento y empresa,sino crearlos
    if (nDepartamento == nullptr)
    {
        nDepartamento = createDepartment(depart);
    }
    if (nEmpresa == nullptr)
    {
        nEmpresa = createCompany(company);
    }

    /********INSERTANDO A UN DEPARTAMENTO*********/
//insertar en nodo departamento
    /**insertando al inicio**/
    if (nDepartamento->down == nullptr)//si abajo de x cabecera dep, no hay nada
    {
        nDepartamento->down = nRentador;  //creo mi nodo usuario abajo
        nRentador->up = nDepartamento;    //y el nodo usuario apunta a hacia el departamento
    }
    /**insertando al final**/
    else if (nEmpresa->down == nullptr)    //si abajo de x cabacera empresa no hay nada
    {
        Nodo* aux = nDepartamento->down;  //Creo un nodo auxiliar, con lo que esta abajo de mi nodo departamento
        while (aux->down != nullptr)       //mientras lo que esta abajo de mi nodo aux sea diferente a nulo
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
                while (auxCo->left != nullptr)         //mientras elanterior del aux no sea nulo
                {
                    auxCo = auxCo->left;              //recorro hacia atras en mi nodo empresa
                }
                while (auxCo->up != nullptr)           ////mientras el arriba del auxiliar sea distinto de nulo
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

        } while (aux->down != nullptr && nRentador->up == nullptr);

        if (nRentador->up == nullptr && nRentador->above == nullptr) //si el arriba del usuario es igual a nulo y el encima es igual a nulo
        {
            aux->down = nRentador;    //el abajo de mi nodo auxilar es el nodo usuario
            nRentador->up = aux;      //el arriba de mi nodo usuario es el aux
        }

    }
    if (nRentador->above != nullptr)
    {
        return;
    }
    /**%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%*/
    //insertar en nodo empresa
    /****insertando al inicio****/
    if (nEmpresa->right == nullptr)
    {
        nEmpresa->right = nRentador;
        nRentador->left = nEmpresa;
    }
    /**insertando al final**/
    else if (nDepartamento->right == nullptr)
    {
        Nodo* aux = nEmpresa->right;
        while (aux->right != nullptr)
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
                while (auxDep->up != nullptr)
                {
                    auxDep = auxDep->up;
                }
                while (auxDep->left != nullptr)
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
        } while (aux->right != nullptr && nRentador->left == nullptr);

        if (nRentador->left == nullptr && nRentador->above == nullptr)
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
    while (aux != nullptr)         //mientras eñ auxiliar sea distinto a nulo
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
    while (aux != nullptr) //mientras mi nodo axualiar sea distitno de nulo
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
    while (aux->down != nullptr)   //mientras que el down de auxiliar sea diferente de nulo
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
    while (aux->right != nullptr)  //mientras que el siguiente de aux sea distinto a nulo
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
    while (auxCo->left != nullptr) //mientras que mi anterior de nodo empresa no sea nulo //*
    {
        auxCo = auxCo->left;      //sigo retrocediendo mientras sea diferente de nulo
    }
    if (auxCo->nombreN == company) //si mi nodo empreesa encuentra a la compañia
    {
        while (first->below != nullptr)    //mientras el debajo de mi actual sea sistinto de nulo
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
    while (auxDep->up != nullptr)  //mientras el arriba del aux sea diferente de nulo
    {
        auxDep = auxDep->up;      //sigo subiendo
    }
    if (auxDep->nombreN == depart) //si mi nodo auxiloar es igual al departamento
    {
        while (first->below != nullptr) //mientras el debajo de mi actual sea distinto de nulo
        {
            first = first->below; //sigo recorriendo el eje x
        }
        first->below = rentador;  //el debajo de miactual apunta a mi usuario
        rentador->above = first;  //y mi encima usuario apunta a actual
        return true;

    }
    return false;
}






