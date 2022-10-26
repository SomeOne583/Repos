#include "LinkedList.h"
#include <iostream>

using namespace std;

int main() {
        int opcion;
        LinkedList<int> lista;
        do {
                int e, e2;
                bool borrado;

                cout << "\nLista: ";
                lista.print();
                cout << endl;

                cout << "1. Añadir al principio" << endl;
                cout << "2. Añadir al final" << endl;
                cout << "3. Encontrar dato" << endl;
                cout << "4. Extraer dato" << endl;
                cout << "5. Borrar dato" << endl;
                cout << "6. Borrar índice" << endl;
                cout << "7. Actualizar dato" << endl;
                cout << "8. Actualizar índice" << endl;
                cout << "9. Salir" << endl;

                cout << "Elige una opcion: ";
                cin >> opcion;

                switch (opcion) {
                        case 1:
                                cout << "Ingresa el dato a ingresar: ";
                                cin >> e;
                                lista.addFirst(e);
                                break;
                        case 2:
                                cout << "Ingresa el dato a ingresar: ";
                                cin >> e;
                                lista.addLast(e);
                                break;
                        case 3:
                                cout << "Ingresa el dato a buscar: ";
                                cin >> e;
                                cout << "Se encontró el dato en el índice: " << lista.findData(e);
                                break;
                        case 4:
                                cout << "Ingresa el índice a obtener: ";
                                cin >> e;
                                cout << "Dato obtenido: " << lista.getData(e);
                                break;
                        case 5:
                                cout << "Ingresa el dato a borrar: ";
                                cin >> e;
                                borrado = lista.deleteData(e);
                                cout << (borrado ? "Sí" : "No") << " se pudo borrar";
                                break;
                        case 6:
                                cout << "Ingresa el índice a borrar: ";
                                cin >> e;
                                borrado = lista.deleteAt(e);
                                cout << (borrado ? "Sí" : "No") << " se pudo borrar";
                                break;
                        case 7:
                                cout << "Ingresa el dato a actualizar: ";
                                cin >> e;
                                cout << "Ingresa el nuevo dato: ";
                                cin >> e2;
                                lista.updateData(e, e2);
                                break;
                        case 8:
                                cout << "Ingresa el índice a actualizar: ";
                                cin >> e;
                                cout << "Ingresa el nuevo dato: ";
                                cin >> e2;
                                lista.updateAt(e, e2);
                                break;
                }
        } while (opcion != 9);
}