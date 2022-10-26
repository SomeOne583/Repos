// Jan Carlo Reyes Martínez, 577441
// Doy mi palabra de que he realizado esta actividad con integridad académica

#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

void dfs(std::vector<std::vector<bool>> matAdj, int n) {
        std::vector<bool> status(n, false);
        std::stack<int> pila;

        int i = 0;
        status[0] = true;
        std::cout << i << std::endl;
        
        do {
                if (!pila.empty()) {
                        i = pila.top();
                }

                for (int j = 0; j < n; j++) {
                        if (matAdj[i][j] && !status[j]) {
                                pila.push(j);
                                status[j] = true;
                                std::cout << j << std::endl;
                                break;
                        }
                        if (j == n - 1) {
                                pila.pop();
                        }
                }
        } while (!pila.empty());
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
        // matAdj[1][2] = true;
        // matAdj[1][3] = false;
        matAdj[1][4] = true;

        matAdj[2][0] = true;
        // matAdj[2][1] = true;
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

        dfs(matAdj, 5);
}
