#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
#include <bitset>

using namespace std;

int menor = 10000, operaciones = 0;
vector<bool> visitados(18, false);
vector<vector<int>> grafo(18, vector<int>(18, 99));
map<pair<int, int>, int> dp;
bitset<18> m(1);

bool existeNodo(pair<int, int> nodo) {
        try {
                dp.at(nodo);
                return true;
        } catch (const out_of_range& oor) {
                return false;
        }
        return true;
}

int solve(int i, bitset<18> m)
{
        if (m.all()) {
                return grafo[i][0];
        }
        if (existeNodo({ i, m.to_ulong() })) {
                return dp[{ i, m.to_ulong() }];
        }
        int menor = 1000000;
        for (int k = 0; k < grafo.size(); k++) {
                if (!m[k]) {
                        m[k] = 1;
                        menor = min(menor, grafo[i][k] + solve(k, m));
                        m[k] = 0;
                }
                dp[{ i, m.to_ulong() }] = menor;
        }
        return dp[{ i, m.to_ulong() }];
}

int main()
{
        // Llenar datos
        grafo[0][1] = 3;
        grafo[1][0] = 3;

        grafo[0][2] = 7;
        grafo[2][0] = 7;

        grafo[0][14] = 1;
        grafo[14][0] = 1;

        grafo[1][2] = 4;
        grafo[2][1] = 4;

        grafo[2][3] = 4;
        grafo[3][2] = 4;

        grafo[2][6] = 4;
        grafo[6][2] = 4;

        grafo[3][10] = 2;
        grafo[10][3] = 2;

        grafo[4][5] = 8;
        grafo[5][4] = 8;

        grafo[4][7] = 3;
        grafo[7][4] = 3;

        grafo[4][8] = 3;
        grafo[8][4] = 3;

        grafo[5][6] = 7;
        grafo[6][5] = 7;

        grafo[5][8] = 8;
        grafo[8][5] = 8;

        grafo[6][9] = 2;
        grafo[9][6] = 2;

        grafo[6][10] = 7;
        grafo[10][6] = 7;

        grafo[7][8] = 4;
        grafo[8][7] = 4;

        grafo[7][11] = 3;
        grafo[11][7] = 3;

        grafo[7][14] = 7;
        grafo[14][7] = 7;

        grafo[8][9] = 3;
        grafo[9][8] = 3;

        grafo[8][11] = 8;
        grafo[11][8] = 8;

        grafo[8][12] = 6;
        grafo[12][8] = 6;

        grafo[9][10] = 9;
        grafo[10][9] = 9;

        grafo[9][13] = 3;
        grafo[13][9] = 3;

        grafo[10][13] = 4;
        grafo[13][10] = 4;

        grafo[11][14] = 7;
        grafo[14][11] = 7;

        grafo[11][15] = 5;
        grafo[15][11] = 5;

        grafo[12][13] = 4;
        grafo[13][12] = 4;

        grafo[13][17] = 9;
        grafo[17][13] = 9;
        
        grafo[14][15] = 7;
        grafo[15][14] = 7;

        grafo[15][16] = 5;
        grafo[16][15] = 5;

        grafo[15][17] = 2;
        grafo[17][15] = 2;

        grafo[16][17] = 4;
        grafo[17][16] = 4;


        for (int i = 0; i < grafo.size(); i++) {
                grafo[i][i] = 0;
        }

        cout << solve(0, m) << "\n";

        return 0;
}
