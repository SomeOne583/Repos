// Jan Carlo Reyes Martínez, 577441
// Problema para determinar el costo de determinado consumo segpun ciertas condiciones

import java.io.*;
import java.util.*;

class Factura {
	public static void main(String[] args) {
		Scanner lector = new Scanner(System.in);
		float mesAnt, mesAct, consumido;
		double total;

		System.out.println("Ingresa el consumo del mes anterior: ");
		mesAnt = lector.nextFloat();

		System.out.println("Ingresa el consumo del mes actual: ");
		mesAct = lector.nextFloat();

		consumido = mesAct - mesAnt;

		if (consumido <= 60)
			total = 15;
		else if (consumido <= 160)
			total = (consumido - 60) * 0.5 + 15;
		else if (consumido <= 260)
			total = (consumido - 160) * 0.025 + 65;
		else
			total = (consumido - 260) * 0.015 + 67.5;
		
		System.out.println("El importe de la factura es de: $" + total);
	}
}