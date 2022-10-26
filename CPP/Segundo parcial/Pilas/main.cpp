#include "Stack.h"
#include <iostream>
using namespace std;

int main() {
        Stack<int> stack;
        stack.setMaxSize(10);
        int n;

        for (int i = 0; i < 15; i++) {
                cout << "\n1. Añadir\n2. Quitar\n>>> ";        
                cin >> n;
                if (n == 1) {
                        stack.push(i);
                } else {
                        cout << "Sacando de la pila: " << stack.pop() << endl;
                }
                stack.print();
        }

        cout << "\nFinal" << endl;
        stack.print();
        cout << "\nTop: " << stack.top() << endl;

        return 0;
}