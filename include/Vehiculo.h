#ifndef VEHICULO_H
#define VEHICULO_H

#include "TipoVehiculo.h"
#include <string>

class Conductor; 
class Viaje;

class Vehiculo {
private:
    std::string matricula;
    int capacidad;
    std::string marca;
    std::string modelo;
    TipoVehiculo tipo;

    // listarViajes
    Conductor* conductor;
    std::vector<Viaje*> viajes;

public:
    Vehiculo(std::string matricula, int capacidad, std::string marca, std::string modelo, TipoVehiculo tipo);
    ~Vehiculo();
    
    // Getters
    std::string getMatricula();
    int getCapacidad();
    std::string getMarca();
    std::string getModelo();
    TipoVehiculo getTipo();
    std::string getNicknameConductor();

    // Setters
    void setConductor(Conductor* c);
    
    std::vector<DTListarViaje> obtenerDTListarViajes(std::string nickname);
    bool EsDueño(std::string nickname);
    DTUsuario ObtenerDTUsCond(); 
};

#endif
