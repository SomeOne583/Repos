#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void busquedaSecuencial(string line){
        int index = -1;
        int c = 0;
        for (int i = 0; i < line.length(); i += 2) {
                c++;
                if (i == line.length() - 1 || line[i] != line[i + 1]) {
                        index = i;
                        break;
                }
        }
        cout << "Secuencial: " << line[index] << " (" << (index == line.length() - 1 ? c - 1 : c ) << " operaciones)" << endl;
}

void busquedaBinaria(string line) {
        int izq = 0;
        int der = line.length() - 1;
        int c = 0;
        int index = -1;
        do {
                c++;
                int med = (izq + der) / 2;
                if (line[med - 1] != line[med] && line[med] != line[med + 1]) {
                        index = med;
                        break;
                }
                else if (med % 2 == 0) {
                        if (line[med - 1] == line[med])
                                der = med - 1;
                        else if (line[med] == line[med + 1])
                                izq = med + 1;
                }
                else if (med % 2 != 0) {
                        if (line[med - 1] == line[med])
                                izq = med + 1;
                        else if (line[med] == line[med + 1])
                                der = med - 1;
                }
        } while (line.length() > 1);
        cout << "Binaria: " << line[index] << " (" << (index == line.length() - 1 || index == 0 ? c - 1 : c ) << " operaciones)" << endl;
}

int main() {
        int num, indexS, indexB;
        string line;
        cout << "Número de líneas: ";
        cin >> num;
        for (int i = 0; i < num; i++) {
                cout << "Línea " << i + 1 << ": ";
                cin >> line;
                cout;
                busquedaSecuencial(line);
                busquedaBinaria(line);
        }
        return 0;
}