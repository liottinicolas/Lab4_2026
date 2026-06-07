#include "../include/ManejadorViaje.h"
#include "../include/Vehiculo.h"

ManejadorViaje *ManejadorViaje::instancia = nullptr;

ManejadorViaje::ManejadorViaje() {
  this->ultimoViaje = 0;
}

ManejadorViaje *ManejadorViaje::getInstance() {
  if (instancia == nullptr) {
    instancia = new ManejadorViaje();
  }
  return instancia;
}

std::map<int, Viaje *> ManejadorViaje::obtenerViajes() { return this->viajes; }

void ManejadorViaje::agregarViaje(Viaje *v) {
  if (v != nullptr) {
    this->viajes[v->getCodigo()] = v;
  }
}

Viaje* ManejadorViaje::find(int codigo) {
  auto it = this->viajes.find(codigo);
  if (it != this->viajes.end()) {
    return it->second;
  }
  return nullptr;
}

std::vector<DTConsultaViaje>
ManejadorViaje::consultarViajes(DTFecha fecha, std::string origen,
                                std::string destino, int asientos) {
  std::vector<DTConsultaViaje> resultado;
  // 1.1 foreach viaje
  for (auto const &par : viajes) {
    Viaje *v = par.second;
    // 1.2
    bool ok = v->verificarViaje(fecha, origen, destino, asientos);
    if (ok) {
      DTConsultaViaje datosViaje = v->datosViaje();
      resultado.push_back(datosViaje);
    }
  }

  return resultado;
}

int ManejadorViaje::obtenerCodigo() {
  this->ultimoViaje++;
  return this->ultimoViaje;
}

Viaje* ManejadorViaje::crearViaje(Vehiculo* v, DTFecha fecha, std::string origen, std::string destino, int asientos, float precio) {
  int cod = this->obtenerCodigo();
  Viaje *nuevoViaje = new Viaje(cod, fecha, origen, destino, asientos, precio);
  
  // Se crea un link con v
  nuevoViaje->setVehiculo(v);
  
  // 6.2: add(vi)
  this->agregarViaje(nuevoViaje);
  
  return nuevoViaje;
}
