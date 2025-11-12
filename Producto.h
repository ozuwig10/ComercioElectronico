#pragma once
#include <iostream>
#include <string>
using namespace std;

class Producto {
private:
    string idProducto;
    string nombre;
    float precio;
    int cantidad;

public:
    Producto(string id = "", string nom = "", float pre = 0, int cant = 0);
    string getIdProducto();
    void mostrar();
    string texto();
};