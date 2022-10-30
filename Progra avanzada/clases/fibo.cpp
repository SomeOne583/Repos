#include <iostream>
#include <vector>

using namespace std;

vector<long> calculos;

long fiboR(long n) {
        if (n == 0 || n == 1) {
                return n;
        }
        return fiboR(n - 1) + fiboR(n - 2);
}

long fiboD(long n) {
        if (calculos[n] == -1) {
                calculos[n] = fiboD(n - 1) + fiboD(n - 2);
        }
        return calculos[n];
}

int main() {
        int n = 20;
        calculos.resize(n + 1, -1);
        calculos[0] = 0;
        calculos[1] = 1;
        cout << fiboD(n) << "\n";
        // cout << fiboR(n) << "\n";

        return 0;
}
