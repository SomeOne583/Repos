#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool existeLlave(string llave, std::map<string, string> &mapa) {
        try {
                if (mapa.at(llave) != "") {
                        return true;
                }
        } catch (const std::out_of_range& oor) {
                return false;
        }
        return false;
}

int main() {
        int c;
        char llave;
        string palabra, pagina;
        vector<string> agregadas, eliminadas, cambiadas, diccionario2;
        map<string, string> diccionario;

        cin >> c;

        while (c--) {
                diccionario.clear();
                agregadas.clear();
                eliminadas.clear();
                cambiadas.clear();
                diccionario2.clear();

                cin >> llave;
                while (cin >> palabra && palabra != "]") {
                        cin >> pagina;
                        diccionario[palabra] = pagina;
                }

                cin >> llave;
                while (cin >> palabra && palabra != "]") {
                        cin >> pagina;
                        diccionario2.push_back(palabra);
                        if (existeLlave(palabra, diccionario)) {
                                if (diccionario[palabra] != pagina) {
                                        cambiadas.push_back(palabra);
                                }
                        } else {
                                agregadas.push_back(palabra);
                        }
                }
                for (map<string, string>::iterator it = diccionario.begin(); it != diccionario.end(); it++) {
                        if (find(diccionario2.begin(), diccionario2.end(), it->first) == diccionario2.end()) {
                                eliminadas.push_back(it->first);
                        }
                }

                if (agregadas.size() == 0 && eliminadas.size() == 0 && cambiadas.size() == 0) {
                        cout << "Iguales" << endl;
                } else {
                        sort(agregadas.begin(), agregadas.end());
                        sort(eliminadas.begin(), eliminadas.end());
                        sort(cambiadas.begin(), cambiadas.end());

                        if (agregadas.size() != 0) {
                                cout << "+";
                                for (int i = 0; i < agregadas.size() - 1; i++) {
                                        cout << agregadas[i] << ",";
                                }
                                cout << agregadas.back() << endl;
                        }
                        if (eliminadas.size() != 0) {
                                cout << "-";
                                for (int i = 0; i < eliminadas.size() - 1; i++) {
                                        cout << eliminadas[i] << ",";
                                }
                                cout << eliminadas.back() << endl;
                        }
                        if (cambiadas.size() != 0) {
                                cout << "#";
                                for (int i = 0; i < cambiadas.size() - 1; i++) {
                                        cout << cambiadas[i] << ",";
                                }
                                cout << cambiadas.back() << endl;
                        }
                }
                cout << endl;
        }
        
        return 0;
}
