#pragma once
#include "Cliente.h"

class Pedido : public Cliente {
private:
    string idPedido;
    string idProducto;
    int cantidad;

public:
    Pedido(string idP = "", string idC = "", string nom = "", string tel = "",
        string idProd = "", int cant = 0);
    string getIdPedido();
    void mostrar();
    string texto();
};