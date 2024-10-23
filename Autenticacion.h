#ifndef AUTENTICACION_H
#define AUTENTICACION_H
#include<iostream>
#include"Usuario.h"

using namespace std;

class Autenticacion
{
    public:
        Autenticacion();
        virtual ~Autenticacion();

        Usuario* iniciarSesion(vector<Usuario*> _usuarios);



    protected:

    private:
};

#endif // AUTENTICACION_H
