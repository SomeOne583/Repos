#include <iostream>
#include <bitset>

using namespace std;

int soluciones;

void genera(string &bin, int n, int &c, int &cd) {
        if (bin.size() == n) {
                cout << bin << " = " << c << " = " << cd << endl;
                if (c == cd) {
                        soluciones++;
                }
        } else {
                int i = bin.size();
                int a = c;
                for (int j = 48; j < 50; j++) {
                        if (bin.size() > 1 && bin.back() != char(j)) {
                                c++;
                        }
                        bin += char(j);
                        genera(bin, n, c, cd);
                        bin = bin.substr(0, i);
                        c = a;
                }
        }
}

int main() {
        string a = "";
        int c = 0, cd = 3;
        soluciones = 0;

        genera(a, 10, c, cd);

        cout << soluciones;
        
        return 0;
}
