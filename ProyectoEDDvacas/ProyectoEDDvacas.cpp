
#include <iostream>
#include <stdio.h>
#include <string>
#include "MatrizDispersa.h"
#include "Activos.h"
#include "AVL.h"
#include "Usuarios.h"
#include <time.h>
#include "Transaccion.h"

/*Metodos*/
void LoginAdmin();
void LoginUsuario();
void MenuAdmin();
void MenuUsuario();
void AgregarActivo();
void CrearUsuario();
void Inicio();
void EliminarActivo();
void MenuReportes();
void ModificarActivo();
void RentarActivo();
string Aleatorio();
void IsLogged();
/*Variables*/
string user;
string password;
string nombre;
string empresa;
string departamento;
string idTran;
string depa;
string em;
string fecha;
string tiempoR;

string nombreActivo;
string ID;
string descripcion;
AVL* arbolavl;
Nodo* tu;
Usuarios* usu;
Activos* actu;
MatrizDispersa* matriz;
//NodoLCD* noditoL;
NodoAVL* nodo;

int main()
{
    matriz = new MatrizDispersa();
   // arbolavl = new AVL();
    Aleatorio();

  //  nodo = new NodoAVL(*nodo);
    Inicio();
}

void Inicio() 
{
    matriz->Insertar(new Usuarios("pedro", "123", "pedro"), "claro", "huehue");
    matriz->Insertar(new Usuarios("jacky", "123", "jacky"), "tigo", "huehue");
    matriz->Insertar(new Usuarios("susel", "147", "susel"), "jugueton", "chimal");
    matriz->Insertar(new Usuarios("maria", "123", "maria"), "jugueton", "chimal");
    matriz->Insertar(new Usuarios("juan", "123", "juan"), "claro", "peten");
    cout << "\n\t\t   Bienvenido al Catalogo de Renta de Activos \n" << endl;
    bool indicador = false;
    int m;
    while (indicador = true)
    {
       // cin.clear();
        cout << "\t\t\t\t- Inicie Sesion -\n\n";
        cout << "\t###################### 1  Administrador ########################\n"; //subir archivo json
        cout << "\t###################### 2    Usuario     ########################\n";
        cout << "\t###################### 3     Salir      ########################\n";
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
        cout << "\t\t\t    Bienvenido Administrador \n" << endl;
    cout << "\t ------------------  Por favor, inicie sesion  ------------------ \n\n" << endl;
    cout << "Nombre de Usuario: ";
    cin >> user;
    cout << "Contrasenia:       ";
    cin >> password;

    Usuarios* usur = matriz->getHeader()->getUsuario();

    if (usur && usur->getUsuario() == user)
    {
        if (password == usur->getContra())
        {
            system("cls");
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
    cout << " \n ------------------------------------------------------------------------------- \n";
    cout << "\t\t\t\t    Bienvenido\n" << endl;
    cout << "\t ------------------  Por favor, inicie sesion  ------------------ \n\n" << endl;
    cout << "Nombre de Usuario:          ";
    cin >> user;
    cout << "Contrasenia:                ";
    cin >> password;
    cout << "Empresa:                    ";
    cin >> empresa;
    cout << "Departamento de Ubicacion:  ";
    cin >> departamento;

    tu = matriz->searchUsuario(user, empresa, departamento);


    if (tu && tu->getUsuario()->getUsuario() == user)
    {
        if (password == tu->getUsuario()->getContra())
        {
            system("cls");
            MenuUsuario();
        }
        else
        {
            cout << "Contraase;a incorrecta";
            LoginUsuario();
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
    cout << " \n ------------------------------------------------------------------------------- \n";
    
    cout << "\t\t\t      Bienvenido "+ tu->getUsuario()->getNombre() +"\n" << endl;
    bool indicador = false;
    int m;
    while (indicador = true)
    {
        cin.clear();
        cout << "\n\t\t\t   - Elija una opcion -\n\n";
        cout << "\t    ############ 1.     Agregar Activo     ############\n"; //subir archivo json
        cout << "\t    ############ 2.    Eliminar Activo     ############\n";
        cout << "\t    ############ 3.    Modificar Activo    ############\n";
        cout << "\t    ############ 4.     Rentar Activos     ############\n";
        cout << "\t    ############ 5.    Activos Rentados    ############\n";
        cout << "\t    ############ 6.  Mis Activos Rentados  ############\n";
        cout << "\t    ############ 7.      Cerrar Sesion     ############\n";
        cout << "\t    ############ 8.          Salir         ############\n";
        cin >> m;
       // cin >> m;
        switch (m)
        {
        case 1:
            system("cls");
            AgregarActivo();
            break;

        case 2:
            system("cls");
            
            EliminarActivo();
            break;

        case 3:
            system("cls");
            ModificarActivo();
            break;

        case 4:
            system("cls");
            RentarActivo();
            exit(0);
            break;
        case 5:
            system("cls");
            tu->getUsuario()->getAvlAct()->graficaravl();
            break;

        case 6:
            system("cls");
            cout << "Reportes";
            break;

        case 7:
            system("cls");
            cout << "Cerrando Sesion" << endl;
            Inicio();
            break;

        case 8:
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
    cout << " \n ------------------------------------------------------------------------------- \n";
    cout << "\t\t\t       Bienvenido Admin\n" << endl;
    bool indicador = false;
    int m;
    while (indicador = true)
    {
        cin.clear();
        cout << "\t\t\t     - Elija una opcion -\n\n";
        cout << "\t     ############## 1.  Crear Usuarios ##############\n"; //subir archivo json
        cout << "\t     ############## 2.     Reportes    ##############\n";
        cout << "\t     ############## 3.  Cerrar Sesion  ##############\n";
        cout << "\t     ############## 4.      Salir      ##############\n";
        cin >> m;
        switch (m)
        {
        case 1:
            system("cls");
            CrearUsuario();
            break;

        case 2:
            system("cls");
            MenuReportes();
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

void MenuReportes() {
    cout << " \n ------------------------------------------------------------------------------- \n";
    cout << "\t\t\t        - Menu Reportes - \n" << endl;
    bool indicador = false;
    int m;
    while (indicador = true)
    {
        cin.clear();
        cout << "\t\t\t     - Elija una opcion -\n\n";
        cout << " ############ 1.              Reporte Matriz Dispersa            #############\n"; 
        cout << " ############ 2.  Reporte Activos Disponibles de un Departamento #############\n";
        cout << " ############ 3.    Reporte Activos Disponibles de una Empresa   #############\n";
        cout << " ############ 4.              Reporte Transacciones              #############\n";
        cout << " ############ 5.          Reporte Activos de un Usuario          #############\n";
        cout << " ############ 6.         Activos rentados por un Usuario         #############\n";
        cout << " ############ 7.             Ordenar Transacciones               #############\n";
        cout << " ############ 8.                    Regresar                     #############\n";
        cin >> m;
        switch (m)
        {
        case 1:
            matriz->imprimir();
            matriz->graficar();
            break;

        case 2:
            //system("cls");
            //cout << "Reportes";
            
            break;

        case 3:
            system("cls");
            cout << "Cerrando Sesion" << endl;
            Inicio();
            break;

        case 4:
            tu->getUsuario()->getAvlAct()->graficaravl();
            break;

        case 5:
            matriz->graficar();
            break;

        case 6:
            //system("cls");
            //cout << "Reportes";

            break;

        case 7:
            system("cls");
            cout << "Cerrando Sesion" << endl;
            Inicio();
            break;

        case 8:
            system("cls");
            MenuAdmin();
            break;
        default:
            system("cls");
            cout << "Opcion no valida.\a\n";
            //  pausa();
            break;
        }
    }
}

void AgregarActivo() {
    cout << " \n ------------------------------------------------------------------------------- \n";
    cout << "\t\t\t       -Creacion de Activo-\n\n";
    cout << "Ingrese el Nombre del Activo:  ";
    getline(cin, nombreActivo);
    getline(cin, nombreActivo);
   // cin >> nombreActivo;
    cout << "Ingrese su Descripcion:        ";
    getline(cin, descripcion);
    //cin >> descripcion;
   
    tu->getUsuario()->getAvlAct()->insertar(new Activos(Aleatorio(), nombreActivo, descripcion));
   // arbolavl->insertar( );  

    cout << "\t\t\t       - Tus Activos -\n\n";
    tu->getUsuario()->getAvlAct()->preOrder();
    cout << "\n\n";

    /*Pruebas*/
 //   arbolavl->insertar(new Activos("A2","SHIne","No pos pa esto y lo otor"));
   // arbolavl->insertar(new Activos("Z2", "SHIne", "No pos pa esto y lo otor"));
    //arbolavl->insertar(new Activos("B5", "SHIne", "No pos pa esto y lo otor"));
   // arbolavl->insertar(new Activos("W5", "SHIne", "No pos pa esto y lo otor"));
   // arbolavl->inOrder();
   //  nodo->graficar();
}   

void CrearUsuario()
{
    cout << " \n ------------------------------------------------------------------------------- \n";
    cout << "\t\t\t     - Creacion de Usuarios - \n" << endl;
            cout<<"Ingrese su nombre de Usuario:  ";
            cin>>user;
            cout<<"Ingrese su Password:           ";
            cin>>password;
            cout<<"Ingrese su Nombre:             ";
            cin>>nombre;
            usu=new Usuarios(user,password,nombre);
            cout<<"\n\nEL Usuario: "+usu->nombre+" ha sido creado exitosamente \nSu password es: " + usu->contra+ " y su Username es: " + usu->usuario+"\n\n"<<endl;
            cout<<"Ingresa la empresa a la que pertenece el usuario:    ";
            cin>>empresa;
            cout<<"Ingresa el departamento al que pertenece el usuario: ";
            cin>>departamento;
            matriz->Insertar(usu,empresa,departamento);
            cout<<"\n\nEL Usuario: "+usu->nombre+" se encuentra en " + empresa+ " y su username es: " + departamento+"\n\n"<<endl;

            /**P R U E B A S**/
           
            

          

}

string Aleatorio() {
    char strrnd[15];
    int x;
    string ale="";
    srand(time(NULL));
    for (int i = 0; i < 15; i++){
        int x= 48 + rand() % (122 - 48);
        int y= 65 + rand() % (90 - 65);
        if ((x >= 48 && x <= 57) ||(x>=65 && x<=90)||(x>=97 && x<=122)) {
            strrnd[i] = x;
          //  ale = "A";
        }
        else {
            strrnd[i] = y;
        }
        ale=ale+ strrnd[i];
    }
   // cout << ale;
   //cin.get();
    return  ale;
}

void EliminarActivo() {
    cout << " \n ------------------------------------------------------------------------------- \n";

    string x;
    cout << "\t\t\t- Bienvenido a la seccion Eliminar -\n\n";
    tu->getUsuario()->getAvlAct()->inOrder();
    cout << "\n\t\t\t      - Elija el ID a eliminar -\n\n";
    cin >> x;
    tu->getUsuario()->getAvlAct()->deleter(x);
    tu->getUsuario()->getAvlAct()->inOrder();
}

void ModificarActivo() {
    string x;
    cout << " \n ------------------------------------------------------------------------------- \n";

    cout << "\t\t\t- Bienvenido a la seccion Modificar -\n\n";

    tu->getUsuario()->getAvlAct()->inOrder();
    cout << "\t\t\t- Elija el ID a mosficar -\n\n";
    
    getline(cin, x);
    //cin >> x;
    tu->getUsuario()->getAvlAct()->modificar(x);
    tu->getUsuario()->getAvlAct()->inOrder();

    

}

void RentarActivo() {
    cout << " \n ------------------------------------------------------------------------------- \n";
    cout << "\t\t\t       -Catalogo de Activo-\n\n";
    tu->getUsuario()->getAvlAct()->preOrder();
    cout << "Ingrese el ID del Activo a rentar:  ";
    cin >> ID;
    cout << "Ingresar Departamento:              ";
    cin >> depa;
    cout<< "Ingresar Empresa:                    ";
    cin >> em;
    cout << "Tiempo en que se realizo:           ";
    cin >> tiempoR;
    
    tu->getUsuario()->getLCD()->Insertar(new Transaccion(Aleatorio(), ID, tu->getUsuario()->getNombre(), depa, em, em, tiempoR));
    tu->getUsuario()->getLCD()->Mostrar();
}