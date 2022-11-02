#include <iostream>
#include <cmath>

using namespace std;

string dividir(string a, string b) {
        int i = b.size();
        string res = "";
        string aux = a.substr(0, i);
        while (i < a.size()) {
                res += to_string(stol(aux) / stol(b));
                aux = to_string(stol(aux) % stol(b));
                aux += a[i];
                i++;
        }
        res += to_string(stol(aux) / stol(b));
        while (res[0] == '0' && res.size() != 1) {
                res.erase(res.begin());
        }
        
        return res;
}

string modulo(string a, string b) {
        int i = b.size();
        string res = "";
        string aux = a.substr(0, i);
        while (i < a.size()) {
                aux = to_string(stol(aux) % stol(b));
                aux += a[i];
                i++;
        }
        aux = to_string(stol(aux) % stol(b));

        return aux;
}

int main() {
        string a, b, operador;
        while (cin >> a >> operador >> b) {
                if (operador == "/") {
                        cout << dividir(a, b) << "\n";
                } else {
                        cout << modulo(a, b) << "\n";
                }
        }

        return 0;
}
