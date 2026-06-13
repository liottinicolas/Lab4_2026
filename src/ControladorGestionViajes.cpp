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
#include <algorithm>

ControladorGestionViajes::ControladorGestionViajes() {
  mu = ManejadorUsuario::getInstancia();
  mv = ManejadorViaje::getInstance();
  codigoActor = -1;
  nicknameActor = "";
}
// ==========================================
// CASO DE USO: Alta de Viaje
// ==========================================

std::set<DTVehiculosConductor>
ControladorGestionViajes::listarVehiculosConductor(std::string nickname) {
  // 1. ya se instanció con el controlador la instancia de manejador
  // 2. Busca conductor
  Conductor *c = dynamic_cast<Conductor *>(mu->find(nickname));
  // 3 Retorna la lista de listaVehiculos del conductor
  return c->listarVehiculos();
}

bool ControladorGestionViajes::altaViaje(std::string matricula, DTFecha fecha,
                                         std::string origen,
                                         std::string destino, int asientos,
                                         float precio) {
  // 1 obtengo la instancia
  ManejadorVehiculos *mve = ManejadorVehiculos::getInstancia();
  // 2 obtengo el vehiculo
  Vehiculo *v = mve->find(matricula);
  // 3 obtengo la capacidad
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
  // 5. la instancia de Viaje en el manejador ( mv->) ya estaba instanciada
  // 6. Crea la instancia de Viaje (en el manejador)
  Viaje *cvi = mv->crearViaje(v, fecha, origen, destino, asientos, precio);
  // 7 agrega el viaje al vehiculo
  v->agregarViaje(cvi);
  return true;
}

// ==========================================
// CASO DE USO: Generar Reserva
// ==========================================

std::vector<DTConsultaViaje>
ControladorGestionViajes::consultarViajes(DTFecha fecha, std::string origen,
                                          std::string destino, int asientos) {
  std::vector<DTConsultaViaje> resultado;
  // instancia mv ya en memoria
  // 1. consulta viajes que retorna un vector de DTConsultaviajes
  resultado = mv->consultarViajes(fecha, origen, destino, asientos);
  return resultado;
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
  // la instancia del manejador usuario ya la tiene.
  Usuario *u = mu->find(nickname);
  Pasajero *p = dynamic_cast<Pasajero *>(u);
  if (p == nullptr) {
    return false;
  }

  //  Obtiene la fecha actual del sistema (no estaba en el DSS)
  ControladorFechaActual *cfa = ControladorFechaActual::getInstance();
  DTFecha fechaActual = cfa->getFecha();

  //  Validar que la fecha de la Reserva no sea posterior al Viaje que
  //  referencia (tampoco en el dss)
  DTFecha fechaViaje = vi->getFecha();
  if (fechaActual.getAnio() > fechaViaje.getAnio()) {
    return false;
  } else if (fechaActual.getAnio() == fechaViaje.getAnio()) {
    if (fechaActual.getMes() > fechaViaje.getMes()) {
      return false;
    } else if (fechaActual.getMes() == fechaViaje.getMes()) {
      if (fechaActual.getDia() > fechaViaje.getDia()) {
        return false;
      }
    }
  }

  // 4 Crea la Reserva
  Reserva *r = new Reserva(asientos, fechaActual);

  // vincula la reserva al viaje y al pasajero
  r->setViaje(vi);
  r->setPasajero(p);
  vi->agregarReserva(r);
  p->agregarReserva(r);

  return true;
}

// ==========================================
// CASO DE USO: Calificar Usuario
// ==========================================

std::set<DTListarViaje>
ControladorGestionViajes::listarViajes(std::string nickname) {
  // 0: guardar el nickname en memoria
  this->nicknameActor = nickname;

  // 1: u := find(nickname)
  Usuario *u = mu->find(nickname);

  // 2: dtViajes := obtenerDTListarViajes()
  std::vector<DTListarViaje> res = u->obtenerDTListarViajes();
  // ordeno por codigo de viaje descendente
  std::set<DTListarViaje> sortedSet(res.begin(), res.end());
  return sortedSet;
}

std::vector<DTUsuario>
ControladorGestionViajes::listarUsuariosViaje(int codigo) {
  // Se guarda en memoria el pasado codigo por parámetro
  this->codigoActor = codigo;
  Viaje *vi = mv->find(codigo); // 1.1 Busca el viaje en el manejador

  // 2 Devuelve el set de los usuarios del viaje
  return vi->listaUsuarios(this->nicknameActor);
}

bool ControladorGestionViajes::calificarUsuario(std::string nicknameCalificado,
                                                int calificacion) {
  if (codigoActor == -1 || nicknameActor == "") {
    return false;
  }
  Viaje *vi = mv->find(codigoActor);    // 1. Busca la instancia del viaje
  Usuario *u = mu->find(nicknameActor); // 2. Busca la instancia del calificador
  Usuario *uc =
      mu->find(nicknameCalificado); // 3. Busca la instancia del calificado
  if (vi == nullptr || u == nullptr || uc == nullptr) {
    this->nicknameActor = "";
    this->codigoActor = -1;
    return false;
  }
  bool ok =
      vi->calificarUsViaje(*u, *uc, calificacion); // 4. Califica el usuario
  this->nicknameActor = "";
  this->codigoActor = -1;
  return ok;
}

// ==========================================
// CASO DE USO: Eliminar Viaje
// ==========================================

std::set<DTListarViaje> ControladorGestionViajes::listarViajes() {
  std::set<DTListarViaje> lista;

  std::map<int, Viaje *> todosLosViajes = mv->obtenerViajes();

  for (auto const &par : todosLosViajes) {
    Viaje *v = par.second;

    std::string nickConductor = v->getNicknameConductor();

    lista.insert(v->getDTListarViaje(nickConductor));
  }

  return lista;
}

DTDetalleViaje ControladorGestionViajes::detalleViaje(int codigo) {
  this->codigoActor = codigo;
  Viaje *vi = mv->find(codigo);
  return vi->getDTDetalleViaje();
}

void ControladorGestionViajes::eliminarViaje() {
  Viaje *vi = mv->find(this->codigoActor);
  if (vi == nullptr) {
    return;
  }

  // 1. Remover el viaje de su vehiculo
  Vehiculo *ve = vi->getVehiculo();
  if (ve != nullptr) {
    ve->removerViaje(vi);
  }

  // 2. Remover cada reserva de su pasajero
  std::vector<Reserva *> res = vi->getReservas();
  for (Reserva *r : res) {
    Pasajero *p = r->getPasajero();
    if (p != nullptr) {
      p->removerReserva(r);
    }
  }

  // 3. Remover el viaje del manejador y borrarlo
  mv->removerViaje(this->codigoActor);
  delete vi;

  // 4. Limpiar el codigo recordado
  this->codigoActor = -1;
}

void ControladorGestionViajes::cancelarEliminarViaje() {
  this->codigoActor = -1;
}
