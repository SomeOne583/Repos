#include <iostream>

int main() {
        int size = 20;
        int operaciones = size / 100;
        std::cout << size << " " << operaciones + 1 << std::endl;

        for (int i = 0; i < size; i++) {
                if (i == size - 1) {
                        std::cout << "1" << std::endl;
                } else {
                        std::cout << "1 ";
                }
        }
        for (int i = 0; i < operaciones; i++) {
                std::cout << "u " << 100 * i + 1 << " " << 100 * (i + 1) << " " << 100 * i + 1 << std::endl;
        }
        std::cout << "q 1 " << size << std::endl;
}
