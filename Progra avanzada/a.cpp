#include <iostream>

using namespace std;

int main()
{
        int n;
        for (int i = 0; i < 1000; i++) {
                for (int j = 0; j < 1000; j++) {
                        // n = rand() % 10 + 1;
                        // cout << (n < 8 ? 'L' : '-');
                        cout << 'L';
                }
                cout << '\n';
        }
        
        return 0;
}
