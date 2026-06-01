std::vector<DTListarViaje> ControladorGestionViajes::listarViajes(std::string nickname) {
    ManejadorUsuario* mu = ManejadorUsuario::getInstancia();
    
    // 1: u := find(nickname)
    Usuario* u = mu->find(nickname); 
    
    if (u != nullptr) {
        // 2: dtViajes := obtenerDTListarViajes()
        return u->obtenerDTListarViajes(); 
    }
    return std::vector<DTListarViaje>();
}

std::vector<DTListarViaje> ControladorGestionViajes::listarViajes() {
    std::vector<DTListarViaje> lista;
    
    ManejadorViaje* mv = ManejadorViaje::getInstance();
    
    std::map<int, Viaje*> todosLosViajes = mv->obtenerViajes();
    
    for (auto const& par : todosLosViajes) {
        Viaje* v = par.second;
        
        std::string nickConductor = v->getNicknameConductor();
        
        lista.push_back(v->getDTListarViaje(nickConductor)); 
    }
    
    return lista;
}