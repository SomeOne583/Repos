#include <iostream>
#include <vector>

using namespace std;

int ciclos;
vector<vector<bool>> container;

void kill(int f, int c) {
        container[f][c] = false;
        for (int i = f - 1; i <= f + 1; i++) {
                for (int j = c - 1; j <= c + 1; j++) {
                        if (container[i][j]) {
                                kill(i, j);
                        }
                }
        }
}

void solve() {
        for (size_t f = 1; f < container.size() - 1; f++) {
                for (size_t c = 1; c < container[0].size() - 1; c++) {
                        if (container[f][c]) {
                                ciclos++;
                                kill(f, c);
                        }
                }
        }
}

int main() {
        int f, c, C;
        char t;

        cin >> C;

        while (C--) {
                ciclos = 0;
                container.clear();
                cin >> f >> c;
                container.resize(f + 2, vector<bool>(c + 2, false));
                for (int i = 0; i < f; i++) {
                        for (int j = 0; j < c; j++) {
                                cin >> t;
                                if (t == '@') {
                                        container[i + 1][j + 1] = true;
                                }
                        }
                }
                solve();
                cout << ciclos << "\n";
        }
        
        return 0;
}
