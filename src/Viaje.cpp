#include "../include/Viaje.h"
#include "../include/Pasajero.h"
#include "../include/Vehiculo.h"

Viaje::Viaje(int codigo, DTFecha fecha, std::string origen, std::string destino,
             int asientosPublicados, float precio) {
  this->codigo = codigo;
  this->fecha = fecha;
  this->origen = origen;
  this->destino = destino;
  this->asientosPublicados = asientosPublicados;
  this->precio = precio;
}

Viaje::~Viaje() {
  for (Reserva *r : this->reservas) {
    delete r;
  }
  reservas.clear();
}

// Getters
int Viaje::getCodigo() { return this->codigo; }

DTFecha Viaje::getFecha() { return this->fecha; }

std::string Viaje::getOrigen() { return this->origen; }

std::string Viaje::getDestino() { return this->destino; }

int Viaje::getAsientosPublicados() { return this->asientosPublicados; }

float Viaje::getPrecio() { return this->precio; }

Vehiculo *Viaje::getVehiculo() { return this->vehiculo; }

std::vector<Reserva *> Viaje::getReservas() { return this->reservas; }

// Setters
void Viaje::setCodigo(int codigo) { this->codigo = codigo; }

void Viaje::setFecha(DTFecha fecha) { this->fecha = fecha; }

void Viaje::setOrigen(std::string origen) { this->origen = origen; }

void Viaje::setDestino(std::string destino) { this->destino = destino; }

void Viaje::setAsientosPublicados(int asientosPublicados) {
  this->asientosPublicados = asientosPublicados;
}

void Viaje::setPrecio(float precio) { this->precio = precio; }

void Viaje::setVehiculo(Vehiculo *v) { this->vehiculo = v; }

std::string Viaje::getNicknameConductor() {
  // 2.2.1.1: nickConductor := getNickname()
  return this->vehiculo->getNicknameConductor();
}

DTListarViaje Viaje::getDTListarViaje(std::string nickConductor) {
  return DTListarViaje(this->codigo, this->fecha, this->origen, this->destino,
                       nickConductor);
}

bool Viaje::verificarViaje(DTFecha fecha, std::string origen,
                           std::string destino, int asientos) {
  // verifico si el viaje cumple con los requisitos
  if (!(this->fecha == fecha && this->origen == origen &&
        this->destino == destino)) {
    return false;
  }

  // 1.2*.1* forach reservas del  viaje
  int totalReservados = 0;
  for (std::vector<Reserva *>::iterator it = this->reservas.begin();
       it != this->reservas.end(); ++it) {
    // 1.2*.1* obtengo los asientos reservados de cada reserva
    totalReservados += (*it)->getAsientosReservados();
  }

  return this->asientosPublicados >= (totalReservados + asientos);
}

bool Viaje::validarViaje(std::string nickname, int asientos) {
  // 2.1 recorre las reservas para ver si el usuario ya reservó en este viaje
  for (std::vector<Reserva *>::iterator it = this->reservas.begin();
       it != this->reservas.end(); ++it) {
    // 2.2 valida si el usuario ya reservó en este viaje
    if ((*it)->getPasajero()->getNickname() == nickname) {
      return false;
    }
  }
  // 2.3 Si no reservó, calcula el total de asientos disponibles
  int totalReservados = 0;
  for (std::vector<Reserva *>::iterator it = this->reservas.begin();
       it != this->reservas.end(); ++it) {
    totalReservados += (*it)->getAsientosReservados();
  }

  return (this->asientosPublicados - totalReservados) >= asientos;
}

void Viaje::agregarReserva(Reserva *r) {
  if (r != nullptr) {
    this->reservas.push_back(r);
  }
}

std::vector<DTUsuario> Viaje::listaUsuarios(std::string nicknameActor) {
  std::vector<DTUsuario> us;
  if (nicknameActor != this->vehiculo->getNicknameConductor()) {
    DTUsuario c = this->vehiculo->ObtenerDTUsCond();
    us.push_back(c);
  }
  // 2.1 foreach reserva
  if (!this->reservas.empty()) {
    for (Reserva *r : this->reservas) {
      if (nicknameActor != r->getPasajero()->getNickname()) {
        // 2.2 obtener usuario
        DTUsuario u = r->getPasajero()->getDTUsuario();
        us.push_back(u);
      }
    }
  }
  return us;
}

bool Viaje::calificarUsViaje(Usuario &calificador, Usuario &calificado,
                             int calificacion) {
  bool a = this->vehiculo->EsDueño(calificador.getNickname());
  if (a) {
    for (Reserva *r : this->reservas) {
      if (r->getPasajero()->getNickname() == calificado.getNickname()) {
        return r->calificarUsRes(calificador, calificado, calificacion);
      }
    }
  } else {
    for (Reserva *r : this->reservas) {
      if (r->getPasajero()->getNickname() == calificador.getNickname()) {
        return r->calificarUsRes(calificador, calificado, calificacion);
      }
    }
  }
  return false;
}

DTConsultaViaje Viaje::datosViaje() {
  // 1.3.1.1 obtengo los datos del vehiculo y el chofer
  DTConsultaViaje dtv =
      this->vehiculo->datosVehiculoYChofer(this->codigo, this->precio);
  // 1.3.1.2 obtengo los datos del vehiculo y el chofer
  return dtv;
}

DTDetalleViaje Viaje::getDTDetalleViaje() {
  Vehiculo *veh = getVehiculo();

  DTDetalleVehiculo dtv = veh->getDTDetalleVehiculo();

  std::vector<DTDetalleReserva> dtrList;
  for (Reserva *r : this->reservas) {
    dtrList.push_back(r->getDTDetalleReserva());
  }

  return DTDetalleViaje(this->codigo, this->fecha, this->origen, this->destino,
                        this->asientosPublicados, this->precio, dtv, dtrList);
}