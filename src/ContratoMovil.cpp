#include "ContratoMovil.h"
#include <iostream>

void ContratoMovil::ver()const {
    Contrato::ver();

    std::cout << " " << minutosUsados << "m, "<< nacionalidad << " " << precioVariable;
}

float ContratoMovil::factura() const {
    return precioVariable * minutosUsados;
}

void ContratoMovil::setMinutosHablados(int newMinutosUsados){
    this->minutosUsados = newMinutosUsados;
}

void ContratoMovil::setPrecioMinuto(float newPrecio){
    this->precioVariable = newPrecio;
}

void ContratoMovil::setNacionalidad(char* newNacionalidad){
    this->nacionalidad = newNacionalidad;
}

std::ostream& operator<<(std::ostream& os, const ContratoMovil& c) {
    os << c.getDniContrato() << " ("<< c.getFechaContrato() << ") "<<c.getMinutosHablados() <<"m, "<< c.getNacionalidad() <<c.getPrecioMinuto()<<" - "<< c.factura() << "€";
    return os;
}
