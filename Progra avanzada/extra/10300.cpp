#include <iostream>

int main() {
        int casos, f, a, b, c, t;
        std::cin >> casos;
        for (int i = 0; i < casos; i++) {
                t = 0;
                std::cin >> f;
                for (int j = 0; j < f; j++) {
                        std::cin >> a >> b >> c;
                        t += (a * c);
                }
                std::cout << t << std::endl;
        }
        
        return 0;
}
