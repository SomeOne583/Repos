#include <iostream>
#include <vector>

int main() {
        int c, tmp;
        bool jolly;
        std::vector<int> nums;
        std::vector<bool> estados;

        while (std::cin >> c) {
                jolly = true;
                nums.clear();
                estados.clear();
                for (int i = 0; i < c; i++) {
                        std::cin >> tmp;
                        nums.push_back(tmp);
                }
                if (nums.size() > 1) {
                        estados.resize(c - 1, false);
                        for (int i = 0; i < nums.size() - 1; i++) {
                                tmp = abs(nums[i] - nums[i + 1]);
                                tmp--;
                                if (tmp >= 0 && tmp < c - 1) {
                                        estados[tmp] = true;
                                }
                        }
                        for (int i = 0; i < estados.size(); i++) {
                                if (!estados[i]) {
                                        jolly = false;
                                        break;
                                }
                        }
                }
                if (jolly) {
                        std::cout << "Jolly" << std::endl;
                } else {
                        std::cout << "Not jolly" << std::endl;
                }
        }

        return 0;
}
