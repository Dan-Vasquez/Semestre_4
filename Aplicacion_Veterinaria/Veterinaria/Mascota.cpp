#include "Mascota.h"


Mascota::Mascota(){           //se crea un constructor por defecto para asigna valores de inicio a los atributos de mascota
    raza = "";
    tipo = "";
    edad = 0;
    peso = 0;
    tipoSangre = "";
    nombreMascota = "";
    mascotaID = 0;
    status = true;
}

Mascota::Mascota(string raza, string tipo, int edad, int peso, string tipoSangre, string nombreMascota, int mascotaID, bool status){
    string fecha;                   //Constructor que recibe como parametros los valores ingresados por el usuarios
    this->raza = raza;              //para asignarlos a los atributos de mascota ademas, si la mascota esta muerta le solicita al usuario la fecha defuncion
    this->tipo = tipo;
    this->edad = edad;
    this->peso = peso;
    this->tipoSangre = tipoSangre;
    this->nombreMascota = nombreMascota;
    this->mascotaID = mascotaID;
    this->status = status;
    if(status == false){  //false = muerto
        cout << "Ingrese la fecha de defuncion de la mascota: ";
        cin >> fecha;
        setEstadoDefuncion(fecha);           //llama a la funcion para signarle una fecha de defuncion a la mascota
    }
    else{  //true = vivo
        this->fechaDefuncion = "Esta vivo UwU";
    }
}



void Mascota::setEstadoDefuncion( string fechaDefuncion){      //Permite asignar al atributo EstadoDefuncion una fecha ingresada      
    this->fechaDefuncion = fechaDefuncion;                     //por el usuario
}

void Mascota::cambiarEstadoDefuncion(){                              //Le pregunta al usuario una fecha de defuncion para una mascota muerta y la ingresa
    string fecha;                                                    //al atributo setEstadoDefuncion
    status = 0;
    cout << "Ingrese la fecha de defuncion de la mascota: ";
    cin >> fecha;
    setEstadoDefuncion(fecha);
}

double Mascota::getMascotaID(){              //Retorna el id de la mascota
    return this->mascotaID;
}

void Mascota::mostrarDatosMascota(){                                                //Permite mostrar en pantalla la informacion de una mascota ademas,
    cout << "El numero de identificacion de la Mascota es: " << mascotaID << "\n";  //solo si la mascota esta muerta muestra la fecha de defuncion
    cout << "El nombre de la Mascota es: " << nombreMascota << "\n";
    cout << "La raza de la Mascota es: " << raza << "\n";
    cout << "La Mascota es: " << tipo << "\n";
    cout << "La edad de la Mascota es: " << edad << "\n";
    cout << "El peso de la Mascota es: " << peso << "\n";
    cout << "El tipo de sangre de la Mascota es: " << tipoSangre << "\n";
    cout << "El status de la mascota esta: ";
    if(status == false){
        cout << "muerta\n";
        cout << "La mascota murio el: " << fechaDefuncion << "\n";
    }
    else{
       cout << "viva\n"; 
    }
    cout << "\n";
}