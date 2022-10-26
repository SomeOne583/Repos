#include <iostream>
#include <sstream>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>

using namespace std;

bool existeNodo(int pos, map<int, char> &ab) {
        try {
                ab.at(pos);
                return true;
        } catch (const out_of_range &oor) {
                return false;
        }
        return false;
}

void generar(int pos, string &inorder, stack<char> &preorder, map<int, char> &ab) {
        char top;
        size_t it;
        if (!preorder.empty()) {
                top = preorder.top();
                ab[pos] = top;
                preorder.pop();
                it = inorder.find(top);
                inorder[it] = '-';
                if (it > 0 && inorder[it - 1] != '-') {
                        generar(pos * 2 + 1, inorder, preorder, ab);
                }
                if (it < inorder.size() - 1 && inorder[it + 1] != '-') {
                        generar(pos * 2 + 2, inorder, preorder, ab);
                }
        }
}

void postorden(int pos, map<int, char> &ab) {
        if (existeNodo(pos * 2 + 1, ab)) {
                postorden(pos * 2 + 1, ab);
        }
        if (existeNodo(pos * 2 + 2, ab)) {
                postorden(pos * 2 + 2, ab);
        }
        cout << ab[pos];
}

int main() {
        int c, longitud;
        string linea, inorder;
        stringstream separador;
        stack<char> preorder;
        map<int, char> ab;

        cin >> c;

        while (c--) {
                while (!preorder.empty()) {
                        preorder.pop();
                }
                ab.clear();

                cin >> longitud;

                cin >> linea;

                for (int i = longitud - 1; i >= 0; i--) {
                        preorder.push(linea[i]);
                }

                cin >> inorder;

                generar(0, inorder, preorder, ab);
                postorden(0, ab);
                cout << endl;
        }

        return 0;
}
