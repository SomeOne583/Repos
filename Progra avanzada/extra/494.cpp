#include <iostream>
#include <sstream>

int main() {
        int c;
        bool nuevaPalabra;
        std::string linea, palabra;

        while(getline(std::cin, linea)) {
                c = 0;
                std::stringstream lineaS(linea);
                while(getline(lineaS, palabra, ' ')) {
                        nuevaPalabra = true;
                        for (int i = 0; i < palabra.size(); i++) {
                                if (isalpha(palabra[i]) && nuevaPalabra) {
                                        c++;
                                        nuevaPalabra = false;
                                } else if (!isalpha(palabra[i])) {
                                        nuevaPalabra = true;
                                }
                        }
                }
                std::cout << c << std::endl;
        }
        
        return 0;
}