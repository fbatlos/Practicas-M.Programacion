#ifndef CONTRATO_H
#define CONTRATO_H
#include "Fecha.h"

class Contrato
{
    private:
        int idContrato;
        long int dni;
        Fecha fechaAlta;

        static int current_id;

    public:
        Contrato(long int dni,Fecha fechaAlta);
        Contrato(const Contrato &otro);

        int getIdContrato()const { return idContrato;}
        long int getDniContrato() const  { return dni;}
        Fecha getFechaContrato() const {return fechaAlta;}

        void setDniContrato(long int newDNI);
        void setFechaContrato(Fecha newFecha);

        virtual void ver() const;
        virtual float factura() const;
};

 std::ostream& operator<<(std::ostream& os, const Contrato& c);

#endif // CONTRATO_H
