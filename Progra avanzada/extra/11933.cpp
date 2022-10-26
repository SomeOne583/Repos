#include <iostream>
#include <bitset>

int main() {
        int n;
        bool turnoA;
        std::bitset<31> nBit, a, b;
        while (std::cin >> n && n != 0) {
                turnoA = true;
                a.reset();
                b.reset();
                nBit = std::bitset<31>(n);
                for (int i = 0; i < 31; i++) {
                        if (nBit[i]) {
                                if (turnoA) {
                                        a[i] = true;
                                } else {
                                        b[i] = true;
                                }
                                turnoA = !turnoA;
                        }
                }
                std::cout << a.to_ullong() << " " << b.to_ullong() << std::endl;
        }

        return 0;
}