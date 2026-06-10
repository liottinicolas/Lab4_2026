#include "../include/Usuario.h"
#include "../include/Reserva.h"
#include "../include/Viaje.h"

Usuario::Usuario(std::string nickname, std::string nombre,
                 std::string contrasena, std::string email) {
  this->nickname = nickname;
  this->nombre = nombre;
  this->contrasena = contrasena;
  this->email = email;
}

std::string Usuario::getNickname() { return this->nickname; }
std::string Usuario::getNombre() { return this->nombre; }
std::string Usuario::getContrasena() { return this->contrasena; }
std::string Usuario::getEmail() { return this->email; }

void Usuario::setNickname(std::string nickname) { this->nickname = nickname; }
void Usuario::setNombre(std::string nombre) { this->nombre = nombre; }
void Usuario::setContrasena(std::string contrasena) {
  this->contrasena = contrasena;
}
void Usuario::setEmail(std::string email) { this->email = email; }

Usuario::~Usuario() {}

DTUsuario Usuario::getDTUsuario() {
  return DTUsuario(this->nickname, this->nombre);
}

bool Usuario::ExisteCal(Usuario &u, Reserva &r) {
  if (!calificaciones.empty()) {
    auto it = calificaciones.begin();
    bool a = false;
    while (!a && it != calificaciones.end()) {
      if ((it->getCalificado()->getNickname() == u.getNickname()) &&
          (r.getViaje()->getCodigo() ==
           it->getReserva()->getViaje()->getCodigo())) {
        a = true;
      } else {
        it++;
      }
    }
    return a;
  } else {
    return false;
  }
}

bool Usuario::calificarUs(Usuario &calificado, Reserva &r, int calificacion,
                          DTFecha fechaSistema) {
  Calificacion cal(fechaSistema, calificacion, calificado, *this, r);
  this->calificaciones.push_back(cal);
  return true;
}

float Usuario::promedioCalificaciones() {
  if (this->calificaciones.empty()) {
    return 0.0f;
  }
  float sum = 0.0f;
  for (Calificacion &c : this->calificaciones) {
    sum += c.getPuntaje();
  }
  return sum / this->calificaciones.size();
}