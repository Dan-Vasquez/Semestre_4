#ifndef PROPIETARIO_H
#define PROPIETARIO_H

#include <iostream>

using std::string;
using std::cin;
using std::cout;



class Propietario{
    private:
        string nombrePropietario;       //Se definen los atributos de la clase propietario
        string email;
        double propietarioID;
        double telefono;
    public:
        Propietario();                  //Se definen las funciones y constructores que van a ser utilizas dentro de propietario
        Propietario(string nombrePropietario, string email, double propietarioID, double telefono);
        double getPropietarioID();
        string getNombrePropietario();
        void mostrarDatosPropietario();
        void editarPropietario();
        void setNombrePropietario(string nombrePropietario);
        void setEmail(string email);
        void setTelefono(double telefono);
};
#endif