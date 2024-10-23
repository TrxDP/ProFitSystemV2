#ifndef INICIO_H
#define INICIO_H
#include<iostream>
#include<vector>
#include"Usuario.h"
#include"BaseDatos.h"
#include"Membresias.h"
#include"Actividades.h"
#include"Autenticacion.h"

using namespace std;



class Inicio
{
    public:
        Inicio();
        virtual ~Inicio();

        //Funcion que ejecuta toda la app
        void iniciarApp();


        // ---------------- Inicializacion de menus ----------------------
        //Funcion para escoger el menu dependiendo el usuario
        void mostrarMenuPorUsuario(Usuario* usuarioLogueado);

        //Menu de Administrador
        void mostrarMenuAdministrador();

        //Menu de Cliente
        void mostrarMenuCliente();

        //Menu del entrenador
        void mostrarMenuEntrenador();




        //Funcion para ver los programadores
        void programadores();



        // --------------- inicializacion de menus ------------------
        void leerBaseDatos();

        //setter
        void setIdUsuarios(int _id);
        void setIdMembresias(int _idMembresias);
        void setUsuarios(vector<Usuario*> _usuarios);
        void setMembresias(vector<Membresias> _membresias);

        // acerca de profitsystem
        void acercaDe();

    protected:

    private:
        int idUsuarios;
        int idMembresias;
        int idActividades;


        vector<Usuario*> usuarios;
        vector<Membresias> membresias;
        vector<Actividades> activiades;


};

#endif // INICIO_H
