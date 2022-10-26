#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

bool valido(int &x1, int y1, int &x2, int y2) {
        if (x1 == x2 || y1 == y2 || abs(x2 - x1) == abs(y2 - y1)) {
                return false;
        }
        return true;
}

void genera(vector<int> &sol, vector<int> &base, int n, int cambios, int &menor) {
        if (sol.size() == n) {
                if (cambios < menor) {
                        menor = cambios;
                }
        } else {
                bool val;
                vector<int> aux;
                for (int i = 1; i <= n; i++) {
                        val = true;
                        for (vector<int>::iterator it = sol.begin(); it != sol.end() && val; it++) {
                                if (!valido(*it, it - sol.begin(), i, sol.size())) {
                                        val = false;
                                }
                        }
                        if (val) {
                                aux = sol;
                                aux.push_back(i);
                                if (i != base[sol.size()]) {
                                        genera(aux, base, n, cambios + 1, menor);
                                } else {
                                        genera(aux, base, n, cambios, menor);
                                }
                                aux.clear();
                        }
                }
        }
}

int main() {
        int n, menor, cant = 0;
        vector<int> sol, base;
        while (cin >> n) {
                cant++;
                menor = 8;
                sol.clear();
                base.clear();

                base.push_back(n);
                for (int i = 0; i < 7; i++) {
                        cin >> n;
                        base.push_back(n);
                }
                genera(sol, base, 8, 0, menor);

                cout << "Case " << cant << ": " << menor << "\n";
        }
        
        return 0;
}
