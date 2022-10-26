#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool ordena(string &a, string &b) {
        return a.size() < b.size();
}

int main() {
        bool valido = true;
        int c = 1;
        string linea;
        vector<string> codes;
        while (cin >> linea) {
                if (linea == "9") {
                        codes.clear();
                        if (valido) {
                                cout << "Set " << c << " is immediately decodable\n";
                        } else {
                                cout << "Set " << c << " is not immediately decodable\n";
                        }
                        valido = true;
                        c++;
                        continue;
                }
                codes.push_back(linea);
                sort(codes.begin(), codes.end(), ordena);
                for (int i = 0; i < codes.size() && valido; i++) {
                        for (int j = i + 1; j < codes.size(); j++) {
                                if (codes[i] == codes[j].substr(0, codes[i].size())) {
                                        valido = false;
                                        break;
                                }
                        }
                }
        }
}
