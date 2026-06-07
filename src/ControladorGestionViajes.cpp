#include "../include/ControladorGestionViajes.h"
#include "../include/ControladorFechaActual.h"
#include "../include/ManejadorUsuario.h"
#include "../include/ManejadorViaje.h"
#include "../include/Pasajero.h"
#include "../include/Reserva.h"
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
  // 0: guardar el nickname en memoria
  this->nicknameActor = nickname;

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

std::vector<DTUsuario>
ControladorGestionViajes::listarUsuariosViaje(int codigo) {
  this->codigoActor = codigo;  // 0. Guarda en memoria el codigo de viaje
  Viaje vi = mv->find(codigo); // 1. Busca el viaje en el manejador
  return vi.listaUsuarios(
      std::string this
          ->nicknameActor); // 2. Devuelve el set de los usuarios del viaje
}

bool ControladorGestionViajes::calificarUsuario(std::string nicknameCalificado,
                                                int calificacion) {
  Viaje vi = mv->find(codigoActor);    // 1. Busca la instancia del viaje
  Usuario u = mu->find(nicknameActor); // 2. Busca la instancia del calificador
  Usuario uc =
      mu->find(nicknameCalificado); // 3. Busca la instancia del calificado
  return vi.calificarUsViaje(
      u, uc, calificacion); // 4. Califica el usuario con las instancias si se
                            // dan las condiciones
}

bool ControladorGestionViajes::generarReserva(std::string nickname, int codigo,
                                              int asientos) {
  // 1. Busca el viaje en el manejador
  Viaje *vi = mv->find(codigo);
  if (vi == nullptr) {
    return false;
  }

  // 2. Valida las condiciones del viaje (si ya reservó y si hay lugar)
  bool viajeOk = vi->validarViaje(nickname, asientos);
  if (!viajeOk) {
    return false;
  }

  // 3. Si el viaje es válido, obtiene la instancia del Pasajero
  Usuario *u = mu->find(nickname);
  Pasajero *p = dynamic_cast<Pasajero *>(u);
  if (p == nullptr) {
    return false;
  }

  // 4. Obtiene la fecha actual del sistema y crea la Reserva
  ControladorFechaActual *cfa = ControladorFechaActual::getInstance();
  DTFecha fechaActual = cfa->getFecha();
  Reserva *r = new Reserva(asientos, fechaActual);

  // 5. Vincula los objetos
  r->setViaje(vi);
  r->setPasajero(p);
  vi->agregarReserva(r);
  p->agregarReserva(r);

  return true;
}
