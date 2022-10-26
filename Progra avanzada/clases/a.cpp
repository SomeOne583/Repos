#include <iostream>
#include <string>

using namespace std;

void procesa(string &s, int &d, int &v, int &c) {
        for (int i = 0; i < s.length(); i++) {
                s[i] = tolower(s[i]);
                if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                        v++;
                } else if (isalpha(s[i])) {
                        c++;
                } else if (isdigit(s[i])) {
                        d++;
                }
        }
}

int main() {
        string linea, texto = "";
        int d = 0, v = 0, c = 0;

        getline(cin, linea);
        
        while (linea != ".......") {
                if (linea[linea.size() - 1] == '-') {
                        linea.erase(linea.size() - 1, 1);
                } else {
                        linea += ' ';
                }
                texto += linea;
                getline(cin, linea);
        }

        procesa(texto, d, v, c);
        
        cout << texto << endl;
        cout << d << " " << v << " " << c << endl;

        return 0;
}