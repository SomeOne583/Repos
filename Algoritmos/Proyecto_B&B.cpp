#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int menor = 10000, operaciones = 0;
vector<int> camino = { 0 }, solucion;
vector<vector<int>> grafo(18, vector<int>(18, 99));

void solve(int acum)
{
        operaciones++;
        if (acum > menor) {
                operaciones++;
                return;
        }
        operaciones++;
        if (camino.size() == grafo.size()) {
                operaciones += 2;
                if (acum + grafo[camino.back()][camino[0]] < menor && grafo[camino.back()][camino[0]] != 0) {
                        operaciones += 2;
                        menor = acum + grafo[camino.back()][camino[0]];
                        solucion = camino;
                }
                return;
        }
        operaciones++;
        int nodo = camino.back();
        for (int i = 0; i < grafo.size(); i++) {
                operaciones++;
                if (find(camino.begin(), camino.end(), i) == camino.end() && grafo[nodo][i] != 0) {
                        operaciones += 3;
                        camino.push_back(i);
                        solve(acum + grafo[nodo][i]);
                        camino.pop_back();
                }
        }
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

        for (int i = 0; i < 18; i++) {
                grafo[i][i] = 0;
        }

        solve(0);

        cout << menor << ": ";
        for (size_t i = 0; i < solucion.size() - 1; i++) {
                cout << solucion[i] << ", ";
        }
        cout << solucion.back() << ": " << operaciones << "\n";

        return 0;
}
