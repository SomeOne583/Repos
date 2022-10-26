// Escudería Object Oriented Imposters
// Problema: Calcular colegiatura de un alumno basado en la cantidad de creditos
// Fecha: 03/09/2021
// Damos nuestra palabra de que hemos realizado esta actividad con integridad académica

import java.util.*;
import java.io.*;

// el problema trata del alumno así que es la clase principal
public class Alumno {
	private String matricula;
	private byte creditos;

        // Método constructor
	public Alumno(String matricula, byte creditos) {
                setMatricula(matricula);
                setCreditos(creditos);
	}
	
        // Método set y get de matrícula
	public void setMatricula(String matricula) {
                this.matricula = matricula;
	}
	
	public String getMatricula() {
                return this.matricula;
	}
	
        // Método set y get de créditos
	public void setCreditos(byte creditos) {
                this.creditos = creditos;
	}
	
	public byte getCreditos() {
                return this.creditos;
	}
	
        // Se calcula la colegiatura con el precio dado
	public float calcularColegiatura() {
                return creditos * 2300.00f;
	}
	
        // Se formatea la impresión
	public String toString() {
                return "Matrícula: " + getMatricula() + "\nCréditos: " + getCreditos() + "\nColegiatura: " + calcularColegiatura();
	}
}

class MainAlumno {
        public static void main(String[] args) {
                // Se crean dos alumnos con datos ingresador por téclado
                Alumno a1 = new Alumno(leerMatricula(), leerCreditos());
                Alumno a2 = new Alumno(leerMatricula(), leerCreditos());

                // Prueba de los métodos get
                System.out.println("Matrícula del alumno 1: " + a1.getMatricula());
                System.out.println("Matrícula del alumno 2: " + a2.getMatricula());

                // Impersión de los alumnos y sus atributos
                System.out.println("\n" + a1);
                System.out.println("\n" + a2);
        }

        // Leer la matrícula, no sabes que clase de matrícula sea por eso es string
        public static String leerMatricula() {
                Scanner s = new Scanner(System.in);
                System.out.print("Ingresa tu matrícula: ");
                String matricula = s.next();

                return matricula;
        }

        // Leer créditos como byte pues es el tipo de dato que queda mejor
        public static byte leerCreditos() {
                byte invalido = 0;
                byte creditos = 0;
                // Validación de que lleve al menos 1 crédito
                do {
                        Scanner s = new Scanner(System.in);
                        invalido = 0;
                        try {
                                System.out.print("Ingresa los créditos que vas a tomar (Tienen que ser más de 0): ");
                                creditos = s.nextByte();
                        } catch (InputMismatchException e) {
                                invalido = 1;
                                System.out.println("Ocurrió un error");
                        }
                } while (creditos <= 0 || invalido == 1);

                return creditos;
        }
}