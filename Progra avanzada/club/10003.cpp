#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int acum, menor;
vector<int> tronco, cortes;
vector<bool> cortados;

void cut() {
        bool terminado = true;
        for (size_t i = 0; i < cortados.size() && terminado; i++) {
                if (!cortados[i]) {
                        terminado = false;
                }
        }
        if (terminado) {
                if (menor == -1 || acum < menor) {
                        menor = acum;
                }
        } else {
                for (size_t i = 0; i < cortes.size(); i++) {
                        if (!cortados[i]) {
                                int j, a;
                                for (j = 0; j < tronco.size() && tronco[j] < cortes[i]; j++);
                                a = (tronco[j] - tronco[j - 1]);
                                acum += a;
                                tronco.insert(tronco.begin() + j, cortes[i]);
                                cortados[i] = true;
                                cut();
                                acum -= a;
                                tronco.erase(tronco.begin() + j);
                                cortados[i] = false;
                        }
                }
        }
}

int main() {
        /*
        [ 0 100 ]
        [ 0 50 100 ]
        [ 0 25 50 100 ]
        [ 0 25 50 75 100 ]
        */
        int l, n, c;
        while (cin >> l && l != 0) {
                acum = 0;
                menor = -1;
                tronco = { 0, l };
                cortes.clear();
                cortados.clear();

                cin >> n;

                while (n--) {
                        cin >> c;
                        cortes.push_back(c);
                }

                cortados.resize(cortes.size(), false);

                cut();

                cout << menor << "\n";
        }
        
        return 0;
}
