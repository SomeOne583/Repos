/*
Jan Carlo Reyes Martínez, 577441
Doy mi palabra de que he realizado esta actividad con integridad académica
*/

#include <iostream>
#include <fstream>      // Este include es para poder leer archivos
#include "AdjMatrix.h"  // Incluyo mi clase de matriz de adyacencia

using namespace std;

vector<int> getRoute(AdjMatrix<int> matrix, int fromVertex, int toVertex, int size) {
        vector<bool> known(size, false);        // Vector para saber cuales han sido visitados
        vector<int> cost(size, 2147483647 / 2); // Vector con los costos, se inicia con valores muy altos
        vector<int> path(size, -1);     // Vector con los caminos, inicia con -1 pues aún no visitamos nada
        vector<int> final_path;         // Vector en donde se va a guardar el camino final y su peso
        vector<vector<int>> matrix_data = matrix.getMatrix();   // Se toma el vector 2D de la matriz de adyacencia
        
        int checked = 0;        // Contador de cuantos vertices han sido revisados

        int smaller;            // Variable del costo más pequeño
        int smallerIndex;       // Indice del costo más pequeño

        cost[fromVertex] = 0;   // Se asigna un costo de 0 al inicio porque es nuestro punto de partida

        int next = fromVertex;  // Next será nuestra variable en donde nos vamos moviendo de vertice a vertice

        do {
                known[next] = true;     // Se marca como visitado
                checked++;      // Incrementamos nuestro contador de visitados
                smaller = 2147483647 / 2; // Se usa un valor grande para la variable smaller de modo que sea reemplazada
                for (int i = 0; i < size; i++) {
                        if (known[i] == false) {        // Condicional para que solo aplique si no hemos visitado el vertice
                                if (cost[i] > cost[next] + matrix_data[next][i]) {
                                        // Si el costo desde nuestra posición hasta el vertice es menor que la registrada se sustituye
                                        cost[i] = cost[next] + matrix_data[next][i];
                                        path[i] = next; // Se añade al arreglo con el camino
                                }
                                if (cost[i] < smaller) {        // Se sustituye la variable smaller con el menor costo
                                        smaller = cost[i];
                                        smallerIndex = i;
                                }
                        }
                }
                next = smallerIndex;    // Se actualiza next con el siguiente vertice a visitar
        } while (checked < size); // Se repite el ciclo mientras no hayamos checamos todos
        
        int marker = toVertex;  // Una variable marcador para saber en que parte voy
        while (path[marker] != -1) {    // Si llega a -1 es porque ya llegue al inicio
                final_path.push_back(marker);   // Se van añadiendo al vector final_path que luego regreso
                marker = path[marker];
        }
        final_path.push_back(fromVertex);
        final_path.push_back(cost[toVertex]);   // Añado el costo al final para que vaya todo junto en el vector

        return final_path;
}

int main() {
        AdjMatrix<int> matrix;
        vector<int> vertices = { 0, 1, 2, 3, 4, 5, 6, 7 };

        matrix.insertVertex(vertices, 8);
        matrix.insert(0, 1, 3);
        matrix.insert(1, 2, 8);
        matrix.insert(1, 3, 3);
        matrix.insert(1, 5, 7);
        matrix.insert(2, 5, 7);
        matrix.insert(2, 6, 4);
        matrix.insert(3, 5, 8);
        matrix.insert(4, 6, 7);
        matrix.insert(6, 7, 3);

        for (int i = 0; i < vertices.size(); i++) {
                vector<int> path = getRoute(matrix, 2, i, matrix.getSize());

                cout << "Camino a " << i << " (pesa: " << path.back() << "): ";

                for (int j = path.size() - 2; j > 0; j--) {
                        cout << path[j] << "-> ";
                }
                cout << path[0] << endl;
        }

        return 0;
}
