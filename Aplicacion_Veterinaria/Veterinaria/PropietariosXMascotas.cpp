#include "PropietariosXMascostas.h"

PropietariosXMascotas::PropietariosXMascotas(){         //Constructor por defecto que inicializa el ID del vector de propietariosXMascotas
    idPropXMascotas = 0;                                //para identificar cada posicion del vector
}

PropietariosXMascotas::PropietariosXMascotas(Propietario propietario, Mascota mascota, int idPropXMascotas){    //Constructor que recibe como parametros un propietario, una mascota y un id
    this->propietario = propietario;                                                                            //para almacenarlos
    this->mascota = mascota;
    this->idPropXMascotas = idPropXMascotas;

}

Propietario PropietariosXMascotas::getPropietario(){    //Permite acceder al propietario y utilizar las funciones de su clase
    return this->propietario;
}

Mascota PropietariosXMascotas::getMascota(){            //Permite acceder a la mascota y utilizar las funciones de su clase
    return this->mascota;
}

void PropietariosXMascotas::motrarDatosPropietariosXMascotas(){     //Permite acceder a la informacion de los propietarios y las mascotas
    cout << "Id: " << idPropXMascotas << "\n";                      //y mostrarlas en pantalla al usuario
    propietario.mostrarDatosPropietario();
    mascota.mostrarDatosMascota();
    cout << "------------------------------------------------\n";
}

double PropietariosXMascotas::getIdPropXMascotas(){        //Retorna el ID del vector propietariosXMascotas
    return this->idPropXMascotas;
}