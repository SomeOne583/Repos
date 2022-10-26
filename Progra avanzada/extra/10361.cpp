#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

int main() {
        int c;
        string linea;
        stringstream separador;
        vector<string> palabras;

        cin >> c;
        getline(cin, linea);

        while (c--) {
                palabras.clear();
                getline(cin, linea);
                separador = stringstream(linea);

                getline(separador, linea, '<');
                palabras.push_back(linea);

                getline(separador, linea, '>');
                palabras.push_back(linea);
                
                getline(separador, linea, '<');
                palabras.push_back(linea);

                getline(separador, linea, '>');
                palabras.push_back(linea);
                
                getline(separador, linea);
                palabras.push_back(linea);

                for (vector<string>::iterator it = palabras.begin(); it != palabras.end(); it++) {
                        cout << *it;
                }
                cout << "\n";

                getline(cin, linea, '.');

                cout << linea << palabras[3] << palabras[2] << palabras[1] << palabras[4] << "\n";

                getline(cin, linea);
        }
        
        return 0;
}
