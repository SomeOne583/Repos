#include <iostream>
#include <unordered_map>

int main() {
        int c = 0;
        std::string palabra, lectura;
        std::unordered_map<std::string, int> indexes;
        for (int i = 0; i < 23; i++) {
                for (int j = 0; j < 24; j++) {
                        if (i != 0 && j <= i) {
                                j = i + 1;
                        }
                        for (int k = 0; k < 25; k++) {
                                if (j != 0 && k <= j) {
                                        k = j + 1;
                                }
                                for (int l = 0; l < 26; l++) {
                                        if (k != 0 && l <= k) {
                                                l = k + 1;
                                        }
                                        for (int m = 1; m < 27; m++) {
                                                if (l != 0 && m <= l) {
                                                        m = l + 1;
                                                }
                                                palabra = "";
                                                if (i != 0) {
                                                        palabra += char('`' + i);
                                                }
                                                if (j != 0) {
                                                        palabra += char('`' + j);
                                                }
                                                if (k != 0) {
                                                        palabra += char('`' + k);
                                                }
                                                if (l != 0) {
                                                        palabra += char('`' + l);
                                                }
                                                if (m != 0) {
                                                        palabra += char('`' + m);
                                                }
                                                if (palabra != "") {
                                                        c++;
                                                        indexes[palabra] = c;
                                                }
                                        }
                                }
                        }
                }
        }

        while (std::cin >> lectura) {
                std::cout << indexes[lectura] << std::endl;
        }

        return 0;
}
