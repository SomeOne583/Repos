#include <iostream>
#include <vector>

using namespace std;

vector<int> denominaciones = { 1, 5, 6, 9 }, calculos;

int monedas(int n) {
        if (calculos[n] == -1) {
                int c, menor = n * denominaciones.back();
                for (size_t i = 0; i < denominaciones.size(); i++) {
                        if (denominaciones[i] <= n) {
                                c = 1 + monedas(n - denominaciones[i]);
                                if (c < menor) {
                                        menor = c;
                                }
                        }
                }
                calculos[n] = menor;
        }
        return calculos[n];
}

int main() {
        int k = 13;
        calculos.resize(k + 1, -1);
        calculos[0] = 0;
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
