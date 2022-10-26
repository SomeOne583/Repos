#include <iostream>
#include <cmath>

int main() {
    long a, b;
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    while (std::cin >> a >> b) {
        std::cout << labs(a - b) << std::endl;
    }
    return 0;
}
