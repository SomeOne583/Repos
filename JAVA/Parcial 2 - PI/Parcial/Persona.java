// Jan Carlo Reyes Martínez, 577441
// Examen del segundo parcial
// 08/10/2021
// Extender el programa creado para los datos de una persona con el uso de composición y métodos adicionales
// Los métodos de obtener las iniciales y el mes en texto los cree en la clase Persona porque pense que agregarlos a las clases Nombre y/o
// Fecha solo las cargaría de métodos que podría no usar siempre que las importe en otros programas, entonces cuando las use en otros
// problemas serán clases más ligeras y sin añadidos innecesarios

import java.io.*;
import java.util.*;

// Clase Nombre ya creada en otros ejercicios con lo básico del primer nonbre y apellidos
class Nombre {
        private String nombre;
        private String apellidoPaterno;
        private String apellidoMaterno;

        // Recibe el nombre como una String y lo divide por espacios
        public Nombre(String nombreCompleto) {
                String nombre[] = nombreCompleto.split(" ");
                setNombre(nombre[0]);
                setApellidoPaterno(nombre[1]);
                setApellidoMaterno(nombre[2]);
        }

        public String getNombre() {
                return this.nombre;
        }

        public void setNombre(String nombre) {
                this.nombre = nombre;
        }

        public String getApellidoPaterno() {
                return this.apellidoPaterno;
        }

        public void setApellidoPaterno(String apellidoPaterno) {
                this.apellidoPaterno = apellidoPaterno;
        }

        public String getApellidoMaterno() {
                return this.apellidoMaterno;
        }

        public void setApellidoMaterno(String apellidoMaterno) {
                this.apellidoMaterno = apellidoMaterno;
        }

        public String toString() {
                return this.getNombre() + " " + this.getApellidoPaterno() + " " + this.getApellidoMaterno();
        }
}

// Clase Fecha ya usada en otros ejercicios
class Fecha {
        private String d;
        private String m;
        private String y;

        // Primero se reemplaza el caracter '-' por '/' para facilitar el split
        public Fecha(String fecha) {
                fecha = fecha.replace('-', '/');
                String[] fechaSeparada = fecha.split("/");
                setD(fechaSeparada[0]);
                setM(fechaSeparada[1]);
                setY(fechaSeparada[2]);
        }

        public String getD() {
                return this.d;
        }

        public void setD(String d) {
                this.d = d;
        }

        public String getM() {
                return this.m;
        }

        public void setM(String m) {
                this.m = m;
        }

        public String getY() {
                return this.y;
        }

        public void setY(String y) {
                this.y = y;
        }

        public String toString() {
                return this.getD() + "/" + this.getM() + "/" + this.getY();
        }
}

// Añadí un atributo booleano llamado personaFisica para determinar si debo imprimir su RFC o no
class Persona {
        private Nombre nombre;
        private Fecha fechaNacimiento;
        private boolean personaFisica;

        public Persona(Nombre nombre, Fecha fechaNacimiento, boolean personaFisica) {
                setNombre(nombre);
                setFechaNacimiento(fechaNacimiento);
                setPersonaFisica(personaFisica);
        }

        public Nombre getNombre() {
                return this.nombre;
        }

        public void setNombre(Nombre nombre) {
                this.nombre = nombre;
        }

        public Fecha getFechaNacimiento() {
                return this.fechaNacimiento;
        }

        public void setFechaNacimiento(Fecha fechaNacimiento) {
                this.fechaNacimiento = fechaNacimiento;
        }

        public boolean getPersonaFisica() {
                return this.personaFisica;
        }

        public void setPersonaFisica(boolean personaFisica) {
                this.personaFisica = personaFisica;
        }

        // Un método que toma el mes de nacimiento y lo convierte en un texto con el nombre, ejemplo 9 => Septiembre
        // Use un arrehlo y luego tomar el mes, restarle 1 y ese sería el ínidce del arreglo (Porque el arreglo empieza en 0)
        public String getMesTexto() {
                byte mes = Byte.valueOf(this.fechaNacimiento.getM());
                String[] meses = { "Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", 
                                        "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre" };
                return meses[mes - 1];
        }

        // Método que saca las iniciales usando substring y las une para devolverlas
        public String obtenerIniciales() {
                return this.nombre.getNombre().substring(0, 1) + this.nombre.getApellidoPaterno().substring(0, 1) + 
                        this.nombre.getApellidoMaterno().substring(0, 1);
        }

        public String calcularRFC() {
                Random rand = new Random();
                String listaLetras, listaNumeros, rfc;
                listaLetras = "abcdefghijklmnopqrstuvwxyz";
                listaNumeros = "1234567890";

                rfc = this.nombre.getApellidoPaterno().substring(0, 2);
                rfc = rfc.concat(this.nombre.getApellidoMaterno().substring(0, 1));
                rfc = rfc.concat(this.nombre.getNombre().substring(0, 1));

                rfc = rfc.concat(this.fechaNacimiento.getY().substring(2));
                rfc = rfc.concat(this.fechaNacimiento.getM());
                rfc = rfc.concat(this.fechaNacimiento.getD());

                int indice1 = rand.nextInt(listaLetras.length());
                int indice2 = rand.nextInt(listaLetras.length());
                int indice3 = rand.nextInt(listaNumeros.length());
                
                rfc = rfc.concat(String.valueOf(listaLetras.charAt(indice1)));
                rfc = rfc.concat(String.valueOf(listaLetras.charAt(indice2)));
                rfc = rfc.concat(String.valueOf(listaNumeros.charAt(indice3)));

                return rfc.toUpperCase();
        }

        // Aquí hay un if que verifica si es persona física antes de agregar el RFC al texto que se imprime
        public String toString() {
                String impresion = "La persona se llama: " + this.nombre.toString() + "\nSus iniciales son: " + this.obtenerIniciales() + 
                        "\nSu fecha de nacimiento es: " + this.fechaNacimiento.toString() + "\nNacio en el mes de: " + this.getMesTexto();
                if (this.personaFisica)
                        impresion += "\nSu RFC es: " + this.calcularRFC();
                return impresion;
        }
}

class Principal {
        public static void main(String[] args) {
                Persona p1 = leerPersona(1);
                Persona p2 = leerPersona(2);
                
                System.out.println("\nPersona 1:");
                System.out.println(p1);
                System.out.println("\nPersona 2:");
                System.out.println(p2);
        }

        public static Persona leerPersona(int numPersona) {
                Nombre n = new Nombre(leerNombre(numPersona));
                Fecha f = new Fecha(leerFecha(numPersona));
                boolean pf = leerPersonaFisica(numPersona);
                Persona p = new Persona(n, f, pf);
                return p;
        }

        public static String leerNombre(int numPersona) {
                Scanner s = new Scanner(System.in);
                System.out.println("Ingresa el nombre de la persona " + numPersona);
                return s.nextLine();
        }

        public static String leerFecha(int numPersona) {
                Scanner s = new Scanner(System.in);
                System.out.println("Ingresa la fecha de nacimiento de la persona " + numPersona + " (dd/mm/aaaa)");
                return s.next();
        }

        // Use algunos métodos de String (toLowerCase) para asegurarme de que la respuesta sea s/n y solo hacer una condición
        public static boolean leerPersonaFisica(int numPersona) {
                Scanner s = new Scanner(System.in);
                System.out.println("¿Es la persona " + numPersona + " una persona física? (S/N)");
                char respuesta = s.next().toLowerCase().charAt(0);
                if (respuesta == 's')
                        return true;
                return false;
        }
}
