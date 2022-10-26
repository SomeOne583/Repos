#include <iostream>
#include <string>
#include "LinkedList.h"

using namespace std;

int main() {
        LinkedList<string> lista;
        lista.addLast("Francisco");
        lista.addLast("Jorge");
        lista.addLast("Luis");
        lista.addLast("Sergio");
        lista.addLast("Ricardo");
        lista.addLast("Salvador");
        lista.addLast("Diego");
        lista.addLast("Maria");

        lista.print();

        int n, contador = 0, indice = 0;
        cout << endl;
        cout << "Ingrese el número de cada cuántos soldados se quitarán: ";
        cin >> n;

        while (lista.getSize() > 1) {
                cout << "Lista: ";
                lista.print();
                cout << endl;

                contador++;
                if (contador == n) {
                        contador = indice >= lista.getSize() - 1 ? 0 : 1;
                        lista.deleteAt(indice);
                }
                if (indice >= lista.getSize() - 1) {
                        indice = 0;
                } else {
                        indice++;
                }
        }

        cout << "Final: ";
        lista.print();
        cout << endl;

        return 0;
}