#include <iostream>
#include <algorithm>

std::string evaluar(std::string expresion) {
        int indexI, parentesis = 0, v, f;
        while (expresion.find('(') != std::string::npos) {
                indexI = -1;
                for (int i = 0; i < expresion.size(); i++) {
                        if (expresion[i] == '(') {
                                if (indexI == -1) {
                                        indexI = i;
                                } else {
                                        parentesis++;
                                }
                        } else if (expresion[i] == ')') {
                                if (parentesis == 0) {
                                        expresion.replace(indexI, i - indexI + 1, evaluar(expresion.substr(indexI + 1, i - indexI - 1)));
                                        break;
                                } else {
                                        parentesis--;
                                }
                        }
                }
        }

        for (int i = 0; i < expresion.size(); i++) {
                if (expresion[i] == '!') {
                        if (expresion[i + 1] == 'V') {
                                expresion.replace(i, 2, "F");
                        } else if (expresion[i + 1] == 'F') {
                                expresion.replace(i, 2, "V");
                        } else {
                                v = expresion.find('V', i);
                                f = expresion.find('F', i);
                                indexI = (v == -1 || f == -1) ? std::max(f, v) : std::min(f, v);
                                for (int j = indexI; j > i; j--) {
                                        if (expresion[j] == 'V') {
                                                expresion.replace(j - 1, 2, "F");
                                        } else if (expresion[j] == 'F') {
                                                expresion.replace(j - 1, 2, "V");
                                        }
                                }
                        }
                        i = 0;
                }
        }
        for (int i = 0; i < expresion.size(); i++) {
                if (expresion[i] == '&') {
                        if (expresion[i - 1] == 'V' && expresion[i + 1] == 'V') {
                                expresion.replace(i - 1, 3, "V");
                        } else {
                                expresion.replace(i - 1, 3, "F");
                        }
                        i--;
                }
        }
        for (int i = 0; i < expresion.size(); i++) {
                if (expresion[i] == '|') {
                        if (expresion[i - 1] == 'V' || expresion[i + 1] == 'V') {
                                expresion.replace(i - 1, 3, "V");
                        } else {
                                expresion.replace(i - 1, 3, "F");
                        }
                        i--;
                }
        }
        return expresion;
}

int main() {
        int i = 0;
        std::string linea;

        while (getline(std::cin, linea)) {
                linea.erase(std::remove_if(linea.begin(), linea.end(), ::isspace), linea.end());
                std::cout << "Expression " << i + 1 << ": " << evaluar(linea) << std::endl;
                i++;
        }
        
        return 0;
}
