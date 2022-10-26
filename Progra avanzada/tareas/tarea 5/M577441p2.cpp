//Juan Manuel Cuevas Gaytan 611978
//Jan Carlo Reyes 577441
//Damos nuestra palabra de que hemos realizado esta actividad con integridad académica
//Problema 2 Ferry

#include <queue>
#include  <vector>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;
void cant(int l, queue<int> &a){
    int acum=0;
    while((acum+a.front())<=l && !a.empty()){
        acum+=a.front();
        a.pop();
    }
}

int main(){
    int c;
    cin >> c;
    while(c--){
        int m;
        int l;
        cin >> l >> m;
        l*=100;
        queue <int> left;
        queue <int> right;
        while(m--){
            int s;
            string lado;
            cin >> s >> lado;
            if(lado=="left"){
                left.push(s);
            }else{
                right.push(s);
            }
        }
        int cont=0;
        while(left.size()!=0 || right.size()!=0){
            int acum=0;
            if(cont%2==0){
                if(!left.empty()){
                    cant(l, left);
                }
            }else{
                if(!right.empty()){
                    cant(l, right);
                }
            }
            cont++;
        }
        cout << cont << endl;
    }
}