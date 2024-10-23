#include "Administrador.h"

Administrador::Administrador(int _id, string _nombre, string _contrasena, string _email, bool _activo):Usuario(_id,_nombre,_contrasena,_email,"Administrador",_activo)
{
    //ctor
}

Administrador::Administrador():Usuario()
{
    //ctor
}

Administrador::~Administrador()
{
    //dtor
}
