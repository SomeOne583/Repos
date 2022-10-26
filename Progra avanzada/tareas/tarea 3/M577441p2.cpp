// Problema Twin Primes
// Jan Carlo Reyes Martínez, 577441
// Juan Manuel Cuevas Gaytan, 611978
// Damos nuestra palabra de que hemos realizado esta actividad con integridad académicas

#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{   
    vector<int> P;
    vector<bool> B;
    vector<int> p;
    B.resize(1000000+1, true);
    int pivote = 2, n, n1, n2, a, b, cont;
    while (pivote <= sqrt(1000000))
    {
        for (int i = pivote * 2; i <= 1000000; i+= pivote)
            B[i] = false;
        for (pivote++; !B[pivote]; pivote++);
    }
    for (int i = 2; i <= 1000000; i++){
        if(B[i])
            P.push_back(i);
    }
    while (cin >> n1 >> n2){
        if (!(n1==0 && n2==0)){
            if(n1>n2){
                cont=n2;
                n2=n1;
                n1=cont;
            }
            cont=0;
            for (int i =0; i<P.size(); i++){ //ciclo para buscar los indices de los valores primos
                if(P[i]>=n1 && cont==0){
                    cont++;
                    a=i;
                }
                if(P[i]>n2){
                    b=i-1;
                    break;
                }
            }
            for(int i=a; i<=b; i++){
                cont=3;
                    if((P[i+1]-P[i])==(P[i+2]-P[i+1])){// Si al diferncia entre tres numeros es igual entra
                        p.push_back(P[i]);
                        p.push_back(P[i+1]);   
                        p.push_back(P[i+2]);          
                        while((P[i+1]-P[i])==(P[i+cont]-P[i+cont-1]) && (P[i+2]-P[i+1])==(P[i+cont]-P[i+cont-1])){ // mientras que la diferncia sea igual segura ingrasando valores
                            p.push_back(P[i+cont]);
                            cont++;
                        }
                        int it=find(P.begin(), P.end(), *p.begin())-P.begin()-1;
                        // Si la lista de numeros primos no es subsecunte los imprime
                        if((*(p.end()-1)<=P[b]) && !(p[0]-P[it]==p[1]-p[0] && it<a)){ 
                            for(int i=0; i<p.size();i++){
                                if(i==p.size()-1)
                                    cout << p[i] << endl;
                                else
                                    cout << p[i] << " ";
                            }            
                        }
                        i+=(p.size()-2);
                        p.clear();  
                    }
            }
        }else{
                break;
        }
    }
    return 0;
}
