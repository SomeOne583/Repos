// Jan Carlo Reyes Martínez, 577441
// 20/05/2021
// Programa para imprimir un triángulo formado por asteriscos ("*") usando una medida dada por el usuario
// Doy mi palabra de que he realizado esta actividad con integridad académica

import java.io.*;
import java.util.*;

class Triangulo {
        public static void main(String[] args) {
                int medida = Triangulo.leerMedida();
                Triangulo.dibujar(medida);
        }

        public static int leerMedida() {
                Scanner lector = new Scanner(System.in);
                int medida;
                // Aquí le hago la primera solicitud de las medidas
                System.out.println("Ingresa la medida de la base del triángulo a dibujar");
                // Dentro de este ciclo le digo los requisitos para que sea un valor válido y leo la medida que da el usuario
                do {
                        System.out.print("El valor debe ser mayor a 2 y debe ser impar\n>>> ");
                        medida = lector.nextInt();
                } while (medida <= 2 || medida % 2 == 0); // Con esta condición reviso de forma simultanea si es igual o menor a 2 y si es par
                // En caso de que sea igual o menor a 2 o sea par pues el ciclo se repite y se vuelve a leer
                
                return medida;
        }

        public static void dibujar(int medida) {
                // En este ciclo se va desde el 1 hasta la medida
                for (int i = 1; i <= medida; i++)
                        // Use un método propio de Java para repetri strings, por eso mi variable del ciclo inicia en 1 y no en 0
                        // Gracias a que uso un println el salto de línea se hace de forma automática
                        // "*".repeat(i); funciona repitiendo la string i veces, ejemplo "*".repeat(3) -> "***"
                        // El ciclo no necesita llaves por ser una línea
                        System.out.println("*".repeat(i));
        }
}
