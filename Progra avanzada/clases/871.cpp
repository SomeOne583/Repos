#include <iostream>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int ciclos;
vector<vector<bool>> container;
queue<pair<int, int>> pendientes;

int solve() {
        pair<int, int> actual;
        int blob = 0;
        while (!pendientes.empty()) {
                actual = pendientes.front();
                pendientes.pop();
                for (int ff = actual.first - 1; ff <= actual.first + 1; ff++) {
                        for (int cc = actual.second - 1; cc <= actual.second + 1; cc++) {
                                if (container[ff][cc]) {
                                        blob++;
                                        container[ff][cc] = false;
                                        pendientes.push({ ff, cc });
                                }
                        }
                }
        }
        return blob;
}

int main() {
        int n, mayor, l;
        char t;
        string linea;

        getline(cin, linea);

        n = stoi(linea);

        getline(cin, linea);

        while (n--) {
                mayor = 0;
                l = 2;
                container.clear();
                getline(cin, linea);
                container.push_back(vector<bool>(linea.size() + 2, false));
                container.push_back(vector<bool>(linea.size() + 2, false));
                for (int i = 0; i < linea.size(); i++) {
                        if (linea[i] == '1')
                                container[1][i + 1] = true;
                }

                while (getline(cin, linea) && linea != "") {
                        container.push_back(vector<bool>(linea.size() + 2, false));
                        for (int i = 0; i < linea.size(); i++) {
                                if (linea[i] == '1')
                                        container[l][i + 1] = true;
                        }
                        l++;
                }
                container.push_back(vector<bool>(container[0].size(), false));

                for (int f = 1; f < container.size() - 1; f++) {
                        for (int c = 1; c < container[0].size() - 1; c++) {
                                if (container[f][c]) {
                                        container[f][c] = false;
                                        pendientes.push({ f, c });
                                        ciclos = 1 + solve();
                                        mayor = max(mayor, ciclos);
                                }
                        }
                }

                cout << mayor << '\n';
                if (n > 0) {
                        cout << '\n';
                }
        }

        return 0;
}
