#include <iostream>
#include "Node.h"
using namespace std;

template<class T>
class LinkedList {
        private:
                Node<T> *head;
                int size;
        public:
                LinkedList();
                ~LinkedList();
                void addFirst(T data);
                void addLast(T data);
                int findData(T data);
                T getData(int index);
                bool deleteData(T data);
                bool deleteAt(int index);
                void updateData(T data, T newData);
                void updateAt(int index, T newData);
                void clear();
                bool isEmpty();
                void print();
                int getSize();
};

template<class T>
LinkedList<T>::LinkedList() {
        cout << "Creando lista\n";
        head = nullptr;
        size = 0;
}

template<class T>
LinkedList<T>::~LinkedList() {
        cout << "Destructor activado\n";
        clear();
}

template<class T>
void LinkedList<T>::addFirst(T data) {
        if (isEmpty()) {
                head = new Node(data);
        } else {
                Node<T> *aux = new Node(data);
                aux->next = head;
                head = aux;
        }
        size++;
}

template<class T>
void LinkedList<T>::addLast(T data) {
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

template<class T>
int LinkedList<T>::findData(T data) {
        int pos = -1;
        if (!isEmpty()) {
                Node<T> *aux = head;
                pos = 0;
                while (aux->data != data && aux != nullptr) {
                        aux = aux->next;
                        pos++;
                }
        }
        return pos == size ? -1 : pos;
}

template<class T>
T LinkedList<T>::getData(int index) {
        if (index < size) {
                Node<T> *aux = head;
                int contador = 0;
                while (contador < index && aux != nullptr) {
                        aux = aux->next;
                        contador++;
                }
                return aux->data;
        } else {
                cout << "Fuera de rango";
        }
}

template<class T>
bool LinkedList<T>::deleteData(T data) {
        if (!isEmpty()) {
                Node<T> *aux = head;
                Node<T> *auxPrev = head;

                while (aux->data != data && aux != nullptr) {
                        auxPrev = aux;
                        aux = aux->next;
                }

                if (aux != nullptr) {
                        cout << "Encontrado\n";
                        if (aux == head) { head = aux->next; }
                        auxPrev->next = aux->next;
                        delete aux;
                        size--;
                        return true;
                } else {
                        return false;
                }
        } else {
                return false;
        }
}

template<class T>
bool LinkedList<T>::deleteAt(int index) {
        if (index < size) {
                Node<T> *aux = head;
                Node<T> *auxPrev = head;
                int contador = 0;
                while (contador < index && aux != nullptr) {
                        auxPrev = aux;
                        aux = aux->next;
                        contador++;
                }
                if (aux == head) { head = aux->next; }
                auxPrev->next = aux->next;
                delete aux;
                size--;
                return true;
        } else {
                return false;
        }
}

template<class T>
void LinkedList<T>::updateData(T data, T newData) {
        if (!isEmpty()) {
                Node<T> *aux = head;

                while (aux->data != data && aux != nullptr) {
                        aux = aux->next;
                }

                if (aux != nullptr) {
                        cout << "Encontrado\n";
                        aux->data = newData;
                }
        }
}

template<class T>
void LinkedList<T>::updateAt(int index, T newData) {
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
void LinkedList<T>::clear() {
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
bool LinkedList<T>::isEmpty() {
        return size == 0;
}

template<class T>
int LinkedList<T>::getSize() {
        return size;
}

template<class T>
void LinkedList<T>::print() {
        Node<T> *aux = head;
        for (int i = 0; i < size; i++) {
                cout << aux->data << " ";
                aux = aux->next;
        }
}






























