#include "Pago.h"

Pago::Pago(string id, string idPed, float m)
    : idPago(id), idPedido(idPed), monto(m) {
}

string Pago::getIdPago() { return idPago; }

void Pago::mostrar() {
    cout << "Pago: " << idPago
        << " | Pedido: " << idPedido
        << " | Monto: " << monto << endl;
}

string Pago::texto() {
    return idPago + "," + idPedido + "," + to_string(monto);
}