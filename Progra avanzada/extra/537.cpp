#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

int main() {
        int c, p = 0;
        double cant1, cant2;
        char concepto1, concepto2;
        string linea;
        stringstream separador;
        pair<char, double> respuesta;

        cin >> c;
        getline(cin, linea);

        while (++p && p <= c) {
                getline(cin, linea);
                separador = stringstream(linea);

                getline(separador, linea, '=');

                concepto1 = linea.back();

                if (concepto1 == 'P') {
                        getline(separador, linea, 'W');
                } else if (concepto1 == 'U') {
                        getline(separador, linea, 'V');
                } else if (concepto1 == 'I') {
                        getline(separador, linea, 'A');
                }

                if (linea.back() == 'm') {
                        cant1 = stod(linea.substr(0, linea.size() - 1)) / 1000;
                } else if (linea.back() == 'k') {
                        cant1 = stod(linea.substr(0, linea.size() - 1)) * 1000;
                } else if (linea.back() == 'M') {
                        cant1 = stod(linea.substr(0, linea.size() - 1)) * 1000000;
                } else {
                        cant1 = stod(linea);
                }

                getline(separador, linea, '=');

                concepto2 = linea.back();
                
                if (concepto2 == 'P') {
                        getline(separador, linea, 'W');
                } else if (concepto2 == 'U') {
                        getline(separador, linea, 'V');
                } else if (concepto2 == 'I') {
                        getline(separador, linea, 'A');
                }

                if (linea.back() == 'm') {
                        cant2 = stod(linea.substr(0, linea.size() - 1)) / 1000;
                } else if (linea.back() == 'k') {
                        cant2 = stod(linea.substr(0, linea.size() - 1)) * 1000;
                } else if (linea.back() == 'M') {
                        cant2 = stod(linea.substr(0, linea.size() - 1)) * 1000000;
                } else {
                        cant2 = stod(linea);
                }

                if (concepto1 == 'P') {
                        if (concepto2 == 'U') {
                                respuesta = { 'I', cant1 / cant2 };
                        } else {
                                respuesta = { 'U', cant1 / cant2 };
                        }
                } else if (concepto1 == 'U') {
                        if (concepto2 == 'P') {
                                respuesta = { 'I', cant2 / cant1 };
                        } else {
                                respuesta = { 'P', cant1 * cant2 };
                        }
                } else {
                        if (concepto2 == 'P') {
                                respuesta = { 'U', cant2 / cant1 };
                        } else {
                                respuesta = { 'P', cant1 * cant2 };
                        }
                }
                cout << fixed << setprecision(2);
                cout << "Problem #" << p << "\n";
                cout << respuesta.first << "=" << respuesta.second;
                cout << (respuesta.first == 'P' ? 'W' : (respuesta.first == 'U' ? 'V' : 'A')) << "\n\n";
        }
        
        return 0;
}
