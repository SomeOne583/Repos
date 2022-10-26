// Jan Carlo Reyes Martínez, 577441
// Problema: Un programa que reciba dos números y realice la división de los mismos
// Doy mi palabra de que he realizado esta actividad con integridad académica

import java.io.*;
import java.util.*;
import java.text.*;

class Fracción {
        public static void main(String[] args) {
                // Se crea la variable resultado en main
                double resultado = dividir();
                // Se despliega la variable con 5 valores decimales
                Fracción.desplegarResultado(resultado, 5);
        }

        public static double leerNumerador() {
                // Se inicializa el escaner y la variable
                Scanner s = new Scanner(System.in);
                double n1;

                // Dado que el numerador no tiene condiciones se hace una lectura simple
                System.out.print("Ingresa el valor del numerador: ");
                n1 = s.nextDouble();

                // Se regresa el valor leído
                return n1;
        }

        public static double leerDenominador() {
                // Se inicializa el escaner y la variable
                Scanner s = new Scanner(System.in);
                double d1;

                // El denominador tiene una condición por lo que se usa un ciclo para validarlo
                do {
                        System.out.print("Ingresa el valor del denominador (No puede ser 0): ");
                        d1 = s.nextDouble();
                } while (d1 == 0);

                // Se regresa el valor leído
                return d1;
        }

        public static double dividir() {
                // Se llaman a los métodos que leen los valores
                double n1 = Fracción.leerNumerador();
                double d1 = Fracción.leerDenominador();

                // Se regresa la operación directamente para ahorrar el uso de una variable
                return n1 / d1;
        }

        public static void desplegarResultado(double resultado, int precision) {
                // Se crea una string format con la cantidad de # que se indiquen en el argumento precisión
                String format = "#." + "#".repeat(precision);
                // Se crea una instancia de un formateador
                DecimalFormat df = new DecimalFormat(format);
                // Se imprime con la precisión que se recibio usando el formateador
                System.out.println("El resultado es: " + df.format(resultado));
        }
}
