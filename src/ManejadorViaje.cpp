#include "../include/ManejadorViaje.h"
#include "../include/Vehiculo.h"

ManejadorViaje *ManejadorViaje::instancia = nullptr;

ManejadorViaje::ManejadorViaje() { this->ultimoViaje = 0; }

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

Viaje *ManejadorViaje::find(int codigo) {
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
    // 1.2 verifico si el viaje cumple con los requisitos
    bool ok = v->verificarViaje(fecha, origen, destino, asientos);
    if (ok) {
      // 1.3 si el viaje cumple con los requisitos obtengo los datos del viaje y
      // lo agrego al vector de resultados
      DTConsultaViaje datosViaje = v->datosViaje();
      // Retorna el DTConsultaViaje y lo agrega al retorno
      resultado.push_back(datosViaje);
    }
  }

  return resultado;
}

// Falto en el DCD
int ManejadorViaje::obtenerCodigo() {
  this->ultimoViaje++;
  return this->ultimoViaje;
}

Viaje *ManejadorViaje::crearViaje(Vehiculo *v, DTFecha fecha,
                                  std::string origen, std::string destino,
                                  int asientos, float precio) {
  // 5.1.1 obtengo el ultimo codigo del viaje
  int cod = this->obtenerCodigo();
  Viaje *nuevoViaje = new Viaje(cod, fecha, origen, destino, asientos, precio);
  // 5.1.2 Creo un link con v
  nuevoViaje->setVehiculo(v);

  // 6.2: add(vi)
  this->agregarViaje(nuevoViaje);

  return nuevoViaje;
}

void ManejadorViaje::removerViaje(int codigo) {
  auto it = this->viajes.find(codigo);
  if (it != this->viajes.end()) {
    this->viajes.erase(it);
  }
}

ManejadorViaje::~ManejadorViaje() {
  for (auto const &par : viajes) {
    delete par.second;
  }
  viajes.clear();
  instancia = nullptr;
}
