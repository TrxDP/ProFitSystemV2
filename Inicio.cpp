#include "Inicio.h"

Inicio::Inicio()
{
    //ctor
}

Inicio::~Inicio()
{
    //dtor
}

// --------------- Implementacion de los setters -------------------
void Inicio::setIdUsuarios(int _id){
    idUsuarios = _id;
}

void Inicio::setIdMembresias(int _idMembresias){
    idMembresias = _idMembresias;
}

void Inicio::setUsuarios(vector<Usuario*> _usuarios){
    usuarios = _usuarios;
}

void Inicio::setMembresias(vector<Membresias> _membresias){
    membresias = _membresias;
}

void Inicio::iniciarApp(){
    Usuario* usuarioLogueado;
    Autenticacion objAuten;
    int opc;
    do{
        system("cls");
        leerBaseDatos();
        cout<<"\n\t\t\t------------------------------";
        cout<<"\n\t\t\t-------- ProFitSystem --------";
        cout<<"\n\t\t\t------------------------------";
        cout<<"\n\t\t\t1) Iniciar Sesion.";
        cout<<"\n\t\t\t2) Acerca De ProFitSystem.";
        cout<<"\n\t\t\t3) Programadores.";
        cout<<"\n\t\t\t4) Salir.";
        cout<<"\n\t\t\tIngrese la opcion: ";
        cin>> opc;
        switch(opc){
            case 1:
                usuarioLogueado = objAuten.iniciarSesion(usuarios);
                if (usuarioLogueado != nullptr) {
                    cout << "\nInicio de sesión exitoso. Bienvenido, " << usuarioLogueado->getNombre() << "!" << endl;
                    mostrarMenuPorUsuario(usuarioLogueado);
                } else {
                    cout << "\n---------- Email o contraseña incorrectos. -----------" << endl;
                }
                break;
            case 2:
                acercaDe();
                system("pause");
                break;
            case 3:
                programadores();
                system("pause");
                break;
            case 4:
                cout<<"\t\t\t\nSaliendo...";
                break;
            default:
                cout<<"\t\t\t\nOpcion invalida.";
                break;
        }
    }while(opc != 4);
}

// ------------

void Inicio::programadores(){
    cout<<"\n------------------ Programadores ------------------ ";
    cout<<"\nNombre: Kevin Castillo Peres - 2363148 ";
    cout<<"\nNombre: Kevin Castillo Peres - 2363148 \n";

}



// ------------------- Implementacion de los menus -----------------------
void Inicio::mostrarMenuPorUsuario(Usuario* _usuarioLogueado){
    if (_usuarioLogueado->getTipoUsuario() == "Administrador") {
        mostrarMenuAdministrador();
    } else if (_usuarioLogueado->getTipoUsuario() == "Cliente") {
        mostrarMenuCliente();
    } else if (_usuarioLogueado->getTipoUsuario() == "Entrenador") {
        mostrarMenuEntrenador();
    } else {
        cout << "Tipo de usuario no reconocido.\n";
    }
}


//Implementacion del menu Administrador

void Inicio::mostrarMenuAdministrador(){
    cout<<"\n\t ------------- Hola Admin -------------------";
    int opcion;
    do {
        cout << "\n\t--- Menu Administrador ---\n";
        cout << "\t1. CRUD Usuarios\n";
        cout << "\t5. Gestionar Actividades\n";
        cout << "\t6. Consultar Estadísticas\n";
        cout << "\t7. CRUD Membresias\n";
        cout << "\t8. Salir\n";
        cout << "\tElija una opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                // llamar el menu CRUDs usuarios
                break;
            case 5:
                // Llamar función para gestionar actividades
                break;
            case 6:
                // Llamar función para consultar estadísticas
                break;
            case 7:
                break;
            case 8:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opción no válida, intente de nuevo.\n";
                break;
        }
    } while (opcion != 8);
}

//Implementacion del menu CLiente

void Inicio::mostrarMenuCliente(){

}

//Implementacion del menu Entrenador

void Inicio::mostrarMenuEntrenador(){

}



//---------- Implementaicon de la base de datos -----------------------

void Inicio::leerBaseDatos(){
    BaseDatos objDB;
    setUsuarios(objDB.leerUsuariosBlockNotas());
    setIdUsuarios(objDB.leerIdBlockNotas());
    setIdMembresias(objDB.leerIdMembresiasBlockNotas());
    setMembresias(objDB.leerMembresiasBlockNotas());
}



void Inicio::acercaDe(){

}
