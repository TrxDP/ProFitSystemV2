#include "BaseDatos.h"

BaseDatos::BaseDatos(){

}

BaseDatos::~BaseDatos(){

}

// Método para leer usuarios desde un archivo de texto
vector<Usuario*> BaseDatos::leerUsuariosBlockNotas() {
    vector<Usuario*> usuarios;
    ifstream archivo(archivoUsuarios);
    if (archivo.is_open()) {
        string linea;
        while (getline(archivo, linea)) {
            istringstream ss(linea);
            string id, nombre, email, contrasena, tipoUsuario,membresia,stringActivo,experiencia;
            bool activo;
            getline(ss, id, ',');
            getline(ss, nombre, ',');
            getline(ss, email, ',');
            getline(ss, contrasena, ',');
            getline(ss, tipoUsuario, ',');
            if(tipoUsuario == "Administrador"){
                getline(ss,stringActivo,',');
                activo = (stringActivo == "true");
                Usuario* user =  new Administrador(stoi(id),nombre,contrasena,email,activo);
                usuarios.push_back(user);

            }else if(tipoUsuario == "Cliente"){
                getline(ss, membresia, ',');
                getline(ss,stringActivo,',');
                activo = (stringActivo == "true");
                Usuario* user =  new Cliente(stoi(id),nombre,contrasena,email,membresia,activo);
                usuarios.push_back(user);
            }else if(tipoUsuario == "Entrenador"){
                getline(ss, experiencia, ',');
                getline(ss,stringActivo,',');
                activo = (stringActivo == "true");
                Usuario* user =  new Entrenador(stoi(id),nombre,contrasena,email,stoi(experiencia),activo);
                usuarios.push_back(user);
            }
        }
        archivo.close();
        return usuarios;
    } else {
        cout << "No se pudo abrir el archivo de usuarios." << endl;
    }
    return usuarios;
}

// Método para escribir usuarios en un archivo de texto
void BaseDatos::escribirUsuariosBlockNotas(vector<Usuario*> _usuarios) {
    ofstream archivo(archivoUsuarios);
    if (archivo.is_open()) {
        for (auto *it : _usuarios) {
            string activo = (*it).getActivo() ? "true" : "false";
            // Comprobamos el tipo de usuario utilizando dynamic_cast
            if (Administrador* admin = dynamic_cast<Administrador*>(it)) {
                archivo << admin->getId() << "," << admin->getNombre() << ","
                        << admin->getEmail() << "," << admin->getContrasena() << ","
                        << admin->getTipoUsuario() << "," << activo << endl;
            } else if (Cliente* cliente = dynamic_cast<Cliente*>(it)) {
                archivo << cliente->getId() << "," << cliente->getNombre() << ","
                        << cliente->getEmail() << "," << cliente->getContrasena() << ","
                        << cliente->getTipoUsuario() << "," << cliente->getMembresia() << ","
                        << activo << endl;
            } else if (Entrenador* entrenador = dynamic_cast<Entrenador*>(it)) {
                archivo << entrenador->getId() << "," << entrenador->getNombre() << ","
                        << entrenador->getEmail() << "," << entrenador->getContrasena() << ","
                        << entrenador->getTipoUsuario() << "," << entrenador->getExperiencia() << ","
                        << activo << endl;
            }
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo para escribir los usuarios." << endl;
    }
}


// Método para actualizar el archivo de usuarios (sobreescribe el archivo)
void BaseDatos::actualizarUsuariosBlockNotas(vector<Usuario*> _usuarios) {
    escribirUsuariosBlockNotas(_usuarios);
}


int BaseDatos::leerIdBlockNotas(){
    int id = 0;
    ifstream archivo(archivoId);
    // Verifica si el archivo se abrió correctamente
    if(archivo.is_open()){
        string linea;
        //Lee la linea del archivo
        getline(archivo,linea);
        id=stoi(linea);
        // Cierra el archivo
        archivo.close();
        return id;
    }else{
        cout << "No se pudo abrir el archivo para escribir los usuarios." << endl;
        //return -1;
    }
    return id;
}

void BaseDatos::escribirIdBlockNotas(int _id){
    ofstream archivo(archivoId);
    // Verifica si el archivo se abrió correctamente
    if (archivo.is_open()) {
        // Escribe en el archivo
        archivo << _id;

        // Cierra el archivo
        archivo.close();
    } else {
        cerr << "No se pudo abrir el archivo." <<endl;
    }
}

void BaseDatos::actualizarIdBlockNotas(int _id){
    escribirIdBlockNotas(_id);
}

// Método para leer las membresias desde un archivo de texto
vector<Membresias> BaseDatos::leerMembresiasBlockNotas() {
    vector<Membresias> membresias;
    ifstream archivo(archivoMembresias);
    if (archivo.is_open()) {
        string linea;
        while (getline(archivo, linea)) {
            istringstream ss(linea);
            string idMembresia, idCliente, nombre, costo, duracionDias,fechaInicio,fechaFin,stringActivo;
            bool activo;
            getline(ss, idMembresia, ',');
            getline(ss, idCliente, ',');
            getline(ss, nombre, ',');
            getline(ss, costo, ',');
            getline(ss, duracionDias, ',');
            getline(ss, fechaInicio, ',');
            getline(ss, fechaFin,',');
            getline(ss, stringActivo,',');
            activo = (stringActivo == "true");
            Membresias membresia(stoi(idMembresia), stoi(idCliente), nombre, stoi(costo), stoi(duracionDias),fechaInicio,fechaFin,activo);
            membresias.push_back(membresia);
        }
        archivo.close();
        return membresias;
    } else {
        cout << "No se pudo abrir el archivo de membresias." << endl;
    }
    return membresias;
}


// Método para escribir las membresias en un archivo de texto
void BaseDatos::escribirMembresiasBlockNotas(vector<Membresias> _membresias){
    ofstream archivo(archivoMembresias);
    if (archivo.is_open()) {
        for (auto& membresia : _membresias) {
            string activo ="false";
            if(membresia.getActivo()==true){activo="true";}
            archivo << membresia.getIdMembresia() << ","
                    << membresia.getIdCliente() << ","
                    << membresia.getNombre() << ","
                    << membresia.getCosto() << ","
                    << membresia.getDuracionDias() << ","
                    << membresia.getFechaInicio() << ","
                    << membresia.getFechaFin() << ","
                    << activo << endl;
        }
        archivo.close();
    } else {
        cout << "No se pudo abrir el archivo para escribir las membresias." << endl;
    }
}


// Método para actualizar el archivo de membresias (sobreescribe el archivo)
void BaseDatos::actualizarMembresiasBlockNotas(vector<Membresias> _membresias){
    escribirMembresiasBlockNotas(_membresias);
}


int BaseDatos::leerIdMembresiasBlockNotas(){
    int idMembresias = 0;
    ifstream archivo(archivoIdMembresias);
    // Verifica si el archivo se abrió correctamente
    if(archivo.is_open()){
        string linea;
        //Lee la linea del archivo
        getline(archivo,linea);
        idMembresias=stoi(linea);
        // Cierra el archivo
        archivo.close();
        return idMembresias;
    }else{
        cout << "No se pudo abrir el archivo para escribir los usuarios." << endl;
        //return -1;
    }
    return idMembresias;
}

void BaseDatos::escribirIdMembresiasBlockNotas(int _idMembresias){
    ofstream archivo(archivoIdMembresias);
    // Verifica si el archivo se abrió correctamente
    if (archivo.is_open()) {
        // Escribe en el archivo
        archivo << _idMembresias;

        // Cierra el archivo
        archivo.close();
    } else {
        cerr << "No se pudo abrir el archivo." <<endl;
    }
}

void BaseDatos::actualizarIdMembresiasBlockNotas(int _idMembresias){
    escribirIdMembresiasBlockNotas(_idMembresias);
}
