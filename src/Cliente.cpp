#include <cstring> // <-- Necesitas esto!!!!!!!!!!!!
#include "Cliente.h"
#include "Fecha.h"
#include <iostream>

Cliente::Cliente(long int dni, const char* nombre, Fecha fechaAlta)
    : dni(dni), fechaAlta(fechaAlta)
{
    this->nombre = new char[strlen(nombre) + 1];
    strcpy(this->nombre, nombre);
}

void Cliente::setNombre(const char* n){
      // 1. Libera
    delete[] this->nombre;

    // 2. Reserva
    this->nombre = new char[strlen(n) + 1];

    // 3. Copia
    strcpy(this->nombre, n);
}

void Cliente::setFecha(const Fecha& nuevaFecha){
    this->fechaAlta = nuevaFecha;
}

bool Cliente::operator==(const Cliente& otro) const {
    return this->dni == otro.dni;
}

std::ostream& operator<<(std::ostream& os, const Cliente& c) {
    os << c.getNombre() << " (" << c.getDni() << " - "
       << c.getFecha() << ")";

    return os;
}
