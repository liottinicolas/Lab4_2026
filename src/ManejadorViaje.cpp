#include "../include/ManejadorViaje.h"

ManejadorViaje *ManejadorViaje::instancia = nullptr;

ManejadorViaje::ManejadorViaje() {}

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
      DTConsultaViaje datosViaje = v->getDTConsultaViaje(asientos);
      // TODO - ARREGLAR QUE ESTO NO ES, SEGUIR
      resultado.push_back(datosViaje);
    }
  }

  return resultado;
}
