//
//
//  Generated by StarUML(tm) Java Add-In
//
//  @ Project : Untitled
//  @ File Name : Estudiante.java
//  @ Date : 24/08/2021
//  @ Author : 
//
//




public class Estudiante {
	private int matricula;
	private float cal1;
	private float cal2;
	private float cal3;

	public Estudiante(int matricula, float cal1, float cal2, float cal3) {
                this.matricula = matricula;
                this.cal1 = cal1;
                this.cal2 = cal2;
                this.cal3 = cal3;
	}
	
	public double calPromedio() {
                return (this.cal1 + this.cal2 + this.cal3) / 3;
	}
	
	public String toString() {
                return "Matrícula: " + this.matricula + "\tPromedio es: " + this.calPromedio();
	}
}

class PrincipalE {
        public static void main(String[] args) {
                Estudiante e1 = new Estudiante(577441, 100, 90, 90);
                System.out.println(e1);
        }
}