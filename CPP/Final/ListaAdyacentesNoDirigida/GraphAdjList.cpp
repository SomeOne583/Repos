#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// aplicación que usa un grafo dirigido y ponderado

#include "Graph.h"

int main()
{
    
    vector<int> vertices = {0,1,2,3,4,5,6,7};

    Graph<int> graph(vertices);

// método insert de la clase grafo, recibe objeto arco con origen, destino y peso
    graph.insert(Edge<int>(0,3,8));
    graph.insert(Edge<int>(0,4,9));
    graph.insert(Edge<int>(1,3,1));
    graph.insert(Edge<int>(1,5,3));
    graph.insert(Edge<int>(1,6,5));
    graph.insert(Edge<int>(2,5,2));
//     graph.insert(Edge<int>(3,0,8));
//     graph.insert(Edge<int>(3,1,1));
    graph.insert(Edge<int>(3,5,3));
//     graph.insert(Edge<int>(4,0,9));
//     graph.insert(Edge<int>(5,1,3));
//     graph.insert(Edge<int>(5,2,2));
//     graph.insert(Edge<int>(5,3,3));
    graph.insert(Edge<int>(5,6,3));
//     graph.insert(Edge<int>(6,1,5));
//     graph.insert(Edge<int>(6,5,3));
    graph.insert(Edge<int>(6,7,6));
//     graph.insert(Edge<int>(7,6,6));


    graph.print();
    
    
    return 0;
}
