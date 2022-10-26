#include <iostream>
#include <vector>
#include <map>

int main() {
        char l;
        long long tmp, total, N, Q, a, b;
        std::vector<long long> datos;
        std::map<long long, long long> cuadrados;

        std::cin >> N >> Q;

        for (long long i = 0; i < N; i++) {
                std::cin >> tmp;
                datos.push_back(tmp);
        }
        for (long long i = 0; i < Q; i++) {
                std::cin >> l;
                if (l == 'u') {
                        std::cin >> a >> b >> tmp;
                        a--;
                        b--;
                        for (long long j = a; j <= b; j++) {
                                datos[j] += tmp;
                        }
                } else {
                        std::cin >> a >> b;
                        a--;
                        b--;
                        total = 0;
                        for (long long j = a; j <= b; j++) {
                                if (!cuadrados[datos[j]]) {
                                        cuadrados[datos[j]] = datos[j] * datos[j];
                                }
                                total += cuadrados[datos[j]];
                        }
                        std::cout << total << std::endl;
                }
        }
}
