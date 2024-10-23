#include "Usuario.h"


Usuario::Usuario()
{
    //ctor
    id = 0;
    nombre = "null";
    contrasena = "null";
    email = "null";
    tipoUsuario = "null";
    activo = true;
}
Usuario::Usuario(int _id, string _nombre, string _contrasena, string _email, string _tipoUsuario, bool _activo)
{
    //ctor
    id = _id;
    nombre = _nombre;
    contrasena = _contrasena;
    email = _email;
    tipoUsuario = _tipoUsuario;
    activo = _activo;
}

Usuario::~Usuario()
{
    //dtor
}

//getters
int Usuario::getId(){
    return id;
}

string Usuario::getNombre(){
    return nombre;
}

string Usuario::getEmail(){
    return email;
}

string Usuario::getContrasena(){
    return contrasena;
}

string Usuario::getTipoUsuario(){
    return tipoUsuario;
}

 bool Usuario::getActivo(){
    return activo;
}


//setters

void Usuario::setId(int _id){
    id = _id;
}

void Usuario::setNombre(string _nombre){
    nombre = _nombre;
}

void Usuario::setEmail(string _email){
    email= _email;
}

void Usuario::setContrasena(string _contrasena){
    contrasena=_contrasena;
}

void Usuario::setTipoUsuario(string _tipoUsuario){
    tipoUsuario= _tipoUsuario;
}

void Usuario::setActivo(bool _activo){
    activo=_activo;
}

void Usuario::setId(){
    cout<<"\nIngrese el id: ";
    cin>>id;
}

void Usuario::setNombre(){
    cout<<"\nIngrese el nombre: ";
    cin>>nombre;
}

void Usuario::setEmail(){
    cout<<"\nIngrese el email: ";
    cin>>email;
}

void Usuario::setContrasena(){
    cout<<"\nIngrese la contraseña: ";
    cin>>contrasena;
}

void Usuario::setTipoUsuario(){
    cout<<"\nIngrese el tipo de usuario: ";
    cin>>tipoUsuario;
}

void Usuario::mostrarInformacion(){
    cout<<"\nInformacion de: "<<tipoUsuario;
    cout<<"\nNombre: "<<nombre;
    cout<<"\nContrasena: "<<contrasena;
    cout<<"\nEmail: "<<email;
    cout<<"\nTipo de usuario: "<<email;
    cout<<"\nActivo: "<<boolalpha<<activo;
}
