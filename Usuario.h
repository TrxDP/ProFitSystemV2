#ifndef USUARIO_H
#define USUARIO_H
#include<iostream>
#include<vector>

using namespace std;

class Usuario
{
    public:
        Usuario();
        Usuario(int _id, string _nombre, string _contrasena, string _email, string _tipoUsuario, bool _activo);
        virtual ~Usuario();

        // Metodos getters y setters
        int getId();
        string getNombre();
        string getEmail();
        string getContrasena();
        string getTipoUsuario();
        bool getActivo();

        void setId(int _id);
        void setNombre(string _nombre);
        void setEmail(string _email);
        void setContrasena(string _contrasena);
        void setTipoUsuario(string _tipoUsuario);
        void setActivo(bool _activo);

        void setId();
        void setNombre();
        void setEmail();
        void setContrasena();
        void setTipoUsuario();

        void mostrarInformacion();


    protected:

    private:
        int id;
        string nombre;
        string contrasena;
        string email;
        string tipoUsuario;
        bool activo;

};

#endif // USUARIO_H
