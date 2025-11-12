#include "Cliente.h"

Cliente::Cliente(string id, string nom, string tel)
    : idCliente(id), nombre(nom), telefono(tel) {
}

string Cliente::getIdCliente() { return idCliente; }

void Cliente::mostrar() {
    cout << "ID Cliente: " << idCliente
        << " | Nombre: " << nombre
        << " | Teléfono: " << telefono << endl;
}

string Cliente::texto() {
    return idCliente + "," + nombre + "," + telefono;
}