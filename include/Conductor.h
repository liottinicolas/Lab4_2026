#ifndef CONDUCTOR_H
#define CONDUCTOR_H

#include "Usuario.h"
#include "TipoLibreta.h"
#include <set>

#include "DTListarViaje.h"
#include <vector>

class Vehiculo;

class Conductor : public Usuario {
private:
    std::set<TipoLibreta> libretas;

    // listarViajes
    std::vector<Vehiculo*> vehiculos;
public:
    Conductor(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::set<TipoLibreta> libs);
    ~Conductor();

    // listarViajes
    void agregarVehiculo(Vehiculo* v);
    std::vector<DTListarViaje> obtenerDTListarViajes() override;
};

#endif
