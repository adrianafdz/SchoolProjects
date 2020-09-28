#ifndef RESERVA_H
#define RESERVA_H
#include "Fecha.h"

class Reserva
{
    public:
        Reserva();
        Reserva(int idM, int idC, Fecha f);
        Fecha calcFechaFinReservacion(int cant);
        void setIdMat(int id) {idMaterial=id;};
        void setIdCli(int id) {idCliente=id;};
        void setFechaRes(Fecha f) {fechaReservacion=f;};
        int getIdMat() {return idMaterial;};
        int getIdCli() {return idCliente;};
        Fecha getFechaRes() {return fechaReservacion;};

    private:
        int idMaterial;
        int idCliente;
        Fecha fechaReservacion;
};

Reserva::Reserva() {
    idMaterial=0;
    idCliente=0;
    fechaReservacion=Fecha();
}

Reserva::Reserva(int idM, int idC, Fecha f) {
    idMaterial=idM;
    idCliente=idC;
    fechaReservacion=f;
}
Fecha Reserva::calcFechaFinReservacion(int cant) {
    return fechaReservacion+cant;
}
#endif // RESERVA_H
