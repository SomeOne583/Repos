// Jan Carlo Reyes Martínez, 577441
// 11/09/2022
// Doy mi palabra de que he realizado esta actividad con integridad académica

#include <iostream>
#include <vector>
#include <queue>

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

int main() {
        bool continuar, mismoGrafo = false;
        int nodo, cantNodos, nodoI, nodoF, peso, decision, minimo;
        std::string nombreNodo;
        std::vector<int> posible;
        std::vector<bool> visitado;
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
		visitado.clear();
		visitado.resize(cantNodos, false);
		resultado.clear();

		std::cout << "Ingresa el índice del nodo para iniciar: ";
		std::cin >> nodo;
		nodo--;

		std::cout << "¿Qué costo quieres?\n1. Menor\n2. Mayor\n>>> ";
		std::cin >> minimo;

		if (minimo == 1) {
			std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, minQ> minPQ;
			do {
				// Añadir vecinos
				for (int i = 0; i < grafo[nodo].size(); i++) {
					if (grafo[nodo][i]) {
						minPQ.push({ nodo, i, grafo[nodo][i] });
					}
				}
				// Buscar el siguiente puente con nodos sin visitar
				do {
					posible = minPQ.top();
					minPQ.pop();
				} while (visitado[posible[0]] && visitado[posible[1]] && !minPQ.empty());
				// Se marcan como visitados
				visitado[posible[0]] = true;
				visitado[posible[1]] = true;
				// Se guarda como resultado
				if (!minPQ.empty()) {
					resultado.push_back(posible);
				}
				// Se actualiza el nodo actual
				nodo = posible[1];
			} while (!minPQ.empty());
		} else {
			// Mismo procedimiento que en la mínima pero ahora es máxima
			std::priority_queue<std::vector<int>, std::vector<std::vector<int>>, maxQ> maxPQ;
			do {
				for (int i = 0; i < grafo[nodo].size(); i++) {
					if (grafo[nodo][i]) {
						maxPQ.push({ nodo, i, grafo[nodo][i] });
					}
				}
				do {
					posible = maxPQ.top();
					maxPQ.pop();
				} while (visitado[posible[0]] && visitado[posible[1]] && !maxPQ.empty());
				visitado[posible[0]] = true;
				visitado[posible[1]] = true;
				if (!maxPQ.empty()) {
					resultado.push_back(posible);
				}
				nodo = posible[1];
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
