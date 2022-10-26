// Problema 1 del parcial - Jan Carlo Reyes Martínez - 577441
// Doy mi palabra de que he realizado esta actividad con integridad académica

#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>

int main() {
    int contador;
    std::string palabra;
    std::vector<std::string> diccionario;
    std::bitset<100> encontradas;
    std::vector<char> letras;

    while (std::cin >> palabra && palabra != "#") {
        diccionario.push_back(palabra);
    }
    getline(std::cin, palabra);
    while (getline(std::cin, palabra) && palabra != "#") {
        contador = 0;
        letras.clear();
        for (int i = 0; i < palabra.size(); i += 2) {
            letras.push_back(palabra[i]);
        }
        sort(letras.begin(), letras.end());
        encontradas.reset();
        do {
            palabra = "";
            for (int i = 0; i < letras.size(); i++) {
                palabra += letras[i];
            }
            for (int i = 0; i < diccionario.size(); i++) {
                if (!encontradas[i]) {
                    if (palabra.find(diccionario[i]) != std::string::npos) {
                        contador++;
                        encontradas[i] = 1;
                        break;
                    }
                }
            }
        } while (std::next_permutation(letras.begin(), letras.end()));
        std::cout << contador << std::endl;
    }

    return 0;
}
