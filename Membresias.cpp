#include "Membresias.h"

Membresias::Membresias(int _idMembresia,int _idCliente,string _nombre, double _costo, int _duracionDias, string _fechaInicio, string _fechaFin , bool _activo)
{
    //ctor
    idMembresia = _idMembresia;
    idCliente = _idCliente;
    nombre = _nombre;
    costo = _costo;
    duracionDias =_duracionDias;
    fechaInicio = _fechaInicio;
    fechaFin = _fechaFin;
    activo = _activo;
}

Membresias::Membresias(){
   //ctor
    idMembresia = 0;
    idCliente = 0;
    nombre = "-";
    costo = 0.0;
    duracionDias =0;
    fechaInicio = "-";
    fechaFin = "-";
    activo = false;
}

Membresias::~Membresias()
{

}



int Membresias::getIdMembresia(){
    return idMembresia;
}

int Membresias::getIdCliente(){
    return idCliente;
}

string Membresias::getNombre(){
    return nombre;
}

double Membresias::getCosto(){
    return costo;
}

int Membresias::getDuracionDias(){
    return duracionDias;
}

string Membresias::getFechaInicio(){
    return fechaInicio;
}

string Membresias::getFechaFin(){
    return fechaFin;
}

bool Membresias::getActivo(){
    return activo;
}

void Membresias::setIdMembresia(int _idMembresia){
    idMembresia = _idMembresia;
}


void Membresias::setNombre(string _nombre){
    nombre= _nombre;
}

void Membresias::setIdCliente(int _idCliente){
    idCliente = _idCliente;
}
void Membresias::setCosto(double _costo){
    costo= _costo;
}

void Membresias::setDuracionDias(int _duracionDias){
    duracionDias= _duracionDias;
}

void Membresias::setFechaInicio(string _fechaInicio){
    fechaInicio= _fechaInicio;
}

void Membresias::setFechaFin(string _fechaFin){
    fechaFin= _fechaFin;
}
void Membresias::setActivo(bool _activo){
    activo=_activo;
}

void Membresias::setNombre(){
    int opcion;
    verMembresias(0);
    cout << "\n\t\t---------------------------------";
    cout << "\nIngrese la opcion del nombre: ";
    cin>>opcion;
    while(opcion<1 || opcion>4){
        cout << "\nOpcion invalida ";
        cout << "\nIngrese nuevamente la opcion del nombre: ";
        cin>>opcion;
    }
    nombre = nombreMembresias[opcion-1];
}

void Membresias::setCosto(){
    if(nombre =="Plan Básico"){costo = 20000.0*(duracionDias/30);}
    if(nombre =="Plan Familiar"){costo = 90000.0*(duracionDias/30);}
    if(nombre =="Plan Corporativo"){costo = 200000.0*(duracionDias/30);}
    if(nombre =="Plan Premium"){costo = 100000.0*(duracionDias/30);}
}

void Membresias::setDuracionDias(){
    int dias = 30;
    int opcion;
    cout << "\n\t\t\t---------------------------------";
    cout << "\n1) 1 Mes ";
    cout << "\n2) 1 Año (10% de descuento) ";
    cout << "\nIngrese la duracion: ";
    cin>>opcion;
    while(opcion<1 || opcion>2){
        cout << "\nOpcion invalida ";
        cout << "\nIngrese nuevamente la opcion: ";
        cin>>opcion;
    }
    if(opcion==1){duracionDias = dias;}
    if(opcion == 2){duracionDias = dias * 12;}
}

void Membresias::setFechaInicio(){
    cout << "\n\t\t\t---------------------------------";
    cout << "\n\t\t\tIngrese la fecha de inicio (DD/MM/AAAA): ";
    cin>>fechaInicio;
}

void Membresias::setFechaFin(){
    fechaFin = sumarDias(duracionDias);
}

void Membresias::mostrarInformacion(){
    cout << "Membresía ID: " << idMembresia << endl;
    cout << "Tipo: " << nombre << endl;
    cout << "Costo: $" << costo << endl;
    cout << "Duración: " << duracionDias << " días" << endl;
    cout << "Fecha de inicio: " << fechaInicio << endl;
    cout << "Fecha de finalización: " << fechaFin << endl;
}

void Membresias::modificarMembresia(string nuevoNombre, double nuevoCosto, int nuevaDuracion, string nuevaFechaInicio, string nuevaFechaFin) {
    setNombre(nuevoNombre);
    setCosto(nuevoCosto);
    setDuracionDias(nuevaDuracion);
    setFechaInicio(nuevaFechaInicio);
    setFechaFin(nuevaFechaFin);
    cout << "Membresía modificada. Nuevo Nombre: " << nuevoNombre
        << ", Nuevo costo: $" << nuevoCosto
        << ", Nueva duración: " << nuevaDuracion << " días"
        << ", Nueva fecha de inicio: " << nuevaFechaInicio
        << ", Nueva fecha de finalización: " << nuevaFechaFin << endl;
}

void Membresias::infoMembresias(){

    //----------------   Datos de plan basico ----------------
    planBasico["Precio"]={
                    "20.000",
                    "(1 miembro)"
                    };
    planBasico["Acceso"]={
                    "Acceso limitado al área de pesas y cardio.",
                    "Horarios restringidos: 9:00 am - 5:00 pm",
                    };
    planBasico["Beneficios"]={
                    "Asesoría ocasional por parte de entrenadores.",
                    "Descuentos en inscripciones de eventos deportivos.",
                    "No incluye clases grupales."
                    };
    planBasico["Ideal para"]={
                    "Personas que entrenan de manera casual y tienen flexibilidad de horario."
                    };


    //----------------   datos de plan familias ----------------
    planFamiliar["Precio"]={
                    "90.000",
                    "(hasta 4 miembros)"
                    };
    planFamiliar["Acceso"]={
                    "Acceso completo al gimnasio para toda la familia.",
                    "Uso ilimitado de máquinas y acceso a todas las áreas."
                    };
    planFamiliar["Beneficios"]={
                    "Clases grupales familiares (ej. yoga en familia).",
                    "Evaluación física básica para cada miembro.",
                    "Descuento del 15% en productos del gimnasio.",
                    "Actividades recreativas los fines de semana."
                    };
    planFamiliar["Ideal para"]={
                    "Familias que desean entrenar juntas y disfrutar de actividades deportivas."
                    };


    //----------------   datos del plan corporativo ----------------
    planCorporativo["Precio"]={
                    "200.000",
                    "(hasta 10 empleados)"
                    };
    planCorporativo["Acceso"]={
                    "Acceso completo al gimnasio para empleados de la empresa.",
                    "Horarios flexibles: 5:00 am - 11:00 pm."
                    };
    planCorporativo["Beneficios"]={
                    "Clases grupales personalizadas para equipos de trabajo.",
                    "Evaluaciones físicas y planes de entrenamiento personalizados para empleados.",
                    "Descuento del 25% en eventos de bienestar corporativo.",
                    "Actividades de team-building (competencias internas, retos deportivos)."
                    };
    planCorporativo["Ideal para"]={
                    "Empresas que buscan fomentar la salud y el bienestar de sus empleados."
                    };


    //----------------   datos del plan premium ----------------
    planPremium["Precio"]={
                    "100.000",
                    "(1 miembro)"
                    };
    planPremium["Acceso"]={
                    "Acceso VIP completo y sin restricciones a todas las áreas y equipos.",
                    "Acceso prioritario a clases grupales y actividades exclusivas."
                    };
    planPremium["Beneficios"]={
                    "Entrenador personal dedicado.",
                    "Evaluación física mensual detallada.",
                    "Acceso al spa, sauna y piscina.",
                    "1 sesión de masaje mensual incluida.",
                    "Toalla, agua embotellada y snack post-entrenamiento incluidos en cada visita."
                    };
    planPremium["Ideal para"]={
                    "Clientes que buscan una experiencia de lujo y atención personalizada."
                    };


    todasMembresias["Plan Básico"] = planBasico;
    todasMembresias["Plan Familiar"] = planFamiliar;
    todasMembresias["Plan Corporativo"] = planCorporativo;
    todasMembresias["Plan Premium"] = planPremium;

}

void Membresias::verMembresias(int num){
    infoMembresias();
    if(num == 1 ){
        //--------------- ver la informacion de las membresias en pantalla ----------------------
        int cantidad =1;
        cout<<"\n\t\t-------- Membresias -------";
        for(pair<string,map<string,vector<string>>> it:todasMembresias){
            cout<<"\n"<<cantidad<<": "<<it.first;
            cout<<"\n\n\t-------- Informacion de "<< it.first<<" -------";
            for(pair<string,vector<string>> info : it.second){
                cout<<"\n\t"<<info.first;
                for(string datos : info.second){
                    cout<<"\n\t\t->"<<datos;
                }
            }
            cantidad++;
        }
    }else{
        int cantidad =1;
        cout<<"\n\t\t-------- Membresias -------";
        for(pair<string,map<string,vector<string>>> it:todasMembresias){
            cout<<"\n"<<cantidad<<": "<<it.first;
            cantidad++;
        }
    }
}

string Membresias::sumarDias(int _dias){
// Función para sumar días a la fecha actual
    time_t tiempoActual = time(0);
    struct tm *tiempoLocal = localtime(&tiempoActual);

    // Sumar los días
    tiempoLocal->tm_mday += _dias;

    // Normalizar la estructura 'tm' para ajustar correctamente el mes y el año si es necesario
    mktime(tiempoLocal);

    stringstream fechaHoraModificada;
    fechaHoraModificada << setfill('0') << setw(2) << tiempoLocal->tm_mday << "/"
                        << setw(2) << tiempoLocal->tm_mon + 1 << "/"
                        << tiempoLocal->tm_year + 1900 << " "
                        << setw(2) << tiempoLocal->tm_hour << ":"
                        << setw(2) << tiempoLocal->tm_min << ":"
                        << setw(2) << tiempoLocal->tm_sec;

    return fechaHoraModificada.str();
}
