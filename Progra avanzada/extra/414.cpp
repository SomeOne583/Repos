#include <iostream>
#include <vector>

int main() {
        int c, mayor, cont;
        std::string linea;
        std::vector<int> nums;
        while (std::cin >> c && c != 0) {
                getline(std::cin, linea);
                nums.clear();
                mayor = 0;

                for (int i = 0; i < c; i++) {
                        getline(std::cin, linea);
                        cont = 0;
                        for (int j = 0; j < linea.size(); j++) {
                                if (linea[j] == 'X') {
                                        cont++;
                                }
                        }
                        nums.push_back(cont);
                        if (cont > mayor) {
                                mayor = cont;
                        }
                }
                cont = 0;
                for (int i = 0; i < nums.size(); i++) {
                        cont += mayor - nums[i];
                }
                std::cout << cont << std::endl;
        }
        
        return 0;
}
