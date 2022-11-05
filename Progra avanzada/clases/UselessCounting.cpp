#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

long cant;
long factoriales[21];
int repeticiones[10];

long factorial(int n) {
        if (factoriales[n] == -1) {
                factoriales[n] = n * factorial(n - 1);
        }
        return factoriales[n];
}

void solve(string actual, int index, int acum, int N) {
        if (acum == N) {
                long perms = factorial(N) / factorial(N - actual.size());
                memset(repeticiones, 0, sizeof(repeticiones));
                for (size_t i = 0; i < actual.size(); i++) {
                        repeticiones[actual[i] - 48]++;
                }
                for (int i = 0; i < 10; i++) {
                        perms /= factorial(repeticiones[i]);
                }
                cant += perms;
                return;
        }
        for (int i = index; i < 10; i++) {
                if (acum + i <= N) {
                        solve(actual + char(48 + i), i, acum + i, N);
                }
        }
}

void solveMalo(string actual, int acum, int N) {
        if (actual.size() && acum == N) {
                cant++;
                return;
        }
        if (actual.size() == N) {
                return;
        }
        for (int i = 0; i < 10; i++) {
                if (acum + i <= N) {
                        solveMalo(actual + char(48 + i), acum + i, N);
                }
        }
}

int main() {
        int k, N;
        memset(factoriales, -1, sizeof(factoriales));
        factoriales[0] = 1;

        cin >> k;

        while (k--) {
                cant = 0;
                cin >> N;
                if (N == 1) {
                        cant++;
                }
                
                solve("", 1, 0, N);
                cout << cant << "\n";
        }

        return 0;
}