#include <iostream>
#include <vector>

int main() {
        int mayor = 0;
        std::string linea;
        std::vector<std::string> lineas;

        while (getline(std::cin, linea)) {
                lineas.push_back(linea);
                if (linea.size() > mayor) {
                        mayor = linea.size();
                }
        }
        for (int i = 0; i < lineas.size(); i++) {
                while (lineas[i].size() < mayor) {
                        lineas[i] += " ";
                }
        }
        for (int i = 0; i < mayor; i++) {
                for (int j = lineas.size() - 1; j >= 0; j--) {
                        std::cout << lineas[j][i];
                }
                std::cout << std::endl;
        }
        
        return 0;
}
