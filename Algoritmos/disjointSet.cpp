/*
struct dentro de c++ que contenga la cantidad de conjuntos, así como dos vectores, los cuales irán simulando un árbol, uno de los vectores contendrá el padre del conjunto del índice y el otro contendrá la cantidad de niveles (rank) que tiene como descendientes.
*/
#include <iostream>
#include <vector>
using namespace std;

struct disjointSet{
  vector<int> parent;
  vector<int> rank;
  int n;
  disjointSet(int n){
    this->n = n;
    for (int i=0;i<=n; i++){
      parent.push_back(i);
      rank.push_back(0);
    }
  }
  void add();
  int find(int i);
  void merge(int x, int y);
  void print();
};

void disjointSet::add(){
  n++;
  parent.push_back(n);
  rank.push_back(0);
}
//El método find recibe como parámetro el elemento, del cual se desea encontrar la raíz del árbol parent, esto significa el conjunto al que pertenece;

int disjointSet::find(int u){
  if (u != parent[u]){
    return find(parent[u]);
  }
  return parent[u];
}

//El método merge recibe como parámetro dos elementos, de los cuales se desean unir los dos conjuntos a los que ellos pertenecen, la precondición es que ambos pertenezcan a diferentes conjuntos.
void disjointSet::merge(int x, int y) {
  x = find(x); // encuentra la raíz del árbol
  y = find(y);
  cout << x << " " << y << endl;
  if (rank[x] > rank[y]){ // se revisa el rank y el más chico se agrega al más grande
    parent[y] = x;
  } else{
    parent[x] = y;
  }
  if (rank[x] == rank[y]){
    rank[y]++;
  }
}

void disjointSet::print(){
  for (int i=0;i<=n; i++){
      cout << i <<" ";
    }
  cout << endl;
  for (int i=0;i<=n; i++){
      cout << parent[i] <<" ";
    }
  cout << endl;
  for (int i=0;i<=n; i++){
      cout << rank[i] <<" ";
    }
  cout << endl;
}

int main() {
  disjointSet miejemplo(5);
  miejemplo.print();
  miejemplo.merge(4,5);
  miejemplo.print();
miejemplo.merge(2,3);
  miejemplo.print();
  miejemplo.merge(2,4);
  miejemplo.print();
  miejemplo.merge(1,5);
  miejemplo.print();
  cout << "Hello World!\n";
}