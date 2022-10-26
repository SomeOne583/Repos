// Problema 902 - Password Search

#include <iostream>
#include <unordered_map>
#include <algorithm>

int main() {
        int passwordLength;
        std::string linea, posiblePassword;
        std::unordered_map<std::string, int> frecuencias;
        while (std::cin >> passwordLength >> linea) {
                frecuencias.clear();
                for (int i = 0; i < linea.size() - passwordLength; i++) {
                        posiblePassword = "";
                        for (int j = 0; j < passwordLength; j++) {
                                posiblePassword += linea[i + j];
                        }
                        if (frecuencias[posiblePassword]) {
                                frecuencias[posiblePassword]++;
                        } else {
                                frecuencias[posiblePassword] = 1;
                        }
                }

                std::unordered_map<std::string, int>::iterator itr, aux;
                int mayor = 0;
                for (itr = frecuencias.begin(); itr != frecuencias.end(); itr++) {
                        if (itr->second > mayor) {
                                mayor = itr->second;
                                aux = itr;
                        }
                }
                std::cout << aux->first << std::endl;
        }
        return 0;
}
