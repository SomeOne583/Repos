// Problema Store
// Jan Carlo Reyes Martínez, 577441
// Juan Manuel Cuevas Gaytan, 611978
// Damos nuestra palabra de que hemos realizado esta actividad con integridad académica

#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
using namespace std;
#include <algorithm>
int main(){
    int n1,n2;
    vector <string> a; // Vector para gaurdar las palabras irregulares juntos con sus conjugaciones
    string p1, p2;
    cin >> n1 >> n2; // Lee la cantidad de palabras irregulares y el total de palabras 
    getline(cin, p1);
    for (int i=0; i< n1; i++){ // Ciclo para leer y almacenar en el vector las palabras irregulares
        cin >> p1 >> p2;
        a.push_back(p1);
        a.push_back(p2);
        getline(cin, p1);
    }
    for (int i=0; i< n2; i++){ // Ciclo para cambiar las palabras a su forma plural
        cin >> p1; // Se lee la palabra 
        if(find(a.begin(),a.end(),p1)!=a.end()){ //Si la palabra se encuentra en el vector de los irregulares entra
            for(int i=0; i<a.size();i++){ // Busca la palabra en el vector
                if(p1==a[i]){
                    cout << a[i+1] << endl;//Imprime la palabra en plural 
                    break;
                }
            }
        }else{
            if(p1[p1.length()-1]=='y' && p1[p1.length()-2]  != 'a' && p1[p1.length()-2]  != 'e' && p1[p1.length()-2]  != 'i' && p1[p1.length()-2]  != 'o' && p1[p1.length()-2]  != 'u'){ // Si la palabra termina en 'y' y su caracter predecesor a este no es consonante entra
                p1.erase(p1.length()-1); // Elimina la y
                p1+="ies";
            }else{
                if(p1[p1.length()-1]=='o' || p1[p1.length()-1]=='s' || p1.substr(p1.length()-2,2)=="ch" || p1.substr(p1.length()-2,2)=="sh" || p1[p1.length()-1]=='x'){ //Si la palabra termina en o,s,ch,sh,x  entra 
                    p1+="es";
                }else{
                    p1+='s'; // Si no se cumplio ninguna de las consiciones anteriroes solo agrega una s al final
                }
            }
            cout << p1 << endl;
        }
        getline(cin,p1);// Salta de linea
    }

    return 0;
}
