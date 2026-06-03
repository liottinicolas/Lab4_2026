#ifndef MANEJADORVIAJE_H
#define MANEJADORVIAJE_H

#include <map>
#include <vector>
#include "Viaje.h"
#include "DTConsultaViaje.h"
#include "DTFecha.h"

class ManejadorViaje {
private:
    static ManejadorViaje* instancia;
    
    std::map<int, Viaje*> viajes;
    
    ManejadorViaje();

public:
    static ManejadorViaje* getInstance();
    
    std::map<int, Viaje*> obtenerViajes();
    
    void agregarViaje(Viaje* v); 

    std::vector<DTConsultaViaje> consultarViajes(DTFecha fecha, std::string origen, std::string destino, int asientos);
};

#endif