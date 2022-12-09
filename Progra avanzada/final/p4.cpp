#include <iostream>
#include <map>

using namespace std;

int main() {
        int P, L, n, sol;

        while (cin >> P >> L && !(P == 0 && L == 0)) {
                map<int, int> apariciones;
                sol = 0;
                for (int i = 0; i < P; i++) {
                        cin >> n;
                        apariciones[n] = 1;
                }
                for (int i = 0; i< L; i++) {
                        cin >> n;
                        if (apariciones[n]) {
                                sol++;
                        }
                }
                cout << sol << "\n";
        }
        
        return 0;
}