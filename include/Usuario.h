#ifndef USUARIO_H
#define USUARIO_H

#include <string>

class Usuario {
protected:
    std::string nickname;
    std::string nombre;
    std::string contrasena;
    std::string email;

public:
    Usuario(std::string nickname, std::string nombre, std::string contrasena, std::string email);
    std::string getNickname();
    std::string getNombre();
    std::string getContrasena();
    std::string getEmail();
    virtual ~Usuario();
};

#endif
