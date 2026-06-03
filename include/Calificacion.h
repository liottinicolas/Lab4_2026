#ifndef CALIFICACION_H
#define CALIFICACION_H

#include "DTFecha.h"

class Calificacion {
private:
    DTFecha fecha;
    int puntaje;

public:
    Calificacion(DTFecha fecha, int puntaje);
    ~Calificacion();

    DTFecha getFecha();
    int getPuntaje();

    void setFecha(DTFecha fecha);
    void setPuntaje(int puntaje);
};

#endif
