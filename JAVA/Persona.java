// Jan Carlo Reyes Martínez, 577441
// Objetivo: Desarrollar programas orientados a objetos
// Problema: Se busca calcular el IMC y masa ideal de las personas según género, masa y altura
// 30/08/2021
// Doy mi palabra de que he realizado esta actividad con integridad académica

import java.io.*;
import java.util.*;
import java.time.LocalDate;

// Clase Persona, con atributos básicos
public class Persona {
        private float estatura;
        private float masa;
        private char genero;
        private String nombre;
        private LocalDate fechaNacimiento;

        // Método constructor
        public Persona(float estatura, float masa, char genero) {
                this.estatura = estatura;
                this.masa = masa;
                this.genero = genero;
        }

        // Se retorna directamente el IMC
        public double calcularIMC() {
                return this.masa / Math.pow(this.estatura, 2);
        }

        // Se retorna la masa ideal
        public int calcularMasaIdeal() {
                int masaIdeal = 0;
                switch (this.genero) {
                        case 'm':
                        masaIdeal = (int) (Math.round((this.estatura - 1.0) * 100 - 10));
                        break;
                        case 'h':
                        masaIdeal = (int) (Math.round((this.estatura - 1.0) * 100));
                        break;
                }
                return masaIdeal;
        }

        // Método para imprimir
        public String toString() {
        }
}

// Clase para instanciar
class Principal1 {
        public static void main(String[] args) {
                login();
                // instanciación
                Persona p1 = new Persona(1.78f, 64.3f, 'h');
                Persona p2 = new Persona(1.64f, 55f, 'm');
                Persona p3 = leerDatos();
                System.out.println(p1);
                System.out.println(p2);
                System.out.println(p3);
        }

        // Lectura y validación de datos
        public static Persona leerDatos() {
                Scanner s = new Scanner(System.in);
                float estatura, masa;
                char genero;
                do {
                        System.out.print("Ingresa la estatura de la persona: ");
                        estatura = s.nextFloat();
                } while (estatura == 0);
                do {
                        System.out.print("Ingresa la masa de la persona: ");
                        masa = s.nextFloat();
                } while (masa == 0);
                do {
                        System.out.print("Ingresa el género de la persona: ");
                        genero = s.next().charAt(0);
                } while (genero != 'h' && genero != 'm');
                return new Persona(estatura, masa, genero);
        }
        
        // Método para autenticar con una contraseña
        public static void login() {
                String password = "@ttV@2Tq8H3*&EX";
                Scanner s = new Scanner(System.in);
                do {
                        System.out.print("Ingresa la contraseña: ");
                } while (!s.next().equals(password));
        }
}