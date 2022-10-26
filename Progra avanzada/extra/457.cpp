#include <iostream>
#include <vector>

int main() {
        int casos, tmp;
        std::vector<int> dna, platos, platosAux;
        std::cin >> casos;
        for (int i = 0; i < casos; i++) {
                dna.clear();
                platos.clear();
                platos.resize(40, 0);
                platos[19] = 1;
                platosAux = platos;
                for (int j = 0; j < 10; j++) {
                        std::cin >> tmp;
                        dna.push_back(tmp);
                }
                for (int j = 0; j < 50; j++) {
                        for (int k = 0; k < 40; k++) {
                                if (platos[k] == 0) {
                                        std::cout << " ";
                                } else if (platos[k] == 1) {
                                        std::cout << ".";
                                } else if (platos[k] == 2) {
                                        std::cout << "x";
                                } else {
                                        std::cout << "W";
                                }
                        }
                        std::cout << std::endl;
                        platosAux[0] = dna[platos[0] + platos[1]];
                        platosAux[39] = dna[platos[38] + platos[39]];
                        for (int k = 1; k < 39; k++) {
                                platosAux[k] = dna[platos[k - 1] + platos[k] + platos[k + 1]];
                        }
                        platos = platosAux;
                }
                if (i != casos - 1) {
                        std::cout << "\n";
                }
        }
}
