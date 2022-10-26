// Escuderia Object Oriented Impostors
// 26/10/2021
// Damos nuestra palabra de que hemos realizado nesta actividad con integridad académica

import java.io.*;
import java.time.LocalDate;
import java.time.Period;
import java.util.*;

// Clases para datos básicos
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
        
        public String getNombre() { return this.nombre; }
        
        public void setNombre(String nombre) { this.nombre = nombre; }
        
        public String getApellidoPaterno() { return this.apellidoPaterno; }
        
        public void setApellidoPaterno(String apellidoPaterno) { this.apellidoPaterno = apellidoPaterno; }
        
        public String getApellidoMaterno() { return this.apellidoMaterno; }
        
        public void setApellidoMaterno(String apellidoMaterno) { this.apellidoMaterno = apellidoMaterno; }
        
        public String toString() { return this.getNombre() + " " + this.getApellidoPaterno() + " " + this.getApellidoMaterno(); }
}

class RFC {
        private String iniciales;
        private String fechaNacimiento;
        private String identificador;
        
        public RFC(String rfc) {
                setIniciales(rfc.substring(0, 4));
                setFechaNacimiento(rfc.substring(4, 10));
                setIdentificador(rfc.substring(10));
        }
        
        public void setIniciales(String iniciales) { this.iniciales = iniciales; }
        
        public String getIniciales() { return this.iniciales; }
        
        public void setFechaNacimiento(String fechaNacimiento) { this.fechaNacimiento = fechaNacimiento; }
        
        public String getFechaNacimiento() { return this.fechaNacimiento; }
        
        public void setIdentificador(String identificador) { this.identificador = identificador; }
        
        public String getIdentificador() { return this.identificador; }
        
        public String toString() { return this.getIniciales() + this.getFechaNacimiento() + this.getIdentificador(); }
}

class Telefono {
        private String numero;
        
        public Telefono(String numero) { setNumero(numero); }
        
        public void setNumero(String numero) { this.numero = numero; }
        
        public String getNumero() { return this.numero; }
        
        public String toString() { return this.numero; }
}

class Direccion {
        private String calle;
        private int numero;
        private int codigoPostal;
        private String colonia;
        private String municipio;
        
        public Direccion(String calle, int numero, int codigoPostal, String colonia, String municipio) {
                setCalle(calle);
                setNumero(numero);
                setCodigoPostal(codigoPostal);
                setColonia(colonia);
                setMunicipio(municipio);
        }
        
        public void setCalle(String calle) { this.calle = calle; }
        
        public String getCalle() { return this.calle; }
        
        public void setNumero(int numero) { this.numero = numero; }
        
        public int getNumero() { return this.numero; }
        
        public void setCodigoPostal(int codigoPostal) { this.codigoPostal = codigoPostal; }
        
        public int getCodigoPostal() { return this.codigoPostal; }
        
        public void setColonia(String colonia) { this.colonia = colonia; }
        
        public String getColonia() { return this.colonia; }
        
        public void setMunicipio(String municipio) { this.municipio = municipio; }
        
        public String getMunicipio() { return this.municipio; }
        
        public String toString() {
                return this.getCalle() + " " + this.getNumero() + " " + this.getColonia() + " " + 
                this.getCodigoPostal() + " " + this.getMunicipio();
        }
}

class Fecha {
        private byte dia;
        private byte mes;
        private short anio;
        
        public Fecha(String fecha) {
                fecha = fecha.replace("-", "/");
                String partes[] = fecha.split("/");
                setDia(partes[0]);
                setMes(partes[1]);
                setAnio(partes[2]);
        }
        
        public void setDia(String dia) { this.dia = Byte.valueOf(dia); }
        
        public byte getDia() { return dia; }
        
        public void setMes(String mes) { this.mes = Byte.valueOf(mes); }
        
        public byte getMes() { return mes; }
        
        public void setAnio(String anio) { this.anio = Short.valueOf(anio); }
        
        public short getAnio() { return anio; }
        
        public String toString() { return this.getDia() + "/" + this.getMes() + "/" + this.getAnio(); }
}

// Clase padre
class Cliente {
        protected Nombre nombre;
        protected RFC rfc;
        protected Telefono telefono;
        protected Direccion direccion;
        protected Fecha fecha1;
        protected Fecha fecha2;
        protected double montoTotal;
        
        public Cliente(Nombre nombre, RFC rfc, Telefono telefono, Direccion direccion, Fecha fecha1, Fecha fecha2, double montoTotal) {
                setNombre(nombre);
                setRfc(rfc);
                setTelefono(telefono);
                setDireccion(direccion);
                setFecha1(fecha1);
                setFecha2(fecha2);
                setMontoTotal(montoTotal);
        }
        
        // Sets y gets
        public void setNombre(Nombre nombre) { this.nombre = nombre; }
        
        public Nombre getNombre() { return this.nombre; }
        
        public void setRfc(RFC rfc) { this.rfc = rfc; }
        
        public RFC getRfc() { return this.rfc; }
        
        public void setTelefono(Telefono telefono) { this.telefono = telefono; }
        
        public Telefono getTelefono() { return this.telefono; }
        
        public void setDireccion(Direccion direccion) { this.direccion = direccion; }
        
        public Direccion getDireccion() { return this.direccion; }
        
        public void setFecha1(Fecha fecha1) { this.fecha1 = fecha1; }
        
        public Fecha getFecha1() { return this.fecha1; }
        
        public void setFecha2(Fecha fecha2) { this.fecha2 = fecha2; }
        
        public Fecha getFecha2() { return this.fecha2; }
        
        public void setMontoTotal(double montoTotal) { this.montoTotal = montoTotal; }
        
        public double getMontoTotal() { return this.montoTotal; }
        
        // Se calcula antigüedad usando una libreria
        public String calcularAntiguedad() {
                LocalDate f1 = LocalDate.of(this.fecha1.getAnio(), this.fecha1.getMes(), this.fecha1.getDia());
                LocalDate f2 = LocalDate.of(this.fecha2.getAnio(), this.fecha2.getMes(), this.fecha2.getDia());
                Period periodo = Period.between(f1, f2);
                if (periodo.getYears() > 0)
                        return periodo.getYears() + " año(s)";
                else if (periodo.getMonths() > 0)
                        return periodo.getYears() + " mes(es)";
                else
                        return periodo.getDays() + " dia(s)";
        }
        
        // Se calcula que porcentaje de descuento se le va a aplicar
        public double calcularDescuento() { 
                if (this.montoTotal >= 20000)
                return 13;
                else
                return 5;
        }
        
        // Impresión más limpia de cliente
        public String toString() {
                return "\nCliente:" + 
                "\nNombre: " + this.getNombre() +
                "\nRFC: " + this.getRfc() +
                "\nTelefono: " + this.getTelefono() +
                "\nDireccion: " + this.getDireccion() +
                "\nFecha de la primera compra: " + this.getFecha1() +
                "\nFecha de la última compra: " + this.getFecha2() +
                "\nAntigüedad del cliente: " + this.calcularAntiguedad() +
                "\nMonto total de compras: " + this.getMontoTotal() + "$";
        }
}

// Primera clase hija
class Gold extends Cliente{
        // Su atributo único
        private double montoAlto;
        
        public Gold (Nombre nombre, RFC rfc, Telefono telefono, Direccion direccion, Fecha fecha1, Fecha fecha2, double montoTotal, double montoAlto) {
                super(nombre, rfc, telefono, direccion, fecha1, fecha2, montoTotal);
                setMontoAlto(montoAlto);
        }
        
        public void setMontoAlto(double montoAlto) {
                this.montoAlto = montoAlto;
        }
        
        public double getMontoAlto() {
                return this.montoAlto;
        }
        
        // Datos que se agregan a la impresión principal de cliente
        public String toString(){
                return super.toString() + 
                "\nMonto más alto: " + montoAlto + 
                "$\nDescuento: " + super.calcularDescuento() + "%";
        }
}

// Segunda clase hija
class Platino extends Cliente{
        /*------------ATRIBUTOS-------------*/
        private double montoAlto;
        private int cantidadCompras;
        /*------------CONSTRUCTOR-------------*/
        public Platino(Nombre nombre, RFC rfc, Telefono telefono, Direccion direccion, Fecha fecha1, Fecha fecha2, double montoTotal, double montoAlto, int cantidadCompras){
                super(nombre, rfc, telefono, direccion, fecha1, fecha2, montoTotal);
                setMontoAlto(montoAlto);
                setCantidadCompras(cantidadCompras);
        }
        /*------------SETS Y GETS-------------*/
        public void setMontoAlto(double montoAlto){
                this.montoAlto = montoAlto;
        }
        public double getMontoAlto(){
                return montoAlto;
        }
        public void setCantidadCompras(int cantidadCompras){
                this.cantidadCompras = cantidadCompras;
        }
        public int getCantidadCompras(){
                return cantidadCompras;
        }
        /*-------------ACTUALIZAR DESCUENTO------------*/   
        public double calcularDescuento(){
                if (montoAlto >= 20000.0 && cantidadCompras>5)
                return 15.0;
                else if (montoAlto>=20000) 
                return 13.0;
                else
                return 5.0;
        }
        /*-------------to String------------*/
        public String toString(){
                return super.toString() + "\nMonto más alto: " + montoAlto + "$\nDescuento: " + calcularDescuento() + 
                "%\nCantidad de compras: " + cantidadCompras;
        }
}

class Main {
        public static void main(String[] args) {
                if (leerTipo() == 'o') {
                        Gold p1 = new Gold(
                                new Nombre(leerNombre()), 
                                new RFC(leerRFC()), 
                                new Telefono(leerNumero()), 
                                new Direccion(leerCalle(), leerNumeroD(), leerCodigoPostal(), leerColonia(), leerMunicipio()), 
                                new Fecha(leerFecha("compra incial")), new Fecha(leerFecha("compra final")),
                                leerMontoTotal(),
                                leerMontoAlto()
                        );
                        System.out.println(p1);
                } else {
                        Platino p1 = new Platino(
                                new Nombre(leerNombre()), 
                                new RFC(leerRFC()), 
                                new Telefono(leerNumero()), 
                                new Direccion(leerCalle(), leerNumeroD(), leerCodigoPostal(), leerColonia(), leerMunicipio()), 
                                new Fecha(leerFecha("compra incial")), new Fecha(leerFecha("compra final")),
                                leerMontoTotal(),
                                leerMontoAlto(),
                                leerCantidadCompras()
                        );
                        System.out.println(p1);
                }
        }

        public static char leerTipo() {
                Scanner s = new Scanner(System.in);
                System.out.println("Ingresa el tipo de cuenta:");
                return s.next().toLowerCase().charAt(0);
        }
        
        public static String leerNombre(){
                Scanner s = new Scanner(System.in);
                System.out.println("Ingresa tu nombre completo: ");
                String nombreCompleto=s.nextLine();
                return nombreCompleto;
        }
        
        public static String leerRFC(){ 
                Scanner s = new Scanner(System.in);
                System.out.println("Ingresa tu rfc: ");
                String rfc=s.nextLine();
                return rfc;
        }
        
        public static String leerFecha(String msg){ 
                Scanner s = new Scanner(System.in);
                System.out.println("Ingresa la fecha de la " + msg);
                String fecha=s.nextLine();
                return fecha;
        } 
        
        public static String leerNumero(){ 
                Scanner s = new Scanner(System.in);
                System.out.println("Ingresa tu numero de telefono: ");
                String numero=s.nextLine();
                return numero;
        }   
        
        public static String leerCalle(){
                Scanner s = new Scanner(System.in);
                System.out.println("Ingresa tu calle: ");
                String calle=s.nextLine();
                return calle;
        }
        
        public static int leerNumeroD(){ 
                Scanner s = new Scanner(System.in);
                System.out.println("Ingresa tu numero de direccion: ");
                int numero=s.nextInt();
                return numero;
        }
        
        public static int leerCodigoPostal(){
                Scanner s = new Scanner(System.in);
                System.out.println("Ingresa tu codigo postal: ");   
                int codigoPostal=s.nextInt();
                return codigoPostal;
        }
        
        public static String leerColonia(){ 
                Scanner s = new Scanner(System.in);
                System.out.println("Ingresa tu colonia: ");
                String colonia=s.nextLine();
                return colonia;
        }
        
        public static String leerMunicipio(){ 
                Scanner s = new Scanner(System.in);
                System.out.println("Ingresa tu municipio: ");
                String municipio=s.nextLine();
                return municipio;
        } 
        
        public static double leerMontoTotal(){ 
                Scanner s = new Scanner(System.in);
                System.out.println("Ingresa tu monto total: ");
                double montoTotal=s.nextDouble();
                return montoTotal;
        }
        
        public static double leerMontoAlto(){ 
                Scanner s = new Scanner(System.in);
                System.out.println("Ingresa tu monto alto: ");
                double montoAlto=s.nextDouble();
                return montoAlto;
        }
        
        public static int leerCantidadCompras(){ 
                Scanner s = new Scanner(System.in);
                System.out.println("Ingresa tu cantidad de compras: ");
                int cantidadCompras=s.nextInt();
                return cantidadCompras;
        }    
}
