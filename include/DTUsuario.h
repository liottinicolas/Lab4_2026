#ifndef DT_USUARIO_H
#define DT_USUARIO_H

#include <set>
#include <string>

class DTUsuario {
private:
  std::string nickname;
  std::string nombre;

public:
  DTUsuario(std::string nickname, std::string nombre);

  std::string getNickname() const;
  std::string getNombre() const;
  // operador para ordenar en los sets.
  bool operator<(const DTUsuario &other) const;
};

#endif
