// Jan Carlo Reyes Martínez, 577441
// Primer examen parcial
// 07/09/2021
// Doy mi palabra de que he realizado esta actividad con integridad académica

import java.time.LocalDate;
import java.util.*;

public class Paciente {
        // Atributos privados de la clase
	private String nombre;
	private String enfermedad;
	private LocalDate fechaNacimiento;
	private String telefono;
	private String medicamento;
	private short[] periodoAplicacion;
	private LocalDate fechaUltimaAplicacion;
	
        public Paciente(String nombre, String enfermedad, String fechaNacimiento, String telefono, String medicamento, String periodo, String fechaUltimaAplicacion) {
                // Uso de sets para definir los atributos
                setNombre(nombre);
                setEnfermedad(enfermedad);
                setFechaNacimiento(fechaNacimiento);
                setTelefono(telefono);
                setMedicamento(medicamento);
                setPeriodoAplicacion(periodo);
                setFechaUltimaAplicacion(fechaUltimaAplicacion);
	}
	
	public String getNombre() {
                return this.nombre;
	}
	
	public void setNombre(String nombre) {
                this.nombre = nombre;
	}
	
	public String getEnfermedad() {
                return this.enfermedad;
	}
	
	public void setEnfermedad(String enfermedad) {
                this.enfermedad = enfermedad;
	}
	
	public LocalDate getFechaNacimiento() {
                return this.fechaNacimiento;
	}
	
	public void setFechaNacimiento(String fechaNacimiento) {
                // Convertir una fecha como texto a un objeto LocalDate
                String[] fecha = fechaNacimiento.split("/");
                this.fechaNacimiento = LocalDate.of(Integer.parseInt(fecha[2]), Integer.parseInt(fecha[1]), Integer.parseInt(fecha[0]));
	}
	
	public String getTelefono() {
                return this.telefono;
	}
	
	public void setTelefono(String telefono) {
                this.telefono = telefono;
	}
	
	public String getMedicamento() {
                return this.medicamento;
	}
	
	public void setMedicamento(String medicamento) {
                this.medicamento = medicamento;
	}
	
	public String getPeriodoAplicacion() {
                // El periodo se guarda como un arreglo entonces aquí se genera una versión legible
                String periodoLegible = "";
                switch (this.periodoAplicacion[1]) {
                case 1:
                        periodoLegible = String.valueOf(this.periodoAplicacion[0]) + " semana";
                        break;
                case 2:
                        periodoLegible = String.valueOf(this.periodoAplicacion[0]) + " mes";
                        break;
                case 3:
                        periodoLegible = String.valueOf(this.periodoAplicacion[0]) + " año";
                        break;
                }

                return periodoLegible;
	}
	
	public void setPeriodoAplicacion(String periodoIngresado) {
                // Se transforma el periodo a un arreglo para los calculos
                String[] periodoAplicacion = periodoIngresado.split(" ");
                short[] periodo = new short[2];
                
                periodo[0] = Short.parseShort(periodoAplicacion[0]);
                switch (periodoAplicacion[1].toLowerCase().charAt(0)) {
                case 's':
                        periodo[1] = 1;
                        break;
                case 'm':
                        periodo[1] = 2;
                        break;
                case 'a':
                        periodo[1] = 3;
                        break;
                }

                this.periodoAplicacion = periodo;
	}
	
	public LocalDate getFechaUltimaAplicacion() {
                return this.fechaUltimaAplicacion;
	}
	
	public void setFechaUltimaAplicacion(String fechaUltimaAplicacion) {
                // Se transforma fecha de texto a LocalDate
                String[] fecha = fechaUltimaAplicacion.split("/");
                this.fechaUltimaAplicacion = LocalDate.of(Integer.parseInt(fecha[2]), Integer.parseInt(fecha[1]), Integer.parseInt(fecha[0]));
	}
	
	public LocalDate calcularSiguienteAplicacion() {
                // Usando el arreglo de periodo y los métodos de LocalDate se suma lo necesario para obtener la nueva fecha
                LocalDate nuevaFecha = this.fechaUltimaAplicacion;

                switch (this.periodoAplicacion[1]) {
                case 1:
                        nuevaFecha = nuevaFecha.plusWeeks(this.periodoAplicacion[0]);
                        break;
                case 2:
                        nuevaFecha = nuevaFecha.plusMonths(this.periodoAplicacion[0]);
                        break;
                case 3:
                        nuevaFecha = nuevaFecha.plusYears(this.periodoAplicacion[0]);
                        break;
                }
                
                return nuevaFecha;
	}
	
	public String toString() {
                // Se imprimen los datos del usurio de forma ordenada
                return "\nPaciente:\nNombre: " + getNombre() + "\nFecha de fecha de nacimiento: " + getFechaNacimiento() + "\nTelefono: " +
                        getTelefono() + "\nEnfermedad: " + getEnfermedad() + "\nMedicamento: " + getMedicamento() + "\nPeriodo de aplicación: " + 
                        getPeriodoAplicacion() + "\nFecha de la última aplicación: " + getFechaUltimaAplicacion() + 
                        "\nFecha de la siguiente aplicación: " + calcularSiguienteAplicacion();

	}
}

class Main {
        public static void main(String[] args) {
                Scanner s = new Scanner(System.in);
                byte opcion;
                // Se crea al usuario
                Paciente p1 = crearPaciente();
                
                do {
                        // Menú para modificar o ver datos del paciente
                        System.out.println("Opciones:");
                        System.out.println("1. Actualizar datos del paciente\n2. Ver datos del paciente" + 
                                                "\n3. Ver siguiente fecha de aplicación" + "\n4. Salir");
                        opcion = s.nextByte();

                        switch (opcion) {
                        case 1:
                                actualizarInformacion(p1);
                                break;
                        case 2:
                                System.out.println(p1);
                                break;
                        case 3:
                                System.out.println("La siguiente fecha es: " + p1.calcularSiguienteAplicacion());
                                break;
                        }

                } while (opcion != 4);
        }

        public static Paciente crearPaciente() {
                // Método para crear al paciente, se lee cada dato individualmente y se guarda
                Scanner s = new Scanner(System.in);
                String nombre, enfermedad, fechaNacimiento, telefono, medicamento, periodo, fechaUltimaAplicacion;

                System.out.print("Ingresa el nombre del paciente: ");
                nombre = s.nextLine();

                System.out.print("Ingresa la fecha de nacimiento del paciente (Formato: DD/MM/AAAA): ");
                fechaNacimiento = s.nextLine();

                System.out.print("Ingresa el télefono del paciente: ");
                telefono = s.nextLine();

                System.out.print("Ingresa el nombre de la enfermedad del paciente: ");
                enfermedad = s.nextLine();

                System.out.print("Ingresa el nombre del medicamento que toma: ");
                medicamento = s.nextLine();

                System.out.print("Ingresa el periodo que pasa entre cada aplicación del medicamento (1 semana, 2 meses, etc): ");
                periodo = s.nextLine();

                System.out.print("Ingresa la última fecha en que se aplico el medicamento: ");
                fechaUltimaAplicacion = s.nextLine();

                // Se regresa el objeto paciente
                return new Paciente(nombre, enfermedad, fechaNacimiento, telefono, medicamento, periodo, fechaUltimaAplicacion);
        }

        public static void actualizarInformacion(Paciente p) {
                // Actualizar información del paciente
                Scanner sOpcion = new Scanner(System.in);
                Scanner sDato = new Scanner(System.in);
                byte opcion;
                
                do {
                        // Menú con los datos que se pueden actualizae
                        System.out.println("Opciones:");
                        System.out.println("1. Actualizar enfermedad\n2. Actualizar medicamento\n3. Actualizar período de aplicación\n" + 
                                                "4. Fecha de última aplicación\n5. Actualizar télefono\n6. Salir");
                        opcion = sOpcion.nextByte();

                        // Uso de los set para modificar los datos
                        switch (opcion) {
                        case 1:
                                System.out.print("Ingresa la nueva enfermedad: ");
                                p.setEnfermedad(sDato.nextLine());
                                break;
                        case 2:
                                System.out.print("Ingresa el nuevo medicamento: ");
                                p.setMedicamento(sDato.nextLine());
                                break;
                        case 3:
                                System.out.print("Ingresa el nuevo periodo de aplicación (1 semana, 1 mes, etc): ");
                                p.setPeriodoAplicacion(sDato.nextLine());
                                break;
                        case 4:
                                System.out.print("Ingresa la fecha de la última aplicación (Formato: DD/MM/AAAA): ");
                                p.setFechaUltimaAplicacion(sDato.next());
                                break;
                        case 5:
                                System.out.print("Ingresa el nuevo número de télefono: ");
                                p.setTelefono(sDato.next());
                                break;
                        }

                } while (opcion != 6);
	}
}
