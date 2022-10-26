#include <iostream>
#include <cmath>
#include <string>
#include <vector>
#include <stdio.h>

using namespace std;

int sudoku[9][9];
int solucion[9][9];
int soluciones;

bool validarSudoku(int f,int c,int n)
{
   //revisar fila
   for(int cc=0;cc<9;cc++)
      if(sudoku[f][cc]==n)
         return false;
   //revisar columna
   for(int ff=0;ff<9;ff++)
      if(sudoku[ff][c]==n)
         return false; 
   //revisar cuadrante
   int fc=(f/3)*3;
   int cc=(c/3)*3;
   
   for(int i=fc;i<fc+3;i++)
      for(int j=cc;j<cc+3;j++)
         if(sudoku[i][j]==n)
               return false;
   return true;
}

bool solve()
{
   int f,c;
   bool found=false;
   for(f = 0; f < 9 && !found; f++)
      for(c = 0; c < 9 && !found; c++)
      {
         if(sudoku[f][c]==0)
            found=true;
      }
        f--;
        c--;
   if(!found) //NO hubo celda vacía, tenemos solución
   {
      soluciones++;
      if(soluciones==1)
         for(f = 0; f < 9 ; f++)
            for(c = 0; c < 9 ; c++)
               solucion[f][c]=sudoku[f][c];      
      return true;
   }
   for (int i = 1; i <=9; i++)
   {
      if(validarSudoku(f,c,i))
      {
         sudoku[f][c]=i; //2
         solve();
         sudoku[f][c]=0;
      }
   }
   return false;
}

int main()
{
   int n;
   cin>>n;
   string s;
   for(int c=0;c<n;c++){
      for(int i=0;i<9;i++){
         cin>>s;
         for (int j = 0; j < 9; j++)
            sudoku[i][j]=s[j]-'0';
      }
      soluciones=0;
      solve();
      if(soluciones==0)
         cout<<"NO SOLUTION"<<"\n";
      if(soluciones==1)
         for(int i=0;i<9;i++)
         {
           for(int j=0;j<9;j++)
               cout<<solucion[i][j];
            cout<<endl;
         }
      if(soluciones>1)
         cout<<soluciones<<" SOLUTIONS\n";
   }
}