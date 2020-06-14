
#include <iostream>
#include "MatrizDispersa.h"
#include "Usuarios.h"

/*Metodos*/
void Login();
void MenuAdmin();
void MenuUsuario();
void CrearUsuario();
void Reporte();
/*Variables*/
string user;
string password;
string nombre;
string empresa;
string departamento;
Usuarios* usu;
MatrizDispersa* matriz;


int main()
{
    matriz = new MatrizDispersa();
    Login();
}
void Login()
{
    cout << " \n \n ##################################################################### \n";
    cout << "\t\t\t   Bienvenido \n" << endl;
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


void MenuUsuario()
{
    cout << " \n \n ##################################################################### \n";
    cout << "NO POS SI ENTRO A DONDE ERA XD";
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
            cout << "mierda a reportar";
            break;

        case 3:
            system("cls");
            cout << "Cerrando Sesion" << endl;
            Login();
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



