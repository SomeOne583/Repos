// Jan Carlo Reyes Martínez - 577441
// Doy mi palabra de que he realizado esta actividad con integridad académica

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<int> sol;

// Función para validar si dos reinas se atacan
bool valido(int x1, int y1, int x2, int y2) {
        if (x1 == x2 || y1 == y2 || abs(x2 - x1) == abs(y2 - y1)) {
                return false;
        }
        return true;
}

// Función recursiva que recive la posicón que voy resolviendo con la cantidad de reinas
void genera(int pos, int &n) {
        // Caso base, ya llegue a la posición fuera del arreglo
        if (pos == n) {
                for (vector<int>::iterator it = sol.begin(); it != sol.end(); it++) {
                        cout << *it << ", ";
                }
                cout << "\n";
        } else {
                bool val;
                // Reviso todos los posibles valores
                for (int i = 1; i <= n; i++) {
                        val = true; // Asumo que son validos
                        // Itero en las reinas que ya puse para ver si la que quiero poner no ataca a ninguna ya puesta
                        for (int j = 0; j < pos && val; j++) {
                                if (!valido(j, sol[j], pos, i)) {
                                        // Si ataca a alguna ya puesta pues la bandera se marca
                                        val = false;
                                }
                        }
                        // Aquí sucede la poda porque no continua con árboles que ya no darán resultados
                        if (val) {
                                // Se llama de nuevo pero ahora con una posición mayor
                                sol[pos] = i;
                                genera(pos + 1, n);
                        }
                }
        }
}

int main() {
        int n;
        cin >> n;
        sol.resize(n, 0);
        genera(0, n);

        return 0;
}
