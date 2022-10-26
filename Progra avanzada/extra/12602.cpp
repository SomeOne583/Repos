#include <iostream>

int main() {
        int c, totalL, totalN;
        std::string placa;
        std::cin >> c;
        for (int i = 0; i < c; i++) {
                std::cin >> placa;
                totalL = (placa[0] - 'A') * 676 + (placa[1] - 'A') * 26 + (placa[2] - 'A');
                totalN = std::stoi(placa.substr(4));
                if (abs(totalL - totalN) <= 100) {
                        std::cout << "nice" << std::endl;
                } else {
                        std::cout << "not nice" << std::endl;
                }
        }
        
        return 0;
}