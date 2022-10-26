// Jan Carlo Reyes Martínez
// Problema de fracción orientaa a objetos

import java.io.*;
import java.util.*;
import java.text.*;

class Fraccion {
        private float numerador;
        private float denominador;

        public Fraccion(float n, float d) {
                setNumerador(n);
                setDenominador(d);
        }

        public void setNumerador(float numerador) {
                this.numerador = numerador;
        }

        public float getNumerador() {
                return this.numerador;
        }

        public void setDenominador(float denominador) {
                this.denominador = denominador;
        }

        public float getDenominador() {
                return this.denominador;
        }

        public double dividir() {
                return this.numerador / this.denominador;
        }

        public String toString() {
                DecimalFormat df = new DecimalFormat("#.####");
                return this.numerador + " / " + this.denominador + " = " + df.format(this.dividir());
        }
}

class Main10 {
        public static void main(String[] args) {
                Scanner s = new Scanner(System.in);
                float n, d;

                // Validaciones de entradas
                System.out.print("Ingresa el numerador: ");
                n = s.nextFloat();
                
                do {
                        System.out.print("Ingresa el denominador (No puede ser 0): ");
                        d = s.nextFloat();
                } while (d == 0);

                s.close();

                // Se crea e imprime el objeto
                Fraccion f1 = new Fraccion(n, d);
                System.out.println("Fracción: " + f1);
                System.out.println("Numerador: " + f1.getNumerador());
                System.out.println("Denominador: " + f1.getDenominador());
        }
}
