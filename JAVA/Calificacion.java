// Jan Carlo Reyes Martínez, 577441
// Programa para determinar la calificación promedio de un alumno en base a tres examenes

import java.io.*;
import java.util.*;

class Calificacion {
	public static void main(String[] args) {
		byte calif1, calif2, calif3;
		int promedio;
		char calif_Final;
		Scanner lector = new Scanner(System.in);

		System.out.print("Ingresa la calificación 1: ");
		calif1 = lector.nextByte();
		
		System.out.print("Ingresa la calificación 2: ");
		calif2 = lector.nextByte();

		System.out.print("Ingresa la calificación 3: ");
		calif3 = lector.nextByte();

		promedio = (calif1 + calif2 + calif3) / 3;

		if (promedio < 60)
			calif_Final = 'F';
		else if (promedio < 70)
			calif_Final = 'D';
		else if (promedio < 80)
			calif_Final = 'C';
		else if (promedio < 90)
			calif_Final = 'B';
		else
			calif_Final = 'A';

		System.out.println("La calificación del alumno es: " + calif_Final);
	}
}
