#include <iostream>
#include <set>

int main() {
        int N;
        long a, X;
        std::set<int> multiplos;
        std::cin >> N >> X;
        for (int i = 0; i < N; i++) {
                std::cin >> a;
                for (int j = 1; a * j <= X; j++) {
                        multiplos.insert(a * j);
                }
        }
        std::cout << multiplos.size() << std::endl;
}
