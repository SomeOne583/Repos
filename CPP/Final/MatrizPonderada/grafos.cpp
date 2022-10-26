#include <iostream>
using namespace std;
#include "GraphM.h"
// aplicación que utiliza matriz de adyacencias con ponderación

int main() {
        GraphM<char> grafo;
        
        char vertices[10];
        vertices[0] = 'a';
        vertices[1] = 'b';
        vertices[2] = 'c';
        vertices[3] = 'd';
        vertices[4] = 'e';
        vertices[5] = 'f';
        vertices[6] = 'g';
        vertices[7] = 'h';
        
        grafo.insertVertices(vertices,8);
        
        grafo.insert('a','e', 2);
        grafo.insert('b','c', 4);
        grafo.insert('b','d', 2);
        grafo.insert('b','g', 6);
        grafo.insert('c','e', 5);
        grafo.insert('d','h', 8);
        grafo.insert('f','d', 9);
        grafo.insert('g','e', 1);
        
        grafo.print();
        cout << endl;
        
        grafo.remove('g','e');
        
        grafo.print();
        
        return 0;
}
