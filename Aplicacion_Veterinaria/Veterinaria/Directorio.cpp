#include "Directorio.h"

Directorio::Directorio(){                        //Es constructor por defecto para inicializar el contador del directorio para ingresarlo
    contId = 1;                                  //al vector PropietariosXMascotas
}

int Directorio::getContId(){                     //Retorna el contador del directorio
    return this -> contId;
}

void Directorio::agregarMascota(){              //Permite al usuario agregar una mascota con los respectivos datos de la mascota 
    string raza, tipo, tipoSangre, nombreMascota, fechaDefuncion;
    int edad, peso;
    double mascotaID;
    bool status;
    cout << "Indique la identificacion de la mascota: ";
    cin >> mascotaID;
    for(j = mapMascota.begin(); j != mapMascota.end(); ++j){    //Recorre el mapa de Mascotas para verificar que la mascota no exista
        if(mascotaID == j->first){                              //Si encuentra el ID de la mascota a registrar, devuelve un mensaje de error y termina la funcion
            cout << "Esta mascota ya se encuentra registrada en el directorio de la Veterinaria Pulguitas\n";
            return;
        }
    }
    cout << "Indique la nombre de la mascota: ";                //Se llenan las variables con los datos necesarios para registrar la mascota
    cin >> nombreMascota;
    cout << "Indique la raza: ";
    cin >> raza;
    cout << "Indique el tipo de mascota (Perro, Gato, Pez, otro): ";
    cin >> tipo;
    cout << "Indique la tipo de sangre: ";
    cin >> tipoSangre;
    cout << "Indique la edad (anios): ";
    cin >> edad;
    cout << "Indique la peso (Kg): ";
    cin >> peso;
    cout << "Indique si la mascota esta viva (1) o muerta (0): ";
    cin >> status;
    Mascota petTemp(raza, tipo, edad, peso, tipoSangre, nombreMascota, mascotaID, status);  //Se crea una mascota nueva temporal de tipo Mascota
    mapMascota[mascotaID] = petTemp;                                                        //para ser agregada al mapa(desordenado) mascota, y la clave del mapa Mascota es el mismo ID de la mascota
}

void Directorio::agregarPropietario(){                              //Permite al usuario agregar un nuevo propietario con los respectivos datos
    string nombrePropietario, email;
    double propietarioID, telefono;
    cout << "Indique el ID del propietario: ";
    cin >> propietarioID;
    for(i = mapPropietario.begin(); i != mapPropietario.end(); ++i){    //Recorre el mapa(desordenado) de propietarios para verificar que no se encuentre registrado
        if(propietarioID == i->first){                                  //el nuevo propietario
            cout << "El propietario ya existe en el directorio de la Veterinaria Pulguitas\n";
            return;
        }
    }
    cout << "Indique el nombre del propietario: ";
    cin >> nombrePropietario;
    cout << "Indique el email del propietario: ";
    cin >> email;
    cout << "Indique el telefono del propietario: ";
    cin >> telefono;
    Propietario propieTemp(nombrePropietario, email, propietarioID, telefono);      //Se cre un propietario temporal para ser agregado al mapa propietario
    mapPropietario[propietarioID] = propieTemp;
}

void Directorio::cantidadPropietariosRegistrados(){                     //Es una funcion con un contador la cual recorre el mapa propietarios
    int cantidad = 0;                                                   //indicando la cantidad de propietarios registrados
    for(i = mapPropietario.begin(); i != mapPropietario.end(); ++i){
        cantidad++;
    }
    cout << "El directorio tiene " << cantidad << " propietarios registrados\n";
}

void Directorio::informacionPropietariosRegistrados(){                  //Funcion que recorre el mapa propietarios y muestra la informacion de cada propietario presente en el mapa
    for(i = mapPropietario.begin(); i != mapPropietario.end(); ++i){    //Recorre el mapa desde el inicio hasta que no encuentre mas elementos
        i->second.mostrarDatosPropietario();                            //Se para en la informacion presente de cada posicion del mapa y llama a la funcion que imprime los datos
    }   
}

void Directorio::informacionMascotasRegistradas(){                      //Funcion que recorre el mapa mascotas y muestra la informacion de cada mascota presente en el mapa
    for(j = mapMascota.begin(); j != mapMascota.end(); ++j){            //Recorre el mapa desde el inicio hasta que no encuentre mas elementos
        j->second.mostrarDatosMascota();                                //Se para en la informacion presente de cada posicion del mapa y llama a la funcion que imprime los datos
    }
}

void Directorio::asociarPropietarioMascotas(){                          //Funcion que permite hacer una relacion de asignacion entre propietario y mascotas
    double idPet = 0, idProp = 0;                                       //y las envia al vector propietariosXMascotas
    int cantidadMascotas = 0;
    cout << "Ingrese el numero de identificacion del propietario: ";
    cin >> idProp;
    cout << "Ingrese la cantidad de mascotas que desea asociar con este propietario: ";
    cin >> cantidadMascotas;
    for( int i = 0; i < cantidadMascotas; i++ ){                        
        cout << "Ingrese el numero de identificacion de la mascota la cual desea asociar: ";
        cin >> idPet;
        PropietariosXMascotas objet1(mapPropietario[idProp], mapMascota[idPet], contId++);
        propietariosXMascotas.push_back(objet1);
    }
}

void Directorio::asociarMascotaPropietarios(){                          //Funcion que permite hacer una relacion de asignacion entre mascota y propietarios
    double idPet = 0, idProp = 0;                                       //y las envia al vector propietariosXMascotas
    int cantidadPropietarios = 0;
    cout << "Ingrese el numero de identificacion de la mascota: ";
    cin >> idPet;
    cout << "Ingrese la cantidad de propietarios que desea asociar con esta mascota: ";
    cin >> cantidadPropietarios;
    for( int i = 0; i < cantidadPropietarios; i++ ){
        cout << "Ingrese el numero de identificacion del propietario que se va asociar con esta mascota: ";
        cin >> idProp;
        PropietariosXMascotas objet1(mapPropietario[idProp], mapMascota[idPet], contId++);
        propietariosXMascotas.push_back(objet1);
    }  
}

void Directorio::mostrarDirectorio(){                                   //Funcion que recorre el vector de propietariosXMascotas y muestra
    for(int i = 0; i < propietariosXMascotas.size(); i++){              //en pantalla los datos de los propietarios y las mascotas utilizando
        propietariosXMascotas[i].motrarDatosPropietariosXMascotas();    //la funcion mostrarDatosPropietariosXMascotas
    }
}

void Directorio::editarInfoPropietarioDMascota(){                       //Funcion que permite al usuario editar la informacion de un propietario en especifico
    double idPropietario = 0;                                           
    listarInfoPropietariosDMascota();
    cout << "Ingrese el numero de identificacion del propietario que desea editar: ";
    cin >> idPropietario;
    mapPropietario[idPropietario].editarPropietario();                  //Ingresa al mapa propietario con el ID del propietario y edita la informacion para despues guardarla en el mapa
}

void Directorio::eliminarPropietariosDMascota(){                        //Funcion que permite eliminar del vector propietariosXMascotas la asociacion entre un propietario
    double idVector = 0;                                                //y una mascota
    listarInfoPropietariosDMascota();
    cout << "Ingrese el id la asociacion que desea eliminar: ";
    cin >> idVector;
    for( int l = 0; l < propietariosXMascotas.size(); l++ ){            //Recorre el vector propietariosXMascotas evaluando en cada posicion
        if(propietariosXMascotas[l].getIdPropXMascotas() == idVector){  //que el ID, que marca las relaciones, ingresado por el usario coincida con el ID
            propietariosXMascotas.erase(propietariosXMascotas.begin() + l); //que sirve como clave en el vector y ,a traves de la funcion erase, elimina esa posicion 
        }
    }
}

void Directorio::listarInfoPropietariosDMascota(){                  //Funcion que muestra en pantalla la informacion de los propietarios
    double idPet = 0;                                               //asociados a una mascota determinada
    int opcion = 0;
    cout << "Ingrese el numero de identificacion de la mascota: ";
    cin >> idPet;
    
    for(int l = 0; l < propietariosXMascotas.size(); l++){          //Recorre el vector de las asociones evaluando el ID de la mascota para mostrar
        if(propietariosXMascotas[l].getMascota().getMascotaID() == idPet){  //la informacion de los propietarios asociados
            propietariosXMascotas[l].motrarDatosPropietariosXMascotas();
        }
    }
}

void Directorio::listarInfoMascotasDPropietario(){                  //Funcion que muestra en pantalla la informacion de las mascotas
    double idProp = 0;                                              //asociadas a un propietario determinado
    int opcion = 0;
    cout << "Ingrese el numero de identificacion del propietario: ";
    cin >> idProp;
    
    for(int l = 0; l < propietariosXMascotas.size(); l++){          //Recorre el vector de las asociones evaluando el ID del propietario para mostrar
        if(propietariosXMascotas[l].getPropietario().getPropietarioID() == idProp){     //la informacion de los propietarios asociados
            propietariosXMascotas[l].motrarDatosPropietariosXMascotas();
        }
    }
}

void Directorio::cambiarStatusMascota(){                            //Funcion que permite modificar el estado de una mascota
    int idPet = 0;                                                  //utilizando como clave el ID de la mascota a encontrar
    cout << "Ingrese el numero de identificacion de la mascota: ";
    cin >> idPet;
    mapMascota[idPet].cambiarEstadoDefuncion();
}