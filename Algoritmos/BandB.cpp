// Jan Carlo Reyes Martínez
// 577441
// Doy mi palabra de que he realizado esta actividad con integridad académica

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int upper;
vector<int> trabajos;
vector<bool> hechos;
vector<vector<int>> datos;

// Implementación con backtracking
void solve(int tiempo, int trabajo) {
        for (int i = trabajo; i <= 4; i++) {
                if (tiempo + datos[2][i - 1] <= datos[1][i - 1]) {
                        hechos[i - 1] = true;
                        int costo = 0;
                        for (int j = 1; j < i; j++) {
                                if (!hechos[j - 1]) {
                                        costo += datos[0][j - 1];
                                }
                        }
                        if (costo > upper) {
                                hechos[i - 1] = false;
                                continue;
                        }
                        int upperLocal = 0;
                        for (int j = 1; j <= 4; j++) {
                                if (!hechos[j - 1]) {
                                        upperLocal += datos[0][j - 1];
                                }
                        }
                        if (upperLocal < upper) {
                                for (int i = 0; i < 4; i++) {
                                        if (hechos[i]) {
                                                cout << i + 1 << ", ";
                                        }
                                }
                                cout << upperLocal << "\n";
                                upper = upperLocal;
                        }
                        solve(tiempo + datos[2][i - 1], i + 1);
                        hechos[i - 1] = false;
                }
        }
}

int main() {
        upper = 100;
        trabajos = { 1, 2, 3, 4 };
        hechos.resize(4, false);
        datos = {
                /* Penalidades */ { 5, 10, 6, 3 },
                /* Deadline */ { 1, 3, 2, 1 },
                /* Time */ { 1, 2, 1, 1 }
        };

        // solve(0, 1);

        // cout << "///////" << endl;

        int tiempo;
        queue<vector<int>> fila;
        vector<int> e;

        fila.push({ 1 });
        fila.push({ 2 });
        fila.push({ 3 });
        fila.push({ 4 });

        upper = 1000;
        int upperLocal;
        vector<int> sol;
        // Implementación con filas
        while (!fila.empty()) {
                tiempo = 0;
                upperLocal = 0;
                e = fila.front();
                for (size_t i = 0; i < e.size(); i++) {
                        tiempo += datos[2][e[i] - 1];
                }
                for (int i = 1; i <= 4; i++) {
                        if (find(e.begin(), e.end(), i) == e.end()) {
                                upperLocal += datos[0][i - 1];
                        }
                }
                if (upperLocal < upper) {
                        sol.clear();
                        for (size_t i = 0; i < e.size(); i++) {
                                sol.push_back(e[i]);
                        }
                        upper = upperLocal;
                } 
                for (int i = e.back() + 1; i <= 4; i++) {
                        if (tiempo + datos[2][i - 1] <= datos[1][i - 1]) {
                                e.push_back(i);
                                fila.push(e);
                                e.pop_back();
                        }
                }
                fila.pop();
        }

        cout << "Trabajos: ";
        for (int i = 0; i < sol.size(); i++) {
                cout << sol[i] << ", ";
        }
        cout << "\nPenalidad: " << upper << endl;
        
        return 0;
}
