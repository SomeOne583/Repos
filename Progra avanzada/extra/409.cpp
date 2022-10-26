#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
        int k, e, m, mayor, c = 0, pos;
        string excusa, excusaM;
        vector<string> excusas;
        vector<pair<string, int>> coincidencias;

        while (cin >> k >> e) {
                c++;
                excusas.clear();
                coincidencias.clear();

                while (k--) {
                        cin >> excusa;
                        excusas.push_back(excusa);
                }
                getline(cin, excusa);
                while (e--) {
                        m = 0;
                        getline(cin, excusa);
                        excusaM = excusa;
                        transform(excusa.begin(), excusa.end(), excusaM.begin(), ::tolower);
                        for (vector<string>::iterator it = excusas.begin(); it != excusas.end(); it++) {
                                pos = 0;
                                while (excusaM.find(*it, pos) != string::npos) {
                                        pos = excusaM.find(*it, pos);
                                        if ((pos == 0 || !isalpha(excusaM[pos - 1])) && ((pos + (*it).size() > excusaM.size() - 1) || !isalpha(excusaM[pos + (*it).size()]))) {
                                                m++;
                                        }
                                        pos++;
                                }
                        }
                        coincidencias.push_back({ excusa, m });
                }
                mayor = 0;
                for (int i = 0; i < coincidencias.size(); i++) {
                        if (coincidencias[i].second > mayor) {
                                mayor = coincidencias[i].second;
                        }
                }

                cout << "Excuse Set #" << c << "\n";
                for (int i = 0; i < coincidencias.size(); i++) {
                        if (coincidencias[i].second == mayor) {
                                cout << coincidencias[i].first << "\n";
                        }
                }
                cout << "\n";
        }
        
        return 0;
}
