// Problema Walking Roger
// Jan Carlo Reyes Martínez, 577441
// Juan Manuel Cuevas Gaytan, 611978
// Damos nuestra palabra de que hemos realizado esta actividad con integridad académica

#include <iostream>
#include <algorithm>
#include <cmath>

bool isSingle(std::string s) {
        for (int i = 0; i < s.size(); i++) {
                if (s[i] == ' ') {
                        return false;
                }
        }
        return true;
}

int main() {
        std::string linea;
        std::string::iterator divisor;
        int indexDivisor, raiz, cx = 0, cy = 0;
        long long x, y, pos, diferencia;
        do {
                x = 0;
                y = 0;
                getline(std::cin, linea);
                if (isSingle(linea)) {
                        x = std::stoll(linea);
                } else {
                        divisor = find(linea.begin(), linea.end(), ' ');
                        indexDivisor = divisor - linea.begin();
                        x = std::stoll(linea.substr(0, indexDivisor));
                        y = std::stoll(linea.substr(indexDivisor + 1));
                }

                if (x == 0) {
                        break;
                } else if (y == 0) {
                        for (raiz = 1; pow(raiz, 2) < x; raiz++);
                        diferencia = pow(raiz, 2) - x;
                        if (raiz % 2 == 0) {
                                cx = raiz;
                                cy = 1;
                                while (diferencia > 0) {
                                        if (cy < raiz) {
                                                cy++;
                                        } else {
                                                cx--;
                                        }
                                        diferencia--;
                                }
                        } else {
                                cx = 1;
                                cy = raiz;
                                while (diferencia > 0) {
                                        if (cx < raiz) {
                                                cx++;
                                        } else {
                                                cy--;
                                        }
                                        diferencia--;
                                }
                        }
                        std::cout << cx << " " << cy << std::endl;
                } else {
                        raiz = (x > y) ? x : y;
                        pos = pow(raiz, 2);
                        if (raiz % 2 == 0) {
                                cx = raiz;
                                cy = 1;
                                while (cx != x || cy != y) {
                                        if (cy != y) {
                                                cy++;
                                        } else {
                                                cx--;
                                        }
                                        pos--;
                                }
                        } else {
                                cx = 1;
                                cy = raiz;
                                while (cx != x || cy != y) {
                                        if (cx != x) {
                                                cx++;
                                        } else {
                                                cy--;
                                        }
                                        pos--;
                                }
                        }
                        std::cout << pos << std::endl;
                }
        } while (x != 0);

        return 0;
}
