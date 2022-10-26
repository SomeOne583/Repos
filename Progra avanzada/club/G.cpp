#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
        int n;
        vector<int> nums;

        for (int i = 0; i < 4; i++) {
                cin >> n;
                nums.push_back(n);
        }
        sort(nums.begin(), nums.end());

        cout << abs((nums[0] + nums[3]) - (nums[1] + nums[2])) << "\n";
        
        return 0;
}
