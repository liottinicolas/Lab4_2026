#ifndef MANEJADORVIAJE_H
#define MANEJADORVIAJE_H

#include <map>
#include "Viaje.h"

class ManejadorViaje {
private:
    static ManejadorViaje* instancia;
    
    std::map<int, Viaje*> viajes;
    
    ManejadorViaje();

public:
    static ManejadorViaje* getInstance();
    
    std::map<int, Viaje*> obtenerViajes();
    
    void agregarViaje(Viaje* v); 
};

#endif