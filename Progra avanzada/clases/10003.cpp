#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> cortes;
int calculos[1001][1001];

int cortar(int troncoI, int troncoF, int corte) {
        int caben = 0;
        for (size_t i = corte; i < cortes.size() && caben < 2; i++) {
                if (cortes[i] > troncoI && cortes[i] < troncoF) {
                        caben++;
                }
        }
        if (caben == 0) {
                return 0;
        }
        if (caben == 1) {
                return troncoF - troncoI;
        }
        if (calculos[troncoI][troncoF] == -1) {
                int menor = 0, costo;
                for (size_t i = corte; i < cortes.size() && cortes[i] < troncoF; i++) {
                        costo = troncoF - troncoI + cortar(troncoI, cortes[i], corte) + cortar(cortes[i], troncoF, i + 1);
                        if (menor == 0 || costo < menor) {
                                menor = costo;
                        }
                }
                calculos[troncoI][troncoF] = menor;
        }
        return calculos[troncoI][troncoF];
}

int main() {
        int l, c, n;

        while (cin >> l && l != 0) {
                cortes.clear();
                memset(calculos, -1, sizeof(calculos));

                cin >> c;

                while (c--) {
                        cin >> n;
                        cortes.push_back(n);
                }

                cout << "The minimum cutting is " << cortar(0, l, 0) << ".\n";
        }
        
        return 0;
}
