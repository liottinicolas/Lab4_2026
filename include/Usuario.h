#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <vector>
#include "DTUsuario.h"
#include "DTListarViaje.h"

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

    void setNickname(std::string nickname);
    void setNombre(std::string nombre);
    void setContrasena(std::string contrasena);
    void setEmail(std::string email);

    DTUsuario getDTUsuario();
    virtual std::vector<DTListarViaje> obtenerDTListarViajes() = 0;

    virtual ~Usuario();
};

#endif
