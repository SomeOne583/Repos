import java.io.*;
import java.util.*;

abstract class Figura {
        abstract double calcularArea();
}

class Circulo extends Figura {
        private double radio;

        public Circulo(double radio) {
                setRadio(radio);
        }

        public void setRadio(double radio) {
                this.radio = radio;
        }

        public double getRadio() {
                return this.radio;
        }

        public double calcularArea() {
                return Math.PI * this.radio * this.radio;
        }

        public String toString() {
                return "El área del circulo es: " + this.calcularArea();
        }
}

class Triangulo extends Figura {
        private double base;
        private double altura;

        public Triangulo(double base, double altura) {
                setBase(base);
                setAltura(altura);
        }

        public void setBase(double base) {
                this.base = base;
        }

        public double getBase() {
                return this.base;
        }

        public void setAltura(double altura) {
                this.altura = altura;
        }

        public double getAltura() {
                return this.altura;
        }

        public double calcularArea() {
                return this.base * this.altura / 2;
        }

        public String toString() {
                return "El área del triángulo es: " + this.calcularArea();
        }
}

class Rectangulo extends Figura {
        private double base;
        private double altura;

        public Rectangulo(double base, double altura) {
                setBase(base);
                setAltura(altura);
        }

        public void setBase(double base) {
                this.base = base;
        }

        public double getBase() {
                return this.base;
        }

        public void setAltura(double altura) {
                this.altura = altura;
        }

        public double getAltura() {
                return this.altura;
        }

        public double calcularArea() {
                return this.base * this.altura;
        }

        public String toString() {
                return "El área del rectangulo es: " + this.calcularArea();
        }
}

class Cuadrado extends Figura {
        private double lado;

        public Cuadrado(double lado) {
                setLado(lado);
        }

        public void setLado(double lado) {
                this.lado = lado;
        }

        public double getLado() {
                return this.lado;
        }

        public double calcularArea() {
                return this.lado * this.lado;
        }

        public String toString() {
                return "El área del cuadrado es: " + this.calcularArea();
        }
}

interface LeerCirculo {
        public double leerRadio();
}

class Main implements LeerCirculo {
        public static void main(String[] args) {
                Main m1 = new Main();
                Circulo c1 = new Circulo(m1.leerRadio());

                System.out.println(c1);
        }

        public double leerRadio() {
                boolean valido = true;
                double radio = 0;
                do {
                        Scanner s = new Scanner(System.in);
                        try {
                                valido = true;
                                System.out.print("Ingresa el valor del radio: ");
                                radio = s.nextDouble();
                        } catch (InputMismatchException e) {
                                System.out.println("\nSe ingreso un valor inválido, intenta de nuevo");
                                valido = false;
                        }
                } while (!valido);

                return radio;
        }
}
