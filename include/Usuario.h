#ifndef USUARIO_H
#define USUARIO_H

#include <string>
#include <vector>
#include "DTUsuario.h"
#include "DTListarViaje.h"
#include "Calificacion.h"

class Usuario {
protected:
    std::string nickname;
    std::string nombre;
    std::string contrasena;
    std::string email;
    std::vector<Calificacion> califRealizadas;
    std::vector<Calificacion> califRecibidas

public:
    Usuario(std::string nickname, std::string nombre, std::string contrasena, std::string email);
    
    float promedioCalificaciones();
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
    bool ExisteCal(Usuario& calificado, Reserva& r);
    bool calificarUs(Usuario& calificado, Reserva& r, int calificacion, DTFecha fechaSistema);
    virtual ~Usuario();
};

#endif
