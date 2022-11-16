
#include <iostream>
using namespace std;


int adjMat[18][18];



int costo=999;
string ruta="";

int sum;

int maximo=10;
 
// Función para encontrar todas las permutaciones de una string dada `str[i…n-1]`
// que contiene todos los caracteres distintos
void permutations(string str, int i, int n)
{
  // condición base
  if (i == n - 1){
        

    sum=adjMat[0][str[0]-65]+
        adjMat[str[0]-65][str[1]-65]+
        adjMat[str[1]-65][str[2]-65]+
        adjMat[str[2]-65][str[3]-65]+
        adjMat[str[3]-65][str[4]-65]+
        adjMat[str[4]-65][str[5]-65]+
        adjMat[str[5]-65][str[6]-65]+
        adjMat[str[6]-65][str[7]-65]+
        adjMat[str[7]-65][str[8]-65]+
        adjMat[str[8]-65][str[9]-65]+
        adjMat[str[9]-65][str[10]-65]+
        adjMat[str[10]-65][str[11]-65]+
        adjMat[str[11]-65][str[12]-65]+
        adjMat[str[12]-65][str[13]-65]+
        adjMat[str[13]-65][str[14]-65]+
        adjMat[str[14]-65][str[15]-65]+
        adjMat[str[15]-65][str[16]-65]+
        adjMat[str[16]-65][str[17]-65]+
        adjMat[str[17]-65][0];
  
    if(sum<costo){
      costo=sum;
      ruta=str;
    }
  


  
     
    return;
  }
 
    // procesa cada caracter de la string restante
    for (int j = i; j < n; j++)
    {
        // intercambiar carácter en el índice `i` con el carácter actual
        swap(str[i], str[j]);        // STL `swap()` usado
 
        // recurre para la subcadena `str[i+1, n-1]`
        permutations(str, i + 1, n);
 
        // retroceder (restaurar la string a su estado original)
        swap(str[i], str[j]);
    }
}
 
int main()
{

  adjMat[0][0]=0;
adjMat[0][1]=3;
adjMat[0][2]=7;
adjMat[0][3]=11;
adjMat[0][4]=11;
adjMat[0][5]=18;
adjMat[0][6]=11;
adjMat[0][7]=8;
adjMat[0][8]=12;
adjMat[0][9]=13;
adjMat[0][10]=13;
adjMat[0][11]=8;
adjMat[0][12]=18;
adjMat[0][13]=16;
adjMat[0][14]=1;
adjMat[0][15]=8;
adjMat[0][16]=13;
adjMat[0][17]=10;
adjMat[1][0]=3;
adjMat[1][1]=0;
adjMat[1][2]=4;
adjMat[1][3]=8;
adjMat[1][4]=14;
adjMat[1][5]=15;
adjMat[1][6]=8;
adjMat[1][7]=11;
adjMat[1][8]=13;
adjMat[1][9]=10;
adjMat[1][10]=10;
adjMat[1][11]=11;
adjMat[1][12]=17;
adjMat[1][13]=13;
adjMat[1][14]=4;
adjMat[1][15]=11;
adjMat[1][16]=16;
adjMat[1][17]=13;
adjMat[2][0]=7;
adjMat[2][1]=4;
adjMat[2][2]=0;
adjMat[2][3]=4;
adjMat[2][4]=12;
adjMat[2][5]=11;
adjMat[2][6]=4;
adjMat[2][7]=13;
adjMat[2][8]=9;
adjMat[2][9]=6;
adjMat[2][10]=6;
adjMat[2][11]=15;
adjMat[2][12]=13;
adjMat[2][13]=9;
adjMat[2][14]=8;
adjMat[2][15]=15;
adjMat[2][16]=20;
adjMat[2][17]=17;
adjMat[3][0]=11;
adjMat[3][1]=8;
adjMat[3][2]=4;
adjMat[3][3]=0;
adjMat[3][4]=15;
adjMat[3][5]=15;
adjMat[3][6]=8;
adjMat[3][7]=16;
adjMat[3][8]=12;
adjMat[3][9]=9;
adjMat[3][10]=2;
adjMat[3][11]=19;
adjMat[3][12]=10;
adjMat[3][13]=6;
adjMat[3][14]=12;
adjMat[3][15]=17;
adjMat[3][16]=22;
adjMat[3][17]=15;
adjMat[4][0]=11;
adjMat[4][1]=14;
adjMat[4][2]=18;
adjMat[4][3]=19;
adjMat[4][4]=0;
adjMat[4][5]=8;
adjMat[4][6]=15;
adjMat[4][7]=3;
adjMat[4][8]=3;
adjMat[4][9]=16;
adjMat[4][10]=17;
adjMat[4][11]=6;
adjMat[4][12]=9;
adjMat[4][13]=13;
adjMat[4][14]=10;
adjMat[4][15]=11;
adjMat[4][16]=16;
adjMat[4][17]=13;
adjMat[5][0]=18;
adjMat[5][1]=15;
adjMat[5][2]=11;
adjMat[5][3]=15;
adjMat[5][4]=8;
adjMat[5][5]=0;
adjMat[5][6]=7;
adjMat[5][7]=11;
adjMat[5][8]=8;
adjMat[5][9]=9;
adjMat[5][10]=14;
adjMat[5][11]=14;
adjMat[5][12]=14;
adjMat[5][13]=12;
adjMat[5][14]=18;
adjMat[5][15]=19;
adjMat[5][16]=24;
adjMat[5][17]=21;
adjMat[6][0]=11;
adjMat[6][1]=8;
adjMat[6][2]=4;
adjMat[6][3]=8;
adjMat[6][4]=8;
adjMat[6][5]=7;
adjMat[6][6]=0;
adjMat[6][7]=9;
adjMat[6][8]=5;
adjMat[6][9]=2;
adjMat[6][10]=7;
adjMat[6][11]=12;
adjMat[6][12]=9;
adjMat[6][13]=5;
adjMat[6][14]=12;
adjMat[6][15]=16;
adjMat[6][16]=21;
adjMat[6][17]=14;
adjMat[7][0]=8;
adjMat[7][1]=11;
adjMat[7][2]=15;
adjMat[7][3]=19;
adjMat[7][4]=3;
adjMat[7][5]=11;
adjMat[7][6]=18;
adjMat[7][7]=0;
adjMat[7][8]=4;
adjMat[7][9]=17;
adjMat[7][10]=18;
adjMat[7][11]=3;
adjMat[7][12]=10;
adjMat[7][13]=14;
adjMat[7][14]=7;
adjMat[7][15]=8;
adjMat[7][16]=13;
adjMat[7][17]=10;
adjMat[8][0]=12;
adjMat[8][1]=15;
adjMat[8][2]=19;
adjMat[8][3]=16;
adjMat[8][4]=3;
adjMat[8][5]=8;
adjMat[8][6]=15;
adjMat[8][7]=4;
adjMat[8][8]=0;
adjMat[8][9]=13;
adjMat[8][10]=14;
adjMat[8][11]=7;
adjMat[8][12]=6;
adjMat[8][13]=10;
adjMat[8][14]=11;
adjMat[8][15]=12;
adjMat[8][16]=17;
adjMat[8][17]=14;
adjMat[9][0]=13;
adjMat[9][1]=10;
adjMat[9][2]=6;
adjMat[9][3]=9;
adjMat[9][4]=6;
adjMat[9][5]=9;
adjMat[9][6]=2;
adjMat[9][7]=7;
adjMat[9][8]=3;
adjMat[9][9]=0;
adjMat[9][10]=7;
adjMat[9][11]=10;
adjMat[9][12]=7;
adjMat[9][13]=3;
adjMat[9][14]=14;
adjMat[9][15]=14;
adjMat[9][16]=19;
adjMat[9][17]=12;
adjMat[10][0]=13;
adjMat[10][1]=10;
adjMat[10][2]=6;
adjMat[10][3]=2;
adjMat[10][4]=13;
adjMat[10][5]=14;
adjMat[10][6]=7;
adjMat[10][7]=14;
adjMat[10][8]=10;
adjMat[10][9]=7;
adjMat[10][10]=0;
adjMat[10][11]=17;
adjMat[10][12]=8;
adjMat[10][13]=4;
adjMat[10][14]=14;
adjMat[10][15]=15;
adjMat[10][16]=20;
adjMat[10][17]=13;
adjMat[11][0]=8;
adjMat[11][1]=11;
adjMat[11][2]=15;
adjMat[11][3]=19;
adjMat[11][4]=6;
adjMat[11][5]=14;
adjMat[11][6]=19;
adjMat[11][7]=3;
adjMat[11][8]=7;
adjMat[11][9]=19;
adjMat[11][10]=20;
adjMat[11][11]=0;
adjMat[11][12]=13;
adjMat[11][13]=16;
adjMat[11][14]=7;
adjMat[11][15]=5;
adjMat[11][16]=10;
adjMat[11][17]=7;
adjMat[12][0]=18;
adjMat[12][1]=17;
adjMat[12][2]=13;
adjMat[12][3]=10;
adjMat[12][4]=9;
adjMat[12][5]=14;
adjMat[12][6]=9;
adjMat[12][7]=10;
adjMat[12][8]=6;
adjMat[12][9]=7;
adjMat[12][10]=8;
adjMat[12][11]=13;
adjMat[12][12]=0;
adjMat[12][13]=4;
adjMat[12][14]=17;
adjMat[12][15]=15;
adjMat[12][16]=20;
adjMat[12][17]=13;
adjMat[13][0]=16;
adjMat[13][1]=13;
adjMat[13][2]=9;
adjMat[13][3]=6;
adjMat[13][4]=9;
adjMat[13][5]=12;
adjMat[13][6]=5;
adjMat[13][7]=10;
adjMat[13][8]=6;
adjMat[13][9]=3;
adjMat[13][10]=4;
adjMat[13][11]=13;
adjMat[13][12]=4;
adjMat[13][13]=0;
adjMat[13][14]=17;
adjMat[13][15]=11;
adjMat[13][16]=16;
adjMat[13][17]=9;
adjMat[14][0]=1;
adjMat[14][1]=4;
adjMat[14][2]=8;
adjMat[14][3]=12;
adjMat[14][4]=10;
adjMat[14][5]=18;
adjMat[14][6]=12;
adjMat[14][7]=7;
adjMat[14][8]=11;
adjMat[14][9]=14;
adjMat[14][10]=14;
adjMat[14][11]=7;
adjMat[14][12]=17;
adjMat[14][13]=17;
adjMat[14][14]=0;
adjMat[14][15]=7;
adjMat[14][16]=12;
adjMat[14][17]=9;
adjMat[15][0]=8;
adjMat[15][1]=11;
adjMat[15][2]=15;
adjMat[15][3]=17;
adjMat[15][4]=11;
adjMat[15][5]=19;
adjMat[15][6]=16;
adjMat[15][7]=8;
adjMat[15][8]=12;
adjMat[15][9]=14;
adjMat[15][10]=15;
adjMat[15][11]=5;
adjMat[15][12]=15;
adjMat[15][13]=11;
adjMat[15][14]=7;
adjMat[15][15]=0;
adjMat[15][16]=5;
adjMat[15][17]=2;
adjMat[16][0]=13;
adjMat[16][1]=16;
adjMat[16][2]=20;
adjMat[16][3]=19;
adjMat[16][4]=16;
adjMat[16][5]=24;
adjMat[16][6]=18;
adjMat[16][7]=13;
adjMat[16][8]=17;
adjMat[16][9]=16;
adjMat[16][10]=17;
adjMat[16][11]=10;
adjMat[16][12]=17;
adjMat[16][13]=13;
adjMat[16][14]=12;
adjMat[16][15]=5;
adjMat[16][16]=0;
adjMat[16][17]=4;
adjMat[17][0]=10;
adjMat[17][1]=13;
adjMat[17][2]=17;
adjMat[17][3]=15;
adjMat[17][4]=13;
adjMat[17][5]=21;
adjMat[17][6]=14;
adjMat[17][7]=10;
adjMat[17][8]=14;
adjMat[17][9]=12;
adjMat[17][10]=13;
adjMat[17][11]=7;
adjMat[17][12]=13;
adjMat[17][13]=9;
adjMat[17][14]=9;
adjMat[17][15]=2;
adjMat[17][16]=7;
adjMat[17][17]=0;
  
    string str = "ABCDEFGHIJKLMNOPQR";
 
    permutations(str, 0, str.length());

  cout<<ruta[0]-65<<","<<ruta[1]-65<<","<<ruta[2]-65<<","<<ruta[3]-65<<","<<ruta[4]-65<<","<<ruta[5]-65<<","<<ruta[6]-65<<","<<ruta[7]-65<<","<<ruta[9]-65<<","<<ruta[10]-65<<","<<ruta[11]-65<<","<<ruta[12]-65<<","<<ruta[13]-65<<","<<ruta[14]-65<<","<<ruta[15]-65<<","<<ruta[16]-65<<","<<ruta[17]-65<<","<<"0"<<endl;
  cout<<"Costo: "<<costo<<endl;
 
    return 0;
}
