#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int costos[1000][1000];
int costosMinimos[1000][1000];

int viajar(int i, int f) {
        if (costosMinimos[i][f] == -1) {
                int menor = costos[i][f];
                for (int k = i + 1; k <= f; k++) {
                        menor = min(menor, costos[i][k] + viajar(k, f));
                }
                costosMinimos[i][f] = menor;
        }
        return costosMinimos[i][f];
}

int main() {
        int n;

        cin >> n;

        memset(costosMinimos, -1, sizeof(costosMinimos));

        for (int i = 0; i < n; i++) {
                for (int j = i; j < n; j++) {
                        cin >> costos[i][j];
                        if (i == j) {
                                costosMinimos[i][j] = 0;
                        } else if (i + 1 == j) {
                                costosMinimos[i][j] = costos[i][j];
                        }
                }
        }

        for (int i = 0; i < n; i++) {
                for (int j = i; j < n; j++) {
                        cout << viajar(i, j) << " ";
                }
                cout << "\n";
        }

        return 0;
}
