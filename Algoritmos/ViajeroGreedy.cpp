#include <iostream>
#include <vector>
#include <limits>
using namespace std;


int minimo(vector<int> conj, vector<int> rutaOptima, int c){
    int min = numeric_limits<int>::max();
    int vert = -1;
    bool f = true;

    for(int i=0; i<conj.size(); i++){
        f = true;
        for(int j=0; j<rutaOptima.size(); j++){
            if(i==rutaOptima[j]){
                if(i!=rutaOptima[0] || c > 9)   
                    f = false;
            }
                
        }

        if(conj[i] < min && f){
            min = conj[i];
            vert = i;
        }
    }

    return vert;
}

int obtenerRutaOptima(vector<vector<int>> grafo) {
    int pos = 0, c = 17, suma=0, p=0;
    vector<int> rutaOptima;
    
    while (pos!=0 || c==17) {
        rutaOptima.push_back(pos);
        pos = minimo(grafo[p], rutaOptima, c);
        suma += grafo[p][pos];
        p = pos;    
        c--;
    }

    for(int i=0; i<rutaOptima.size(); i++){
        if(i < rutaOptima.size()-1)
            cout << rutaOptima[i] << " -> ";
        else
            cout << rutaOptima[i];
    }
    cout << " -> 0" << endl;  

    return suma;
}



int main(){

    vector<vector<int>> grafo = {{99, 3, 7, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 1, 99, 99, 99},
                                 {3, 99, 4, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99},
                                 {7, 4, 99, 4, 99, 99, 4, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99},
                                 {99, 99, 4, 99, 99, 99, 99, 99, 99, 2, 99, 99, 99, 99, 99, 99, 99, 99},
                                 {99, 99, 99, 99, 99, 8, 99, 3, 3, 99, 99, 99, 99, 99, 99, 99, 99, 99},
                                 {99, 99, 99, 99, 8, 99, 7, 99, 8, 99, 99, 99, 99, 99, 99, 99, 99, 99},
                                 {99, 99, 4, 99, 99, 7, 99, 99, 99, 2, 7, 99, 99, 99, 99, 99, 99, 99},
                                 {99, 99, 99, 99, 3, 99, 99, 99, 4, 99, 99, 3, 99, 99, 7, 99, 99, 99},
                                 {99, 99, 99, 99, 3, 8, 99, 4, 99, 3, 99, 8, 6, 99, 99, 99, 99, 99},
                                 {99, 99, 99, 99, 99, 99, 2, 99, 3, 99, 9, 99, 99, 3, 99, 99, 99, 99},
                                 {99, 99, 99, 2, 99, 99, 7, 99, 99, 9, 99, 99, 99, 3, 99, 99, 99, 99},
                                 {99, 99, 99, 99, 99, 99, 99, 3, 8, 99, 99, 99, 99, 99, 7, 5, 99, 99},
                                 {99, 99, 99, 99, 99, 99, 99, 99, 6, 99, 99, 99, 99, 4, 99, 99, 99, 99},
                                 {99, 99, 99, 99, 99, 99, 99, 99, 99, 3, 3, 99, 4, 99, 99, 99, 99, 9},
                                 {1, 99, 99, 99, 99, 99, 99, 7, 99, 99, 99, 7, 99, 99, 99, 7, 99, 99},
                                 {99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 5, 99, 99, 7, 99, 5, 2},
                                 {99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 5, 99, 4},
                                 {99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 99, 9, 99, 2, 4, 99}};    
    
    int costo = obtenerRutaOptima(grafo);

    cout << "\nCosto total: " << costo << endl;
    

}