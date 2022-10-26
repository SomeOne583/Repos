// Jan Carlo Reyes Martínez, 577441
// 11/09/2022
// Doy mi palabra de que he realizado esta actividad con integridad académica

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

// Clases para usar comparadores personalizados en la priority queue
class maxQ {
        public:
                bool operator() (std::vector<int> a, std::vector<int> b) {
                        return a[2] < b[2];
                }
};

class minQ {
        public:
                bool operator() (std::vector<int> a, std::vector<int> b) {
                        return a[2] > b[2];
                }
};

// Función para ver si algún arco genera un ciclo
bool cicla(int nodoA, int nodoB, std::vector<std::vector<int>> agregados) {
        int indice = 0;
        std::vector<int> visitados, vecinos;
        visitados.push_back(nodoA);
        while (true) {
                nodoA = visitados[indice];
                for (int i = 0; i < agregados.size(); i++) {
                        if (agregados[i][0] == nodoA) {
                                if (find(visitados.begin(), visitados.end(), agregados[i][1]) == visitados.end()) {
                                        vecinos.push_back(agregados[i][1]);
                                        visitados.push_back(vecinos.back());
                                }
                        }
                        if (agregados[i][1] == nodoA) {
                                if (find(visitados.begin(), visitados.end(), agregados[i][0]) == visitados.end()) {
                                        vecinos.push_back(agregados[i][0]);
                                        visitados.push_back(vecinos.back());
                                }
                        }
                }
                if (indice == visitados.size() - 1) {
                        break;
                } else {
                        indice++;
                }
        }
        return find(vecinos.begin(), vecinos.end(), nodoB) != vecinos.end();
}

int main() {
        int minimo = 2, peso, cantNodos, nodoI, nodoF, decision;
        bool mismoGrafo = false, continuar;
        std::string nombreNodo;
        std::vector<int> posible;
        std::vector<std::string> vertices;
        std::vector<std::vector<int>> grafo, resultado;

	do {
		if (!mismoGrafo) {
			// Lectura del grafo
			std::cout << "Ingresa la cantidad de nodos que tendrá el grafo: ";
        		std::cin >> cantNodos;

			vertices.clear();
			for (int i = 0; i < cantNodos; i++) {
				std::cout << "Ingresa el nombre del nodo " << i + 1 << ": ";
				std::cin >> nombreNodo;
				vertices.push_back(nombreNodo);
			}

			grafo.resize(cantNodos, std::vector<int>(cantNodos, 0));

			std::cout << "Ingresa los arcos usando los indices de cada vertice y el peso separados por un espacio (escribe 'salir' y presiona enter para terminar la lectura)" << std::endl;
			for (int i = 0; i < cantNodos; i++) {
				std::cout << i + 1 << ". " << vertices[i] << std::endl;
			}
			std::cout << std::endl;
			while (std::cin >> nodoI >> nodoF >> peso) {
				grafo[nodoI - 1][nodoF - 1] = peso;
				grafo[nodoF - 1][nodoI - 1] = peso;
			}
			std::cin.clear();
			std::cin.ignore(100, '\n');
		}
		// Reinicio de variables
		resultado.clear();

		std::cout << "¿Qué costo quieres?\n1. Menor\n2. Mayor\n>>> ";
		std::cin >> minimo;

		if (minimo == 1) {
                        // Se añaden los arcos a una priority queue
                        std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, minQ> minPQ;
                        for (int i = 0; i < grafo.size(); i++) {
                                for (int j = 0; j < grafo[i].size(); j++) {
                                        if (grafo[i][j]) {
                                                minPQ.push({ i, j, grafo[i][j] });
                                        }
                                }
                        }
                        do {
                                do {
                                        posible = minPQ.top();
                                        minPQ.pop();
                                } while (cicla(posible[0], posible[1], resultado) && !minPQ.empty());
                                if (!minPQ.empty()) {
                                        resultado.push_back(posible);
                                }
                        } while (!minPQ.empty());
                } else {
                        std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, maxQ> maxPQ;
                        for (int i = 0; i < grafo.size(); i++) {
                                for (int j = 0; j < grafo[i].size(); j++) {
                                        if (grafo[i][j]) {
                                                maxPQ.push({ i, j, grafo[i][j] });
                                        }
                                }
                        }
                        do {
                                do {
                                        posible = maxPQ.top();
                                        maxPQ.pop();
                                } while (cicla(posible[0], posible[1], resultado) && !maxPQ.empty());
                                if (!maxPQ.empty()) {
                                        resultado.push_back(posible);
                                }
                        } while (!maxPQ.empty());
                }

		// impresión de resultados
		peso = 0;
		for (int i = 0; i < resultado.size(); i++) {
			peso += resultado[i][2];
			std::cout << vertices[resultado[i][0]] << " -> " << vertices[resultado[i][1]] << " (" << resultado[i][2] << ")" << std::endl;
		}
		std::cout << "El costo total es: " << peso << std::endl;

		std::cout << "Deseas continuar:" << std::endl;
		std::cout << "1. Sí, con el mismo grafo" << std::endl;
		std::cout << "2. Sí, con un nuevo grafo" << std::endl;
		std::cout << "3. No" << std::endl;

		std::cin >> decision;

		if (decision == 1) {
			continuar = true;
			mismoGrafo = true;
		} else if (decision == 2) {
			continuar = true;
			mismoGrafo = false;
		} else {
			continuar = false;
		}
	} while (continuar);

        return 0;
}
