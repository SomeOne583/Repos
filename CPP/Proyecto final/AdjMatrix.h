/*
Jan Carlo Reyes Martínez, 577441
Estructura de datos MV1130
Doy mi palabra de que he realizado esta actividad con integridad académica
*/

#pragma once    // Esto es para decirle al compilador que solo compile este archivo 1 vez y evitar posibles errores

#include <vector>       // Use vectores en la mayoría de casos pues necesitaba que se adaptara al tamaño del archivo

using namespace std;

template <class T>
class AdjMatrix {
private:
        vector<vector<int>> matrix;     // Vector bidimensional donde se guardan los pesos
        vector<T> vertices;             // Vector unidimensional donde se guarda la lista de vertices
        int size;                       // Atributo que guarda la cantidad de vertices
        int findVertex(T vertex);                               // Método para encontrar el índice de cierto elemento
public:
        AdjMatrix();
        void insertVertex(T vertices[], int size);              // Método para añadir los vertices que se usaran
        void insert(T from_vertex, T to_vertex, int weight);      // Método para insertar conexiones entre vertices, el peso es la distancia
        void remove(T from_vertex, T to_vertex);                  // Método para remover un enlace
        void print();                                           // Método para imprimir la mátriz
        vector<T> getVertices();                        // Método para obtener los vertices, lo necesitaba para poder imprimirlos en el main  
        vector<vector<int>> getMatrix();                // Método para obtener la matriz, lo necesitaba en el main para las rutas
        int getSize();                                  // Método para obtener el tamaño de la matriz
};

template <class T>
AdjMatrix<T>::AdjMatrix() {
        size = 0;
}

template <class T>
void AdjMatrix<T>::insertVertex(T vertices[], int size) {
        this->vertices.resize(size);    // Ajusto el tamaño de mi vector de vertices de la clase para ajustarse a lo que recibí
        matrix.resize(size);            // Ajusto una de las dimensiones de la matriz también al tamaño recibido
        for (int i = 0; i < size; i++) {
                matrix[i].resize(size, 2147483647 / 2); // Ajusto el tamaño de cada elemento pues es un vector 2D
                this->vertices[i] = vertices[i];        // Transfiero los datos de la lista de entrada a la lista de la clase
        }
        this->size = size;      // Ajusto el tamaño para que este actualizado
}

template <class T>
int AdjMatrix<T>::findVertex(T vertex) {
        for (int i = 0; i < size; i++) {        // Se itera por cada vertice
                if (vertices[i] == vertex) {    // Se compara el elemento con el parametro
                        return i;               // Se regresa el índice
                }
        }
        return -1;      // Este return es en caso de que no se encuentre
}

template <class T>
void AdjMatrix<T>::insert(T from_vertex, T to_vertex, int weight) {
        if (from_vertex != to_vertex) {   // Validamos que no sea el mismo vértice
                int pos_from_vertex = findVertex(from_vertex);     // Buscamos en que posición de la lista de vértices se encuentra from_vertex
                if (pos_from_vertex == -1) {      // Validamos si no se encuentra en la lista de vértices
                        // Agregamos el vértice a la lista de vértices
                        vertices.push_back(from_vertex);
                        pos_from_vertex = size;
                        size++;
                }
                
                int pos_to_vertex = findVertex(to_vertex);        // Buscamos en que posición de la lista de vértices se encuentra to_vertex
                if (pos_to_vertex == -1) {        // Validamos si no se encuentra en la lista de vértices
                        // Agregamos el vértice a la lista de vértices
                        vertices.push_back(to_vertex);
                        pos_to_vertex = size;
                        size++;
                }
                
                // Actualizamos en true la posición correspondiente en la matriz
                matrix[pos_from_vertex][pos_to_vertex] = weight;
                matrix[pos_to_vertex][pos_from_vertex] = weight;
        }
}

template <class T>
void AdjMatrix<T>::remove(T from_vertex, T to_vertex) {
        if (from_vertex != to_vertex) {         // Validamos que no sea el mismo
                int pos_from_vertex = findVertex(from_vertex);  // Buscamos el indice del vértice origen
                if (pos_from_vertex == -1) {    // Validamos que si existe, en caso contrario nos salimos de la función
                        return;
                }

                int pos_to_vertex = findVertex(to_vertex);      // Buscamos el indice del vértice destino
                if (pos_to_vertex == -1) {      // Validamos que si existe, en caso contrario nos salimos de la función
                        return;
                }

                // Actualizamos la matriz en las posiciones correspondientes
                matrix[pos_from_vertex][pos_to_vertex] = 0;
                matrix[pos_to_vertex][pos_from_vertex] = 0;
        }
}

template <class T>
int AdjMatrix<T>::getSize() {
        return size;
}

template <class T>
vector<T> AdjMatrix<T>::getVertices() {
        return vertices;
}

template <class T>
vector<vector<int>> AdjMatrix<T>::getMatrix() {
        return matrix;
}

template <class T>
void AdjMatrix<T>::print() {
        for (int i = 0; i < size; i++) {
                cout << vertices[i] << " | ";   // Se imprimen los índices con un separador
        }
        cout << "\n" << endl;
        for (int i = 0; i < size; i++) {        // Ciclo doble para imprimir los valores de la matriz
                for (int j = 0; j < size; j++) {
                        cout << matrix[i][j] << "\t";
                }
                cout << endl;
        }
}
