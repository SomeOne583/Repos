#include <iostream>
#include "NodeT.h"
using namespace std;

template<class T>
class BAT {
        private:
                NodeT<T> *root;
                void printTree(NodeT<T> *aux, int level);
        public:
                BAT();
                ~BAT();
                void play();
                void print();
                bool isEmpty();
                bool isPregunta(NodeT<T> *aux);
};

template<class T>
BAT<T>::BAT() {
        cout << "Creando árbol" << endl;
        root = nullptr;
}

template<class T>
BAT<T>::~BAT() {
        cout << "Destructor activado" << endl;
}

template<class T>
void BAT<T>::play() {
        string pregunta, animal, confirmacion, auxData;
        if (root == nullptr) {
                cout << "Aún no tengo información" << endl;
                cout << "Ingresa el animal en el que piensas: ";
                cin >> animal;
                cout << "Ingresa como identificarlo: ";
                cin >> pregunta;
                root = new NodeT(pregunta);
                root->left = new NodeT(animal);
        } else {
                NodeT<T> *aux = root;
                while (true) {
                        if (isPregunta(aux)) {
                                cout << "¿" << aux->data << "?" << endl;
                                cin >> confirmacion;    
                                if (confirmacion == "y") {
                                        aux = aux->left;
                                } else {
                                        if (aux->right == nullptr) {
                                                cout << "Ingresa el animal en el que piensas: ";
                                                cin >> animal;
                                                aux->right = new NodeT(animal);
                                                break;
                                        } else {
                                                aux = aux->right;
                                        }
                                }
                        } else {
                                cout << "Es " << aux->data << "?" << endl;
                                cin >> confirmacion;
                                if (confirmacion == "y") {
                                        cout << "Gane" << endl;
                                        break;
                                } else {
                                        cout << "Ingresa el animal en el que piensas: ";
                                        cin >> animal;
                                        cout << "Ingresa como identificarlo: ";
                                        cin >> pregunta;
                                        auxData = aux->data;
                                        aux->data = pregunta;
                                        aux->left = new NodeT(animal);
                                        aux->right = new NodeT(auxData);
                                        break;
                                }
                        }
                }
        }
}

template<class T>
void BAT<T>::print() {
        if (!isEmpty()) {
                int level = 0;
                cout << endl;
                printTree(root, level);
                cout << endl;
        } else {
                cout << "Esta vacio" << endl;
        }
}

template<class T>
void BAT<T>::printTree(NodeT<T> *aux, int level) {
        if (aux != nullptr) {
                printTree(aux->right, level + 1);
                for (int i = 0; i < level; i++) {
                        cout << " ";
                }
                cout << aux->data << endl;
                printTree(aux->left, level + 1);
        }
}

template<class T>
bool BAT<T>::isEmpty() {
        return root == nullptr;
}

template<class T>
bool BAT<T>::isPregunta(NodeT<T> *aux) {
        return (aux->left != nullptr || aux->right != nullptr);
}

/*
template<class T>
bool BST<T>::search(T data) {
        NodeT<T> *p = root;
        while (p != nullptr) {
                if (p->data == data)
                        return true;
                else
                        p = (p->data > data ? p->left: p->right);
        }
        return false; 
}

template<class T>
void BST<T>::insert(T data) {
        if (root == nullptr) {
                root = new NodeT(data);
        }
        NodeT<T> *aux = root;
        while (aux->data != data) {
                if (aux->data > data) {
                        if (aux->left == nullptr) {
                                aux->left = new NodeT(data);
                        } else {
                                aux = aux->left;
                        }
                } else if (aux->data < data) {
                        if (aux->right == nullptr) {
                                aux->right = new NodeT(data);
                        } else {
                                aux = aux->right;
                        }
                }
        }
}

template<class T>
void BST<T>::deleteT(T data) {
        if (search(data)) {
                NodeT<T> *auxPrev = root;
                NodeT<T> *aux = root;
                while (aux->data != data) {
                        auxPrev = aux;
                        aux = (aux->data > data ? aux->left: aux->right);
                }
                if (aux->left == nullptr && aux->right == nullptr) {
                        if (aux == root)
                                root = nullptr;
                        else if (auxPrev->left == aux)
                                auxPrev->left = nullptr;
                        else if (auxPrev->right == aux)
                                auxPrev->right = nullptr;
                        delete aux;
                } else if (aux->left == nullptr || aux->right == nullptr) {
                        if (aux == root)
                                root = (aux->left != nullptr ? aux->left : aux->right);
                        else if (auxPrev->left == aux)
                                auxPrev->left = (aux->left != nullptr ? aux->left : aux->right);
                        else if (auxPrev->right == aux)
                                auxPrev->right = (aux->left != nullptr ? aux->left : aux->right);
                        delete aux;
                } else if (aux->left != nullptr && aux->right != nullptr) {
                        NodeT<T> *predecesor = aux->left;
                        while (predecesor->right != nullptr) {
                                predecesor = predecesor->right;
                        }
                        T auxData = predecesor->data;
                        deleteT(predecesor->data);
                        aux->data = auxData;
                }
        }
}



template<class T>
void BST<T>::ancestors(T data) {
        if (search(data)) {
                NodeT<T> *auxPrev = root;
                NodeT<T> *aux = root;
                while (aux->data != data) {
                        auxPrev = aux;
                        aux = (aux->data > data ? aux->left: aux->right);
                }
                if (aux == root) {
                        cout << aux->data << endl;
                } else {
                        cout << aux->data << " <- ";
                        ancestors(auxPrev->data);
                }
        }
}

template<class T>
int BST<T>::whatlevelamI(T data) {
        int level = -1;
        if (search(data)) {
                NodeT<T> *aux = root;
                level = 0;
                while (aux->data != data) {
                        aux = (aux->data > data ? aux->left: aux->right);
                        level++;
                }
        }
        return level;
}

template<class T>
int BST<T>::height() {
        Queue<NodeT<T>> q;
        NodeT<T> aux = *root;
        q.enqueue(aux);
        int height = 0, level = 0;
        while (!q.isEmpty()) {
                aux = q.dequeue();
                if (aux.left != nullptr)
                        q.enqueue(*aux.left);
                if (aux.right != nullptr)
                        q.enqueue(*aux.right);
                level = whatlevelamI(aux.data) + 1;
                if (level > height) {
                        height = level;
                }
        }

        return height;
}

template<class T>
void BST<T>::preorder(NodeT<T> *aux) {
        cout << aux->data << ", ";
        if (aux->left != nullptr) {
                preorder(aux->left);
        }
        if (aux->right != nullptr) {
                preorder(aux->right);
        }
}

template<class T>
void BST<T>::inorder(NodeT<T> *aux) {
        if (aux->left != nullptr) {
                inorder(aux->left);
        }
        cout << aux->data << ", ";
        if (aux->right != nullptr) {
                inorder(aux->right);
        }
}

template<class T>
void BST<T>::postorder(NodeT<T> *aux) {
        if (aux->left != nullptr) {
                postorder(aux->left);
        }
        if (aux->right != nullptr) {
                postorder(aux->right);
        }
        cout << aux->data << ", ";
}

template<class T>
void BST<T>::levelByLevel() {
        Queue<NodeT<T>> q;
        NodeT<T> aux = *root;
        q.enqueue(aux);
        while (!q.isEmpty()) {
                aux = q.dequeue();
                if (aux.left != nullptr)
                        q.enqueue(*aux.left);
                if (aux.right != nullptr)
                        q.enqueue(*aux.right);
                cout << aux.data << ", ";
        }
}

template<class T>
void BST<T>::visit(int metodo) {
        switch (metodo) {
                case 1:
                       preorder(root);
                       break;
                case 2:
                       inorder(root);
                       break;
                case 3:
                       postorder(root);
                       break;
                case 4:
                       levelByLevel();
                       break;
        }
        cout << endl;
}
*/