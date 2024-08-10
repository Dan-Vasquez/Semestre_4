#ifndef MASCOTA_H
#define MASCOTA_H

#include <iostream>

using std::cin;
using std::cout;
using std::string;

class Mascota{
    private:
        string raza;            //Se definen los atributos para la clase Mascota
        string tipo;
        int edad;
        int peso;
        string tipoSangre;
        string nombreMascota;
        double mascotaID;
        bool status;
        string fechaDefuncion;
    public:
        Mascota();          //Se definen los constructores y funciones a utilizar en Mascota
        Mascota(string raza, string tipo, int edad, int peso, string tipoSangre, string nombreMascota, int mascotaID, bool status);
        void cambiarEstadoDefuncion();
        void setEstadoDefuncion(string fechaDefuncion);
        double getMascotaID();
        void mostrarDatosMascota();
};
#endif