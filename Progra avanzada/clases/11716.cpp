// Problema 11716 - Digital Fortress

#include <iostream>
#include <cmath>

int main() {
        int n, c;
        std::string linea, b;

        std::cin >> n;

        getline(std::cin, linea);
        for (int i = 0; i <= n; i++) {
                getline(std::cin, linea);
                if (sqrt(linea.length()) == (int) sqrt(linea.length())) {
                        c = sqrt(linea.length());
                        for (int j = 0; j < c; j++) {
                                for (int k = 0; k < linea.size(); k+=c) {
                                        std::cout << linea[j + k];
                                }
                        }
                } else {
                        std::cout << "INVALID";
                }
                if (i != n - 1) {
                        std::cout << std::endl;
                }
        }
        
        return 0;
}