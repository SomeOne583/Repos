#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int soluciones;

void genera(vector<int> &sol, int &n) {
        if (sol.size() == n) {
                // for (vector<int>::iterator it = sol.begin(); it != sol.end(); it++) {
                //         cout << *it << ", ";
                // }
                // cout << "\n";
                soluciones++;
                // cout << soluciones << endl;
        } else {
                bool val;
                vector<int> aux;
                for (int i = 1; i <= n; i++) {
                        val = true;
                        if (find(sol.begin(), sol.end(), i) != sol.end()) {
                                continue;
                        }
                        if (sol.size() >= 2 && i > sol[sol.size() - 2] && i < sol[sol.size() - 1]) {
                                val = false;
                        }
                        if (val) {
                                // aux = sol;
                                // aux.push_back(i);
                                sol.push_back(i);
                                genera(sol, n);
                                sol.erase(sol.end() - 1);
                        }
                }
        }
}

int main() {
        int n, s;
        vector<int> sol;
        cin >> n;
        while (n--) {
                sol.clear();
                soluciones = 0;

                cin >> s;
                genera(sol, s);
                cout << soluciones << "\n";
        }

        return 0;
}
