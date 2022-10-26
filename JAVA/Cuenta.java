// Jan Carlo Reyes Martínez
// Programa para calcular el costo total de una cuenta basado en el código del producto y aplicar un descuento cuando aplique

import java.io.*;
import java.util.*;

class Cuenta {
	public static void main(String[] args) {
		Scanner lector = new Scanner(System.in);
		double total = 0.0;
		short cantidad;
		byte codigo;

		System.out.println("Ingresa el código del producto que vas a comprar: ");
		codigo = lector.nextByte();

		System.out.println("Ingresa la cantidad que llevas: ");
		cantidad = lector.nextShort();

		switch (codigo) {
			case 10:
				total = cantidad * 24.3;
				break;
			case 20:
				total = cantidad * 105.0;
				break;
			case 30:
				total = cantidad * 10.35;
				break;
			case 40:
				total = cantidad * 200.0;
				break;
		}

		if (total >= 1000)
			total *= 0.98;
		else if (total >= 800)
			total *= 0.99;

		System.out.println("El total de la compra es: $" + total);
	}
}