// Juan Manuel Cuevas Gaytan 611978
// Jan Carlo Reyes Martínez 577441
// Damos nuestra palabra de que hemos realizado esta actividad con integridad académica
// Problema 3 String popping

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
int a;
void solve(string l){
    if(l.empty()){
        a=1;
        return;
    }
    if(a==1){
        return;
    }
    for(int i=0; i<l.size();i++){
        int cont=1;
        if(l[i+cont]==l[i]){
            while(l[i+cont]==l[i]){
                cont++;
            }
            string aux=l;
            aux.erase(i, cont);
            solve(aux);
            i+=(cont-1);
        }
    }
}
int main(){
    int n;
    cin >> n;
    string l;
    for(int i=0; i<n; i++){
        cin >> l;
        a=0;
        solve(l);
        cout << a << endl;
    }
}
