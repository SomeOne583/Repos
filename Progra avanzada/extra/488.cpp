#include <iostream>

int main() {
        int c, a, b;
        std::cin >> c;
        for (int i = 0; i < c; i++) {
                std::cin >> a;
                std::cin >> b;
                for (int j = 0; j < b; j++) {
                        for (int k = 1; k < a; k++) {
                                std::cout << std::string(k, k + '0') << std::endl;
                        }
                        std::cout << std::string(a, a + '0') << std::endl;
                        for (int k = a - 1; k > 0; k--) {
                                std::cout << std::string(k, k + '0') << std::endl;
                        }
                        if (j < b - 1) {
                                std::cout << std::endl;
                        }
                }
                if (i < c - 1) {
                        std::cout << std::endl;
                }
        }
        
        return 0;
}
