#ifndef VIAJE_H
#define VIAJE_H

#include "DTFecha.h"
#include "DTListarViaje.h"
#include "DTConsultaViaje.h"
#include <string>

class Vehiculo;

class Viaje {
private:
    int codigo;
    DTFecha fecha;
    std::string origen;
    std::string destino;
    int asientosPublicados;
    float precio;

    //listarViajes
    Vehiculo* vehiculo;

public:
    Viaje(int codigo, DTFecha fecha, std::string origen, std::string destino, int asientosPublicados, float precio);
    ~Viaje();

    // Getters
    int getCodigo();
    DTFecha getFecha();
    std::string getOrigen();
    std::string getDestino();
    int getAsientosPublicados();
    float getPrecio();
    Vehiculo* getVehiculo();

    // Setters
    void setCodigo(int codigo);
    void setFecha(DTFecha fecha);
    void setOrigen(std::string origen);
    void setDestino(std::string destino);
    void setAsientosPublicados(int asientosPublicados);
    void setPrecio(float precio);
    void setVehiculo(Vehiculo* v);

    std::string getNicknameConductor();
    DTListarViaje getDTListarViaje(std::string nickConductor);
    bool verificarViaje(DTFecha fecha, std::string origen, std::string destino, int asientos);
    DTConsultaViaje getDTConsultaViaje(int asientos); // Wait, we should check if getDTConsultaViaje needs a parameter or what it gets.
};

#endif
