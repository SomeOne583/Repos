// Jan Carlo Reyes Martínez, 577441
// Programa para calcular la comisión que gana cierto vendedor según la marca que vende

import java.io.*;
import java.util.*;

class Venta {
	public static void main(String[] args) {
		Scanner lector = new Scanner(System.in);
		String nombre, nombreMarca = "";
		byte marca;
		double total, comision = 0;

		System.out.print("Ingresa tu nombre: ");
		nombre = lector.nextLine();

		System.out.println("\nIngresa la marca del vehículo que vendiste: \n1. Mercedes\n2. Toyota\n3. Chrysler");
		marca = lector.nextByte();

		System.out.print("\nIngresa el total de la venta: ");
		total = lector.nextDouble();

		switch (marca) {
			case 1:
				comision = total * 0.05;
				nombreMarca = "Mercedes";
				break;
			case 2:
				comision = total * 0.1;
				nombreMarca = "Toyota";
				break;
			case 3:
				comision = total * 0.08;
				nombreMarca = "Chrysler";
				break;
		}

		System.out.println("Vendedor: " + nombre + "\t\tMarca: " + nombreMarca + "\t\tVenta: " + total + "\t\tComisión: " + comision);
	}
}