#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <iomanip>
using namespace std;
//Juan Manuel Cuevas Gaytan 611978
//Jan Carlo Reyes 577441
//Damos nuestra palabra de que hemos realizado esta actividad con integridad académica
//Problema 2 World Cup Cards
int main(){
   int n;
   cin >> n;
   int aux2=n;
   while(n--){
      int c;
      cin >> c;
      int aux=1;
      map <int, set<int>> m;
      set<int> v;
      set<int>b;
      while(aux<=c){
         int p;
         cin >> p;
         set<int>s;
         while(p--){
            int k;
            cin >> k;
            if(s.find(k)==s.end()){
               if(v.find(k)==v.end()){
                  s.insert(k);
                  v.insert(k);
               }else{
                  if(b.find(k)==b.end()){
                     for(auto it=m.begin(); it!=m.end(); it++){
                        if(it->second.find(k)!=it->second.end()){
                           it->second.erase(it->second.find(k));
                        }
                     }
                     b.insert(k);
                  }
               }
            }
         }
         m[aux]=s;
         aux++;
      }
      cout << "Case " << aux2-n << ":";
      for(auto it=m.begin(); it!=m.end(); it++){
         cout << " ";
         double v1=it->second.size(), v2=v.size()-b.size();
         cout << fixed << setprecision(6)<< (v1/v2)*100 << "%";
      }
      cout << endl;
   }
}