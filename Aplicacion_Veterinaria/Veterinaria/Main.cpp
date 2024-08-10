#include "Directorio.h"

using std::cin;
using std::cout;
using std::string;

void menu(Directorio directorio)                    //Muestra en pantalla las opciones que el usuario puede seleccionar
{                                                   //en el directorio Pulguitas
    int opcion = 0; 
    do
    {
        cout << "======Bienvenidos al directorio de la Veterinaria Pulguitas======\n";
        cout << "1.  Agregar un nuevo propietario al directorio\n";
        cout << "2.  Agregar una nueva mascota al directorio\n";
        cout << "3.  Asociar propietarios a una mascota\n";
        cout << "4.  Asociar mascotas a un propietario\n";
        cout << "5.  Eliminar propietarios de una mascota\n";
        cout << "6.  Modificar informacion de los propietarios de una mascota\n";
        cout << "7.  Listar informacion de los propietarios de una mascota\n";
        cout << "8.  Listar informacion de las mascotas de un propietario\n";
        cout << "9.  Mostrar cantidad de propietarios registrados en el directorio\n";
        cout << "10. Listar informacion de las mascotas registradas\n";
        cout << "11. Listar informacion de los propietarios registrados\n";
        cout << "12. Cambiar status de vivo o muerto de una mascota\n";
        cout << "13. Mostrar directorio\n";
        cout << "0.  Salir \n";

        cin >> opcion;

        switch (opcion)                                     //Permite ingresar a cada funcion segun la opcion elegida
        {                                                   //por el usuario
        case 1:
            directorio.agregarPropietario();
            break;
        case 2:
            directorio.agregarMascota();
            break;
        case 3:
            directorio.asociarMascotaPropietarios();
            ;
            break;
        case 4:
            directorio.asociarPropietarioMascotas();
            ;
            break;
        case 5:
            directorio.eliminarPropietariosDMascota();
            break;
        case 6:
            directorio.editarInfoPropietarioDMascota();
            ;
            break;
        case 7: 
            directorio.listarInfoPropietariosDMascota();
            ;
            break;
        case 8:
            directorio.listarInfoMascotasDPropietario();
            ;
            break;
        case 9:
            directorio.cantidadPropietariosRegistrados();
            ;
            break;
        case 10:
            directorio.informacionMascotasRegistradas();
            ;
            break;
        case 11:
            directorio.informacionPropietariosRegistrados();
            ;
            break;
        case 12:
            directorio.cambiarStatusMascota();
            break;
        case 13:
            directorio.mostrarDirectorio();
        default:
            break;
        }
    } while (opcion != 0);
}

int main()
{
    Directorio directorio;                                      //Crea una clase de tipo directorio para enviarlo al menu e ingresar
    menu(directorio);                                           //a las funciones de Directorio
    return 0;
}