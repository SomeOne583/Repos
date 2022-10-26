// Jan Carlo Reyes Martínez - 577441
// Doy mi palabra de que he realizado esta actividad con integridad académica

#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

// Función para validar si dos reinas se atacan
bool valido(int &x1, int y1, int &x2, int y2) {
        if (x1 == x2 || y1 == y2 || abs(x2 - x1) == abs(y2 - y1)) {
                return false;
        }
        return true;
}

// Función recursiva que recive como referencia el arreglo que se va generando con la cantidad de reinas
void genera(vector<int> &sol, int &n) {
        // Caso base, el arreglo ya llegó al tamaño que debía
        if (sol.size() == n) {
                for (vector<int>::iterator it = sol.begin(); it != sol.end(); it++) {
                        cout << *it << ", ";
                }
                cout << "\n";
        } else {
                bool val;
                vector<int> aux;
                // Reviso todos los posibles valores
                for (int i = 1; i <= n; i++) {
                        val = true; // Asumo que son validos
                        // Itero en las reinas que ya puse para ver si la que quiero poner no ataca a ninguna ya puesta
                        for (vector<int>::iterator it = sol.begin(); it != sol.end() && val; it++) {
                                if (!valido(*it, it - sol.begin(), i, sol.size())) {
                                        // Si ataca a alguna ya puesta pues la bandera se marca
                                        val = false;
                                }
                        }
                        // Si resulta ser una opción valida, aquí sucede la poda porque no continua con árboles que ya no darán resultados
                        if (val) {
                                // Se hace una copia del arreglo
                                aux = sol;
                                // Se le añade la solución
                                aux.push_back(i);
                                // Se llama de nuevo pero ahora con un arreglo con un elemento más
                                genera(aux, n);
                        }
                }
        }
}

int main() {
        int n;
        vector<int> sol;
        cin >> n;
        genera(sol, n);

        return 0;
}
