#pragma once
#include <iostream>
#include "Node.h"
#include "Stack.h"
#include "LinkedList.h"
using namespace std;

template<class T>
class PriorityQueue {
        private:
                Node<T> *head;
                int size;
                T getData(int index);
                int getSize();
                bool isEmpty();
                void updateAt(int index, T newData);
                PriorityQueue(Node<T> *PQHead, int size);
        public:
                PriorityQueue();
                PriorityQueue(LinkedList<T> lista);
                ~PriorityQueue();
                void print();
                void enqueue(T data);
                T dequeue();
                void heapSort(int orden);
                void clear();
};

template<class T>
PriorityQueue<T>::PriorityQueue() {
        cout << "Creando fila de prioridad\n";
        head = nullptr;
        size = 0;
}

template<class T>
PriorityQueue<T>::PriorityQueue(LinkedList<T> lista) {
        cout << "Creando fila de prioridad\n";
        head = nullptr;
        size = 0;
        for (int i = 0; i < lista.getSize(); i++) {
                enqueue(lista.getData(i));
        }
}

template<class T>
PriorityQueue<T>::PriorityQueue(Node<T> *PQhead, int size) {
        cout << "Copiando fila de prioridad\n";
        Node<T> *current = PQhead;
        Node<T> *aux = new Node(current->data);
        aux->next = nullptr;
        head = aux;
        current = current->next;
        this->size = size;
        while (current != nullptr) {
                aux = aux->next = new Node(current->data);
                aux->next = nullptr;
                current = current->next;
        }
}

template<class T>
PriorityQueue<T>::~PriorityQueue() {
        cout << "\nDestructor activado\n";
        clear();
}

template<class T>
void PriorityQueue<T>::clear() {
        if (!isEmpty()) {
                Node<T> *aux = head;
                while (aux != nullptr) {
                        head = aux->next;
                        delete aux;
                        aux = head;
                }
                size = 0;
        }
}

template<class T>
int PriorityQueue<T>::getSize() {
        return size;
}

template<class T>
bool PriorityQueue<T>::isEmpty() {
        return size == 0;
}

template<class T>
void PriorityQueue<T>::print() {
        Node<T> *aux = head;
        cout << "Fila priorizada: ";
        for (int i = 0; i < size; i++) {
                cout << aux->data << " | ";
                aux = aux->next;
        }
        cout << endl;
}

template<class T>
T PriorityQueue<T>::getData(int index) {
        if (index < size) {
                Node<T> *aux = head;
                int contador = 0;
                while (contador < index && aux != nullptr) {
                        aux = aux->next;
                        contador++;
                }
                return aux->data;
        } else {
                throw invalid_argument("Fuera de rango");
        }
}

template<class T>
void PriorityQueue<T>::updateAt(int index, T newData) {
        if (index < size) {
                Node<T> *aux = head;
                int contador = 0;
                while (contador < index && aux != nullptr) {
                        aux = aux->next;
                        contador++;
                }
                aux->data = newData;
        }
}

template<class T>
void PriorityQueue<T>::enqueue(T data) {
        if (isEmpty()) {
                head = new Node(data);
                size++;
        } else {
                Node<T> *aux = head;
                while (aux->next != nullptr) {
                        aux = aux->next;
                }
                aux->next = new Node(data);
                size++;
                int n = size / 2;
                T padre, mayor;
                do {
                        padre = getData(n - 1);
                        T hijo1, hijo2;
                        try {
                                hijo1 = getData(n * 2 - 1);
                        } catch (invalid_argument& e) {
                                hijo1 = 0;
                        }
                        try {
                                hijo2 = getData(n * 2);
                        } catch (invalid_argument& e) {
                                hijo2 = 0;
                        }
                        mayor = ((hijo1 > hijo2) ? hijo1 : hijo2) > padre ? ((hijo1 > hijo2) ? hijo1 : hijo2) : padre;
                        if (hijo1 == mayor) {
                                updateAt(n * 2 - 1, padre);
                                updateAt(n - 1, mayor);
                        } else if (hijo2 == mayor) {
                                updateAt(n * 2, padre);
                                updateAt(n - 1, mayor);
                        }
                        n /= 2;
                } while (mayor != padre);
        }
}

template<class T>
T PriorityQueue<T>::dequeue() {
        if (isEmpty()) {
                throw invalid_argument("La lista esta vacia");
        } else {
                T auxData = getData(0);
                updateAt(0, getData(size - 1));
                updateAt(size - 1, auxData);
                Node<T> *aux = head;
                Node<T> *auxPrev = head;
                while (aux->next != nullptr) {
                        auxPrev = aux;
                        aux = aux->next;
                }
                if (aux == head) { head == nullptr; }
                auxPrev->next = nullptr;
                delete aux;
                size--;

                T padre, mayor;
                T hijo1, hijo2;
                for (int n = 1; n <= size; n++) {
                        padre = getData(n - 1);
                        try {
                                hijo1 = getData(n * 2 - 1);
                        } catch (invalid_argument& e) {
                                hijo1 = 0;
                        }
                        try {
                                hijo2 = getData(n * 2);
                        } catch (invalid_argument& e) {
                                hijo2 = 0;
                        }
                        mayor = ((hijo1 > hijo2) ? hijo1 : hijo2) > padre ? ((hijo1 > hijo2) ? hijo1 : hijo2) : padre;
                        if (hijo1 == mayor) {
                                updateAt(n * 2 - 1, padre);
                                updateAt(n - 1, mayor);
                        } else if (hijo2 == mayor) {
                                updateAt(n * 2, padre);
                                updateAt(n - 1, mayor);
                        }
                };

                return auxData;
        }
}

template<class T>
void PriorityQueue<T>::heapSort(int orden) {
        PriorityQueue *aux = new PriorityQueue(head, size);
        Stack<T> stack;
        switch (orden) {
                case 1:
                        while (!aux->isEmpty()) {
                                stack.push(aux->dequeue());
                        }
                        while (!stack.isEmpty()) {
                                cout << stack.pop() << ", ";
                        }
                        break;
                case 2:
                        while (!aux->isEmpty()) {
                                cout << aux->dequeue() << ", ";
                        }
                        break;
        }
}
