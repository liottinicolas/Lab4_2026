#include "../include/ControladorUsuario.h"
#include "../include/Conductor.h"
#include "../include/Pasajero.h"

ControladorUsuario::ControladorUsuario() {
    mu = ManejadorUsuario::getInstance();
}

std::vector<DTUsuario> ControladorUsuario::listarUsuarios() {
    std::vector<DTUsuario> lista;
    ManejadorUsuario* mu = ManejadorUsuario::getInstancia(); 
    
    // 1: colU := obtenerUsuarios()
    std::map<std::string, Usuario*> usuarios = mu->obtenerUsuarios();
    
    // 2*: [foreach] u := next()
    for (auto const& par : usuarios) {
        Usuario* u = par.second;
        
        // 2.1*: dtu := getDTUsuario()
        lista.push_back(u->getDTUsuario());
    }
    
    return lista;
}

// listarVehiculos usa un setter, que se necesita llenar en registrarVehiculo():
//Conductor* c = (Conductor*) mu->find(nickname);
//Vehiculo* v = new Vehiculo(matricula, capacidad, marca, modelo, tipo);
//v->setConductor(c);