#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

bool ordena(string &a, string &b) {
        return a.size() > b.size();
}

string suma(string a, string b) {
        int residuo = 0, acum;
        string resultado, tmp;
        vector<string> nums;

        reverse(a.begin(), a.end());
        nums.push_back(a);

        reverse(b.begin(), b.end());
        nums.push_back(b);

        sort(nums.begin(), nums.end(), ordena);

        for (int i = 0; i < nums[0].size(); i++) {
                acum = 0;
                for (int j = 0; j < nums.size(); j++) {
                        if (i >= nums[j].size()) {
                                break;
                        }
                        acum += nums[j][i] - 48;
                }
                acum += residuo;
                residuo = acum / 10;
                tmp = to_string(acum % 10);
                reverse(tmp.begin(), tmp.end());
                resultado += tmp;
        }
        if (residuo > 0) {
                tmp = to_string(residuo);
                reverse(tmp.begin(), tmp.end());
                resultado += tmp;
        }
        reverse(resultado.begin(), resultado.end());

        return resultado;
}

string multiplicacion(string a, string b) {
        int resultadoInt, auxInt;
        string resultado, aux;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());

        aux = "0";
        for (size_t i = 0; i < b.size(); i++) {
                auxInt = 0;
                resultado = "";
                for (size_t j = 0; j < a.size(); j++) {
                        resultadoInt = ((b[i] - 48) * (a[j] - 48));
                        resultadoInt += auxInt;
                        resultado += to_string(resultadoInt % 10);
                        auxInt = resultadoInt / 10;
                }
                resultado += to_string(auxInt);
                reverse(resultado.begin(), resultado.end());
                for (size_t j = 0; j < i; j++) {
                        resultado += "0";
                }
                aux = suma(aux, resultado);
        }
        while (aux[0] == '0' && aux.size() != 1) {
                aux.erase(aux.begin());
        }
        
        return aux;
}

int main() {
        string a, b, operador, res;
        while (cin >> a >> operador >> b) {
                cout << a << " " << operador << " " << b << "\n";
                try {
                        stoi(a);
                } catch (const out_of_range &oor) {
                        cout << "first number too big\n";
                }
                try {
                        stoi(b);
                } catch (const out_of_range &oor) {
                        cout << "second number too big\n";
                }
                if (operador == "+") {
                        res = suma(a, b);
                } else {
                        res = multiplicacion(a, b);
                }
                try {
                        stoi(res);
                } catch (const out_of_range &oor) {
                        cout << "result too big\n";
                }
        }
        
        return 0;
}
