// Escuderia Object Oriented Imposters
// Convertir el programa existente sobre la factura para que use arreglos de objetos
// 15/10/2021
// Damos nuestra palabra de que realizamos esta actividad con integridad académica

import java.io.*;
import java.util.*;

class Factura {
        private int numero;
        private String nombreEmpresa;
        private String rfcEmpresa;
        private Nombre nombreCliente;
        private Direccion direccionCliente;
        private String rfcCliente;
        private Detalle[] d;
        private float descuento;
        
        public Factura(int numero, String nombreEmpresa, String rfcEmpresa, Nombre nombreCliente, Direccion direccionCliente, String rfcCliente, Detalle[] d, float descuento) {
                setNumero(numero);
                setNombreEmpresa(nombreEmpresa);
                setRfcEmpresa(rfcEmpresa);
                setNombreCliente(nombreCliente);
                setDireccionCliente(direccionCliente);
                setRfcCliente(rfcCliente);
                setDetalle(d);
                setDescuento(descuento);
        }
        
        public void setNumero(int numero) {
                this.numero = numero;
        }
        
        public int getNumero() {
                return numero;
        }
        
        public void setNombreEmpresa(String nombreEmpresa) {
                this.nombreEmpresa = nombreEmpresa;
        }
        
        public String getNombreEmpresa() {
                return nombreEmpresa;
        }
        
        public void setRfcEmpresa(String rfcEmpresa) {
                this.rfcEmpresa = rfcEmpresa;
        }
        
        public String getRfcEmpresa() {
                return rfcEmpresa;
        }
        
        public void setNombreCliente(Nombre nombreCliente) {
                this.nombreCliente = nombreCliente;
        }
        
        public Nombre getNombreCliente() {
                return nombreCliente;
        }
        
        public void setDireccionCliente(Direccion direccionCliente) {
                this.direccionCliente = direccionCliente;
        }
        
        public Direccion getDireccionCliente() {
                return direccionCliente;
        }
        
        public void setRfcCliente(String rfcCliente) {
                this.rfcCliente = rfcCliente;
        }
        
        public String getRfcCliente() {
                return rfcCliente;
        }
        
        public void setDetalle(Detalle[] d) {
                this.d = d;
        }
        
        public Detalle[] getDetalle() {
                return d;
        }
        
        public void setDescuento(float descuento) {
                this.descuento = descuento;
        }
        
        public float getDescuento() {
                return descuento;
        }
        
        public double calcularSubtotal() {
                double subtotal = 0;

                for (int i = 0; i < d.length; i++) {
                        if (d[i] != null)
                                subtotal += d[i].calcularImporte();
                }

                return subtotal;
        }
        
        public double calcularTotal() {
                double subtotal = calcularSubtotal();
                return subtotal * (1 - descuento / 100);
        }
        
        public String toString() {
                String impresion = "Factura " + numero + "\nCliente:\nNombre: " + nombreCliente.toString() + 
                                "\nDirección: " + direccionCliente.toString() +  "\nRFC: " + rfcCliente + 
                                "\n\nEmpresa:\nNombre: " + nombreEmpresa + "\nRFC: " + rfcEmpresa + 
                                "\n\nDetalles:\n";
                for (int i = 0; i < d.length; i++) {
                        if (d[i] != null)
                                impresion += "\nDetalle " + (i + 1) + ": " + d[i].toString();
                }
                impresion += "\nSubtotal: " + this.calcularSubtotal() + "$" + 
                                "\nDescuento: " + this.descuento + "%" + 
                                "\nTotal: " + this.calcularTotal() + "$";

                return impresion;
        }
}

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

class Direccion {
        private String calle;
        private short numero;
        private String colonia;
        private String codigoPostal;
        private String municipio;
        
        public Direccion(String calle, short numero, String colonia, String municipio, String codigoPostal)
        {
                setCalle(calle);
                setNumero(numero);
                setColonia(colonia);
                setMunicipio(municipio);
                setCodigoPostal(codigoPostal);
        }
        
        public void setCalle(String calle)
        {
                this.calle=calle;
        }
        
        public void setNumero(short numero)
        {
                this.numero=numero;
        }
        
        public void setColonia(String colonia)
        {
                this.colonia=colonia;
        }
        
        public void setMunicipio(String municipio)
        {
                this.municipio=municipio;
        }
        
        public void setCodigoPostal(String codigoPostal)
        {
                this.codigoPostal=codigoPostal;
        }
        
        public String getCalle()
        {
                return calle;
        }
        
        public short getNumero()
        {
                return numero;
        }
        
        public String getColonia()
        {
                return colonia;
        }
        
        public String getMunicipio()
        {
                return municipio;
        }
        
        public String getCodigoPostal()
        {
                return codigoPostal;
        }
        
        public String toString()
        {
                return calle+" "+numero+" "+colonia+" "+municipio+" "+codigoPostal;
        }
}

class Detalle{
        private int clave;
        private int cantidad;
        private double precio;
        private String descripcion;
        
        public Detalle(int clave,int cantidad,double precio, String descripcion){
                setClave(clave);
                setCantidad(cantidad);
                setPrecio(precio);
                setD(descripcion);
        }
        
        public void setClave(int clave){
                this.clave=clave;
        }
        
        public void setCantidad(int cantidad){
                this.cantidad=cantidad;
        }
        
        public void setPrecio(double precio){
                this.precio=precio;
        }
        
        
        public void setD(String descripcion){
                this.descripcion=descripcion;
        }
        
        public int getClave(){
                return clave;
        }
        
        public int getCantidad(){
                return cantidad;
        }
        
        public double getPrecio(){
                return precio;
        }
        
        public String getDescripcion(){
                return descripcion;
        }
        
        public double calcularImporte(){
                return precio*cantidad+(precio*cantidad*0.16);
        }
        
        public String toString(){        
                return cantidad+"\t"+clave+"\t"+descripcion+"\t"+precio+"\t"+calcularImporte();
        }
}

class Producto{
        private int clave;
        private double precio;
        private String descripcion;
        
        public Producto(int clave,double precio, String descripcion){
                setClave(clave);
                setPrecio(precio);
                setD(descripcion);
        }
        
        public void setClave(int clave){
                this.clave=clave;
        }
        
        public void setPrecio(double precio){
                this.precio=precio;
        }
        
        public void setD(String descripcion){
                this.descripcion=descripcion;
        }
        
        public int getClave(){
                return clave;       
        }
        
        public double getPrecio(){
                return precio;
        }
        
        public String getDescripcion(){
                return descripcion;
        }
        
        public String toString(){
                return clave+"\t"+descripcion+"\t"+precio;
        }
}

class Cliente{
        private Nombre nombre;
        private Direccion direccion;
        private String rfc;
        
        public Cliente(Nombre nombre, Direccion direccion, String rfc)
        {
                setNombre(nombre);
                setDireccion(direccion);
                setRfc(rfc);
        }
        
        public void setNombre(Nombre nombre)
        {
                this.nombre=nombre;
        }
        
        public void setDireccion(Direccion direccion)
        {
                this.direccion=direccion;
        }
        
        public void setRfc(String rfc)
        {
                this.rfc=rfc;
        }
        
        public Nombre getNombre()
        {
                return nombre;
        }
        
        public Direccion getDireccion()
        {
                return direccion;
        }
        
        public String getRfc()
        {
                return rfc;
        }
        
        public String toString()
        {
                return nombre+" \t"+direccion+"\t"+rfc;
        }
}  

class Empresa {
        private String nombre;
        private String rfc;
        
        public Empresa(String nombre, String rfc)
        {
                setNombre(nombre);
                setRfc(rfc);
        }
        
        public void setNombre(String nombre)
        {
                this.nombre=nombre;
        }
        
        public void setRfc(String rfc)
        {
                this.rfc=rfc;
        }
        
        public String getNombre()
        {
                return nombre;
        }
        
        public String getRfc()
        {
                return rfc;
        }
        
        public String toString()
        {
                return nombre+" "+rfc;
        }
}

class Principal {
        public static void main(String[] args) {
                Producto[] p = leerProducto(5);
                Cliente c = leerCliente();
                Empresa e = leerEmpresa();
                Detalle[] d = leerDetalle(p);
                float descuento = leerDescuento();
                Factura f = new Factura(1, e.getNombre(), e.getRfc(), c.getNombre(), c.getDireccion(), c.getRfc(), d, descuento);
                System.out.print(f);
        }

        public static Producto[] leerProducto(int cantidad) {
                Scanner s = new Scanner(System.in);
                Producto[] p = new Producto[cantidad];
                int clave;
                double precio;
                String descripcion;
                for (int i = 0; i < cantidad; i++) {
                        System.out.println("\nProducto " + (i + 1));
                        System.out.print("Ingresa la clave del producto " + (i + 1) + ": ");
                        clave = s.nextInt();
                        System.out.print("Ingresa el precio del producto " + (i + 1) + ": ");
                        precio = s.nextDouble();
                        System.out.print("Ingresa la descripción del producto " + (i + 1) + ": ");
                        s.nextLine();
                        descripcion = s.nextLine();
                        p[i] = new Producto(clave, precio, descripcion);
                }

                return p;
        }
        
        public static Cliente leerCliente() {
                Scanner s = new Scanner(System.in);
                System.out.print("\nIngresa el nombre del cliente: ");
                Nombre n = new Nombre(s.nextLine());

                System.out.println("Ingresa los datos de la dirección");
                System.out.print("Ingresa el nombre de la calle: ");
                String calle = s.nextLine();
                System.out.print("Ingresa el número de la casa: ");
                short numero = s.nextShort();
                System.out.print("Ingresa el nombre de la colonia: ");
                s.nextLine();
                String colonia = s.nextLine();
                System.out.print("Ingresa el nombre del municipio: ");
                String municipio = s.nextLine();
                System.out.print("Ingresa el código postal: ");
                String cp = s.next();
                Direccion d = new Direccion(calle, numero, colonia, municipio, cp);

                System.out.print("Ingresa el RFC del cliente: ");
                String rfc = s.next();
                
                return new Cliente(n, d, rfc);
        }

        public static Empresa leerEmpresa() {
                Scanner s = new Scanner(System.in);
                System.out.println("\nIngresa los datos de la empresa");
                System.out.print("Ingresa el nombre de la empresa: ");
                String nombre = s.nextLine();
                System.out.print("Ingresa el RFC de la empresa: ");
                String rfc = s.nextLine();

                return new Empresa(nombre, rfc);
        }

        public static Detalle[] leerDetalle(Producto[] p) {
                Detalle[] d = new Detalle[p.length];
                Scanner s = new Scanner(System.in);
                System.out.println("\nIngresa los detalles de la factura");
                int cantidad = 0;
                for (int i = 0; i < p.length; i++) {
                        System.out.print("Cantidad del producto "+ (i + 1) + ": ");
                        cantidad = s.nextInt();
                        if (cantidad > 0)
                                d[i] = new Detalle(p[i].getClave(), cantidad, p[i].getPrecio(),  p[i].getDescripcion());
                }

                return d;
        }

        public static float leerDescuento() {
                Scanner s = new Scanner(System.in);
                System.out.print("Ingresa el descuento a aplicar: ");
                return s.nextFloat();
        }
}