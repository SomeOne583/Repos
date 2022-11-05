#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> monedas;
vector<vector<long>> calculos;

long formas(int n, int i) {
        if (n == 0) {
                return 1;
        }
        if (n < 0 || i > 20) {
                return 0;
        }
        if (calculos[n][i] == -1) {
                calculos[n][i] = formas(n - monedas[i], i) + formas(n, i + 1); 
        }
        return calculos[n][i];
}

int main() {
        int k;
        for (int i = 0; i < 21; i++) {
                monedas.push_back((i + 1) * (i + 1) * (i + 1));
        }

        calculos.resize(10000, vector<long>(21, -1));
        while (cin >> k) {
                cout << formas(k, 0) << "\n";
        }
        
        return 0;
}
