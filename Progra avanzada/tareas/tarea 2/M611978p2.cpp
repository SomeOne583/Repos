#include <iostream>

int main() {
        int a, b, c, d, moves;

        std::cin >> a >> b >> c >> d;

        do {
                if (a == c && b == d) {
                        moves = 0;
                } else if (a == c || b == d || abs(a - c) == abs(b - d)) {
                        moves = 1;
                } else {
                        moves = 2;
                }

                std::cout << moves << std::endl;
                std::cin >> a >> b >> c >> d;
        } while (a != 0 && b != 0 && c != 0 && d != 0);

        return 0;
}
