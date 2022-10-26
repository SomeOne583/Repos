#include <iostream>

int main() {
        std::string linea;
        while (getline(std::cin, linea)) {
                for (int i = 0; i < linea.size(); i++) {
                        std::cout << char(linea[i] - 7);
                }
                std::cout << std::endl;
        }
        
        return 0;
}
