#include <iostream>
#include <vector>
#include <algorithm>

int main() {
        int n, m, basura, a, b, acum;
        std::vector<int> cabezas, caballeros;

        while (std::cin >> n >> m && !(n == 0 && m == 0)) {
                cabezas.clear();
                caballeros.clear();
                a = 0;
                b = 0;
                acum = 0;
                for (int i = 0; i < n; i++) {
                        std::cin >> basura;
                        cabezas.push_back(basura);
                }
                for (int i = 0; i < m; i++) {
                        std::cin >> basura;
                        caballeros.push_back(basura);
                }
                if (n > m) {
                        std::cout << "Loowater is doomed!" << std::endl;
                } else {
                        sort(caballeros.begin(), caballeros.end());
                        sort(cabezas.begin(), cabezas.end());
                        while (a != caballeros.size() && b != cabezas.size()) {
                                if (caballeros[a] >= cabezas[b]) {
                                        acum += caballeros[a];
                                        a++;
                                        b++;
                                } else {
                                        a++;
                                }
                        }
                        if (b == cabezas.size()) {
                                std::cout << acum << std::endl;
                        } else {
                                std::cout << "Loowater is doomed!" << std::endl;
                        }
                }
        }
        
        return 0;
}
