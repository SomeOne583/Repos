// Jan Carlo Reyes Martínez, 577441
// Doy mi palabra de que he realizado esta actividad con integridad académica

#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

int main() {
        int mayor;
        std::string linea, palabra, lineaS, palabraO, palabraM;
        std::vector<std::vector<int>> v;
        std::ifstream myFileE("lcs.in");
        std::ofstream myFileS("salida.txt");
        while (getline(myFileE, linea)) {
                palabraO = "";
                std::stringstream lineaS(linea);
                while (getline(lineaS, palabra, ' ')) {
                        if (palabraO == "") {
                                palabraO = palabra;
                                mayor = 0;
                                palabraM = "";
                        } else {
                                v.resize(palabra.size(), std::vector<int>(palabraO.size(), 0));
                                for (int i = 0; i < palabra.size(); i++) {
                                        for (int j = 0; j < palabraO.size(); j++) {
                                                if (palabraO[j] == palabra[i]) {
                                                        if (i == 0 || j == 0) {
                                                                v[i][j] = 1;
                                                        } else {
                                                                v[i][j] = v[i - 1][j - 1] + 1;
                                                        }
                                                } else {
                                                        if (i > 0 && j > 0) {
                                                                v[i][j] = std::max(v[i - 1][j], v[i][j - 1]);
                                                        } else {
                                                                if (i == 0 && j == 0) {
                                                                        v[i][j] = 0;
                                                                } else if (i == 0) {
                                                                        v[i][j] = v[i][j - 1];
                                                                } else {
                                                                        v[i][j] = v[i - 1][j];
                                                                }
                                                        }
                                                }
                                        }
                                }
                                if (v[palabra.size() - 1][palabraO.size() - 1] > mayor) {
                                        mayor = v[palabra.size() - 1][palabraO.size() - 1];
                                        palabraM = palabra;
                                }
                        }
                }
                myFileS << palabraO << " con " << palabraM << ": " << mayor << "\n";
        }
        myFileE.close();
        myFileS.close();

        return 0;
}
