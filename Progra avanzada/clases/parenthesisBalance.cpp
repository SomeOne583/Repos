#include <iostream>
#include <stack>

int main() {
        int casos;
        char cierre;
        bool v;
        std::string linea;
        std::stack<char> inicios;

        std::cin >> casos;
        getline(std::cin, linea);

        for (int i = 0; i < casos; i++) {
                v = true;
                while (!inicios.empty()) {
                        inicios.pop();
                }
                getline(std::cin, linea);
                for (int j = 0; j < linea.size(); j++) {
                        if (linea[j] == '(' || linea[j] == '{' || linea[j] == '[') {
                                inicios.push(linea[j]);
                        } else {
                                if (inicios.empty()) {
                                        v = false;
                                        break;
                                }
                                cierre = inicios.top();
                                if (linea[j] == ')' && cierre == '(') {
                                        inicios.pop();
                                } else if (linea[j] == ']' && cierre == '[') {
                                        inicios.pop();
                                } else if (linea[j] == '}' && cierre == '{') {
                                        inicios.pop();
                                } else {
                                        v = false;
                                        break;
                                }
                        }
                }
                if (inicios.empty() && v) {
                        std::cout << "Yes" << std::endl;
                } else {
                        std::cout << "No" << std::endl;
                }
        }

        return 0;
}
