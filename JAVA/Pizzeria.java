// Jan Carlo Reyes Martínez, 577441
// Programa para calcular el costo de un pedido en una pizzería, el cual depende de la cantidad de pizzas, cantidad de ingredientes, 
// cantidad de refrescos y litros de nieve que lleva el cliente, también hay un costo de flete y cualquier cantidad podrías ser cero

import java.io.*;
import java.util.*;

class Pizzeria {
	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);

		byte cant_Pizzas, cant_Ingredientes, cant_Refrescos, cant_Nieve;
		
		System.out.println("¿Cuántas pizzas lleva?");
		cant_Pizzas = s.nextByte();

		System.out.println("¿Cuántos ingredientes adicionales lleva?");
		cant_Ingredientes = s.nextByte();

		System.out.println("¿Cuántos refrescos lleva?");
		cant_Refrescos = s.nextByte();

		System.out.println("¿Cuántos litros de nieve lleva?");
		cant_Nieve = s.nextByte();

		double total = cant_Pizzas * 130.0 + cant_Ingredientes * 12.0 + cant_Refrescos * 10.0 + cant_Nieve * 25.0 + 10.0;
		System.out.println("El total del pedido es: $" + total);
  }
}
