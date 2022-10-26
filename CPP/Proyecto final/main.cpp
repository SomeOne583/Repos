/*
Jan Carlo Reyes Martínez, 577441
Estructura de datos MV1130
Doy mi palabra de que he realizado esta actividad con integridad académica
*/

#include <iostream>
#include <fstream>      // Este include es para poder leer archivos
#include "AdjMatrix.h"  // Incluyo mi clase de matriz de adyacencia

using namespace std;

AdjMatrix<string> readFile() {          // Método para leer el archivo
        cout << "Ingresa el nombre del archivo: ";
        string file_name;
        cin >> file_name;       // Se lee como se llama el archivo

        AdjMatrix<string> matrix;       // Se inicializa la matriz de adyacencia
        ifstream file_reader;
        int num_routes, num_ports;

        file_reader.open(file_name);    // Se abre el archivo
        if (file_reader.fail()) {       // Condicional en caso de que el archivo no existiera
                cout << "Error al leer el archivo" << endl;
                return matrix;
        }

        file_reader >> num_routes;      // Se lee la primera línea que contiene la cantidad de rutas
        string routes[num_routes][3];   // Se crea un arreglo del tamaño adecuado para guardar las rutas
        for (int i = 0; i < num_routes; i++) {  // Se almacena la información de cada ruta porque no puedo añadirlas a la matriz aún
                file_reader >> routes[i][0];
                file_reader >> routes[i][1];
                file_reader >> routes[i][2];
        }

        file_reader >> num_ports;       // Se lee la línea que contiene la cantidad de puertos
        string ports[num_ports];        // Se hace un arreglo del tamaño adecuado
        for (int i = 0; i < num_ports; i++) {   // Ciclo para guardar todos los puertos
                file_reader >> ports[i];
        }

        matrix.insertVertex(ports, num_ports);  // Se insertan ahora los vertices que ya se tienen

        for (int i = 0; i < num_routes; i++) {  // Se itera por cada ruta guardad
                matrix.insert(routes[i][0], routes[i][1], stoi(routes[i][2]));  // Se inserta cada ruta con sus elementos individuales
        }

        return matrix;
}

vector<int> getRoute(AdjMatrix<string> matrix, int fromVertex, int toVertex, int size) {
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
        int option;
        AdjMatrix<string> matrix;
        do {
                cout << "\nOpciones:" << endl;
                if (matrix.getSize() == 0) { // Si no hay matriz entonces es porque aún no leo el archivo
                        cout << "1. Leer archivo";
                } else {        // Si ya hay matriz es porque ya lo leí
                        cout << "1. Reemplazar archivo\n2. Buscar ruta";
                }
                cout << "\n0. Salir\n>>> ";
                cin >> option;

                cout << endl;
                if (option == 1) {
                        matrix = readFile();
                } else if (option == 2) {
                        vector<string> vertices = matrix.getVertices(); // Obtengo la lista de vertices para poder imprimirlos
                        int start, end;
                        
                        for (int i = 0; i < vertices.size(); i++) {
                                cout << i + 1 << ". " << vertices[i] << endl;   // Los imprimo numerados para que solo se ponga el índice
                        }
                        
                        cout << "Elige el puerto de salida: ";
                        cin >> start;

                        cout << "Elige el puerto destino: ";
                        cin >> end;

                        vector<int> path = getRoute(matrix, start - 1, end - 1, matrix.getSize());      // Genero el camino

                        cout << endl;
                        for (int i = 0; i < path.size() - 1; i++) {
                                cout << vertices[path[i]] << (i == path.size() - 2 ? "" : " <- ");      // Imprimo el camino
                        }
                        cout << "\nDistancia: " << path.back() << endl; // El último elemento se imprime afuera porque es el costo
                }
        } while (option != 0);

        return 0;
}
