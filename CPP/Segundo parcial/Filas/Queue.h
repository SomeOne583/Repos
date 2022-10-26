#include <iostream>
#include "Node.h"
using namespace std;

template<class T>
class Queue {
        private:
                Node<T> *head;
                int size;
                int maxSize;
        public:
                Queue();
                ~Queue();
                void enqueue(T data);
                T dequeue();
                void setMaxSize(int maxSize);
                T front();
                T back();
                void clear();
                bool isFull();
                bool isEmpty();
                void print();
                int getSize();
};

template<class T>
Queue<T>::Queue() {
        cout << "Creando fila\n";
        head = nullptr;
        size = 0;
        maxSize = 0;
}

template<class T>
Queue<T>::~Queue() {
        cout << "\nDestructor activado\n";
        clear();
}

template<class T>
void Queue<T>::enqueue(T data) {
        if (isFull()) {
                cout << "La fila ya esta llena, no se pudo añadir" << endl;
        } else {
                if (isEmpty()) {
                        head = new Node(data);
                } else {
                        Node<T> *aux = head;
                        while (aux->next != nullptr) {
                                aux = aux->next;
                        }
                        aux->next = new Node(data);
                }
                size++;
        }
}

template<class T>
T Queue<T>::dequeue() {
        if (!isEmpty()) {
                Node<T> *aux = head;
                head = aux->next;
                T data = aux->data;
                delete aux;
                size--;
                return data;
        }
}

template<class T>
void Queue<T>::setMaxSize(int maxSize) {
        this->maxSize = maxSize;
}

template<class T>
T Queue<T>::front() {
        if (!isEmpty()) {
                Node<T> *aux = head;
                return aux->data;
        }
}

template<class T>
T Queue<T>::back() {
        if (!isEmpty()) {
                Node<T> *aux = head;
                while (aux->next != nullptr) {
                        aux = aux->next;
                }
                return aux->data;
        }
}

template<class T>
void Queue<T>::clear() {
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
bool Queue<T>::isFull() {
        return maxSize == 0 ? false : maxSize == size;
}

template<class T>
bool Queue<T>::isEmpty() {
        return size == 0;
}

template<class T>
int Queue<T>::getSize() {
        return size;
}

template<class T>
void Queue<T>::print() {
        Node<T> *aux = head;
        cout << "Fila: ";
        for (int i = 0; i < size; i++) {
                cout << aux->data << " | ";
                aux = aux->next;
        }
}
