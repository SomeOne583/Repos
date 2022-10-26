// Problema Formula 1
// Jan Carlo Reyes Martínez, 577441
// Juan Manuel Cuevas Gaytan, 611978
// Damos nuestra palabra de que hemos realizado esta actividad con integridad académica

#include <iostream>
#include <algorithm>
#include <vector>

// Esta función es para ordenar los nombres porque el problema dice que se deben ordenar case insensitive así que había que convertir 
// o a mayusculas o a minusculas
bool ordenarString(std::string a, std::string b) {
        std::string aa = "", bb = "";
        for (int i = 0; i < a.size(); i++) {
                aa += std::tolower(a[i]);
        }
        for (int i = 0; i < b.size(); i++) {
                bb += std::tolower(b[i]);
        }
        return aa < bb;
}

int main() {
        int cantParticipantes, min, sec, ms, fila, filaAux;     // fila y filaAux son para el proceso de imprimir por filas
        std::string nombre, basura;                             // basura es para leer cosas como los :, las comas y las unidades
        std::vector<std::string> nombres, auxNombres;
        std::vector<int> tiempos, auxTiempos;
        std::vector<int>::iterator index;                       // Esto se usa al buscar el elemento en un vector

        while (std::cin >> cantParticipantes) {                 // Leemos mientras haya datos
                fila = 1;                                       // Estas variables son para la impresión
                filaAux = 0;
                for (int i = 0; i < cantParticipantes; i++) {   // Según la cantidad de participantes leemos y guardamos sus datos
                        std::cin >> nombre >> basura >> min >> basura >> sec >> basura >> ms >> basura;
                        ms += min * 60000 + sec * 1000;         // Se guardan en milisegundos por simplicidad
                        nombres.push_back(nombre);
                        tiempos.push_back(ms);
                }

                auxTiempos = tiempos;                           // Aquí se guardan los tiempos originales
                sort(tiempos.begin(), tiempos.end());           // Ordenamos del más rápido al más lento

                for (int i = 0; i < tiempos.size(); i++) {      // Por cada tiempo registrado en el vector ordenado
                        do {                                    // Ciclo en caso de que haya participantes con el mismo tiempo
                                index = find(auxTiempos.begin(), auxTiempos.end(), tiempos[i]);         // Hayamos el indice del participante
                                if (index != auxTiempos.end()) {        // Cuando index == auxTiempos.end() es porque no se encontró el tiempo
                                        auxTiempos[index - auxTiempos.begin()] = 0;     // Reiniciamos esa casilla para que no coincida en otras busquedas
                                        auxNombres.push_back(nombres[index - auxTiempos.begin()]); // Agregamos el nombre que acabamos de encontrar
                                }
                        } while (index != auxTiempos.end());

                        sort(auxNombres.begin(), auxNombres.end(), ordenarString); // Ordenamos nombres con nuestra función del principio
                        for (int j = 0; j < auxNombres.size(); j++) {           // Imprimimos los nombres
                                if (filaAux % 2 == 0) {
                                        std::cout << "Row " << fila << std::endl;
                                        fila++;
                                }
                                std::cout << auxNombres[j] << std::endl;
                                filaAux++;
                        }
                        auxNombres.clear();     // El arreglo de nombres repetidos se limpia por cada tiempo
                }

                // Limpiamos nuestros otros vectores e imprimimos el salto de línea después de cada caso
                nombres.clear();
                tiempos.clear();
                std::cout << std::endl;
        }

        return 0;
}
