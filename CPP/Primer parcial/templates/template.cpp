#include <iostream>
#include <string>
#include <vector>
#include "Lista.h"
using namespace std;

template<class A>
A suma(A n1, A n2, A n3) {
        return n1 + n2 + n3;
}

int main() {
        double a = 1.1, b = 2.2, c = 3.3, d;
        d = suma(a, b, c);

        int e = 1, f = 2, g = 3, h;
        h = suma(e, f, g);

        string i = "Hola", j = " ", k = "amigo", l;
        l = suma(i, j, k);

        cout << "La suma de enteros: " << d << endl;
        cout << "La suma de dobles: " << h << endl;
        cout << "La suma de strings: " << l << endl;

        // ------------------------------------- //

        Lista<double> listaDoble;
        Lista<int> listaEntero;
        Lista<string> listaString;

        for (int i = 62; i < 68; i++)
                listaDoble.agrega(i/10.0);
        
        for (int i = 0; i < 5; i++)
                listaEntero.agrega(i);

        if (listaEntero.agrega(3))
                cout << "Se pudo agregar el 3" << endl;
        else
                cout << "No se pudo agregar el 3" << endl;

        cout << "Los elementos de la lista de doubles son:" << endl;
        for (int i = 0; i < listaDoble.getSize(); i++)
                cout << listaDoble.getElem(i) << endl;
        
        cout << "Los elementos de la lista de enteros son:" << endl;  
        for (int i = 0; i < listaEntero.getSize(); i++)
                cout << listaEntero.getElem(i) << endl;

        try {
                cout << "El dato de la casilla 7 es " << listaDoble.getElem(7) << endl;
        } catch (out_of_range& e) {
                cout << "Error: " << e.what() << endl;
        }

        return 0;
}