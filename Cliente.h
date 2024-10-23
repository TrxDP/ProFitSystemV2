#ifndef CLIENTE_H
#define CLIENTE_H
#include<iostream>
#include<vector>
#include"Usuario.h"
#include"Actividades.h"

using namespace std;

class Cliente:public Usuario
{
    public:
        Cliente(int _id, string _nombre, string _contrasena, string _email,string _membresia, bool _activo);
        Cliente();
        virtual ~Cliente();


        string getMembresia();

        void setMembresia(string _membresia);

        void verPerfil();

    protected:



    private:
        string membresia;
        vector<Actividades> actividades;
        vector<string> progreso;
};

#endif // CLIENTE_H
