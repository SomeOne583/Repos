// 10394 - Twin Prime

#include <iostream>
#include <cmath>
#include <vector>

int main() {
        int max = 20000000, pivote = 2, nth;
        std::vector<int> P;
        std::vector<bool> B(max + 1, true);

        while (pivote <= sqrt(max)) {
                for (int i = pivote * 2; i <= max; i += pivote) {
                        B[i] = false;
                }
                for (pivote++; !B[pivote]; pivote++);
        }

        for (int i = 2; i <= max; i++) {
                if (B[i] && B[i + 2]) {
                        P.push_back(i);
                }
        }

        while (std::cin >> nth) {
                std::cout << "(" << P[nth - 1] << ", " << P[nth - 1] + 2 << ")" << std::endl;
        }

        return 0;
}
