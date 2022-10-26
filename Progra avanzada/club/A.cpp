#include <iostream>
#include <sstream>

using namespace std;

int main() {
        int acum = 0;
        string linea;
        cin >> linea;
        cin >> linea;

        stringstream lineaS(linea);

        while (getline(lineaS, linea, 'b')) {
                if (linea.size() > 1) {
                        acum += linea.size();
                }
        }
        cout << acum << "\n";
}
