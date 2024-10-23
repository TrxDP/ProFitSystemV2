#include "Autenticacion.h"

Autenticacion::Autenticacion()
{
    //ctor
}

Autenticacion::~Autenticacion()
{
    //dtor
}


Usuario* Autenticacion::iniciarSesion(vector<Usuario*> _usuarios){

    string email,contrasena;
    cout<<"\n\t\t\tIngrese el email: ";
    cin>>email;
    cout<<"\n\t\t\tIngrese la contraseña: ";
    cin>>contrasena;

    for (auto *usuario : _usuarios) {
        if (usuario->getEmail() == email && usuario->getContrasena() == contrasena) {
            return usuario;  // Devuelve el puntero al usuario que ha iniciado sesión
        }
    }
    return nullptr;  // Si no coincide, retorna nullpt
}
