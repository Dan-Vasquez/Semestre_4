#include "Propietario.h"

Propietario::Propietario(){         //Constructor por defecto que asigna valores de inicio a los atributos de propietario
    nombrePropietario = "";
    email = "";
    propietarioID = 0;
    telefono = 0;
}

Propietario::Propietario(string nombrePropietario, string email, double propietarioID, double telefono){   //Constructor que recibe como parametros los valores ingresados por el usuarios
    this->nombrePropietario = nombrePropietario;                                                           //para asignarlos a los atributos de propietario
    this->email = email;
    this->propietarioID = propietarioID;
    this->telefono = telefono;
}

double Propietario::getPropietarioID(){         //Retorna el ID del propietario
    return this->propietarioID;
}

string Propietario::getNombrePropietario(){     //Retorna el nombre del propietario
    return this->nombrePropietario;
}

void Propietario::mostrarDatosPropietario(){        //Permite mostrar en pantalla la informacion de un propietario
    cout << "El numero de identificacion del Propietario es: " << propietarioID << "\n";
    cout << "El nombre del Propietario es: " << nombrePropietario << "\n";
    cout << "El email del Propietario es: " << email << "\n";
    cout << "El telefono del Propietario es: " << telefono << "\n";
    cout << "\n";
}

void Propietario::setNombrePropietario(string nombrePropietario){       //Permite asignar al atributo nombrePropietario un valor ingresado
    this->nombrePropietario = nombrePropietario;                        //por el usuario
}

void Propietario::setEmail(string email){                 //Permite asignar al atributo email un valor ingresado
    this->email = email;                                  //por el usuario
}

void Propietario::setTelefono(double telefono){         //Permite asignar al atributo telefono un valor ingresado
    this->telefono = telefono;                          //por el usuario
}

void Propietario::editarPropietario(){                  //Permite modificar, a traves de setters, los atributos de un propietario ya almacenado
    int opcion = 0;
    double tempID = 0, tempTelefono = 0;
    string tempNombre;
    string tempEmail;
    do
    {
        cout << "Seleccione la informacion que desea editar del propietario\n";         //Se crea un menu con ayuda de un do-while para que el usario pueda realizar
        cout << "1. Nombre\n";                                                          //todas las modificaciones que desee
        cout << "2. Email\n";
        cout << "3. Telefono\n";
        cout << "0.  Salir \n";

        cin >> opcion;
        
        switch(opcion)                                  //Se realizan los cambios a traves de setters segun la opcion seleccionada por el usuario
        {
        case 1:
            cout << "Ingrese el nuevo nombre: ";
            cin >> tempNombre;
            setNombrePropietario(tempNombre);
            break;
        case 2:
            cout << "Ingrese el nuevo email: ";
            cin >> tempEmail;
            setEmail(tempEmail);
            break;
        case 3:
            cout << "Ingrese el nuevo numero telefono: ";
            cin >> tempTelefono;
            setTelefono(tempTelefono);
            break;
        default:
            break;
        }
        
    } while (opcion != 0); 
}




