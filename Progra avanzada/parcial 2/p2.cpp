#include <iostream>
#include <map>
#include <cmath>

using namespace std;

bool existeNodo(long pos, map<long, int> &ABB) {
        try {
                ABB.at(pos);
                return true;
        } catch (const std::out_of_range& oor) {
                return false;
        }
        return false;
}

long insertar(int valor, map<long, int> &ABB) {
        if (ABB.empty()) {
                ABB[0] = valor;
                return 0;
        } else {
                long pos = 0;
                while(existeNodo(pos, ABB)) {
                        if (valor < ABB[pos]) {
                                pos = pos * 2 + 1;
                        } else {
                                pos = pos * 2 + 2;
                        }
                }
                ABB[pos] = valor;
                return pos;
        }
}

int main() {
        bool iguales;
        int c, nodo;
        long nodos, posicion;
        map<long, int> arbol1, arbol2;

        cin >> c;

        while (c--) {
                arbol1.clear();
                arbol2.clear();
                iguales = true;

                cin >> nodos;
                for (long i = 0; i < nodos; i++) {
                        cin >> nodo;
                        insertar(nodo, arbol1);
                }
                for (long i = 0; i < nodos; i++) {
                        cin >> nodo;
                        if (iguales) {
                                posicion = insertar(nodo, arbol2);
                                if (!existeNodo(posicion, arbol1)) {
                                        iguales = false;
                                }
                        }
                }

                if (iguales) {
                        cout << "iguales" << endl;
                } else {
                        cout << "diferentes" << endl;
                }
        }

        return 0;
}
