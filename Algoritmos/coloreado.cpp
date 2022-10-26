// Jan Carlo Reyes Martínez
// Doy mi palabra de que he realizado esta actividad con integridad académica

#include <iostream>
#include <vector>

using namespace std;

vector<int> colores;
vector<vector<bool>> matriz;

// Función para validar si puedo meter c color en la posición pos
bool valido(int &pos, int &c) {
        for (int i = 0; i < matriz[pos].size(); i++) {
                if (matriz[pos][i] && colores[i] == c) {
                        return false;
                }
        }
        return true;
}

// Función recursiva que recibe la posición a resolver y la cantidad de colores
void genera(int pos, int &m) {
        // Caso base, ya llegó a una solución
        if (pos == matriz.size()) {
                cout << "[ ";
                for (int i = 0; i < colores.size() - 1; i++) {
                        cout << colores[i] << ", ";
                }
                cout << colores.back() << " ]\n";
        } else {
                // Itera en todos los posibles colores
                for (int i = 1; i <= m; i++) {
                        // Revisa si es valido
                        if (valido(pos, i)) {
                                // Pinta de ese color
                                colores[pos] = i;
                                // Hace recursividad
                                genera(pos + 1, m);
                                // Despinta la celda para seguir explorando posibilidades
                                colores[pos] = 0;
                        }
                }
        }
}

int main() {
        /*
        Grafo
          1  2  3  4  5
        1 F  T  F  F  T
        2 T  F  T  F  F
        3 F  T  F  T  T
        4 F  F  T  F  T
        5 T  F  T  T  F
        */
       int m = 3;
       colores.resize(5, 0);
       matriz.resize(5, vector<bool>(5, false));

       matriz[0][1] = true;
       matriz[1][0] = true;

       matriz[0][4] = true;
       matriz[4][0] = true;

       matriz[1][2] = true;
       matriz[2][1] = true;

       matriz[2][3] = true;
       matriz[3][2] = true;

       matriz[2][4] = true;
       matriz[4][2] = true;
       
       matriz[3][4] = true;
       matriz[4][3] = true;

       genera(0, m);
       
       return 0;
}
