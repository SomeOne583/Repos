#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> mochila;
pair<vector<int>, int> mayor;
vector<pair<int, int>> objetos;

void solve(int pesoActual, int acum, int &pesoMaximo) {
        if (acum > mayor.second) {
                mayor.first = mochila;
                mayor.second = acum;
        }
        for (size_t i = 0; i < objetos.size(); i++) {
                if (find(mochila.begin(), mochila.end(), i) == mochila.end() && pesoActual + objetos[i].first <= pesoMaximo) {
                        mochila.push_back(i);
                        solve(pesoActual + objetos[i].first, acum + objetos[i].second, pesoMaximo);
                        mochila.pop_back();
                }
        }
}

int main() {
        int mochilaSize = 10;
        objetos = {
                { 4, 40 },
                { 6, 30 },
                { 3, 50 },
                { 5, 10 }
        };
        mayor = { {}, 0 };

        solve(0, 0, mochilaSize);

        cout << "[ ";
        for (size_t i = 0; i < mayor.first.size() - 1; i++) {
                cout << mayor.first[i] << ", ";
        }
        cout << mayor.first.back() << " ] = " << mayor.second << "\n";

        return 0;
}
