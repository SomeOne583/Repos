//
//
//  Generated by StarUML(tm) Java Add-In
//
//  @ Project : Untitled
//  @ File Name : Ecuacion.java
//  @ Date : 
//  @ Author :
//    Objetivo: Generar las dos raices de una ecuacion cuadratica
//
// Código corregido por: Object Oriented Imposters
// Fecha corrección: 03/09/2021
// Damos nuesta palabra de que hemos realizado esta actividad con integridad académica

public class Ecuacion {
        private double a; /* a. representa el valor del coeficiente cuadratico */ 
        private double b; /* b. representa el valor del coeficiente lineal */ 
        private double c; /* c. representa el valor de la constante */ 
        
        // Constructor para asignar los coeficientes
        public Ecuacion(double a, double b, double c)
        {
                setA(a);
                setB(b);
                setC(c); 
        }
        
        // Set y get de cada atributo
        public void setA(double a) {
                this.a = a;
        }
        
        public void setB(double b) {
                this.b = b;
        }
        
        public void setC(double c) {
                this.c = c;
        }
        
        public double getA() {
                return a;
        }
        
        public double getB() {
                return b;
        }
        
        public double getC() {
                return c;
        }
     
        // Método para calcular la raíz 1 considerando la raíz cuadrada del discriminante como negativa
        public double calcular_Raiz1() {      
                double d = (b * b) - (4 * a * c);
                double r;
                if (d<0){
                        r=0;
                        System.out.println("Error:discriminante negativo");
                } else
                        r = (-b-Math.sqrt(d))/(2*a);
                return r;
        }
        
        // Método para calcular la raíz 2 considerando la raíz cuadrada del discriminante como positiva
        public double calcular_Raiz2() {
                double d = (b * b) - (4 * a * c);
                double r;
                if (d<0){
                        r=0;
                        System.out.println("Error:discriminante negativo");
                } else 
                        r = (-b+Math.sqrt(d))/(2*a);
                return r;  
        }
     
        // Imprimir resultados
        public String toString() {
                return "Las raices de la Ecuacion: "+ getA() + "x^2 + "+ getB() +"x + "+ getC() + " son: " +
                "\nr1="+ calcular_Raiz1() + "\nr2="+calcular_Raiz2() + "\n";
        }
        
     }
     
class Principal4 {
        public static void main (String args[]){
                Ecuacion Ec1=new Ecuacion(1,2,1);
                System.out.println(Ec1);
                Ecuacion Ec2=new Ecuacion(8,6,4);
                System.out.println(Ec2);
                Ecuacion Ec3=new Ecuacion(4,2,3);
                System.out.println(Ec3);
        }
}