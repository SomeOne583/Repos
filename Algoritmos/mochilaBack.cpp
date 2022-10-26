#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> mochila;
pair<vector<int>, int> mayor;
vector<pair<int, int>> objetos;

void solve(int pesoActual, int &pesoMaximo) {
        int acum = 0;
        for (size_t i = 0; i < mochila.size(); i++) {
                acum += objetos[mochila[i]].second;
        }
        if (acum > mayor.second) {
                mayor.first = mochila;
                mayor.second = acum;
        }
        for (size_t i = 0; i < objetos.size(); i++) {
                if (find(mochila.begin(), mochila.end(), i) == mochila.end() && pesoActual + objetos[i].first <= pesoMaximo) {
                        mochila.push_back(i);
                        solve(pesoActual + objetos[i].first, pesoMaximo);
                        mochila.pop_back();
                }
        }
}

int main() {
        int mochilaSize = 10;
        objetos = {
                { 3, 50 },
                { 4, 40 },
                { 5, 10 },
                { 6, 30 }
        };
        mayor = { {}, 0 };

        solve(0, mochilaSize);

        cout << "[ ";
        for (size_t i = 0; i < mayor.first.size() - 1; i++) {
                cout << mayor.first[i] << ", ";
        }
        cout << mayor.first.back() << " ] = " << mayor.second << "\n";

        return 0;
}
