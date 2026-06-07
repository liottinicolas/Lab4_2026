#include "../include/ControladorGestionViajes.h"
#include "../include/Conductor.h"
#include "../include/ControladorFechaActual.h"
#include "../include/ManejadorUsuario.h"
#include "../include/ManejadorVehiculos.h"
#include "../include/ManejadorViaje.h"
#include "../include/Pasajero.h"
#include "../include/Reserva.h"
#include "../include/Usuario.h"
#include "../include/Vehiculo.h"
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
// CASO DE USO ALTA VIAJE
std::set<DTVehiculosConductor>
ControladorGestionViajes::listarVehiculosConductor(std::string nickname) {
  // 1. ya se instanció con el controlador la instancia de manejador
  // 2. Busca conductor
  Conductor *c = dynamic_cast<Conductor *>(mu->find(nickname));
  // 3 Retorna la lista de listaVehiculos del conductor
  return c->listarVehiculos();
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
  this->codigoActor = codigo;   // 0. Guarda en memoria el codigo de viaje
  Viaje *vi = mv->find(codigo); // 1. Busca el viaje en el manejador
  return vi->listaUsuarios(
      this->nicknameActor); // 2. Devuelve el set de los usuarios del viaje
}

bool ControladorGestionViajes::calificarUsuario(std::string nicknameCalificado,
                                                int calificacion) {
  Viaje *vi = mv->find(codigoActor);    // 1. Busca la instancia del viaje
  Usuario *u = mu->find(nicknameActor); // 2. Busca la instancia del calificador
  Usuario *uc =
      mu->find(nicknameCalificado); // 3. Busca la instancia del calificado
  return vi->calificarUsViaje(*u, *uc, calificacion); // 4. Califica el usuario
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

bool ControladorGestionViajes::altaViaje(std::string matricula, DTFecha fecha,
                                         std::string origen,
                                         std::string destino, int asientos,
                                         float precio) {
  // 1 obtengo la instancia
  ManejadorVehiculos *mve = ManejadorVehiculos::getInstancia();
  // 2 obtengo el vehiculo
  Vehiculo *v = mve->find(matricula);

  int capacidad = v->getCapacidad();
  // 3 si asientos es mayor que la capacidad retorno false
  if (asientos > capacidad) {
    return false;
  }

  // 4 verifico si hay viajes con la fecha indicada
  // si hay viajes con la misma fecha retorno false
  bool hayViajesFecha = v->hayViajesConductor(fecha);
  if (hayViajesFecha) {
    return false;
  }

  // 5. Crea la instancia de Viaje (en el manejador)
  Viaje *cvi = mv->crearViaje(v, fecha, origen, destino, asientos, precio);
  v->agregarViaje(cvi);
  return true;
}
