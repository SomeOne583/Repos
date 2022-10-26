#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
//Juan Manuel Cuevas Gaytan 611978
//Jan Carlo Reyes 577441
//Damos nuestra palabra de que hemos realizado esta actividad con integridad académica
//Problema 1 PEF Projects
bool ordena(std::pair<std::string, int> &a, std::pair<std::string, int> &b) {
        if (a.second == b.second) {
                return a.first < b.first;
        } else {
                return a.second > b.second;
        }
}

int main() {
        std::string linea, proyecto;
        std::set<std::string> agregados, borrados;
        std::vector<std::pair<std::string, int>> ordenado;
        std::map<std::string, std::set<std::string>> proyectos;

        while (getline(std::cin, linea) && linea != "0") {
                if (linea == "1") {
                        for (std::map<std::string, std::set<std::string>>::iterator it = proyectos.begin(); it != proyectos.end(); it++) {
                                ordenado.push_back({ it->first, it->second.size() });
                        }
                        sort(ordenado.begin(), ordenado.end(), ordena);
                        for (int i = 0; i < ordenado.size(); i++) {
                                std::cout << ordenado[i].first << " " << ordenado[i].second << std::endl;
                        }
                        agregados.clear();
                        borrados.clear();
                        ordenado.clear();
                        proyectos.clear();
                } else {
                        if (isupper(linea[0])) {
                                proyecto = linea;
                                proyectos[proyecto] = {};
                        } else {
                                if (proyectos[proyecto].find(linea) == proyectos[proyecto].end()) {
                                        if (agregados.find(linea) == agregados.end()) {
                                                proyectos[proyecto].insert(linea);
                                                agregados.insert(linea);
                                        } else {
                                                if (borrados.find(linea) == borrados.end()) {
                                                        for (std::map<std::string, std::set<std::string>>::iterator it = proyectos.begin(); it != proyectos.end(); it++) {
                                                                it->second.erase(linea);
                                                        }
                                                        borrados.insert(linea);
                                                }
                                        }
                                }
                        }
                }
        }

        return 0;
}
