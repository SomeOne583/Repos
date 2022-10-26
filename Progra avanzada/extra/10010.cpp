#include <iostream>
#include <vector>

bool search(int x, int y, std::string palabra, std::vector<std::string> &grid) {
        std::string intento = "";
        for (int i = 0; i < palabra.size(); i++) {
                palabra[i] = tolower(palabra[i]);
        }
        // Arriba
        if (y >= palabra.size() - 1) {
                for (int i = 0; i < palabra.size(); i++) {
                        intento += tolower(grid[y - i][x]);
                }
                if (intento == palabra) {
                        return true;
                } else {
                        intento = "";
                }
        }
        if (y >= palabra.size() - 1 && grid[0].size() - x >= palabra.size()) {
                for (int i = 0; i < palabra.size(); i++) {
                        intento += tolower(grid[y - i][x + i]);
                }
                if (intento == palabra) {
                        return true;
                } else {
                        intento = "";
                }
        }
        if (grid[0].size() - x >= palabra.size()) {
                for (int i = 0; i < palabra.size(); i++) {
                        intento += tolower(grid[y][x + i]);
                }
                if (intento == palabra) {
                        return true;
                } else {
                        intento = "";
                }
        }
        if (grid.size() - y >= palabra.size() && grid[0].size() - x >= palabra.size()) {
                for (int i = 0; i < palabra.size(); i++) {
                        intento += tolower(grid[y + i][x + i]);
                }
                if (intento == palabra) {
                        return true;
                } else {
                        intento = "";
                }
        }
        if (grid.size() - y >= palabra.size()) {
                for (int i = 0; i < palabra.size(); i++) {
                        intento += tolower(grid[y + i][x]);
                }
                if (intento == palabra) {
                        return true;
                } else {
                        intento = "";
                }
        }
        if (x >= palabra.size() && grid.size() - y >= palabra.size()) {
                for (int i = 0; i < palabra.size(); i++) {
                        intento += tolower(grid[y + i][x - i]);
                }
                if (intento == palabra) {
                        return true;
                } else {
                        intento = "";
                }
        }
        if (x >= palabra.size()) {
                for (int i = 0; i < palabra.size(); i++) {
                        intento += tolower(grid[y][x - i]);
                }
                if (intento == palabra) {
                        return true;
                } else {
                        intento = "";
                }
        }
        if (x >= palabra.size() && y >= palabra.size()) {
                for (int i = 0; i < palabra.size(); i++) {
                        intento += tolower(grid[y - i][x - i]);
                }
                if (intento == palabra) {
                        return true;
                } else {
                        intento = "";
                }
        }

        return false;
}

int main() {
        int casos, filas, columnas, cantPalabras;
        std::string linea;
        std::vector<std::string> grid;

        std::cin >> casos;
        for (int i = 0; i < casos; i++) {
                std::cin >> filas >> columnas;
                for (int j = 0; j < filas; j++) {
                        std::cin >> linea;
                        grid.push_back(linea);
                }
                std::cin >> cantPalabras;
                for (int j = 0; j < cantPalabras; j++) {
                        std::cin >> linea;
                        for (int k = 0; k < filas; k++) {
                                for (int l = 0; l < columnas; l++) {
                                        if (tolower(grid[k][l]) == tolower(linea[0])) {
                                                if (search(l, k, linea, grid)) {
                                                        std::cout << k + 1 << " " << l + 1 << std::endl;
                                                        linea = "";
                                                        break;
                                                }
                                        }
                                }
                                if (linea == "") {
                                        break;
                                }
                        }
                }
                grid.clear();
                if (i != casos - 1) {
                        std::cout << "\n";
                }
        }
        
        return 0;
}
