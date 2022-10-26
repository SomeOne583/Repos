// Jan Carlo Reyes Martínez, 577441
// Programa para calcular el factorial de N números y almacenar la suma de los factoriales calculados

import java.io.*;
import java.util.*;

class Fac_Num {
        public static void main(String[] args) {
                Scanner lector = new Scanner(System.in);
                int cant_Factoriales, factorial, num, suma_Factoriales = 0;

                System.out.print("¿De cuántos números deseas calcular el factorial?: ");
                cant_Factoriales = lector.nextInt();

                for (int i = 0; i < cant_Factoriales; i++) {
                        factorial = 1;
                        
                        System.out.print("Ingresa el número: ");
                        num = lector.nextInt();
                        
                        for (int j = num; j > 0; j--)
                                factorial *= j;
                        suma_Factoriales += factorial;

                        System.out.println("El factorial de " + num + " es: " + factorial);
                }

                System.out.println("La suma de todos los factoriales calculados es: " + suma_Factoriales);
        }
}