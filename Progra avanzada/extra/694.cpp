#include <iostream>

int main() {
        int c, caso = 0;
        long A, L;
        while (std::cin >> A >> L && (A > 0 || L > 0)) {
                c = 0;
                caso++;
                std::cout << "Case " << caso << ": A = " << A << ", limit = " << L << ", number of terms = ";
                while (A <= L) {
                        c++;
                        if (A == 1) {
                                break;
                        } else if (A % 2 == 0) {
                                A /= 2;
                        } else {
                                A = A * 3 + 1;
                        }
                }
                std::cout << c << std::endl;
        }

        return 0;
}
