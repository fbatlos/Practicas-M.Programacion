#include "Fecha.h"
#include <iostream>

// Un año es bisiesto si es divisible por 4,
// excepto si es divisible por 100 a menos que también lo sea por 400.
bool Fecha::esAnioBisiesto(int a)const{
    return (a % 4 == 0 && a % 100 != 0) || (a % 400 == 0);
}

int Fecha::getDiaMaximo(){
    switch (this->mes) {
        case 4: case 6: case 9: case 11:
            return 30;
            break;
        case 2:
            if (esAnioBisiesto(anio)) {
                return 29;
            } else {
                return 28;
            }
            break;
        default:
            return 31;
            break;
    }
}

void Fecha::validarYAsignar(int d,int m , int a){
    //Año (se asume que siempre es correcto)
    this->anio = a;

    //Validar mes
    if (m < 1) {
        this->mes = 1;
    } else if (m > 12) {
        this->mes = 12;
    } else {
        this->mes = m;
    }

    int diasMaximos = getDiaMaximo();

    //validar dia
    if (d < 1) {
        this->dia = 1;
    } else if (d > diasMaximos) {
        this->dia = diasMaximos;
    } else {
        this->dia = d;
    }
}

Fecha::Fecha(int d,int m,int a){
   validarYAsignar(d,m,a);
}

void Fecha::setFecha(int d,int m, int a){
    validarYAsignar(d,m,a);
}

void Fecha::ver() const {
    std::cout << dia << "/" << mes << "/" << anio;
}

bool Fecha::bisiesto()const{
    return esAnioBisiesto(anio);
}

void Fecha::sumarDia() {
    int diasMaximos = getDiaMaximo();

    if (dia < diasMaximos) {
        dia++;
    } else {
        dia = 1;
        if (mes < 12) {
            mes++;
        } else {
            mes = 1;
            anio++;
        }
    }
}

Fecha& Fecha::operator++() {
    sumarDia();
    return *this;
}

Fecha Fecha::operator++(int) {
    Fecha temp = *this;
    sumarDia();
    return temp;
}

Fecha Fecha::operator+(int d)const{
    Fecha resultado = *this;
    for (int i = 0; i < d; ++i) {//Preguntar si esto es mejor que hacer una funcion de sumar(int d)
        resultado.sumarDia();
    }
    return resultado;
}
Fecha operator+(int d, const Fecha& f) {
    return f + d;
}

std::ostream& operator<<(std::ostream& os, const Fecha& f) {
    os << f.getDia() << "/" << f.getMes() << "/"
       << f.getAnio();

    return os;
}
