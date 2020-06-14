
#include <iostream>
#include "MatrizDispersa.h"
#include "Usuarios.h"

/*Metodos*/
void LoginAdmin();
void LoginUsuario();
void MenuAdmin();
void MenuUsuario();
void CrearUsuario();
void Inicio();
/*Variables*/
string user;
string password;
string nombre;
string empresa;
string departamento;
Nodo* tu;
Usuarios* usu;
MatrizDispersa* matriz;


int main()
{
    matriz = new MatrizDispersa();
    Inicio();
}

void Inicio() 
{
    cout << "\n\t\t   Bienvenido al Catalogo de Renta de Activos \n" << endl;
    bool indicador = false;
    int m;
    while (indicador = true)
    {
       // cin.clear();
        cout << "\t\t\t\t- Inicie Sesion -\n\n";
        cout << "1  Administrador \n"; //subir archivo json
        cout << "2  Usuario \n";
        cout << "3  Salir\n";
        cin >> m;
        switch (m)
        {
        case 1:
            system("cls");
            LoginAdmin();
            break;

        case 2:
            system("cls");
            LoginUsuario();
            break;

        case 3:
            system("cls");
            cout << "Saliendo" << endl;
            exit(0);
           
            break;

        default:
            system("cls");
            cout << "Opcion no valida.\a\n";
            //  pausa();
            break;
        }
    }

}

void LoginAdmin()
{
    cout << " \n ------------------------------------------------------------------------ \n";
    cout << "\t\t\t Bienvenido Administrador \n" << endl;
    cout << "Por favor, inicie sesion \n\n" << endl;
    cout << "Nombre de Usuario: ";
    cin >> user;
    cout << "Contrasenia: ";
    cin >> password;

    Usuarios* usur = matriz->getHeader()->getUsuario();

    if (usur && usur->getUsuario() == user)
    {
        if (password == usur->getContra())
        {
            MenuAdmin();
        }
        else
        {
            cout << "Contraase;a incorrecta";
            exit(0);
        }
    }
    else
    {
        cout << "Usuario Inexistenete";
        exit(0);
    }
}

void LoginUsuario() {
    cout << " \n ------------------------------------------------------------------------ \n";
    cout << "\t\t\t Bienvenido\n" << endl;
    cout << "Por favor, inicie sesion \n\n" << endl;
    cout << "Nombre de Usuario: ";
    cin >> user;
    cout << "Contrasenia: ";
    cin >> password;
    cout << "Empresa: ";
    cin >> empresa;
    cout << "Departamento de Ubicacion: ";
    cin >> departamento;

    tu = matriz->searchUsuario(user, empresa, departamento);


    if (tu && tu->getUsuario()->getUsuario() == user)
    {
        if (password == tu->getUsuario()->getContra())
        {
            MenuUsuario();
        }
        else
        {
            cout << "Contraase;a incorrecta";
            exit(0);
        }
    }
    else
    {
        cout << "Usuario Inexistenete, asegurese que los datos sean correctos";
        exit(0);
    }
}

void MenuUsuario()
{
    cout << "\n\t\t\t    Bienvenido "+ tu->getUsuario()->getNombre() +"\n" << endl;
    bool indicador = false;
    int m;
    while (indicador = true)
    {
        cin.clear();
        cout << "\t\t\t- Elija una opcion -\n\n";
        cout << "1  Agregar Activo \n"; //subir archivo json
        cout << "2  Eliminar Activo\n";
        cout << "3  Modificar Activo\n";
        cout << "2  Rentar Activo\n";
        cout << "2  Activos Rentados \n";
        cout << "2  Mis Activos Rentados\n";
        cout << "3  Cerrar Sesion \n";
        cout << "4  Salir\n";
        cin >> m;
        switch (m)
        {
        case 1:
            system("cls");
            CrearUsuario();
            break;

        case 2:
            system("cls");
            cout << "Reportes";
            break;

        case 3:
            system("cls");
            cout << "Cerrando Sesion" << endl;
            Inicio();
            break;

        case 4:
            cout << "Gracias por jugar scrabble" << endl;
            exit(0);
            break;

        default:
            system("cls");
            cout << "Opcion no valida.\a\n";
            //  pausa();
            break;
        }
    }
}
void MenuAdmin()
{
    cout << "\n\t\t\t    Bienvenido Admin\n" << endl;
    bool indicador = false;
    int m;
    while (indicador = true)
    {
        cin.clear();
        cout << "\t\t\t- Elija una opcion -\n\n";
        cout << "1  Crear Usuarios \n"; //subir archivo json
        cout << "2  Reportes\n";
        cout << "3  Cerrar Sesion \n";
        cout << "4  Salir\n";
        cin >> m;
        switch (m)
        {
        case 1:
            system("cls");
            CrearUsuario();
            break;

        case 2:
            system("cls");
            cout << "Reportes";
            matriz->graficar();
            break;

        case 3:
            system("cls");
            cout << "Cerrando Sesion" << endl;
            Inicio();
            break;

        case 4:
            cout << "Gracias" << endl;
            exit(0);
            break;

        default:
            system("cls");
            cout << "Opcion no valida.\a\n";
            //  pausa();
            break;
        }
    }
}
void CrearUsuario()
{
    cout<<"\t\t-Creacion de Usuarios-\n\n";
            cout<<"Ingrese su nombre de Usuario: "<<endl;
            cin>>user;
            cout<<"Ingrese su Password: "<<endl;
            cin>>password;
            cout<<"Ingrese su Nombre: "<<endl;
            cin>>nombre;
            usu=new Usuarios(user,password,nombre);
            cout<<"EL Usuario: "+usu->nombre+" ha sido creado exitosamente, su password es: " + usu->contra+ " y su username es: " + usu->usuario+"\n\n"<<endl;
            cout<<"Empresa a la que pertenece el usuario: "<<endl;
            cin>>empresa;
            cout<<"Departamento al que pertenece el usuario: "<<endl;
            cin>>departamento;
            matriz->Insertar(usu,empresa,departamento);
            cout<<"EL Usuario: "+usu->nombre+" se encuentra en " + empresa+ " y su username es: " + departamento+"\n\n"<<endl;

            /**P R U E B A S**/

            matriz->Insertar(new Usuarios("pedro","123","pedro"),"claro","huehue");
           matriz->Insertar(new Usuarios("jacky","123","jacky"),"tigo","huehue");
            matriz->Insertar(new Usuarios("susel","147","susel"),"jugueton","chimal");
            matriz->Insertar(new Usuarios("maria","123","maria"),"jugueton","chimal");
            matriz->Insertar(new Usuarios("juan","123","juan"),"claro","peten");

            if(matriz->searchCompany("claro",matriz->header))
            {
                cout<<"true";
            }

}



