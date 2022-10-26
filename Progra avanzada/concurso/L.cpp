#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


int main() {
        // ios_base::sync_with_stdio(false);
        // cin.tie(NULL);

        int Q, N, K, cant, maximo = 100000;
        vector<int> mayores(maximo + 1, 0);

        for (int i = 2; i <= maximo; i++) {
                if (mayores[i] == 0) {
                        for (int j = 1; i * j <= maximo; j++) {
                                mayores[i * j] = i;
                        }
                }
        }

        cin >> Q;

        while (Q--) {
                cant = 0;
                cin >> N >> K;
                for (int i = 2; i <= N; i++) {
                        if (mayores[i] <= K) {
                                cant++;
                        }
                }
                cout << cant << '\n';
        }

        return 0;
}
