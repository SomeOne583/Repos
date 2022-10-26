#include "Queue.h"
#include <iostream>

int main() {
        Queue<int> queue;
        queue.setMaxSize(10);
        int n;

        for (int i = 0; i < 15; i++) {
                cout << "\n1. Añadir\n2. Quitar\n>>> ";        
                cin >> n;
                if (n == 1) {
                        queue.enqueue(i);
                } else {
                        cout << "Sacando de la cola: " << queue.dequeue() << endl;
                }
                queue.print();
        }

        cout << "Final" << endl;
        queue.print();
        cout << "\nFrente: " << queue.front() << endl;
        cout << "Fondo: " << queue.back() << endl;

        return 0;
}