#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
        int n, i, j, c, is;
        string res;
        vector<bool> visitados;
        vector<vector<int>> grafo;
        queue<int> pendientes;
        
        while (cin >> n && n != 0) {
                grafo.clear();
                grafo.resize(n + 1, {});
                while (cin >> i && i != 0)
                        while (cin >> j && j != 0)
                                grafo[i].push_back(j);
                cin >> is;
                while (is--) {
                        visitados.clear();
                        visitados.resize(n + 1, false);
                        
                        cin >> i;
                        pendientes.push(i);
                        while (!pendientes.empty()) {
                                i = pendientes.front();
                                pendientes.pop();
                                for (j = 0; j < grafo[i].size(); j++)
                                        if (!visitados[grafo[i][j]]) {
                                                visitados[grafo[i][j]] = true;
                                                pendientes.push(grafo[i][j]);
                                        }
                        }
                        c = 0;
                        res = "";
                        for (i = 1; i < visitados.size(); i++)
                                if (!visitados[i]) {
                                        c++;
                                        res += " " + to_string(i);
                                }
                        cout << c << res << '\n';
                }
        }

        return 0;
}
