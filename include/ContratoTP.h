#ifndef CONTRATOTP_H
#define CONTRATOTP_H
#include "Fecha.h"
#include "Contrato.h"

class ContratoTP:public Contrato
{
    private:
        int minutosHablados;

        static int limiteMinutos;
        static float precio;

    public:
        ContratoTP(long int dni, Fecha fechaAlta, int minutos):Contrato(dni,fechaAlta){minutosHablados = minutos;}

        int getMinutosHablados() const {return minutosHablados;}
        void setMinutosHablados(int newMinutosUsados);

        void ver() const override;
        float factura() const override;

        static void setTarifaPlana(int newLimiteMinutos, float newPrecio);
        static int getLimiteMinutos();
        static float getPrecio();

};

std::ostream& operator<<(std::ostream& os, const ContratoTP& c);
#endif // CONTRATOTP_H
