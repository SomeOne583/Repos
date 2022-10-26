#include <iostream>

int main() {
        int c;
        std::string linea, laberinto = "";

        while (getline(std::cin, linea)) {
                if (linea == "") {
                        std::cout << laberinto << "\n" << std::endl;
                        laberinto = "";
                } else if (laberinto != "") {
                        laberinto += "\n";
                }
                c = 0;
                for (int i = 0; i < linea.size(); i++) {
                        if (isdigit(linea[i])) {
                                c += linea[i] - '0';
                        } else {
                                if (linea[i] == 'b') {
                                        laberinto += std::string(c, ' ');
                                } else if (linea[i] == '!') {
                                        laberinto += '\n';
                                } else {
                                        laberinto += std::string(c, linea[i]);
                                }
                                c = 0;
                        }
                }
        }
        std::cout << laberinto << std::endl;
        
        return 0;
}
