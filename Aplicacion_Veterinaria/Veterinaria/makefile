all: compilar
compilar: mascota propietario propietariosxMascotas directorio main
	g++ -o Salida Mascota.o Propietario.o PropietariosxMascotas.o Directorio.o Main.o
mascota: Mascota.cpp Mascota.h 
	g++ -c Mascota.cpp
propietario: Propietario.cpp Propietario.h
	g++ -c Propietario.cpp
propietariosxMascotas: PropietariosxMascotas.cpp Mascota.h Propietario.h
	g++ -c PropietariosxMascotas.cpp
directorio: Directorio.cpp Directorio.h
	g++ -c Directorio.cpp
main: Main.cpp Directorio.h
	g++ -c Main.cpp
clean:
	@echo "Cleaning Compilation..."
	del *.o