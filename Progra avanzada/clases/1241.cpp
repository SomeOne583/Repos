// Problema OJ 1241 Jollybee tournament

#include <iostream>
#include <vector>
#include <bitset>
#include <cmath>

int main() {
        int c, n, m, tmp, indice, wo;
        std::bitset<1024> torneo;

        std::cin >> c;
        for (int i = 0; i < c; i++) {
                wo = 0;
                std::cin >> n >> m;
                for (int j = 0; j < pow(2, n); j++) {
                        torneo[j] = 1;
                }
                for (int j = 0; j < m; j++) {
                        std::cin >> tmp;
                        torneo[tmp - 1] = 0;
                }
                for (int j = 0; j < n; j++) {
                        indice = 0;
                        for (int k = 0; k < 1024; k += 2) {
                                if (torneo[k] != torneo[k + 1]) {
                                        wo++;
                                }
                                if (torneo[k] || torneo[k + 1]) {
                                        torneo[indice] = 1;
                                } else {
                                        torneo[indice] = 0;
                                }
                                indice++;
                        }
                        for (int k = indice; k < 1024; k++) {
                                torneo[k] = 0;
                        }
                }
                std::cout << wo << std::endl;
        }

        return 0;
}