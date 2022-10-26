// Jan Carlo Reyes Martínez - 577441
// Doy mi palabra de que he realizado esta actividad con integridad académica

#include <iostream>
#include <vector>
#include <algorithm>

int main() {
        int total = 0, tope = 36;
        std::vector<int> monedas = { 25, 10, 10, 5, 1, 1 }, elegidas;
        std::sort(monedas.begin(), monedas.end(), std::greater<int>());
        for (int i = 0; i < monedas.size(); i++) {
                if (total + monedas[i] <= tope) {
                        elegidas.push_back(monedas[i]);
                        total += monedas[i];
                }
                if (total == tope) {
                        break;
                }
        }
        std::cout << "Monedas usadas: ";
        for (int i = 0; i < elegidas.size(); i++) {
                if (i == elegidas.size() - 1) {
                        std::cout << elegidas[i] << std::endl;
                } else {
                        std::cout << elegidas[i] << ", ";
                }
        }
        
        return 0;
}
