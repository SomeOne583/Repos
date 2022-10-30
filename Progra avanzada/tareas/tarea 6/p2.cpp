#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> denominaciones;
vector<bool> visitados;
vector<vector<int>> soluciones;

void solve(int acum, int i, int total) {
        if (acum == total) {
                vector<int> sol;
                for (size_t i = 0; i < visitados.size(); i++) {
                        if (visitados[i]) {
                                sol.push_back(denominaciones[i]);
                        }
                }
                if (find(soluciones.begin(), soluciones.end(), sol) == soluciones.end()) {
                        soluciones.push_back(sol);
                }
        } else {
                for (size_t j = i; j < denominaciones.size(); j++) {
                        if (acum + denominaciones[j] <= total) {
                                visitados[j] = true;
                                solve(acum + denominaciones[j], j + 1, total);
                                visitados[j] = false;
                        }
                }
        }
}

int main() {
        int C, n, num;

        while (cin >> C >> n && !(C == 0 && n == 0)) {
                denominaciones.clear();
                visitados.clear();
                soluciones.clear();
                while (n--) {
                        cin >> num;
                        denominaciones.push_back(num);
                }
                sort(denominaciones.begin(), denominaciones.end(), greater<int>());
                visitados.resize(denominaciones.size(), false);
                solve(0, 0, C);
                cout << "Para " << C << " hay " << soluciones.size() << " sumas:\n";
                if (soluciones.size() == 0) {
                        cout << "IMPOSIBLE\n";
                } else {
                        for (size_t i = 0; i < soluciones.size(); i++) {
                                for (size_t j = 0; j < soluciones[i].size() - 1; j++) {
                                        cout << soluciones[i][j] << "+";
                                }
                                cout << soluciones[i].back() << "\n";
                        }
                }
        }

        return 0;
}
