#include "ContratoTP.h"
#include <iostream>

int ContratoTP::limiteMinutos=300;
float ContratoTP::precio=10.0f;

int ContratoTP::getLimiteMinutos(){
    return limiteMinutos;
}

float ContratoTP::getPrecio(){
    return precio;
}

void ContratoTP::setTarifaPlana(int newLimiteMinutos, float newPrecio){
    limiteMinutos = newLimiteMinutos;
    precio = newPrecio;
}

void ContratoTP::ver()const {
    Contrato::ver();

     std::cout << " " << this->minutosHablados << "m, "<< ContratoTP::getLimiteMinutos() << "(" << ContratoTP::getPrecio() << ")";
}

float ContratoTP::factura() const {
    if (minutosHablados <= limiteMinutos){
        return precio;
    }else{
        return precio + ((minutosHablados-limiteMinutos)*0.15f);
    }
}

void ContratoTP::setMinutosHablados(int newMinutosUsados){
    this->minutosHablados = newMinutosUsados;
}

std::ostream& operator<<(std::ostream& os, const ContratoTP& c) {
    os << c.getDniContrato() << " ("<< c.getFechaContrato() << ") "<<c.getMinutosHablados() <<"m, "<< c.getLimiteMinutos() << "("<<c.getPrecio()<<")  - "<< c.factura() << "€";
    return os;
}
