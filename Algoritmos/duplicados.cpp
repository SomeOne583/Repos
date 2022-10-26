// Doy mi palabra de que he realizado esta actividad con integridad acdémica

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

int main() {
        int s;
        std::vector<int> original;
        std::unordered_set<int> detector, duplicados;

        original.push_back(1);
        original.push_back(2);
        original.push_back(3);
        original.push_back(5);
        original.push_back(1);
        original.push_back(6);
        original.push_back(9);
        original.push_back(10);
        original.push_back(10);
        original.push_back(5);
        original.push_back(5);

        for (int i = 0; i < original.size(); i++) {
                s = detector.size();
                detector.insert(original[i]);
                if (detector.size() == s) {
                        duplicados.insert(original[i]);
                }
        }

        for (int i: duplicados) {
                std::cout << i << std::endl;
        }
}