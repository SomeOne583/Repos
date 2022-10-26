#include <iostream>
#include <vector>
#include <cmath>

int main() {
        int pivote = 2, max = 5000001;
        std::vector<int> primos;
        std::vector<bool> esPrimo(max, true);
        
        while (pivote <= sqrt(max)) {
                for (int i = pivote * 2; i <= max; i+= pivote) {
                        esPrimo[i] = false;
                }
                for (pivote++; !esPrimo[pivote]; pivote++);
        }

        for (int i = 2; i <= max; i++){
                if(esPrimo[i]) {
                        primos.push_back(i);
                }
        }

        

        return 0;
}