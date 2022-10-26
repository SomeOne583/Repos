import java.io.*;
import java.util.*;

class Serie1{
        public static void main(String arg[]){
                float x=Serie1.leerX();
                float acumSerie = 10.0f;
                Serie1.desplegar(acumSerie);
        }
        
        public static float leerX() {
                Scanner s=new Scanner(System.in);
                float x;
                do {
                        System.out.println("Dame el valor de x: ");
                        x = s.nextFloat();
                } while (x > 1 || x < 0);
                
                return x;
        }
        
        public static void desplegar(float acumSerie) {
                System.out.println("El resultado de la serie es:  "+acumSerie); 
        }
}
