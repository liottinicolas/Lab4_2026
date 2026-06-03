#ifndef RESERVA_H
#define RESERVA_H

#include "DTFecha.h"
#include "DTListarViaje.h"

class Viaje;

class Reserva {
private:
    int asientosReservados;
    DTFecha fecha;

    // listarViaje
    Viaje* viaje;

public:
    Reserva(int asientosReservados, DTFecha fecha);
    ~Reserva();

    int getAsientosReservados();
    void setAsientosReservados(int asientosReservados);

    DTFecha getFecha();
    void setFecha(DTFecha fecha);

    //listarViaje
    void setViaje(Viaje* v);
    Viaje* getViaje();
    DTListarViaje getDTListarViaje();
};

#endif
