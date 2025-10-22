#ifndef CONTRATOMOVIL_H
#define CONTRATOMOVIL_H
#include "Fecha.h"
#include "Contrato.h"


class ContratoMovil:public Contrato
{
    private:
        int minutosUsados;
        float precioVariable;
        char* nacionalidad;

    public:
        ContratoMovil(long int dni, Fecha fechaAlta,float precio ,int minut, char* nacion):Contrato(dni,fechaAlta){
            minutosUsados = minut;
            precioVariable = precio;
            nacionalidad = nacion;
        }

        int getMinutosHablados() const {return minutosUsados;}
        float getPrecioMinuto() const {return precioVariable;}
        char* getNacionalidad() const {return nacionalidad;}

        void setMinutosHablados(int newMinutosUsados);
        void setPrecioMinuto(float newPrecio);
        void setNacionalidad(char* newNacionalidad);


        void ver() const override;
        float factura() const override;

};

std::ostream& operator<<(std::ostream& os, const ContratoMovil& c);
#endif // CONTRATOMOVIL_H
