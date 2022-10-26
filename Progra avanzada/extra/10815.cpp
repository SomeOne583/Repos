#include <iostream>
#include <sstream>
#include <set>
#include <algorithm>

using namespace std;

int main() {
        string palabra, linea;
        stringstream palabraS;
        set<string> palabras;

        while (getline(cin, linea)) {
                for (int i = 0; i < linea.size(); i++) {
                        if (!isalpha(linea[i])) {
                                linea[i] = ' ';
                        }
                }
                palabraS = stringstream(linea);
                while (getline(palabraS, palabra, ' ')) {
                        transform(palabra.begin(), palabra.end(), palabra.begin(), ::tolower);
                        palabras.insert(palabra);
                }
        }

        for (set<string>::iterator it = palabras.begin(); it != palabras.end(); it++) {
                if ((*it).size() != 0) {
                        cout << *it << "\n";
                }
        }

        return 0;
}
