#include <iostream>
#include <unordered_map>

int main() {
        bool palindromo, espejo;
        std::string palabra, volteada;
        std::unordered_map<char, char> reversos;

        reversos['A'] = 'A';
        reversos['E'] = '3';
        reversos['H'] = 'H';
        reversos['I'] = 'I';
        reversos['J'] = 'L';
        reversos['L'] = 'J';
        reversos['M'] = 'M';
        reversos['O'] = 'O';
        reversos['S'] = '2';
        reversos['T'] = 'T';
        reversos['U'] = 'U';
        reversos['V'] = 'V';
        reversos['W'] = 'W';
        reversos['X'] = 'X';
        reversos['Y'] = 'Y';
        reversos['Z'] = '5';
        reversos['1'] = '1';
        reversos['2'] = 'S';
        reversos['3'] = 'E';
        reversos['5'] = 'Z';
        reversos['8'] = '8';

        while (std::cin >> palabra) {
                palindromo = true;
                espejo = true;
                for (int i = 0; i <= palabra.size() / 2; i++) {
                        if (!(palabra[i] == palabra[palabra.size() - 1 - i])) {
                                palindromo = false;
                        }
                        if (!(palabra[i] == reversos[palabra[palabra.size() - 1 - i]])) {
                                espejo = false;
                        }
                        if (!palindromo && !espejo) {
                                break;
                        }
                }
                if (palindromo && espejo) {
                        std::cout << palabra << " -- is a mirrored palindrome." << std::endl;
                } else if (palindromo) {
                        std::cout << palabra << " -- is a regular palindrome." << std::endl;
                } else if (espejo) {
                        std::cout << palabra << " -- is a mirrored string." << std::endl;
                } else {
                        std::cout << palabra << " -- is not a palindrome." << std::endl;
                }
                std::cout << std::endl;
        }
        
        return 0;
}
