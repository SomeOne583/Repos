#include <iostream>
#include <bitset>

using namespace std;

int main() {
        int l, acum;
        cin >> l;
        string num;
        bitset<8> d1, d2, d3, d4;
        for (int i = 0; i < l; i++) {
                cin >> num;
                d1 = bitset<8>(num.substr(0, 8));
                d2 = bitset<8>(num.substr(8, 8));
                d3 = bitset<8>(num.substr(16, 8));
                d4 = bitset<8>(num.substr(24, 8));

                cout << d1.to_ulong() << '.' << d2.to_ulong() << '.' << d3.to_ulong() << '.' << d4.to_ulong() << "\n";
        }
        
        return 0;
}