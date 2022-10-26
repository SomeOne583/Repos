#include <map>
#include <iostream>

bool existeNodo(int pos, std::map<int, int> &ABB) {
        try {
                if (ABB.at(pos)) {
                        return true;
                }
        } catch (const std::out_of_range& oor) {
                return false;
        }
        return false;
}

void insertar(int valor, std::map<int, int> &ABB) {
        if (ABB.empty()) {
                ABB[0] = valor;
        } else {
                int pos = 0;
                while(existeNodo(pos, ABB)) {
                        if (valor<ABB[pos]) {
                                pos = pos * 2 + 1;
                        } else {
                                pos = pos * 2 + 2;
                        }
                }
                ABB[pos] = valor;
        }
}

bool borrar(int valor, std::map<int, int> &ABB) {
        int pos = 0;
        while(existeNodo(pos, ABB)) {
                if(ABB[pos] == valor) {
                        if(!existeNodo(pos * 2 + 1, ABB) && !existeNodo(pos * 2 + 2, ABB)) {
                                ABB.erase(pos);
                                return true;
                        }
                        int pi=-1;
                        if(existeNodo(pos * 2 + 1, ABB)) {
                                pi = pos * 2 + 1;
                                while(existeNodo(pi * 2 + 2, ABB)) {
                                        pi = pi * 2 + 2;
                                }
                        }
                        int pd=-1;
                        if(existeNodo(pos * 2 + 2, ABB)) {
                                pd = pos * 2 + 2;
                                while(existeNodo(pd*2+1, ABB)) {
                                        pd = pd * 2 + 1;
                                }
                        }
                        if(pi!=-1) {
                                int val=ABB[pi];
                                borrar(val, ABB);
                                ABB[pos]=val;
                        } else {
                                int val=ABB[pd];
                                borrar(val, ABB);
                                ABB[pos]=val;
                        }
                        return true;
                } else {
                        if(valor<ABB[pos]) {
                                pos=pos*2+1; //izq
                        } else {
                                pos=pos*2+2; //der
                        }
                }
        }
        return false;
}

int main() {
        return 0;
}
