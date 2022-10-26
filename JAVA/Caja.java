// Jan Carlo Reyes Martínez, 577441
import java.io.*;
import java.util.*;

class Caja {
	public static void main(String[] args) {
		double total;
		double efectivo;
		double diferencia;
		Scanner s = new Scanner(System.in);
		
		System.out.println("Ingresa el total de la compra: ");
		total = s.nextDouble();
		
		System.out.println("Ingresa lo que pagó el cliente: ");
		efectivo = s.nextDouble();
		
		if (efectivo >= total) {
			diferencia = efectivo - total;
			System.out.println("Sí completa, su cambio es de: $" + diferencia);
		} else {
			diferencia = total - efectivo;
			System.out.println("No completa, le faltan: $" + diferencia);
		}
	}
}
