// Problema 10008 What's Cryptanalysis?

#include <iostream>
#include <algorithm>
#include <vector>

int main() {
        int n;
        bool continuar;
        std::string linea;
        std::vector<int> contador(26, 0), aux;
        std::vector<int>::iterator index;

        std::cin >> n;
        getline(std::cin, linea);

        for (int i = 0; i < n; i++) {
                getline(std::cin, linea);
                
                for (int i = 0; i < linea.length(); i++) {
                        if (isalpha(linea[i])) {
                                contador[toupper(linea[i]) - 'A']++;
                        }
                }
        }

        aux = contador;

        std::sort(contador.begin(), contador.end(), std::greater<int> ());

        for (int i = 0; i < contador.size(); i++) {
                index = std::find(aux.begin(), aux.end(), contador[i]);
                if (contador[i] != 0) {
                        std::cout << char((index - aux.begin()) + 'A') << ' ' << contador[i] << std::endl;
                        aux[(index - aux.begin())] = 0;
                }
        }

        return 0;
}