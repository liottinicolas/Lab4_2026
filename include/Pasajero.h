#ifndef PASAJERO_H
#define PASAJERO_H

#include "Usuario.h"
#include <string>

#include "DTListarViaje.h"
#include <vector>

class Reserva;

class Pasajero : public Usuario {
private:
    std::string ci;

    // listarViajes
    std::vector<Reserva*> reservas;
public:
    Pasajero(std::string nickname, std::string nombre, std::string contrasena, std::string email, std::string documento);
    ~Pasajero();

    // listar Viajes
    void agregarReserva(Reserva* r);
    void removerReserva(Reserva* r);
    std::vector<DTListarViaje> obtenerDTListarViajes() override;

    std::string getCi();
    void setCi(std::string ci);

    std::vector<Reserva*> getReservas();
    void setReservas(std::vector<Reserva*> reservas);
};

#endif
