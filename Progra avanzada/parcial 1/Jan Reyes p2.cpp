// Problema 1 del parcial - Jan Carlo Reyes Martínez - 577441
// Doy mi palabra de que he realizado esta actividad con integridad académica

#include <iostream>
#include <cmath>

int main() {
    int c, total, valor;
    std::string placa;

    std::cin >> c;
    getline(std::cin, placa);

    for (int i = 0; i < c; i++) {
        total = 0;
        valor = 0;
        getline(std::cin, placa);
        total = (placa[0] - 'A') * pow(26, 2);
        total += (placa[1] - 'A') * pow(26, 1);
        total += (placa[2] - 'A');

        valor = std::stoi(placa.substr(4));

        if (abs(total - valor) <= 100) {
            std::cout << "REGIA" << std::endl;
        } else {
            std::cout << "NO REGIA" << std::endl;
        }
    }

    return 0;
}