#ifndef GraphM_h
#define GraphM_h
// Grafo implementado en matriz de adyacencias con ponderación
template <class T>
class GraphM {
private:
        int matrix[10][10] { 0 };
        T vertices[10];
        int numVertices;
        int findVertex(T vertex);
public:
        GraphM();
        void insertVertices(T vertices[10], int numVertices);
        void insert(T fromVertex, T toVertex, int weight);
        void remove(T fromVertex, T toVertex);
        void print();
};

template <class T>
GraphM<T>::GraphM() {
        numVertices = 0;
}

template <class T>
void GraphM<T>::insertVertices(T vertices[10], int numVertices) {
        for (int i = 0; i < numVertices; i++) {
                this->vertices[i] = vertices[i];
        }
        this->numVertices = numVertices;
}

template <class T>
int GraphM<T>::findVertex(T vertex) {
        for (int i = 0; i < numVertices; i++) {
                if (vertices[i] == vertex) {
                        return i;
                }
        }
        return -1;
}

template <class T>
void GraphM<T>::insert(T fromVertex, T toVertex, int weight) {
        // Validamos que no sea el mismo vértice
        if (fromVertex != toVertex) {
                // Buscamos en que posición de la lista de vértices se encuentra fromVertex
                int posFromVertex = findVertex(fromVertex);
                // Validamos si no se encuentra en la lista de vértices
                if (posFromVertex == -1) {
                        // Agregamos el vértice a la lista de vértices
                        if (numVertices < 10) {
                                vertices[numVertices] = fromVertex;
                                posFromVertex = numVertices;
                                numVertices++;
                        } else {
                                return;
                        }
                }
                
                // Buscamos en que posición de la lista de vértices se encuentra toVertex
                int posToVertex = findVertex(toVertex);
                // Validamos si no se encuentra en la lista de vértices
                if (posToVertex == -1) {
                        // Agregamos el vértice a la lista de vértices
                        if (numVertices < 10) {
                                vertices[numVertices] = toVertex;
                                posToVertex = numVertices;
                                numVertices++;
                        } else {
                                return;
                        }
                }
                
                // Actualizamos en true la posición correspondiente en la matriz
                matrix[posFromVertex][posToVertex] = weight;
                matrix[posToVertex][posFromVertex] = weight;
        }
}

template <class T>
void GraphM<T>::remove(T fromVertex, T toVertex) {
        if (fromVertex != toVertex) {
                // Buscamos el indice del vértice origen
                int posFromVertex = findVertex(fromVertex);
                // Validamos que si existe, en caso contrario nos salimos de la función
                if (posFromVertex == -1) {
                        return;
                }
                // Buscamos el indice del vértice destino
                int posToVertex = findVertex(toVertex);
                // Validamos que si existe, en caso contrario nos salimos de la función
                if (posToVertex == -1) {
                        return;
                }
                // Actualizamos la matriz en las posiciones correspondientes
                matrix[posFromVertex][posToVertex] = 0;
                matrix[posToVertex][posFromVertex] = 0;
        }
}

template <class T>
void GraphM<T>::print() {
        cout << "  ";
        for (int i = 0; i < numVertices; i++) {
                cout << vertices[i] << " ";
        }
        cout << endl;
        for (int i = 0; i < numVertices; i++) {
                cout << vertices[i] << " ";
                for (int j = 0; j < numVertices; j++) {
                        cout << matrix[i][j] << " ";
                }
                cout << endl;
        }
}
#endif