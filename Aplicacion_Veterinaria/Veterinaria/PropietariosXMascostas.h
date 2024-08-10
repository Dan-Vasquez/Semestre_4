#ifndef PROPIETARIOSXMASCOTAS_H
#define PROPIETARIOSXMASCOTAS_H

#include "Propietario.h"
#include "Mascota.h"

class PropietariosXMascotas{
    private:
        Propietario propietario;    //Se definen los atributos para la clase que va a hacer las relaciones entre propietarios y mascotas
        Mascota mascota;            
        int idPropXMascotas;
    public:
        PropietariosXMascotas();    //Se definieron las funciones y constructores a utilizar en PropietariosXMascotas
        PropietariosXMascotas(Propietario propietario, Mascota mascota, int idPropXMascotas);
        Propietario getPropietario();
        Mascota getMascota();
        void motrarDatosPropietariosXMascotas();
        double getIdPropXMascotas();
};
#endif