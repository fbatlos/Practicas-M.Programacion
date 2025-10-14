#ifndef FECHA_H
#define FECHA_H
#include <iostream>

class Fecha
{
    private:
        int dia,mes,anio;
        int getDiaMaximo();
        bool esAnioBisiesto(int a)const;
        void validarYAsignar(int d, int m, int a);
        void sumarDia();

    public:
        Fecha(int dia, int mes, int anio);

        int getDia() const { return dia; }
        int getMes() const { return mes; }
        int getAnio() const { return anio; }

        void setFecha(int dia, int mes, int anio);
        void ver() const;
        bool bisiesto()const;

        Fecha& operator++();
        Fecha operator++(int);
        Fecha operator+(int dias)const;
};

Fecha operator+(int dias, const Fecha& f);
std::ostream& operator<<(std::ostream& os, const Fecha& f);
#endif // FECHA_H
