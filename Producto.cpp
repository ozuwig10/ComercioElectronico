#include "Producto.h"

Producto::Producto(string id, string nom, float pre, int cant)
    : idProducto(id), nombre(nom), precio(pre), cantidad(cant) {
}

string Producto::getIdProducto() { return idProducto; }

void Producto::mostrar() {
    cout << "ID: " << idProducto
        << " | Nombre: " << nombre
        << " | Precio: " << precio
        << " | Cantidad: " << cantidad << endl;
}

string Producto::texto() {
    return idProducto + "," + nombre + "," + to_string(precio) + "," + to_string(cantidad);
}
