// Juan Manuel Cuevas Gaytan 611978
// Jan Carlo Reyes 577441
// Damos nuestra palabra de que hemos realizado esta actividad con integridad académica
// Problema 1 Depósitos de litio

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int depositos;
vector<vector<bool>> container;
queue<pair<int, int>> pendientes;

void solve() {
        pair<int, int> actual;
        for (size_t f = 1; f < container.size() - 1; f++) {
                for (size_t c = 1; c < container[0].size() - 1; c++) {
                        if (container[f][c]) {
                                depositos++;
                                container[f][c] = false;
                                pendientes.push({ f, c });
                                while (!pendientes.empty()) {
                                        actual = pendientes.front();
                                        pendientes.pop();
                                        for (int ff = actual.first - 1; ff <= actual.first + 1; ff++) {
                                                for (int cc = actual.second - 1; cc <= actual.second + 1; cc++) {
                                                        if (container[ff][cc]) {
                                                                container[ff][cc] = false;
                                                                pendientes.push({ ff, cc });
                                                        }
                                                }
                                        }
                                }
                        }
                }
        }
}

int main() {
        int f, c;
        char t;

        while (cin >> f >> c && !(f == 0 && c == 0)) {
                depositos = 0;
                container.clear();
                container.resize(f + 2, vector<bool>(c + 2, false));
                for (int i = 0; i < f; i++) {
                        for (int j = 0; j < c; j++) {
                                cin >> t;
                                if (t == 'L') {
                                        container[i + 1][j + 1] = true;
                                }
                        }
                }
                solve();
                cout << depositos << "\n";
        }
        
        return 0;
}
