// Jan Carlo Reyes Martínez, 577441
// Doy mi palabra de que he realizado esta actividad con integridad académica

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

void bfs(std::vector<std::vector<bool>> matAdj, int n) {
        std::vector<bool> status(n, false);
        std::queue<int> fila;
        int i;
        do {
                if (fila.empty()) {
                        i = 0;
                        status[0] = true;
                } else {
                        i = fila.front();
                        fila.pop();
                }

                std::cout << i << std::endl;
        
                for (int j = 0; j < n; j++) {
                        if (matAdj[i][j] && !status[j]) {
                                fila.push(j);
                                status[j] = true;
                        }
                }
        } while (!fila.empty());
}

int main() {
        std::vector<std::vector<bool>> matAdj(5, { false, false, false, false, false });

        // matAdj[0][0] = false;
        matAdj[0][1] = true;
        matAdj[0][2] = true;
        // matAdj[0][3] = false;
        // matAdj[0][4] = false;

        matAdj[1][0] = true;
        // matAdj[1][1] = false;
        matAdj[1][2] = true;
        // matAdj[1][3] = false;
        matAdj[1][4] = true;

        matAdj[2][0] = true;
        matAdj[2][1] = true;
        // matAdj[2][2] = false;
        matAdj[2][3] = true;
        matAdj[2][4] = true;

        // matAdj[3][0] = false;
        // matAdj[3][1] = false;
        matAdj[3][2] = true;
        // matAdj[3][3] = false;
        matAdj[3][4] = true;

        // matAdj[4][0] = false;
        matAdj[4][1] = true;
        matAdj[4][2] = true;
        matAdj[4][3] = true;
        // matAdj[4][4] = false;

        bfs(matAdj, 5);
}
