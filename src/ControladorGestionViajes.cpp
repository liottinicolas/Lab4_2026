#include "../include/ControladorGestionViajes.h"
#include "../include/ManejadorUsuario.h"
#include "../include/ManejadorViaje.h"
#include "../include/Usuario.h"
#include "../include/Viaje.h"

ControladorGestionViajes *ControladorGestionViajes::instancia = nullptr;

ControladorGestionViajes::ControladorGestionViajes() {
  mu = ManejadorUsuario::getInstancia();
  mv = ManejadorViaje::getInstance();
}

ControladorGestionViajes *ControladorGestionViajes::getInstancia() {
  if (instancia == nullptr) {
    instancia = new ControladorGestionViajes();
  }
  return instancia;
}

std::vector<DTListarViaje>
ControladorGestionViajes::listarViajes(std::string nickname) {
  // 1: u := find(nickname)
  Usuario *u = mu->find(nickname);

  if (u != nullptr) {
    // 2: dtViajes := obtenerDTListarViajes()
    return u->obtenerDTListarViajes();
  }
  return std::vector<DTListarViaje>();
}

std::vector<DTListarViaje> ControladorGestionViajes::listarViajes() {
  std::vector<DTListarViaje> lista;

  std::map<int, Viaje *> todosLosViajes = mv->obtenerViajes();

  for (auto const &par : todosLosViajes) {
    Viaje *v = par.second;

    std::string nickConductor = v->getNicknameConductor();

    lista.push_back(v->getDTListarViaje(nickConductor));
  }

  return lista;
}

std::vector<DTConsultaViaje>
ControladorGestionViajes::consultarViajes(DTFecha fecha, std::string origen,
                                          std::string destino, int asientos) {
  std::vector<DTConsultaViaje> resultado;
  // 1 TODO TERMINAR.
  resultado = mv->consultarViajes(fecha, origen, destino, asientos);
  return resultado;
}

std::vector<DTUsuario> ControladorGestionViajes::listarUsuariosViaje(int codigo){
  Viaje vi = mv->find(codigo);                     // 1. Busca el viaje en el manejador
  return vi.listaUsuarios();                       // 2. Devuelve el set de los usuarios del viaje
}