#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
        bool small = true;
        int N, K, n, acum;
        vector<int> nums, nums2;
        vector<vector<int>> sol;

        cin >> N >> K;

        for (int i = 0; i < K; i++) {
                cin >> n;
                nums.push_back(n);
        }
        sort(nums.begin(), nums.end());

        sol.resize(N, {});

        for (int i = 0; i < K / N; i++) {
                for (int j = 0; j < N; j++) {
                        if (small) {
                                sol[j].push_back(nums[0]);
                                nums.erase(nums.begin());
                        } else {
                                sol[j].push_back(nums.back());
                                nums.erase(nums.end() - 1);
                        }
                }
                small = !small;
        }

        for (int i = 0; i < N; i++) {
                acum = 0;
                for (int j = 0; j < K / N; j++) {
                        acum += sol[i][j];
                }
                nums.push_back(acum);
        }
        sort(nums.begin(), nums.end());
        cout << nums.back() - nums[0] << endl;
        
        return 0;
}
