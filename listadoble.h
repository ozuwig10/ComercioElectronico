#pragma once
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

template <typename T>
class Nodo {
public:
    T dato;
    Nodo<T>* anterior;
    Nodo<T>* siguiente;
    Nodo(T valor) : dato(valor), anterior(nullptr), siguiente(nullptr) {}
};

template <typename T>
class ListaDoble {
private:
    Nodo<T>* cabeza;
    Nodo<T>* cola;

public:
    ListaDoble() : cabeza(nullptr), cola(nullptr) {}

    void insertar(T valor) {
        Nodo<T>* nuevo = new Nodo<T>(valor);
        if (!cabeza) {
            cabeza = cola = nuevo;
        }
        else {
            cola->siguiente = nuevo;
            nuevo->anterior = cola;
            cola = nuevo;
        }
    }

    void mostrar() {
        Nodo<T>* actual = cabeza;
        while (actual) {
            actual->dato.mostrar();
            actual = actual->siguiente;
        }
    }

    bool eliminar(string id) {
        Nodo<T>* actual = cabeza;
        while (actual) {
            if constexpr (requires(T a) { a.getIdProducto(); }) {
                if (actual->dato.getIdProducto() == id)
                    return eliminarNodo(actual);
            }
            else if constexpr (requires(T a) { a.getIdCliente(); }) {
                if (actual->dato.getIdCliente() == id)
                    return eliminarNodo(actual);
            }
            else if constexpr (requires(T a) { a.getIdPedido(); }) {
                if (actual->dato.getIdPedido() == id)
                    return eliminarNodo(actual);
            }
            else if constexpr (requires(T a) { a.getIdPago(); }) {
                if (actual->dato.getIdPago() == id)
                    return eliminarNodo(actual);
            }
            actual = actual->siguiente;
        }
        return false;
    }

private:
    bool eliminarNodo(Nodo<T>* actual) {
        if (!actual) return false;
        if (actual->anterior) actual->anterior->siguiente = actual->siguiente;
        else cabeza = actual->siguiente;
        if (actual->siguiente) actual->siguiente->anterior = actual->anterior;
        else cola = actual->anterior;
        delete actual;
        return true;
    }

public:
    void guardarArchivo(string nombre) {
        ofstream file(nombre);
        Nodo<T>* actual = cabeza;
        while (actual) {
            file << actual->dato.texto() << endl;
            actual = actual->siguiente;
        }
        file.close();
    }
};
