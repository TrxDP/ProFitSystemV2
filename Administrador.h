#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H
#include<iostream>
#include<vector>
#include"Usuario.h"

using namespace std;

class Administrador:public Usuario
{
    public:
        Administrador(int _id, string _nombre, string _contrasena, string _email, bool _activo);
        Administrador();
        virtual ~Administrador();

    protected:

    private:
};

#endif // ADMINISTRADOR_H
