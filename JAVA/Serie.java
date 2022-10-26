// Escuderia: Object Oriented Impostors
// Problema: Hacer un programa que sume terminos de la serie (x^n)/n! mientras dichos términos sean mayores que 10^-8
// Fecha: 12/08/2021
// Damos nuestra palabra de que realizamos esta actividad con integridad académica

import java.io.*;
import java.util.*;

class Serie {
        public static void main(String[] args) {
                double acumSerie = Serie.secuenciarSerie(); // Se llama al método encargado de ejecutar la sumatoria y se guarda su retorno
                Serie.desplegarSuma(acumSerie); // Se entrega el valor obtenido a un método que lo imprime
        }
        
        public static double secuenciarSerie() {
                double acumSerie = 0;           // Se inicializan variables
                int i = 0;
                double termino = 0;
                double x = Serie.leerX();       // Se solicita el valor de x del usuario
                do {                            // Ciclo para añadir los términos
                        termino = Serie.calcularTermino(x,i);   // Se invoca la función que calcula el siguiente término
                        acumSerie += termino;   // Se suma al acumulador
                        i++;                    // Se incrementa la variable de control
                } while (termino != 0);         // 0 es un valor que no puede aparecer de forma natural y es usado como señal cierre
        
                return acumSerie;
        }

        public static double leerX() {          // Función para leer el valor que ingrese el usuario
                Scanner s = new Scanner(System.in);
                double x;
                do {
                        System.out.print("Dame el valor de x: ");
                        x = s.nextDouble();
                } while (x < 0 || x > 1);       // Condición para asegurar que sea un valor en el rango válido
                
                return x;
        }
        
        public static void desplegarSuma(double acumSerie) {
                System.out.println("El resultado de la serie es:  " + acumSerie); 
        }

        public static double calcularTermino(double x, int i) { // Método para calcular el siguente termino de la serie
                long factorial = Serie.calcularFactorial(i);    // Mandar llamar al método para calcular el factorial
                double termino = Math.pow(x,i) / factorial;     // Realizar la operación para saber el siguente termin�
                if (termino < Math.pow(10,-8))                  //Condicional para saber si el termino cumple con las condiciones dadas
                        termino = 0.0;
                return termino; // Devulve el termino
        }                
        
        public static long calcularFactorial(int i) {           // Método para calcular el factorial de un número dado
                if (i <= 1)                        // En caso de ser 0 o 1 se devuelve 1 pues son casos especiales
                        return 1;
                else                               // En caso de ser arriba de 1 la función se llama a sí misma con un argumento diferente
                        return i * calcularFactorial(i - 1);
        }        
}
