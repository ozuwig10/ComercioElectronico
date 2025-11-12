#pragma once
#include <iostream>
#include <string>
using namespace std;

class Cliente {
protected:
    string idCliente;
    string nombre;
    string telefono;

public:
    Cliente(string id = "", string nom = "", string tel = "");
    string getIdCliente();
    void mostrar();
    string texto();
};
