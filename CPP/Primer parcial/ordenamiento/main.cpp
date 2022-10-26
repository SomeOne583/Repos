#include <vector>
#include <iostream>
using namespace std;

template<class T>
void seleccion(vector<T> &lista, int inicio, int tam) {
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
                seleccion(lista, inicio + 1, tam);
        }
}

template<class T>
void insercion(vector<T> &lista) {
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

template<class T>
void bubble(vector<T> &lista) {
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

template<class T>
void mergeSort(int n, vector<T> &lista) {
        if (n > 1) {
                int tamIzq = n / 2;
                int tamDer = n - tamIzq;
                vector<T> izq, der;
                for (int i = 0; i < tamIzq; i++)
                        izq.push_back(lista[i]);
                for (int i = tamIzq; i < n; i++)
                        der.push_back(lista[i]);
                mergeSort(tamIzq, izq);
                mergeSort(tamDer, der);
                merge(tamIzq, tamDer, izq, der, lista);
        }
}

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

template<class T>
void quickSort(vector<T> &lista, int inicio, int fin) {
        if (inicio < fin) {
                int pi = particion(lista, inicio, fin);
                quickSort(lista, inicio, pi - 1);
                quickSort(lista, pi + 1, fin);
        }
}

int main() {
        vector<string> lista = { "ade", "desfe", "aaaaa", "bbbb" };
        seleccion(lista, 0, lista.size());
        insercion(lista);
        bubble(lista);
        mergeSort(lista.size(), lista);
        quickSort(lista, 0, lista.size() - 1);
        for (int i = 0; i < lista.size(); i++)
                cout << lista[i] << ", ";
        return 0;
}