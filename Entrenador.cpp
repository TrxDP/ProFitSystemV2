#include "Entrenador.h"

Entrenador::Entrenador(int _id, string _nombre, string _contrasena, string _email,int _experiencia, bool _activo):Usuario(_id,_nombre,_contrasena,_email,"Entrenador",_activo)
{
    //ctor
    experiencia = _experiencia;
}

Entrenador::Entrenador():Usuario()
{
    //ctor
    experiencia = 0;
}

Entrenador::~Entrenador()
{
    //dtor
}


int Entrenador::getExperiencia(){
    return experiencia;
}
