#include <iostream>

using namespace std;

int main() {
        int N, B, p, acum;

        while (cin >> N >> B && !(N == 0 && B == 0)) {
                acum = 0;
                while (N--) {
                        cin >> p;
                        acum += p;
                }
                cout << B / acum << endl;
        }
}
