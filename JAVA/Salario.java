// Jan Carlo Reyes Martínez, 577441

import java.io.*;
import java.util.*;

class Salario {
	public static void main(String[] args) {
		String nivel;
		Scanner s = new Scanner(System.in);

		System.out.println("Ingresa tu nivel de empleado (Programador / Analista / ITC): ");
		nivel = s.next();
		switch(nivel) {
			case "Programador":
			System.out.println("Tu salario base es de $5,000");
			break;
			case "Analista":
			System.out.println("Tu salario base es de $10,000");
			break;
			case "ITC":
			System.out.println("Tu salario base es de $15,000");
			break;
		}

	}
}
