#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> denominaciones, calculos;

int monedas(int n) {
        if (calculos[n] == -1) {
                int c, menor = -1;
                for (size_t i = 0; i < denominaciones.size(); i++) {
                        if (denominaciones[i] <= n) {
                                c = 1 + monedas(n - denominaciones[i]);
                                if (menor == -1 || c < menor) {
                                        menor = c;
                                }
                        }
                }
                calculos[n] = menor;
        }
        return calculos[n];
}

int main() {
        int k = 10;
        calculos.resize(k + 1, -1);
        calculos[0] = 0;
        for (int i = 1; pow(i, 3) <= k; i++) {
                denominaciones.push_back(pow(i, 3));
        }
        for (size_t i = 0; i < denominaciones.size(); i++) {
                calculos[denominaciones[i]] = 1;
        }

        cout << monedas(k) << "\n";
        for (size_t i = 0; i < calculos.size(); i++) {
                cout << calculos[i] << ", ";
        }
        cout << "\n";
        
        
        return 0;
}
