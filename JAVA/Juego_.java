import java.io.*;
import java.util.*;
class Equis{
   public static void main (String args[]){
      Scanner x=new Scanner (System.in);
      String tablero[][]=new String[8][7];
      String mensaje="";
       do{
          System.out.println("\n"+"�A comenzar!");
          int i=0, j=0, y=0;
          int filaO=0, coluO=0;
          int seguir=7;
          for(i=0;i<8;i++){
            System.out.println();
            for(j=0;j<7;j++){
            tablero[i][j]=" ";
            }
          }
      //Jugador
         int randomFila=(int)(Math.random()*8);
         int randomColu=(int)(Math.random()*7);
         int posicionFila=randomFila;
         int posicionColu=randomColu;
         tablero[randomFila][randomColu]="*";
     //Meta
         randomFila=(int)(Math.random()*8);
         randomColu=(int)(Math.random()*7);
         int metaFila=randomFila;
         int metaColu=randomColu;
         tablero[metaFila][metaColu]="M";
      //Obt�culos
         for(y=0;y<6;y++){
            randomFila=(int)(Math.random()*8);
            randomColu=(int)(Math.random()*7);
            tablero[randomFila][randomColu]="#";
         }
         for(i=0;i<8;i++){
            System.out.println();
            for(j=0;j<7;j++){
               System.out.print(" ");
               System.out.print(tablero[i][j]+"|");
            }
         }

      mensaje="";
      do{
         if(!mensaje.equals("ganaste")){
            System.out.println("\n"+"�Qu� movimiento quieres realizar"+"\n"+"1. Arriba"+"\n"+"2.Abajo"+"\n"+"3.Derecha"+"\n"+"4.Izquierda");
         int respuesta=x.nextInt();
    //Indicaciones
       switch (respuesta){
       case 1:
        tablero[posicionFila][posicionColu]=" ";
        posicionFila-=1; 
        if (posicionFila==-1){
         System.out.println("No se puede ese movimiento, intenta de nuevo");
         posicionFila+=1;}
        if ((tablero[posicionFila][posicionColu]=="#")){
         mensaje="perdiste";}
        else if(tablero[posicionFila][posicionColu]=="M"){
         mensaje="ganaste";}
         System.out.println(mensaje);
         tablero[posicionFila][posicionColu]="*";
         break;
       case 2:
        tablero[posicionFila][posicionColu]=" ";
        posicionFila+=1;
        if (posicionFila==-8){
         System.out.println("No se puede ese movimiento, intenta de nuevo");
         posicionFila-=1;}
        if ((tablero[posicionFila][posicionColu]=="#")){
         mensaje="perdiste";}
        else if(tablero[posicionFila][posicionColu]=="M"){
         mensaje="ganaste";}
         System.out.println(mensaje);
         tablero[posicionFila][posicionColu]="*";
         break;
       case 3:
         tablero[posicionFila][posicionColu]=" ";
         posicionColu+=1; 
         if (posicionColu==8){
            System.out.println("No se puede ese movimiento, intenta de nuevo");
            posicionColu-=1;}
         if ((tablero[posicionFila][posicionColu]=="#")){
           mensaje="perdiste";}
         else if(tablero[posicionFila][posicionColu]=="M"){
            mensaje="ganaste";}
            System.out.println(mensaje);
            tablero[posicionFila][posicionColu]="*";
            break;
   
       case 4:
         tablero[posicionFila][posicionColu]=" ";
         posicionColu-=1; 
         if (posicionColu==-1){
            System.out.println("No se puede ese movimiento, intenta de nuevo");
            posicionColu+=1;}
         if ((tablero[posicionFila][posicionColu]=="#")){
           mensaje="perdiste";}
         else if(tablero[posicionFila][posicionColu]=="M"){
            mensaje="ganaste";}
         System.out.println(mensaje);
         tablero[posicionFila][posicionColu]="*"; 
         }
     if (!mensaje.equals("ganaste")){
      for(i=0;i<8;i++){
         System.out.println();
         for(j=0;j<7;j++){
            System.out.print(" ");
            System.out.print(tablero[i][j]+"|");
         }
      }  
     } 
    }     
   } while(!mensaje.equals ("perdiste"));
  }while(mensaje.equals("perdiste"));
 }
}