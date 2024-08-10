#ifndef DIRECTORIO_H
#define DIRECTORIO_H

#include <iostream>
#include "PropietariosXMascostas.h"
#include <iterator>
#include <vector>
#include <unordered_map>

using std::unordered_map;
using std::vector;
using std::cin;
using std::cout;
using std::string;


class Directorio{
    private:
        int contId;
        unordered_map<double, Propietario>::iterator i;  //Se definio el iterador que permite recorrer el mapa de propietarios
        unordered_map<double, Propietario> mapPropietario;      //Se inicializo el mapa de propietarios
        unordered_map<double, Mascota>::iterator j;     //Se definio el iterador que permite recorrer el mapa de mascotas
        unordered_map<double, Mascota> mapMascota;      //Se inicializo el mapa de mascotas
        vector<PropietariosXMascotas> propietariosXMascotas;    //Se inicializo el vector que contiene las asociaciones entre propietarios y mascotas
    public:
        Directorio();                                   //Se definieron las funciones y constructores que van a ser utilizadas desde el directorio
        int getContId();
        void cantidadPropietariosRegistrados();
        void informacionPropietariosRegistrados();
        void informacionMascotasRegistradas();
        void asociarPropietarioMascotas();
        void asociarMascotaPropietarios();
        void agregarMascota();
        void agregarPropietario();
        void mostrarDirectorio();
        void cambiarStatusMascota();
        void editarInfoPropietarioDMascota();
        void listarInfoPropietariosDMascota();
        void listarInfoMascotasDPropietario();
        void eliminarPropietariosDMascota();
};

#endif