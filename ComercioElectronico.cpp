#include <iostream>
#include "Producto.h"
#include "Cliente.h"
#include "Pago.h"
#include "ListaDoble.h"
using namespace std;

int main() {
    ListaDoble<Producto> productos;
    ListaDoble<Cliente> clientes;
    ListaDoble<Pago> pagos;

    int opcion1 = 0;
    int opcion2 = 0;

    while (opcion1 != 5) {
        cout << "\n====== MENU PRINCIPAL ======\n";
        cout << "1. Clientes\n";
        cout << "2. Pagos\n";
        cout << "3. Pedidos (en construccion)\n";
        cout << "4. Productos\n";
        cout << "5. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion1;

        switch (opcion1) {
        case 1: { 
            opcion2 = 0;
            while (opcion2 != 5) {
                cout << "\n--- MENU CLIENTES ---\n";
                cout << "1. Insertar cliente\n";
                cout << "2. Eliminar cliente\n";
                cout << "3. Mostrar clientes\n";
                cout << "4. Guardar en archivo\n";
                cout << "5. Volver al menu principal\n";
                cout << "Seleccione una opcion: ";
                cin >> opcion2;

                switch (opcion2) {
                case 1: {
                    string id, nombre, tel;
                    cout << "Ingrese ID: "; cin >> id;
                    cout << "Ingrese nombre: "; cin.ignore(); getline(cin, nombre);
                    cout << "Ingrese telefono: "; cin >> tel;
                    clientes.insertar(Cliente(id, nombre, tel));
                    cout << "Cliente agregado.\n";
                    break;
                }
                case 2: {
                    string id;
                    cout << "Ingrese ID a eliminar: ";
                    cin >> id;
                    if (clientes.eliminar(id)) cout << "Cliente eliminado.\n";
                    else cout << "Cliente no encontrado.\n";
                    break;
                }
                case 3:
                    clientes.mostrar();
                    break;
                case 4:
                    clientes.guardarArchivo("clientes.txt");
                    break;
                }
            }
            break;
        }

        case 2: { 
            opcion2 = 0;
            while (opcion2 != 5) {
                cout << "\n--- MENU PAGOS ---\n";
                cout << "1. Insertar pago\n";
                cout << "2. Eliminar pago\n";
                cout << "3. Mostrar pagos\n";
                cout << "4. Guardar en archivo\n";
                cout << "5. Volver al menu principal\n";
                cout << "Seleccione una opcion: ";
                cin >> opcion2;

                switch (opcion2) {
                case 1: {
                    string idPago, idPedido;
                    double monto;
                    cout << "Ingrese ID del pago: "; cin >> idPago;
                    cout << "Ingrese ID del pedido: "; cin >> idPedido;
                    cout << "Ingrese monto: "; cin >> monto;
                    pagos.insertar(Pago(idPago, idPedido, monto));
                    cout << "Pago agregado.\n";
                    break;
                }
                case 2: {
                    string id;
                    cout << "Ingrese ID a eliminar: ";
                    cin >> id;
                    if (pagos.eliminar(id)) cout << "Pago eliminado.\n";
                    else cout << "Pago no encontrado.\n";
                    break;
                }
                case 3:
                    pagos.mostrar();
                    break;
                case 4:
                    pagos.guardarArchivo("pagos.txt");
                    break;
                }
            }
            break;
        }

        case 3: { 
            cout << "\n--- MENU PEDIDOS ---\n";
            cout << "En construcción...\n";
            break;
        }

        case 4: { 
            opcion2 = 0;
            while (opcion2 != 5) {
                cout << "\n--- MENU PRODUCTOS ---\n";
                cout << "1. Insertar producto\n";
                cout << "2. Eliminar producto\n";
                cout << "3. Mostrar productos\n";
                cout << "4. Guardar en archivo\n";
                cout << "5. Volver al menu principal\n";
                cout << "Seleccione una opcion: ";
                cin >> opcion2;

                switch (opcion2) {
                case 1: {
                    string id, nombre;
                    double precio;
                    int cantidad;
                    cout << "Ingrese ID: "; cin >> id;
                    cout << "Ingrese nombre: "; cin.ignore(); getline(cin, nombre);
                    cout << "Ingrese precio: "; cin >> precio;
                    cout << "Ingrese cantidad: "; cin >> cantidad;
                    productos.insertar(Producto(id, nombre, precio, cantidad));
                    cout << "Producto agregado.\n";
                    break;
                }
                case 2: {
                    string id;
                    cout << "Ingrese ID a eliminar: ";
                    cin >> id;
                    if (productos.eliminar(id)) cout << "Producto eliminado.\n";
                    else cout << "Producto no encontrado.\n";
                    break;
                }
                case 3:
                    productos.mostrar();
                    break;
                case 4:
                    productos.guardarArchivo("productos.txt");
                    break;
                }
            }
            break;
        }

        case 5:
            cout << "\nSaliendo del programa...\n";
            break;

        default:
            cout << "\nOpcion invalida. Intente de nuevo.\n";
        }
    }

    return 0;
}

