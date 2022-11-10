#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>

using namespace std;

unsigned long long calculos[100][100];

unsigned long long solve(int n, int l) {
        if (calculos[n][l] == -1) {
                if (n > 9 * l) {
                        calculos[n][l] = 0;
                } else if (l == 1) {
                        calculos[n][l] = 1;
                } else {
                        long acum = 0;
                        for (int i = n; i >= max(0, n - 9); i--) {
                                acum += solve(i, l - 1);
                        }
                        calculos[n][l] = acum;
                }
        }
        return calculos[n][l];
}

int main() {
        int N, k;
        memset(calculos, -1, sizeof(calculos));

        cin >> k;

        while (k--) {
                cin >> N;
                if (N == 1) {
                        cout << solve(N, N) + 1 << "\n";
                } else {
                        cout << solve(N, N) << "\n";
                }
        }
        
        return 0;
}
