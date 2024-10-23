#include "Cliente.h"

Cliente::Cliente(int _id, string _nombre, string _contrasena, string _email,string _membresia, bool _activo):Usuario(_id,_nombre,_contrasena,_email,"Cliente",_activo)
{
    //ctor
    membresia = _membresia;
}

Cliente::Cliente():Usuario()
{
    //ctor
    membresia = "null";
}


Cliente::~Cliente()
{
    //dtor
}

string Cliente::getMembresia(){
    return membresia;
}
