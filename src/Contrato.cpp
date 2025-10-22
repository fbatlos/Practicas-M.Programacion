#include "Contrato.h"
#include <iostream>


int Contrato::current_id;

Contrato::Contrato(long int dni,Fecha fechaAlta):dni(dni),fechaAlta(fechaAlta),idContrato(++current_id){}

Contrato::Contrato(const Contrato &otro): idContrato(++current_id),dni(otro.dni),fechaAlta(otro.fechaAlta){}

void Contrato::ver() const {
    std::cout << dni << " (" << idContrato << " - " << fechaAlta << ")";
}

void Contrato::setDniContrato(long int newDNI){
    this->dni = newDNI;
}

void Contrato::setFechaContrato(Fecha newFecha){
    this->fechaAlta = newFecha;
}

float Contrato::factura() const {}

std::ostream& operator<<(std::ostream& os, const Contrato& c) {
    os << c.getDniContrato() << " (" << c.getIdContrato() << " - "
       << c.getFechaContrato() << ")";

    return os;
}
