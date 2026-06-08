#include "../include/ControladorUsuario.h"
#include "../include/Conductor.h"
#include "../include/ManejadorVehiculos.h"
#include "../include/Pasajero.h"
#include "../include/Vehiculo.h"


ControladorUsuario *ControladorUsuario::instancia = nullptr;

ControladorUsuario::ControladorUsuario() {
  mu = ManejadorUsuario::getInstancia();
}

ControladorUsuario *ControladorUsuario::getInstancia() {
  if (instancia == nullptr) {
    instancia = new ControladorUsuario();
  }
  return instancia;
}

bool ControladorUsuario::altaPasajero(string nickname, string nombre,
                                      string contrasena, string email,
                                      string ci) {
  bool agregado = !mu->existe(nickname);
  if (agregado) {
    Usuario *pasajero_nuevo =
        new Pasajero(nickname, nombre, contrasena, email, ci);
    mu->agregarUsuario(pasajero_nuevo);
    return !agregado;
  }
  return agregado;
}

bool ControladorUsuario::altaConductor(string nickname, string nombre,
                                       string contrasena, string email,
                                       set<TipoLibreta> libretas) {
  bool agregado = !mu->existe(nickname);
  if (agregado) {
    Usuario *usuario_nuevo =
        new Conductor(nickname, nombre, contrasena, email, libretas);
    mu->agregarUsuario(usuario_nuevo);
    return !agregado;
  }
  return agregado;
}

std::set<DTUsuario> ControladorUsuario::listarUsuarios() {
  std::set<DTUsuario> lista;
  ManejadorUsuario *mu = ManejadorUsuario::getInstancia();

  // 1: colU := obtenerUsuarios()
  std::map<std::string, Usuario *> usuarios = mu->obtenerUsuarios();

  // 2*: [foreach] u := next()
  for (auto const &par : usuarios) {
    Usuario *u = par.second;

    // 2.1*: dtu := getDTUsuario()
    lista.insert(u->getDTUsuario());
  }

  return lista;
}

// IA ARREGLAR TODO
int ControladorUsuario::registrarVehiculo(string nickname, string matricula,
                                          int capacidad, string marca,
                                          string modelo, TipoVehiculo tipo) {

  // 1 obtengo la instancia  del manejador
  ManejadorVehiculos *mve = ManejadorVehiculos::getInstancia();
  if (mve->existe(matricula)) {
    return -1;
  }

  Conductor *c = dynamic_cast<Conductor *>(mu->find(nickname));
  if (c == nullptr) {
    return -3;
  }

  std::set<TipoLibreta> libretas = c->getLibretas();
  bool tieneLibreta = false;
  if (tipo == TipoVehiculo::Auto) {
    if (libretas.count(TipoLibreta::AutoProfesional) > 0 ||
        libretas.count(TipoLibreta::AutoAmateur) > 0) {
      tieneLibreta = true;
    }
  } else if (tipo == TipoVehiculo::Moto) {
    if (libretas.count(TipoLibreta::MotoProfesional) > 0 ||
        libretas.count(TipoLibreta::MotoAmateur) > 0) {
      tieneLibreta = true;
    }
  }

  if (!tieneLibreta) {
    return -2;
  }

  Vehiculo *v = new Vehiculo(matricula, capacidad, marca, modelo, tipo);
  v->setConductor(c);
  c->agregarVehiculo(v);
  mve->agregarVehiculo(v);

  return 0;
}

void ControladorUsuario::listarVehiculosConductor() {
  // Dummy implementation to satisfy compiler/linker
}

std::set<string> ControladorUsuario::listarPasajeros() {
  std::set<string> pasajeros;
  std::map<std::string, Usuario *> usuarios = mu->obtenerUsuarios();
  for (auto const &par : usuarios) {
    Pasajero *p = dynamic_cast<Pasajero *>(par.second);
    if (p != nullptr) {
      pasajeros.insert(p->getNickname());
    }
  }
  return pasajeros;
}