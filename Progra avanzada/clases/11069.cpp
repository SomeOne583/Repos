#include <iostream>
#include <cstring>

using namespace std;

int memo[78][78];

int solve(int i, int &N)
{
        if (memo[i][N] == -1)
                memo[i][N] = solve(i + 2, N) + solve(i + 3, N);
        return memo[i][N];
}

int main()
{
        int n;

        memset(memo, -1, sizeof(memo));
        for (int i = 0; i < 77; i++) {
                if (i > 0)
                        memo[i][i - 1] = 0;
                memo[i][i] = 1;
                if (i < 76)
                        memo[i][i + 1] = 1;
        }

        while (cin >> n)
                cout << solve(1, n) + solve(2, n) << "\n";
}
