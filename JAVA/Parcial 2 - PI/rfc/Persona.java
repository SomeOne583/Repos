import java.io.*;
import java.util.*;

class Nombre {
        private String nombre;
        private String apellidoPaterno;
        private String apellidoMaterno;

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

class Fecha {
        private String d;
        private String m;
        private String y;

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

class Persona {
        private Nombre nombre;
        private Fecha fechaNacimiento;

        public Persona(Nombre nombre, Fecha fechaNacimiento) {
                setNombre(nombre);
                setFechaNacimiento(fechaNacimiento);
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

        public String toString() {
                return "La persona se llama: " + this.nombre + "\nSu fecha de nacimiento es: " + this.fechaNacimiento +
                "\nSu RFC es: " + this.calcularRFC();
        }
}

class Principal {
        public static void main(String[] args) {
                Nombre n1 = new Nombre(leerNombre());
                Fecha f1 = new Fecha(leerFecha());
                Persona p1 = new Persona(n1, f1);
                System.out.println(p1);
        }

        public static String leerNombre() {
                Scanner s = new Scanner(System.in);
                System.out.print("Ingresa tu nombre: ");
                return s.nextLine();
        }

        public static String leerFecha() {
                Scanner s = new Scanner(System.in);
                System.out.print("Ingresa tu fecha de nacimiento (dd/mm/aaaa): ");
                return s.next();
        }
}
