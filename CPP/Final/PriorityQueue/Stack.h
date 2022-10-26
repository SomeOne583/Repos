#pragma once
#include <iostream>
#include "Node.h"
using namespace std;

template<class T>
class Stack {
        private:
                Node<T> *head;
                int size;
                int maxSize;
        public:
                Stack();
                ~Stack();
                void push(T data);
                T pop();
                void setMaxSize(int maxSize);
                T top();
                void clear();
                bool isFull();
                bool isEmpty();
                void print();
                int getSize();
};

template<class T>
Stack<T>::Stack() {
        cout << "Creando pila\n";
        head = nullptr;
        size = 0;
        maxSize = 0;
}

template<class T>
Stack<T>::~Stack() {
        cout << "\nDestructor activado\n";
        clear();
}

template<class T>
void Stack<T>::push(T data) {
        if (isFull()) {
                cout << "La pila ya esta llena, no se pudo añadir" << endl;
        } else {
                if (isEmpty()) {
                        head = new Node(data);
                } else {
                        Node<T> *aux = new Node(data);
                        aux->next = head;
                        head = aux;
                }
                size++;
        }
}

template<class T>
T Stack<T>::pop() {
        if (!isEmpty()) {
                Node<T> *aux = head;
                head = aux->next;
                T data = aux->data;
                delete aux;
                size--;
                return data;
        } else {
                throw "La pila esta vacia";
        }
}

template<class T>
void Stack<T>::setMaxSize(int maxSize) {
        this->maxSize = maxSize;
}

template<class T>
T Stack<T>::top() {
        if (!isEmpty()) {
                Node<T> *aux = head;
                return aux->data;
        } else {
                throw "La pila esta vacia";
        }
}

template<class T>
void Stack<T>::clear() {
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
bool Stack<T>::isFull() {
        return maxSize == 0 ? false : maxSize == size;
}

template<class T>
bool Stack<T>::isEmpty() {
        return size == 0;
}

template<class T>
int Stack<T>::getSize() {
        return size;
}

template<class T>
void Stack<T>::print() {
        Node<T> *aux = head;
        cout << "Pila: ";
        for (int i = 0; i < size; i++) {
                cout << aux->data << " | ";
                aux = aux->next;
        }
}
