#ifndef ENTRENADOR_H
#define ENTRENADOR_H
#include<iostream>
#include<vector>
#include"Usuario.h"
#include"Cliente.h"

using namespace std;

class Entrenador: public Usuario
{
    public:
        Entrenador(int _id, string _nombre, string _contrasena, string _email,int _experiencia, bool _activo);
        Entrenador();
        virtual ~Entrenador();


        int getExperiencia();
        vector<string> getEspecializaciones();

    protected:



    private:
        int experiencia;
        vector<string> especializaciones;
        vector<Cliente> clientes;
};

#endif // ENTRENADOR_H
