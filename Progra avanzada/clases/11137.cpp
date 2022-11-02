#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<vector<long>> calculos;

long monedas(int n, int i) {
        if (n == 0) {
                return 1;
        } else if (n < 0 || i > 21) {
                return 0;
        } else {
                if (calculos[n][i] == 0) {
                        calculos[n][i] = monedas(n - pow(i, 3), i) + monedas(n, i + 1); 
                }
                return calculos[n][i];
        }
}

int main() {
        int k;

        calculos.resize(10000, vector<long>(22, 0));
        while (cin >> k) {
                cout << monedas(k, 1) << "\n";
        }
        
        return 0;
}
