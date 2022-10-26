#include <iostream>
#include <vector>
#include <map>

int main() {
        char l;
        int N, Q, a, b;
        long long tmp, total;
        std::vector<long long> datos;

        std::cin >> N >> Q;

        for (int i = 0; i < N; i++) {
                std::cin >> tmp;
                datos.push_back(tmp);
        }
        for (int i = 0; i < Q; i++) {
                std::cin >> l;
                if (l == 'u') {
                        std::cin >> a >> b >> tmp;
                        a--;
                        b--;
                        for (int j = a; j <= b; j++) {
                                datos[j] += tmp;
                        }
                } else {
                        std::cin >> a >> b;
                        a--;
                        b--;
                        total = 0;
                        for (int j = a; j <= b; j++) {
                                total += datos[j] * datos[j];
                        }
                        std::cout << total << std::endl;
                }
        }
}
