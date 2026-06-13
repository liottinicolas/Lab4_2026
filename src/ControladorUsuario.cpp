#include "../include/ControladorUsuario.h"
#include "../include/Conductor.h"
#include "../include/ManejadorVehiculos.h"
#include "../include/Pasajero.h"
#include "../include/Vehiculo.h"

ControladorUsuario::ControladorUsuario() {
  mu = ManejadorUsuario::getInstancia();
}

// ==========================================
// CASO DE USO: Alta de Usuario
// ==========================================

bool ControladorUsuario::altaPasajero(string nickname, string nombre,
                                      string contrasena, string email,
                                      string ci) {
  // instancia ya está en el controlador
  // 1 existe usuario
  bool agregado = !mu->existe(nickname);
  if (agregado) {
    // 2 si no existe, agrego pasajero
    Usuario *pasajero_nuevo =
        new Pasajero(nickname, nombre, contrasena, email, ci);
    // 3 agrego el pasajero al manejador
    mu->agregarUsuario(pasajero_nuevo);
    return agregado;
  }
  return agregado;
}

bool ControladorUsuario::altaConductor(string nickname, string nombre,
                                       string contrasena, string email,
                                       set<TipoLibreta> libretas) {
  // instancia ya está en el controlador
  // 1 existe usuario
  bool agregado = !mu->existe(nickname);
  if (agregado) {
    // 2 si no existe, agrego pasajero
    Usuario *usuario_nuevo =
        new Conductor(nickname, nombre, contrasena, email, libretas);
    // 3 agrego el pasajero al manejador
    mu->agregarUsuario(usuario_nuevo);
    return agregado;
  }
  return agregado;
}

int ControladorUsuario::registrarVehiculo(string nickname, string matricula,
                                          int capacidad, string marca,
                                          string modelo, TipoVehiculo tipo) {
  // 1  instancio el manejador de vehiculos y verifico que existe
  ManejadorVehiculos *mv = ManejadorVehiculos::getInstancia();
  if (mv->existe(matricula)) {
    return -1;
  }
  // 2 busco el condcutor en la instancia del manejador y verifico que existe
  Conductor *c = dynamic_cast<Conductor *>(mu->find(nickname));
  if (c == nullptr) {
    return -3;
  }

  // 3 obtengo las libretas del conductor y verifico que tiene la libreta
  // correspondiente
  //  Esta parte faltó en el diagrama
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

  // 4 creo el vehiculo
  Vehiculo *v = new Vehiculo(matricula, capacidad, marca, modelo, tipo);
  // 5 lo vinculo al conductor (falto en el diagrama)
  v->setConductor(c);
  c->agregarVehiculo(v);
  // 6 lo agrego al manejador de vehiculos
  mv->agregarVehiculo(v);

  return 0;
}

// ==========================================
// CASO DE USO: Generar Reserva
// ==========================================

std::set<string> ControladorUsuario::listarPasajeros() {
  // Manejador en la instancia controlador
  std::set<string> pasajeros;
  // 1 obtengo el listado de usuarios
  std::map<std::string, Usuario *> usuarios = mu->obtenerUsuarios();
  // 2 por cada usuario verifico que sea pasajero y lo agrego al set de string
  for (auto const &par : usuarios) {
    // 2.1 verifico que sea pasajero.
    Pasajero *p = dynamic_cast<Pasajero *>(par.second);
    if (p != nullptr) {
      pasajeros.insert(p->getNickname());
    }
  }
  return pasajeros;
}

// ==========================================
// CASO DE USO: Calificar Usuario
// ==========================================

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
