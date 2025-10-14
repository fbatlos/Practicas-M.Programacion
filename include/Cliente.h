#ifndef CLIENTE_H
#define CLIENTE_H
#include <iostream>
#include "Fecha.h"


class Cliente
{
    private:
            long int dni;
            char* nombre;
            Fecha fechaAlta;
    public:
        Cliente(long int dni, const char* nombre, Fecha fechaAlta);

        long int getDni() const {return dni;}
        const char* getNombre() const {return nombre;}
        Fecha getFecha() const {return fechaAlta;}

        void setNombre(const char* n);
        void setFecha(const Fecha& nuevaFecha);

        bool operator==(const Cliente& otro) const;


};

std::ostream& operator<<(std::ostream& os, const Cliente& c);

#endif // CLIENTE_H
