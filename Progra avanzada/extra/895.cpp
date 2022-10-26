#include <iostream>
#include <vector>
#include <algorithm>

int main() {
        int a, b, c;
        std::string linea, palabra;
        std::vector<std::string> palabras;

        while (std::cin >> linea && linea != "#") {
                std::sort(linea.begin(), linea.end());
                palabras.push_back(linea);
        }
        getline(std::cin, linea);
        while (getline(std::cin, linea) && linea != "#") {
                c = 0;
                palabra = "";
                for (int i = 0; i < linea.size(); i += 2) {
                        palabra += linea[i];
                }
                std::sort(palabra.begin(), palabra.end());
                for (int i = 0; i < palabras.size(); i++) {
                        a = 0;
                        b = 0;
                        while (a < palabras[i].length() && b < palabra.length()) {
                                if (palabras[i][a] == palabra[b]) {
                                        a++;
                                        b++;
                                } else {
                                        b++;
                                }
                        }
                        if (a == palabras[i].length()) {
                                c++;
                        }
                }
                std::cout << c << std::endl;
        }

        return 0;
}
