// Jan Carlo Reyes Martínez 577441
// Aplicación de la programación dinámica para determinar la cantidad mínima de monedas para regresar
// Doy mi palabra de que he realizado esta actividad con integridad acdémica

#include <iostream>
#include <vector>
#include <cmath>

int main() {
        int cambio = 13, a, b;
        std::vector<int> denominaciones = { 0, 1, 5, 6, 9 };
        std::vector<std::vector<int>> resultado;

        resultado.resize(denominaciones.size(), std::vector<int> (cambio + 1, 100));

        for (int i = 1; i < denominaciones.size(); i++) {
                for (int j = 0; j <= cambio; j++) {
                        if (denominaciones[i] <= j) {
                                a = resultado[i - 1][j];
                                b = j / denominaciones[i];
                                if (j % denominaciones[i] >= 1) {
                                        b+= resultado[i - 1][j % denominaciones[i]];
                                }
                                resultado[i][j] = std::min(a, b);
                        } else {
                                resultado[i][j] = resultado[i - 1][j];
                        }
                }
        }

        std::cout << "\t";
        for (int i = 0; i <= cambio; i++) {
                std::cout << i << "\t";
        }
        std::cout << std::endl;
        for (int i = 0; i < denominaciones.size(); i++) {
                std::cout << denominaciones[i] << "\t";
                for (int j = 0; j <= cambio; j++) {
                        std::cout << resultado[i][j] << "\t";
                }
                std::cout << std::endl;
        }

        std::cout << "Cantidad mínima de monedas: " << resultado[denominaciones.size() - 1][cambio] << std::endl;
}
