/* 
Alan García Rodríguez - 570434
Leslie López Rosales - 571315
CÓDIGO DE HONOR: "Nosotros damos nuestra palabra de que hemos realizado este código con integridad académica"*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

void operar(stack<char> &pilaOp, stack<bool> &pilaB){
    if(pilaOp.top()==')'){//paréntesis
        pilaOp.pop();
        while(pilaOp.top()!='('){//hasta recorrer el paréntesis
            operar(pilaOp, pilaB);//opera lo de adentro
        }
        pilaOp.pop();//elimina el operador
        //checa si es posible realizar un '!' o '&' que le preceda
        if(!pilaOp.empty() && (pilaOp.top()=='!' || pilaOp.top()=='&')){
            operar(pilaOp, pilaB);
        }
    }
    else if(pilaOp.top()=='!'){//NOT
        bool letra=pilaB.top();//obtiene operando
        pilaB.pop();
        pilaB.push(!letra);//inserta resultado
        pilaOp.pop();//elimina el operador
        //checa si es posible realizar un '!' o '&' que le preceda
        if(!pilaOp.empty() && (pilaOp.top()=='!' || pilaOp.top()=='&')){
            operar(pilaOp, pilaB);
        }
    }
    else if(pilaOp.top()=='&'){//AND
        bool letra1=pilaB.top();//obtiene operando 1
        pilaB.pop();
        bool letra2=pilaB.top();//obtiene operando 2
        pilaB.pop();
        pilaB.push(letra1 && letra2);//inserta resultado
        pilaOp.pop();//elimina el operador
    }
    else{//OR
        bool letra1=pilaB.top();//obtiene operando 1
        pilaB.pop();
        bool letra2=pilaB.top();//obtiene operando 2
        pilaB.pop();
        pilaB.push(letra1 || letra2);//inserta resultado
        pilaOp.pop();//elimina el operador
    }
}

int main(){
    stack<char> pilaOp;//pila para operadores
    stack<bool> pilaB;//pila para booleanos
    string s;//expresión
    int n, index;
    cin>>n;
    cin.ignore();
    for(int i=0; i<n; i++){//por cada caso
        getline(cin,s);
        //s="T|T&F";//casos de prueba
        //s="(T|T)&F&(F|T)";
        //s="(F & F|T|!T & !F & !(F|F & T))";
        index=0;
        while(index<s.size()){//hasta terminar de recorrer la expresión
            //cout<<"Leyendo "<<s[index]<<endl;
            if(s[index]=='(' || s[index]==')' || s[index]=='!' || s[index]=='&' || s[index]=='|'){
                pilaOp.push(s[index]);
                if(pilaOp.top()==')'){//si completa un paréntesis
                    operar(pilaOp, pilaB);
                }
            }
            else if(s[index]=='T' || s[index]=='F'){//si es un booleano
                if(s[index]=='T')
                    pilaB.push(true);
                else
                    pilaB.push(false);
                //después de un booleano, es posible realizar el '!' o '&' que le precede
                if(!pilaOp.empty() && (pilaOp.top()=='!' || pilaOp.top()=='&')){
                    operar(pilaOp, pilaB);
                }
            }
            index++;
        }

        while(!pilaOp.empty()){//mientras aún haya operadores
            operar(pilaOp, pilaB);
        }

        cout<<"Expression "<<i+1<<": ";
        pilaB.top()?cout<<"T":cout<<"F";
        pilaB.pop();
        if(i!=n-1)
            cout<<endl;
    }
    return 0;
}