#include <iostream>
#include <bitset>

using namespace std;

int main() {
        string linea;
        bitset<7> letra;

        getline(cin, linea);
        while (getline(cin, linea) && linea[0] != '_') {
                linea.erase(0, 1);
                linea.erase(5, 1);
                linea.erase(8);
                for (int i = linea.size() - 1; i >= 0; i--) {
                        if (linea[i] == 'o') {
                                letra[linea.size() - i - 1] = 1;
                        } else {
                                letra[linea.size() - i - 1] = 0;
                        }
                }
                // cout << linea << " = " << letra << " = " << letra.to_ulong() << endl;
                cout << char(letra.to_ulong());
        }

        return 0;
}
