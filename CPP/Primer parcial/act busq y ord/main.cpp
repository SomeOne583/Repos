// Código hecho por Jan Carlo Reyes Martínez
// 18 de febrero del 2022
// Doy mi palabra de que he realizado esta actividad con integridad académica

#include <vector>
#include <iostream>
#include <chrono>
using namespace std;

// Complejidad O(n)
template<class T>
void ordenaSeleccion(vector<T> &lista, int inicio, int tam) {
        if (inicio < tam - 1) {
                T menor = lista[inicio];
                int posMenor = inicio;
                for (int i = inicio; i < tam; i++) {
                        if (lista[i] < menor) {
                                menor = lista[i];
                                posMenor = i;
                        }
                }
                lista[posMenor] = lista[inicio];
                lista[inicio] = menor;
                ordenaSeleccion(lista, inicio + 1, tam);
        }
}

// Complejidad O(n^2)
template<class T>
void ordenaInsercion(vector<T> &lista) {
        int lsi = 0;
        int mov;
        T x;
        for (int i = 1; i < lista.size(); i++) {
                x = lista[i];
                mov = 0;
                for (int j = lsi; j >= 0; j--) {
                        if (lista[j] > x) {
                                lista[j + 1] = lista[j];
                                mov++;
                        } else {
                                break;
                        }
                }
                lista[i - mov] = x;
                lsi++;
        }
}

// Complejidad O(n)
template<class T>
void ordenaBurbuja(vector<T> &lista) {
        bool cambio;
        T aux;
        do {
                cambio = false;
                for (int i = 1; i < lista.size(); i++)
                        if (lista[i - 1] > lista[i]) {
                                aux = lista[i - 1];
                                lista[i - 1] = lista[i];
                                lista[i] = aux;
                                cambio = true;
                        }
        } while (cambio);
}

// Complejidad O(n)
template<class T>
void merge(int tamIzq, int tamDer, vector<T> izq, vector<T> der, vector<T> &lista) {
        int i = 0, j = 0, k = 0;
        while (i < tamIzq && j < tamDer) {
                if (izq[i] < der[j]) {
                        lista[k] = izq[i];
                        i++;
                } else {
                        lista[k] = der[j];
                        j++;
                }
                k++;
        }
        if (i > tamIzq - 1) {
                for (int l = j; l < tamDer; l++) {
                        lista[k] = der[l];
                        k++;
                }
        } else {
                for (int l = i; l < tamIzq; l++) {
                        lista[k] = izq[l];
                        k++;
                }
        }
}

// Complejidad O(log2 n)
template<class T>
void ordenaMerge(int n, vector<T> &lista) {
        if (n > 1) {
                int tamIzq = n / 2;
                int tamDer = n - tamIzq;
                vector<T> izq, der;
                for (int i = 0; i < tamIzq; i++)
                        izq.push_back(lista[i]);
                for (int i = tamIzq; i < n; i++)
                        der.push_back(lista[i]);
                ordenaMerge(tamIzq, izq);
                ordenaMerge(tamDer, der);
                merge(tamIzq, tamDer, izq, der, lista);
        }
}

// Complejidad O(n)
template<class T>
int particion(vector<T> &lista, int inicio, int fin) {
        int i, indPivote;
        T pivote = lista[inicio];
        T aux;
        indPivote = inicio;
        for (int i = inicio + 1; i <= fin; i++)
                if (lista[i] < pivote) {
                        indPivote++;
                        aux = lista[i];
                        lista[i] = lista[indPivote];
                        lista[indPivote] = aux;
                }
        aux = lista[inicio];
        lista[inicio] = lista[indPivote];
        lista[indPivote] = aux;

        return indPivote;
}

// Complejidad O(n)
template<class T>
void ordenaQuick(vector<T> &lista, int inicio, int fin) {
        if (inicio < fin) {
                int pi = particion(lista, inicio, fin);
                ordenaQuick(lista, inicio, pi - 1);
                ordenaQuick(lista, pi + 1, fin);
        }
}

// Complejidad O(n)
template<class T>
int busqSecuencial(vector<T> &lista, T elem) {
        int index = -1;
        for (int i = 0; i < lista.size(); i++)
                if (lista[i] == elem) {
                        index = i;
                        break;
                }
        return index;
}

// Complejidad O(log n)
template<class T>
int busqBinaria(vector<T> &lista, T elem) {
        int izq = 0;
        int der = lista.size() - 1;
        int med;
        int index = -1;
        do {
                med = (izq + der) / 2;
                if (lista[med] == elem) {
                        index = med;
                        break;
                } else if (lista[med] < elem)
                        izq = med;
                else if (lista[med] > elem)
                        der = med;
        } while (izq != der);

        return index;
}

template<class T>
void leerLista(vector<T> &lista) {
        lista.clear();
        int n;
        T elem;

        cout << "Ingresa la cantidad de elementos: ";
        cin >> n;

        for (int i = 0; i < n; i++) {
                cout << "Ingresa el elemento " << i + 1 << ": ";
                cin >> elem;
                lista.push_back(elem);
        }
}

template<class T>
void imprimirLista(vector<T> &lista) {
        cout << "\nArreglo: ";
        for (int i = 0; i < lista.size(); i++)
                cout << lista[i] << ((i == lista.size() - 1) ? "\n" : ", ");
}

int main() {
        int opcion, opcion2;
        auto start = chrono::steady_clock::now();
        auto end = chrono::steady_clock::now();
        vector<int> listaInt;
        int eI;
        vector<double> listaDouble;
        double eD;
        vector<char> listaChar;
        char eC;
        vector<string> listaString;
        string eS;

        do {
                cout << "\n===== Opciones =====" << endl;
                cout << "1. Crear vector de enteros" << endl;
                cout << "2. Crear vector de doubles" << endl;
                cout << "3. Crear vector de char" << endl;
                cout << "4. Crear vector de string" << endl;
                cout << "5. Salir" << endl;
                cout << ">>> ";
                cin >> opcion;

                switch (opcion) {
                        case 1:
                                leerLista(listaInt);
                                imprimirLista(listaInt);
                                break;
                        case 2:
                                leerLista(listaDouble);
                                imprimirLista(listaDouble);
                                break;
                        case 3:
                                leerLista(listaChar);
                                imprimirLista(listaChar);
                                break;
                        case 4:
                                leerLista(listaString);
                                imprimirLista(listaString);
                                break;
                }

                if (opcion != 5) {
                        cout << "\n===== Opciones =====" << endl;
                        cout << "1. Ordenar por seleccion" << endl;
                        cout << "2. Ordenar por insercion" << endl;
                        cout << "3. Ordenar por burbuja" << endl;
                        cout << "4. Ordenar por merge" << endl;
                        cout << "5. Ordenar por quick" << endl;
                        cout << "6. Busqueda secuencial" << endl;
                        cout << "7. Busqueda binaria" << endl;
                        cout << ">>> ";
                        cin >> opcion2;
                }
                
                switch (opcion) {
                        case 1:
                                switch (opcion2) {
                                        case 1:
                                                start = chrono::steady_clock::now();
                                                ordenaSeleccion(listaInt, 0, listaInt.size());
                                                end = chrono::steady_clock::now();
                                                break;
                                        case 2:
                                                start = chrono::steady_clock::now();
                                                ordenaInsercion(listaInt);
                                                end = chrono::steady_clock::now();
                                                break;
                                        case 3:
                                                start = chrono::steady_clock::now();
                                                ordenaBurbuja(listaInt);
                                                end = chrono::steady_clock::now();
                                                break;
                                        case 4:
                                                start = chrono::steady_clock::now();
                                                ordenaMerge(listaInt.size(), listaInt);
                                                end = chrono::steady_clock::now();
                                                break;
                                        case 5:
                                                start = chrono::steady_clock::now();
                                                ordenaQuick(listaInt, 0, listaInt.size() - 1);
                                                end = chrono::steady_clock::now();
                                                break;
                                        case 6:
                                                cout << "Ingresa elemento a buscar: ";
                                                cin >> eI;
                                                start = chrono::steady_clock::now();
                                                cout << "Indice del elemento: " << busqSecuencial(listaInt, eI) << endl;
                                                end = chrono::steady_clock::now();
                                                break;
                                        case 7:
                                                cout << "Ingresa elemento a buscar: ";
                                                cin >> eI;
                                                ordenaSeleccion(listaInt, 0, listaInt.size());
                                                start = chrono::steady_clock::now();
                                                cout << "Indice del elemento: " << busqBinaria(listaInt, eI) << endl;
                                                end = chrono::steady_clock::now();
                                                break;
                                }
                                imprimirLista(listaInt);
                                cout << "Tiempo en nanosegundos: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ns" << endl;
                                break;
                        case 2:
                                switch (opcion2) {
                                        case 1:
                                                start = chrono::steady_clock::now();
                                                ordenaSeleccion(listaDouble, 0, listaDouble.size());
                                                end = chrono::steady_clock::now();
                                                break;
                                        case 2:
                                                start = chrono::steady_clock::now();
                                                ordenaInsercion(listaDouble);
                                                end = chrono::steady_clock::now();
                                                break;
                                        case 3:
                                                start = chrono::steady_clock::now();
                                                ordenaBurbuja(listaDouble);
                                                end = chrono::steady_clock::now();
                                                break;
                                        case 4:
                                                start = chrono::steady_clock::now();
                                                ordenaMerge(listaDouble.size(), listaDouble);
                                                end = chrono::steady_clock::now();
                                                break;
                                        case 5:
                                                start = chrono::steady_clock::now();
                                                ordenaQuick(listaDouble, 0, listaDouble.size() - 1);
                                                end = chrono::steady_clock::now();
                                                break;
                                        case 6:
                                                cout << "Ingresa elemento a buscar: ";
                                                cin >> eD;
                                                start = chrono::steady_clock::now();
                                                cout << "Indice del elemento: " << busqSecuencial(listaDouble, eD) << endl;
                                                end = chrono::steady_clock::now();
                                                break;
                                        case 7:
                                                cout << "Ingresa elemento a buscar: ";
                                                cin >> eD;
                                                ordenaSeleccion(listaDouble, 0, listaDouble.size());
                                                start = chrono::steady_clock::now();
                                                cout << "Indice del elemento: " << busqBinaria(listaDouble, eD) << endl;
                                                end = chrono::steady_clock::now();
                                                break;
                                }
                                imprimirLista(listaDouble);
                                cout << "Tiempo en nanosegundos: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ns" << endl;
                                break;
                        case 3:
                                switch (opcion2) {
                                        case 1:
                                                start = chrono::steady_clock::now();
                                                ordenaSeleccion(listaChar, 0, listaChar.size());
                                                end = chrono::steady_clock::now();
                                                break;
                                        case 2:
                                                start = chrono::steady_clock::now();
                                                ordenaInsercion(listaChar);
                                                end = chrono::steady_clock::now();
                                                break;
                                        case 3:
                                                start = chrono::steady_clock::now();
                                                ordenaBurbuja(listaChar);
                                                end = chrono::steady_clock::now();
                                                break;
                                        case 4:
                                                start = chrono::steady_clock::now();
                                                ordenaMerge(listaChar.size(), listaChar);
                                                end = chrono::steady_clock::now();
                                                break;
                                        case 5:
                                                start = chrono::steady_clock::now();
                                                ordenaQuick(listaChar, 0, listaChar.size() - 1);
                                                end = chrono::steady_clock::now();
                                                break;
                                        case 6:
                                                cout << "Ingresa elemento a buscar: ";
                                                cin >> eC;
                                                start = chrono::steady_clock::now();
                                                cout << "Indice del elemento: " << busqSecuencial(listaChar, eC) << endl;
                                                end = chrono::steady_clock::now();
                                                break;
                                        case 7:
                                                cout << "Ingresa elemento a buscar: ";
                                                cin >> eC;
                                                ordenaSeleccion(listaChar, 0, listaChar.size());
                                                start = chrono::steady_clock::now();
                                                cout << "Indice del elemento: " << busqBinaria(listaChar, eC) << endl;
                                                end = chrono::steady_clock::now();
                                                break;
                                }
                                imprimirLista(listaChar);
                                cout << "Tiempo en nanosegundos: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ns" << endl;
                                break;
                        case 4:
                                switch (opcion2) {
                                        case 1:
                                                start = chrono::steady_clock::now();
                                                ordenaSeleccion(listaString, 0, listaString.size());
                                                end = chrono::steady_clock::now();
                                                break;
                                        case 2:
                                                start = chrono::steady_clock::now();
                                                ordenaInsercion(listaString);
                                                end = chrono::steady_clock::now();
                                                break;
                                        case 3:
                                                start = chrono::steady_clock::now();
                                                ordenaBurbuja(listaString);
                                                end = chrono::steady_clock::now();
                                                break;
                                        case 4:
                                                start = chrono::steady_clock::now();
                                                ordenaMerge(listaString.size(), listaString);
                                                end = chrono::steady_clock::now();
                                                break;
                                        case 5:
                                                start = chrono::steady_clock::now();
                                                ordenaQuick(listaString, 0, listaString.size() - 1);
                                                end = chrono::steady_clock::now();
                                                break;
                                        case 6:
                                                cout << "Ingresa elemento a buscar: ";
                                                cin >> eS;
                                                start = chrono::steady_clock::now();
                                                cout << "Indice del elemento: " << busqSecuencial(listaString, eS) << endl;
                                                end = chrono::steady_clock::now();
                                                break;
                                        case 7:
                                                cout << "Ingresa elemento a buscar: ";
                                                cin >> eS;
                                                ordenaSeleccion(listaString, 0, listaString.size());
                                                start = chrono::steady_clock::now();
                                                cout << "Indice del elemento: " << busqBinaria(listaString, eS) << endl;
                                                end = chrono::steady_clock::now();
                                                break;
                                }
                                imprimirLista(listaString);
                                cout << "Tiempo en nanosegundos: " << chrono::duration_cast<chrono::nanoseconds>(end - start).count() << " ns" << endl;
                                break;
                }
        } while (opcion != 5);

        return 0;
}