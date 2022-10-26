// Problema 100 | 3n + 1

#include <iostream>

int teorema(int n) {
        int c = 1;
        while (n != 1) {
                c++;
                if (n % 2 == 0) {
                        n /= 2;
                } else {
                        n = 3 * n + 1;
                }
        }

        return c;
}

int main() {
        int a, b, mayor, c, aa, bb;

        while (std::cin >> a >> b) {
                mayor = 0;
                if (a > b) {
                        bb = a;
                        aa = b;
                } else {
                        aa = a;
                        bb = b;
                }
                for (int i = aa; i <= bb; i++) {
                        c = teorema(i);
                        if (c > mayor) {
                                mayor = c;
                        }
                }
                std::cout << a << " " << b << " " << mayor << std::endl;
        }


        return 0;
}