// Escuderia: Object Oriented Impostors
// Objetivo de la actividad: Convertir una solución estructurada al paradigma de la programación orientada a objetos
// Problema: Convertir una medida a sus equivalentes en diferentes unidades
// Fecha: 30/08/2021
// Damos nuestra palabra de que realizamos esta actividad con integridad académica

// Importar librerias necesarias para manejo de texto (entrada, salida, formato)
import java.io.*;
import java.util.*;
import java.text.*;

// Clase Medida
public class Medida {
        // Atributos de la clase
        private char unidad;
        private double valor;
        // Conversiones a cada unidad
        private double valorCenti;
        private double valorMetros;
        private double valorPulg;
        private double valorPies;

        // Constructor que recibe unidad y valor y calcula las conversiones
        public Medida(String unidad, double valor) {
                this.unidad = unidad.toLowerCase().charAt(0);
                this.valor = valor;
                this.valorCenti = convertirCenti();
                this.valorMetros = convertirMetros();
                this.valorPulg = convertirPulg();
                this.valorPies = convertirPies();
        }

        // Métodos para convertir a cada unidad
        public double convertirCenti() {
                double valorCentimetro = 0;
                switch (this.unidad) {
                case 'c':
                        valorCentimetro = this.valor;
                        break;
                case 'm':
                        valorCentimetro = this.valor * 100;
                        break;
                case 'i':
                        valorCentimetro = this.valor * 2.54;
                        break;
                case 'f':
                        valorCentimetro = this.valor * 30.48;
                        break;
                }
                return valorCentimetro;
        }

        public double convertirMetros() {
                double valorMetro = 0;
                switch (this.unidad) {
                case 'c':
                        valorMetro = this.valor / 100;
                        break;
                case 'm':
                        valorMetro = this.valor;
                        break;
                case 'i':
                        valorMetro = this.valor / 39.37;
                        break;
                case 'f':
                        valorMetro = this.valor / 3.281;
                        break;
                }
                return valorMetro;
        }
        
        public double convertirPulg() {
                double valorPulgada = 0;
                switch (this.unidad) {
                case 'c':
                        valorPulgada = this.valor / 2.54;
                        break;
                case 'm':
                        valorPulgada = this.valor * 39.37;
                        break;
                case 'i':
                        valorPulgada = this.valor;
                        break;
                case 'f':
                        valorPulgada = this.valor * 12;
                        break;
                }
                return valorPulgada;
        }
        
        public double convertirPies() {
                double valorPie = 0;
                switch (this.unidad) {
                case 'c':
                        valorPie = this.valor / 30.48;
                        break;
                case 'm':
                        valorPie = this.valor * 3.281;
                        break;
                case 'i':
                        valorPie = this.valor / 12;
                        break;
                case 'f':
                        valorPie = this.valor;
                        break;
                }
                return valorPie;
        }
        
        // Método para imprimir los resultados con un formateador para darle legibilidad
        public String toString() {
                DecimalFormat df = new DecimalFormat("#.###");
                return "\nConversiones:\nMetros: " + df.format(this.valorMetros) + "m\nCentimetros: " + df.format(this.valorCenti) + 
                "cm\nPulgadas: " + df.format(this.valorPulg) + "in\nPies: " + df.format(this.valorPies) + "ft";
        }
}

// Clase para instanciar la clase
class Principal2 {
        // Método donde se almacena el objeto y se imprime
        public static void main(String[] args) {
                Medida m1 = leerMedida();
                System.out.println(m1);
        }

        // Método para leer la unidad con validación 
        public static String leerUnidad() {
                Scanner s = new Scanner(System.in);
                String unidad;
                do {
                        System.out.print("Ingresa la unidad de la medida a convertir (m, cm, in, ft): ");
                        unidad = s.next();
                } while (!unidad.equals("m") && !unidad.equals("cm") && !unidad.equals("in") && !unidad.equals("ft"));
                return unidad;
        }

        // Medida para leer la medida validando que no sea negativo
        public static double leerValor() {
                Scanner s = new Scanner(System.in);
                double valor;
                do {
                        System.out.print("Ingresa el valor de la medida a convertir (mayor o igual a 0): ");
                        valor = s.nextDouble();
                } while (valor < 0);
                return valor;
        }

        // Método para ller ambos datos y regresar una instancia de la clase
        public static Medida leerMedida() {
                String unidad = leerUnidad();
                double valor = leerValor();
                return new Medida(unidad, valor);
        }
}