// Jan Carlo Reyes Martínez, 577441
// Programa para convertir una medida dada en metros a pies, pulgadas y centimetros

import java.io.*;
import java.util.*;

class Conversor {
  public static void main(String[] args) {
    Scanner s = new Scanner(System.in);
    double metros;

    System.out.println("Ingresa la cantidad en metros");
    metros = s.nextDouble();

    double pies = metros * 3.281;
    double centimetros = metros * 100;
    double pulgadas = metros * 39.37;

    System.out.println("Distancia en metros: " + metros + "m");
    System.out.println("Distancia en centimetros: " + centimetros + "cm");
    System.out.println("Distancia en pies: " + pies + "ft");
    System.out.println("Distancia en pulgadas: " + pulgadas + "in");
  }
}
