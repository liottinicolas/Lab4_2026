#include "../include/DTUsuario.h"

DTUsuario::DTUsuario(std::string nickname, std::string nombre, TipoUsuario tipo) {
  this->nickname = nickname;
  this->nombre = nombre;
  this->tipo = tipo;
}

std::string DTUsuario::getNickname() const { return nickname; }
std::string DTUsuario::getNombre() const { return nombre; }
TipoUsuario DTUsuario::getTipo() const { return tipo; }
bool DTUsuario::operator<(const DTUsuario &other) const {
  if (this->tipo != other.tipo) {
    return this->tipo < other.tipo;
  }
  return this->nickname < other.nickname;
}

std::ostream &operator<<(std::ostream &os, DTUsuario u) {
  os << "> Nickname: " << u.getNickname() << ", Nombre: " << u.getNombre();
  return os;
}
