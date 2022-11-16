#include <iostream>
#include <vector>

using namespace std;

int cant = 0;

/*
1 - 2 - 3 - 4 - 5 - 6 - 7 - 8 - 9 - 10 => 16
1 - 3 - 5 - 7 - 9
1 - 3 - 5 - 7 - 10
1 - 3 - 5 - 8 - 10
1 - 3 - 6 - 8 - 10
1 - 3 - 6 - 9
1 - 4 - 6 - 8 - 10
1 - 4 - 6 - 9
1 - 4 - 7 - 9
1 - 4 - 7 - 10
2 - 4 - 6 - 8 - 10
2 - 4 - 6 - 9
2 - 4 - 7 - 9
2 - 4 - 7 - 10
2 - 5 - 7 - 9
2 - 5 - 7 - 10
2 - 5 - 8 - 10
*/

void solve(int i, int &N)
{
        if (i > N)
                return;
        if (i >= N - 1) {
                cant++;
                return;
        }
        for (int k = 2; k < 4; k++) {
                solve(i + k, N);
        }
}

int main()
{
        int n;
        while (cin >> n) {
                cant = 0;
                solve(1, n);
                solve(2, n);
                cout << cant << "\n";
        }
}
