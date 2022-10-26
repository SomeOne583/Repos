// Jan Carlo Reyes Martínez
// Programa para generar un arreglo de números y contar la frecuencia de cada número

import java.io.*;

class Frecuencia {
        public static void main(String[] args) {
                int[] a = new int[10];
                a = Frecuencia.llenarArreglo(10);
                byte[] frecuencias = new byte[6];
                frecuencias = Frecuencia.contarFrecuencia(a, 10);
                Frecuencia.imprimirResultados(a, frecuencias, 6);
        }

        public static int[] llenarArreglo(int n) {
                int[] a = new int[n];
                for (int i = 0; i < n; i++)
                       a[i] = (int) (Math.random() * 6 + 1);
                return a;
        }

        public static byte[] contarFrecuencia(int[] a, int n) {
                byte[] b = {0, 0, 0, 0, 0, 0};
                for (int i = 1; i <= 6; i++) {
                        for (int j = 0; j < n; j++) {
                                if (a[j] == i)
                                        b[i - 1]++;
                        }
                }
                return b;
        }

        public static void imprimirResultados(int[] a, byte[] b, int n) {
                for (int i = 0; i < 10; i++)
                        System.out.print(a[i] + ", ");
                System.out.println("\n");
                for (int i = 0; i < n; i++)
                        System.out.println((i + 1) + ": " + b[i]);
        }
}