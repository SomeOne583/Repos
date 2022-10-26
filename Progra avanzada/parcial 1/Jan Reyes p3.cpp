#include <iostream>
#include <cstring>
#include <sstream>
#include <bitset>
#include <cmath>
#include <algorithm>
#include <vector>

int main() {
    int c, dif, cantEspacios, tmp;
    std::string caso;
    std::vector<int> nums;
    std::bitset<2999> apariciones;

    std::cin >> c;
    getline(std::cin, caso);

    for (int i = 0; i < c; i++) {
        apariciones.reset();
        apariciones.flip();
        nums.clear();
        cantEspacios = 0;
        getline(std::cin, caso);

        for (int i = 0; i < caso.size(); i++) {
            if (caso[i] == ' ') {
                cantEspacios++;
            }
        }

        if (cantEspacios > 0) {
            std::stringstream ss(caso);
            for (int i = 0; i < cantEspacios + 1; i++) {
                ss >> tmp;
                nums.push_back(tmp);
            }
            
            for (int i = nums.size() - 2; i < 2999; i++) {
                apariciones[i] = 0;
            }

            for (int i = 0; i < nums.size() - 1; i++) {
                apariciones[abs(nums[i] - nums[i + 1]) - 1] = 0;
            }
        } else {
            apariciones.reset();
        }

        if (apariciones.any()) {
            std::cout << "imperfecta" << std::endl;
        } else {
            std::cout << "perfecta" << std::endl;
        }
    }

    return 0;
}