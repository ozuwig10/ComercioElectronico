#pragma once
#include <iostream>
#include <string>
using namespace std;

class Pago {
private:
    string idPago;
    string idPedido;
    float monto;

public:
    Pago(string id = "", string idPed = "", float m = 0);
    string getIdPago();
    void mostrar();
    string texto();
};
