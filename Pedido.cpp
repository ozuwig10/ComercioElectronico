#include "Pedido.h"

Pedido::Pedido(string idP, string idC, string nom, string tel,
    string idProd, int cant)
    : Cliente(idC, nom, tel), idPedido(idP), idProducto(idProd), cantidad(cant) {
}

string Pedido::getIdPedido() { return idPedido; }

void Pedido::mostrar() {
    cout << "Pedido: " << idPedido
        << " | Cliente: " << idCliente
        << " | Producto: " << idProducto
        << " | Cantidad: " << cantidad << endl;
}

string Pedido::texto() {
    return idPedido + "," + idCliente + "," + idProducto + "," + to_string(cantidad);
}
