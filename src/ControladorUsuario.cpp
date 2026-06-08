#include "../include/ControladorUsuario.h"
#include "../include/Conductor.h"
#include "../include/Pasajero.h"
#include "../include/ManejadorVehiculos.h"
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

bool ControladorUsuario::altaPasajero(
        string nickname,
        string nombre,
        string contrasena,
        string email,
        string ci
){
    bool agregado = !mu->existe(nickname);
    if(agregado){
        Usuario* pasajero_nuevo = new Pasajero(nickname,nombre,contrasena,email,ci);
        mu->agregarUsuario(pasajero_nuevo);
        return !agregado;
    }
    return agregado;
}

bool ControladorUsuario::altaConductor(
        string nickname,
        string nombre,
        string contrasena,
        string email,
        set<TipoLibreta> libretas
){
    bool agregado = !mu->existe(nickname);
    if(agregado){
        Usuario* usuario_nuevo = new Conductor(nickname,nombre,contrasena,email,libretas);
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


int ControladorUsuario::registrarVehiculo(
    string nickname,
    string matricula,
    int capacidad,
    string marca,
    string modelo,
    TipoVehiculo tipo
) {
    ManejadorVehiculos* mv = ManejadorVehiculos::getInstancia();
    if (mv->existe(matricula)) {
        return -1;
    }
    Conductor* c = (Conductor*) mu->find(nickname);
    Vehiculo* v = new Vehiculo(
        matricula,
        capacidad,
        marca,
        modelo,
        tipo
    );
    v->setConductor(c);
    c->agregarVehiculo(v);
    mv->agregarVehiculo(v);

    return 0;
}

std::set<std::string> ControladorUsuario::listarPasajeros() {
    std::set<std::string> lista;
    std::map<std::string, Usuario*> usuarios = mu->obtenerUsuarios();
    for (auto const& par : usuarios) {
        Usuario* u = par.second;
        if (dynamic_cast<Pasajero*>(u) != nullptr) {
            lista.insert(u->getNickname());
        }
    }
    return lista;
}
// listarVehiculos usa un setter, que se necesita llenar en registrarVehiculo():
// Conductor* c = (Conductor*) mu->find(nickname);
// Vehiculo* v = new Vehiculo(matricula, capacidad, marca, modelo, tipo);
// v->setConductor(c);