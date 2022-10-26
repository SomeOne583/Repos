#include <iostream>
#include <algorithm>

int main() {
        int r, aciertos, fallos;
        std::string linea1, linea2, palabraAdivinar, intentos;
        std::size_t encontrado;
        while (std::cin >> r && r != -1) {
                fallos = 0;
                aciertos = 0;
                palabraAdivinar = "";
                intentos = "";
                std::cin >> linea1 >> linea2;
                for (int i = 0; i < linea1.size(); i++) {
                        if (palabraAdivinar.find(linea1[i]) == std::string::npos) {
                                palabraAdivinar += linea1[i];
                        }
                }
                for (int i = 0; i < linea2.size(); i++) {
                        if (intentos.find(linea2[i]) == std::string::npos) {
                                intentos += linea2[i];
                        }
                }
                for (int i = 0; i < intentos.size(); i++) {
                        encontrado = palabraAdivinar.find(intentos[i]);
                        if (encontrado != std::string::npos) {
                                aciertos++;
                        } else {
                                fallos++;
                        }
                        if (aciertos == palabraAdivinar.size() || fallos == 7) {
                                break;
                        }
                }
                std::cout << "Round " << r << std::endl;
                if (aciertos == palabraAdivinar.size()) {
                        std::cout << "You win." << std::endl;
                } else if (fallos == 7) {
                        std::cout << "You lose." << std::endl;
                } else {
                        std::cout << "You chickened out." << std::endl;
                }
        }
        
        return 0;
}
