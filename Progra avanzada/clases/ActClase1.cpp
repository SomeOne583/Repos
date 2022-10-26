#include <iostream>
#include <string>

using namespace std;

int main() {
        int cantCasos, cantCasas, x, y;
        char basura;
        
        cin >> cantCasos;

        for (int i = 0; i < cantCasos; i++) {
                cin >> cantCasas;
                for (int j = 0; j < cantCasas; j++) {
                        cin >> basura >> x >> basura >> y >> basura;
                        cout << "X: " << x << "\tY: " << y << endl;
                }
        }

        return 0;
}