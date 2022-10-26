#include <iostream>
#include <sstream>
#include <vector>
#include <stack>
#include <map>
#include <algorithm>

using namespace std;

bool existeNodo(int pos, map<int, int> &ab) {
        try {
                ab.at(pos);
                return true;
        } catch (const out_of_range &oor) {
                return false;
        }
        return false;
}

void generar(int pos, vector<int> &inorder, stack<int> &postorder, map<int, int> &ab) {
        int top;
        vector<int>::iterator it;
        if (!postorder.empty()) {
                top = postorder.top();
                ab[pos] = top;
                postorder.pop();
                it = find(inorder.begin(), inorder.end(), top);
                inorder[it - inorder.begin()] = -1;
                if (it - inorder.begin() < inorder.size() - 1 && inorder[it - inorder.begin() + 1] != -1) {
                        generar(pos * 2 + 2, inorder, postorder, ab);
                }
                if (it - inorder.begin() > 0 && inorder[it - inorder.begin() - 1] != -1) {
                        generar(pos * 2 + 1, inorder, postorder, ab);
                }
        }
}

void recorrer(int acum, int pos, map<int, int> &ab, pair<int, int> &menor) {
        acum += ab[pos];
        if (existeNodo(pos * 2 + 1, ab)) {
                recorrer(acum, pos * 2 + 1, ab, menor);
        }
        if (existeNodo(pos * 2 + 2, ab)) {
                recorrer(acum, pos * 2 + 2, ab, menor);
        }
        if (!existeNodo(pos * 2 + 1, ab) && !existeNodo(pos * 2 + 2, ab)) {
                if (menor.first == -1 && menor.second == -1) {
                        menor.first = ab[pos];
                        menor.second = acum;
                } else if (acum == menor.second && ab[pos] < menor.first) {
                        menor.first = ab[pos];
                        menor.second = acum;
                } else if (acum < menor.second) {
                        menor.first = ab[pos];
                        menor.second = acum;
                }
        }
}

int main() {
        string linea;
        stringstream separador;
        vector<int> inorder;
        stack<int> postorder;
        pair<int, int> menor;
        map<int, int> ab;

        while (getline(cin, linea)) {
                inorder.clear();
                while (!postorder.empty()) {
                        postorder.pop();
                }
                ab.clear();
                menor = { -1, -1 };

                separador = stringstream(linea);
                while (getline(separador, linea, ' ')) {
                        inorder.push_back(stoi(linea));                
                }

                getline(cin, linea);
                separador = stringstream(linea);
                while (getline(separador, linea, ' ')) {
                        postorder.push(stoi(linea));                
                }

                generar(0, inorder, postorder, ab);
                recorrer(0, 0, ab, menor);
                cout << menor.first << endl;
        }

        return 0;
}
