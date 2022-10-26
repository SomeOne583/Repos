// Escudería object oriented imposters
// Proyecto final

import java.io.*;
import java.util.*;

// Clase cadena, se compone por varias tiendas y tiene un nombre
class Cadena implements Serializable {
        //Atributos de clase cadena
        private String nombreCadena;
        private Tienda[] tiendasCadena;
        
        //Constructor de clase cadena, recibe String y arreglo de objetos de clase Tienda
        public Cadena(String nombresCadena, Tienda[] tiendasCadena){
                setNombreCadena(nombresCadena);
                setTiendasCadena(tiendasCadena);
        }
        
        //M�todos SET y GET
        public void setNombreCadena(String nombresCadena){
                this.nombreCadena = nombresCadena;
        }
        public void setTiendasCadena(Tienda[] tiendasCadena){
                this.tiendasCadena = tiendasCadena;
        }
        public String getNombreCadena(){
                return nombreCadena;
        }
        public Tienda[] getTiendasCadena(){
                return tiendasCadena;
        }
        
        //M�todo para registrar en el arreglo de tiendas
        public void registrarTienda(Tienda tienda){
                for (int i = 0; i < tiendasCadena.length; i++) {
                        if (tiendasCadena[i] == null) {
                                tiendasCadena[i] = tienda;
                                System.out.println("¡Tienda agregada!");
                                break;
                        }
                        else if (tiendasCadena[i] != null)
                        System.out.println("Registrando");
                        else
                        System.out.println("¡Tienda no agregada!");
                }
        }
        
        public String toString() {
                String imp = "";
                for (byte i = 0; i < tiendasCadena.length; i++) {
                        if (tiendasCadena[i] != null) {
                                imp += "Tienda " + (i + 1) + ": " + tiendasCadena[i].getDireccionTienda() + "\n";
                        }
                }
                return imp;
        }
}

// Clase tienda, la cual compone a una cadena, esta se asocia con los productos y servicios
class Tienda implements Serializable {
        //Atributos de clase Tienda
        private Direccion direccionTienda;
        private String[] nombresProducto;
        private int[] cantProductos;   
        private String[] nombresServicio; 
        private boolean[] dispServicios;   
        
        //Constructor de clase Tienda
        public Tienda(Direccion direccionTienda){
                setDireccionTienda(direccionTienda);
                setNombresProducto(new String[5]);
                setCantProducto(new int[5]);
                setNombresServicio(new String[5]);
                setDispervicio(new boolean[5]);
        }
        //M�todos SET y GET
        public void setDireccionTienda(Direccion direccionTienda) {
                this.direccionTienda = direccionTienda;
        }
        
        public Direccion getDireccionTienda() {
                return direccionTienda;
        }
        public void setNombresProducto(String[] nombresProducto) {
                this.nombresProducto = nombresProducto;
        }
        
        public String[] getNombresProducto() {
                return nombresProducto;
        }
        
        public void setCantProducto(int[] cantProductos) {
                this.cantProductos = cantProductos;
        }
        
        public int[] getCantProducto() {
                return cantProductos;
        }
        public void setNombresServicio(String[] nombresServicio) {
                this.nombresServicio = nombresServicio;
        }
        
        public String[] getNombresServicio() {
                return nombresServicio;
        }
        
        public void setDispervicio(boolean[] dispServicios) {
                this.dispServicios = dispServicios;
        }
        
        public boolean[] getDispervicio() {
                return dispServicios;
        }
        
        //meter un producto como argumento para meterlo al arreglo
        public void registrarNombreProducto(String nombreP) {
                for (int i = 0; i < nombresProducto.length; i++) {
                        if (nombresProducto[i] == null){
                                nombresProducto[i] = nombreP;
                                System.out.println("¡Nombre agregado!");
                                break;
                        }
                        else if (nombresProducto[i] != null)
                        System.out.println("Registrando");
                        else
                        System.out.println("¡Nombre no agregado!");
                }
        }
        
        public void registrarCantProducto(int cantP){
                for (int i = 0; i < cantProductos.length; i++) {
                        if (cantProductos[i] == 0) {
                                cantProductos[i] = cantP;
                                System.out.println("¡Cantidad agregada!");
                                break;
                        }
                        else if (cantProductos[i] != 0)
                        System.out.println("Registrando");
                        else
                        System.out.println("¡Cantidad no agregada!");
                }
        }
        
        // Insertar un servicio en la tienda
        public void registrarNombreServicio(String nombreS){
                for (int i = 0; i < nombresServicio.length; i++) {
                        if (nombresServicio[i] == null){
                                nombresServicio[i] = nombreS;
                                System.out.println("¡Servicio agregado!");
                                break;
                        }
                        else if (nombresServicio[i] != null)
                        System.out.println("Registrando");
                        else
                        System.out.println("¡Servicio no agregado!");
                }
        }
        
        public void registrarDispServicio(boolean dispS){
                for (int i = 0; i < dispServicios.length; i++) {
                        if (!dispServicios[i]){
                                dispServicios[i] = dispS;
                                System.out.println("¡Disponibilidad agregada!");
                                break;
                        }
                        else if(dispServicios[i])
                        System.out.println("Registrando");
                        else
                        System.out.println("¡Disponibilidad no agregada!");
                }
        }
        
        //En metodos de mod habr� que mddificar los 2 atributos al mismo tiempo
        public void modificarProducto(){
                Scanner s = new Scanner(System.in);
                //Metodo para imprimir productos disponibles
                imprimirProductos();
                //Modificar producto
                System.out.println("Escoge un producto a modificar: ");
                int prodmod = s.nextInt();
                System.out.println("Escoge un nuevo nombre de producto: "); 
                nombresProducto[prodmod - 1] = s.next();
                System.out.println("Escoge una nueva cantidad de producto: "); 
                cantProductos[prodmod - 1] = s.nextInt();
        }
        
        // Método para modificar un servicio ya existente
        public void modificarServicio(){
                Scanner s = new Scanner(System.in);
                //Metodo para imprimir servicios disponibles
                imprimirServicios();
                //Modificar servicio
                System.out.println("Escoge un servicio a modificar: ");
                int servmod = s.nextInt();
                System.out.println("Escoge un nuevo nombre de servicio: "); 
                nombresServicio[servmod - 6] = s.next();
                System.out.println("Escoge una nueva disponibilidad de servicio: "); 
                dispServicios[servmod - 6] = s.nextBoolean();
        }

        // Método para eliminar un elemento de la tienda
        public void eliminarElemento(){      
                Scanner s = new Scanner(System.in);
                System.out.println("PRODUCTOS");
                imprimirProductos();
                System.out.println("SERVICIOS");
                imprimirServicios();
                System.out.println("Escoge un elemento a eliminar: ");
                int elemdelete = s.nextInt();
                //Eliminar Producto
                if(elemdelete < 6){
                        nombresProducto[elemdelete-1] = null;
                        cantProductos[elemdelete-1] = 0;
                }
                else{ //Eliminar Servicio
                        nombresServicio[elemdelete-6] = null;
                        dispServicios[elemdelete-6] = false;
                }      
        }
        
        // Métodos para imprimir tanto los productos como los servicios
        public void imprimirProductos(){
                System.out.println("Numero "+"\t\tNombre "+"\t\tCantidad ");
                for (int i = 0; i < nombresProducto.length; i++) {
                        if (nombresProducto[i] != null)
                                System.out.println((i+1) + "\t\t" + nombresProducto[i] + "\t\t" + cantProductos[i]);
                }
        }
        
        public void imprimirServicios(){
                System.out.println("Numero "+"\t\tNombre "+"\t\tDisponibilidad ");
                for (int i = 0; i < nombresServicio.length; i++) {
                        if (nombresServicio[i] != null)
                                System.out.println((i+6) + "\t\t" + nombresServicio[i] + "\t\t" + dispServicios[i]);
                }
        }
}

// Una interfaz con lo que comparten los productos y servicios
interface Elemento {
        Direccion [] buscarExistencia(Tienda [] tiendas);
}

// Un producto se refiere a los elementos físicos en la tienda
class Producto implements Elemento, Serializable {
        private String nombre;
        private double precio;
        private int cantidadPro;
        
        Producto(String nombre, double precio, int cantidaPro){
                setNombre(nombre);
                setPrecio(precio);
                setCantidadPro(cantidadPro);
        }
        //M�todos set
        public void setNombre(String nombre){this.nombre=nombre;}
        
        public void setPrecio(double precio){this.precio=precio;}
        
        public void setCantidadPro(int cantidadPro){this.cantidadPro=cantidadPro;}
        //M�todos get
        public String getNombre(){return nombre;}
        
        public double getPrecio(){return precio;}
        
        public int getCantidadPro(){return cantidadPro;}
        
        //M�todo para encontrar la ubicacion de la tienda que tenga cierto producto
        public Direccion [] buscarExistencia (Tienda [] tiendas){
                Direccion [] direcciones=new Direccion [5];
                for (int i=0; i<tiendas.length;i++){
                        if (tiendas[i] != null) {
                                String [] productos=tiendas[i].getNombresProducto();
                                for (int j=0; j<productos.length;j++){
                                        if (productos[j] != null && productos[j].equals(nombre)){
                                                direcciones[i]=tiendas[i].getDireccionTienda();
                                        }
                                        
                                }
                        }
                }
                
                return direcciones; 
        }
}

// Clase servicio que hace referencia a los elementos intangibles
class Servicio implements Elemento, Serializable {
        private String nombre;
        private boolean disponibilidad;
        private double comisionServ;
        
        Servicio (String nombre, boolean disponibilidad, double comisionServ){
                setNombre(nombre);
                setDisponibilidad(disponibilidad);
                setComisionServ(comisionServ);
        }
        //M�todos set
        public void setNombre(String nombre){this.nombre=nombre;}
        
        public void setDisponibilidad(boolean disponibilidad){this.disponibilidad=disponibilidad;}
        
        public void setComisionServ(double comisionServ){this.comisionServ=comisionServ;}
        
        //M�todos get
        public String getNombre(){return nombre;}
        
        public boolean getDisponibilidad(){return disponibilidad;}
        
        public double getComisionServ(){return comisionServ;}
        
        //M�todo para encontrar la ubicacion de la tienda que tenga cierto servicio
        public Direccion [] buscarExistencia(Tienda [] tiendas){
                Direccion [] direcciones= new Direccion [5];
                for (int i=0;i<tiendas.length;i++){
                        if (tiendas[i] != null) {
                                String [] servicios=tiendas[i].getNombresServicio();
                                boolean [] disponibilidad=tiendas[i].getDispervicio();
                                for (int j=0;j<servicios.length;j++){
                                        if (servicios[j] != null && disponibilidad[j]==true & servicios[j].equalsIgnoreCase(nombre)){
                                                direcciones[i]=tiendas[i].getDireccionTienda();
                                        }
                                }
                        }
                }
                return direcciones;  
                
        }
}

// Clases para componer al empleados
class Nombre implements Serializable {
        private String nombre;
        private String apellidoP;
        private String apellidoM;
        
        public Nombre(String nombreCompleto) {
                String nombre[] = nombreCompleto.split(" ");
                setNombre(nombre[0]);
                setApellidoP(nombre[1]);
                setApellidoM(nombre[2]);
        }
        
        public String getNombre() { return this.nombre; }
        
        public void setNombre(String nombre) { this.nombre = nombre; }
        
        public String getApellidoP() { return this.apellidoP; }
        
        public void setApellidoP(String apellidoP) { this.apellidoP = apellidoP; }
        
        public String getApellidoM() { return this.apellidoM; }
        
        public void setApellidoM(String apellidoM) { this.apellidoM = apellidoM; }
        
        public String toString() { return this.getNombre() + " " + this.getApellidoP() + " " + this.getApellidoM(); }
}

class RFC implements Serializable {
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

class Direccion implements Serializable {
        private String calle;
        private String numero;
        private String colonia;
        private String municipio;
        private String estado;
        private String codigoPostal;
        
        public Direccion(String calle, String numero, String colonia, String municipio, String estado, String codigoPostal) {
                setCalle(calle);
                setNumero(numero);
                setColonia(colonia);
                setMunicipio(municipio);
                setEstado(estado);
                setCodigo(codigoPostal);
        }
        
        public void setCalle(String calle) { this.calle = calle; }
        
        public String getCalle() { return this.calle; }
        
        public void setNumero(String numero) { this.numero = numero; }
        
        public String getNumero() { return this.numero; }
        
        public void setColonia(String colonia) { this.colonia = colonia; }
        
        public String getColonia() { return this.colonia; }
        
        public void setMunicipio(String municipio) { this.municipio = municipio; }
        
        public String getMunicipio() { return this.municipio; }
        
        public void setEstado(String estado) { this.estado = estado; }
        
        public String getEstado() { return this.estado; }
        
        public void setCodigo(String codigoPostal) { this.codigoPostal = codigoPostal; }
        
        public String getCodigo() { return this.codigoPostal; }
        
        public String toString() {
                return this.getCalle() + ", " + this.getNumero() + ", " + this.getColonia() + ", " + 
                this.getMunicipio() + ", " + this.getEstado()+ ", " + this.getCodigo();
                
        }
}

class Fecha implements Serializable {
        private String dia;
        private String mes;
        private String anio;
        
        public Fecha(String fecha) {
                // Se reemplaza "-"" por "/"" para poder soportar ambos formatos
                fecha = fecha.replace("-", "/");
                String partes[] = fecha.split("/");
                setDia(partes[0]);
                setMes(partes[1]);
                setAnio(partes[2]);
        }
        
        public void setDia(String dia) { this.dia = dia; }
        
        public String getDia() { return this.dia; }
        
        public void setMes(String mes) { this.mes = mes; }
        
        public String getMes() { return this.mes; }
        
        public void setAnio(String anio) { this.anio = anio; }
        
        public String getAnio() { return this.anio; }
        
        public String toString() { return this.getDia() + "/" + this.getMes() + "/" + this.getAnio(); }
}

// Case empleado, es quien accesa al sistema
class Empleado implements Serializable {
        private Nombre nombre;
        private Fecha fechaContratacion;
        private RFC rfc;
        private String user;
        private String password;
        
        Empleado(Nombre nombre, Fecha fechaContratacion, RFC rfc, String user, String password) {
                setNombre(nombre);
                setFechaContratacion(fechaContratacion);
                setRfc(rfc);
                setUser(user);
                setPassword(password);
        }
        
        // Métodos set y get
        public void setNombre(Nombre nombre) { this.nombre = nombre; }
        
        public Nombre getNombre() { return this.nombre; }
        
        public void setFechaContratacion(Fecha fechaContratacion) { this.fechaContratacion = fechaContratacion; }
        
        public Fecha getFechaContratacion() { return this.fechaContratacion; }
        
        public void setRfc(RFC rfc) { this.rfc = rfc; }
        
        public RFC getRfc() { return this.rfc; }
        
        public void setUser(String user) { this.user = user; }
        
        public String getUser() { return this.user; }
        
        public void setPassword(String password) { this.password = password; }
        
        public String getPassword() { return this.password; }
        
}

class Main implements Serializable {
        public static void main(String[] args) {
                // Se cargan los archivos para que no se tengan que llenar cada día
                Empleado[] empleados = cargarEmpleados();
                Cadena cadena = cargarCadena();
                
                // Identificar al empleado actual
                Empleado activeUser = login(empleados);
                System.out.println("Bienvenido: " + activeUser.getNombre());
                
                // Ciclo con el menú de opciones
                boolean continuar = true;
                do {
                        Scanner s = new Scanner(System.in);
                        byte opcion = 0;
                        System.out.print(
                        "\n\nMenú de opciones:\n" + 
                        "1. Registrar otra tienda\n" + 
                        "2. Agregar un producto\n" + 
                        "3. Modificar un producto\n" + 
                        "4. Agregar un servicio\n" + 
                        "5. Modificar un servicio\n" + 
                        "6. Buscar existencias\n" + 
                        "7. Registrar otro empleado\n" + 
                        "8. Cerrar el día\n" + 
                        "Opcion >>> "
                        );
                        try {
                                opcion = s.nextByte();
                        } catch (InputMismatchException e) {
                                System.out.println("Opción inválida, intenta de nuevo");
                        }
                        switch (opcion) {
                                case 1:
                                        cadena.registrarTienda(crearTienda());
                                        break;
                                case 2:
                                        System.out.println("En que tienda quieres agregar el producto: ");
                                        try {
                                                System.out.print(cadena + "\n>>> ");
                                                byte numTienda = s.nextByte();
                                                System.out.print("Ingresa el nombre del producto: ");
                                                cadena.getTiendasCadena()[numTienda - 1].registrarNombreProducto(s.next());
                                                System.out.print("Ingresa la cantidad del producto: ");
                                                cadena.getTiendasCadena()[numTienda - 1].registrarCantProducto(s.nextInt());
                                        } catch (InputMismatchException e) {
                                                System.out.println("Error con el dato ingresado");
                                        }
                                        break;
                                case 3:
                                        System.out.println("En que tienda quieres modificar el producto: ");
                                        System.out.print(cadena + "\n>>> ");
                                        try {
                                                byte numTienda = s.nextByte();
                                                cadena.getTiendasCadena()[numTienda - 1].modificarProducto();
                                        } catch (InputMismatchException e) {
                                                System.out.println("Error con el dato ingresado");
                                        }
                                        break;
                                case 4:
                                        System.out.println("En que tienda quieres agregar el servicio: ");
                                        System.out.print(cadena + "\n>>> ");
                                        try {
                                                byte numTienda = s.nextByte();
                                                System.out.print("Ingresa el nombre del servicio: ");
                                                cadena.getTiendasCadena()[numTienda - 1].registrarNombreServicio(s.next());
                                                System.out.print("Ingresa la disponibilidad: ");
                                                cadena.getTiendasCadena()[numTienda - 1].registrarDispServicio(s.nextBoolean());
                                        } catch (InputMismatchException e) {
                                                System.out.println("Error con el dato ingresado");
                                        }
                                        break;
                                case 5:
                                        System.out.println("En que tienda quieres modificar el servicio: ");
                                        System.out.print(cadena + "\n>>> ");
                                        try {
                                                byte numTienda = s.nextByte();
                                                cadena.getTiendasCadena()[numTienda - 1].modificarServicio();
                                        } catch (InputMismatchException e) {
                                                System.out.println("Error con el dato ingresado");
                                        }
                                        break;
                                case 6:
                                        System.out.println("Que vas a buscar, un producto o un servicio (p/s): ");
                                        switch (s.next().charAt(0)) {
                                                case 'p':
                                                System.out.println("Ingresa el nombre del producto: ");
                                                Producto p = new Producto(s.next(), 0, 0);
                                                imprimirReporte(p.buscarExistencia(cadena.getTiendasCadena()));
                                                break;
                                                case 's':
                                                System.out.println("Ingresa el nombre del servicio: ");
                                                Servicio s1 = new Servicio(s.next(), false, 0.0);
                                                imprimirReporte(s1.buscarExistencia(cadena.getTiendasCadena()));
                                                break;
                                        }
                                        break;
                                case 7:
                                        empleados = agregarEmpleado(empleados);
                                        break;
                                case 8:
                                        continuar = false;
                                        break;
                        }
                } while (continuar);
                
                System.out.println(guardarEmpleados(empleados));
                System.out.println(guardarCadena(cadena));
        }
        
        // Se carga el archivo de empleados
        public static Empleado[] cargarEmpleados() {
                // Se usan archivos de objetos, hay un empleado por defecto en caso de que no exista el archivo
                Empleado[] empleados = new Empleado[5];
                try {
                        FileInputStream fis = new FileInputStream(".\\empleados.dat");
                        ObjectInputStream ois = new ObjectInputStream(fis);
                        empleados = (Empleado[]) ois.readObject();
                        ois.close();
                        fis.close();
                } catch (FileNotFoundException e) {
                        System.out.println("Tu archivo de empleados no existe, se cargara el empleado predeterminado");
                } catch (IOException e) {
                        System.out.println("Hubo un error al leer el archivo, se usara el empleado predeterminado");
                } catch (ClassNotFoundException e) {
                        System.out.println("Hubo un error al registrar a los empleados, intente revisar el código");
                } finally {
                        if (empleados[0] == null) {
                                empleados[0] = new Empleado(
                                new Nombre("James Arthur Gosling"),
                                new Fecha("19/05/2021"),
                                new RFC("AUGJ550519HA5"),
                                "java_is_the_best",
                                "2F19478AA237EEB8"
                                );
                        }
                }
                
                return empleados;
        }
        
        public static Empleado[] agregarEmpleado(Empleado[] empleados) {
                // Método para agregar un empleado, en caso de que haya espacio
                if (empleados[empleados.length - 1] != null) {
                        System.out.println("No hay espacio para más empleados");
                        return empleados;
                }
                byte indice = 0;
                for (byte i = 0; i < empleados.length; i++)
                if (empleados[i] == null) {
                        indice = i;
                        break;
                }
                Scanner s = new Scanner(System.in);
                Nombre nombre = null;
                Fecha fecha = null;
                RFC rfc = null;
                String user = "";
                String pass = "";
                do {
                        if (nombre == null) {
                                System.out.print("Ingresa el nombre del empleado: ");
                                try {
                                        nombre = new Nombre(s.nextLine());
                                } catch (ArrayIndexOutOfBoundsException e) {
                                        System.out.println("El nombre consiste de un nombre y dos apellidos");
                                        continue;
                                }
                        }
                        if (fecha == null) {
                                System.out.print("Ingresa la fecha de contratación del empleado (dd/mm/aaaa): ");
                                try {
                                        fecha = new Fecha(s.next());
                                } catch (ArrayIndexOutOfBoundsException e) {
                                        System.out.println("Debes usar el formato de dd/mm/aaaa");
                                        continue;
                                }
                        }
                        if (rfc == null) {
                                System.out.print("Ingresa el RFC del empleado: ");
                                try {
                                        rfc = new RFC(s.next());
                                } catch (IndexOutOfBoundsException e) {
                                        System.out.println("Ese RFC esta incompleto");
                                        continue;
                                }
                        }
                        // Se revisa que el usuario no exista
                        if (user == "") {
                                System.out.print("Ingresa el user del empleado: ");
                                try {
                                        user = s.next();
                                } catch (NoSuchElementException e) {
                                        System.out.println("Hubo un error al leer el usuario");
                                        continue;
                                }
                                for (byte i = 0; i < empleados.length; i++)
                                if (empleados[i] != null && empleados[i].getUser().equals(user)) {
                                        user = "";
                                        System.out.println("Ese usuario ya existe");
                                }
                                if (user == "")
                                continue;
                        }
                        if (pass == "") {
                                System.out.print("Ingresa la contraseña del empleado: ");
                                try {
                                        pass = s.next();
                                } catch (NoSuchElementException e) {
                                        System.out.println("Hubo un error al leer la contraseña");
                                        continue;
                                }
                        }
                        empleados[indice] = new Empleado(
                        nombre,
                        fecha,
                        rfc,
                        user,
                        pass
                        );
                } while (empleados[indice] == null);
                
                return empleados;
        }
        
        // Se guardan los empleados al final del día para que no se registren al día siguiente
        public static String guardarEmpleados(Empleado[] empleados) {
                try {
                        FileOutputStream fos = new FileOutputStream(".\\empleados.dat");
                        ObjectOutputStream oos = new ObjectOutputStream(fos);
                        oos.writeObject(empleados);
                        oos.close();
                        fos.close();
                        return "Se guardaron los empleados con éxito";
                } catch (IOException e) {
                        return "Hubo un error al guardar a los empleados";
                }
        }
        
        // Se carga la cadena con sus tiendas
        public static Cadena cargarCadena() {
                Cadena cadena = null;
                try {
                        FileInputStream fis = new FileInputStream(".\\cadena.dat");
                        ObjectInputStream ois = new ObjectInputStream(fis);
                        cadena = (Cadena) ois.readObject();
                        ois.close();
                        fis.close();
                } catch (FileNotFoundException e) {
                        System.out.println("Tu archivo de cadena no existe, se cargara una cadena vacia");
                } catch (IOException e) {
                        System.out.println("Hubo un error al leer el archivo, se usara una cadena vacia");
                } catch (ClassNotFoundException e) {
                        System.out.println("Hubo un error al registrar la cadena, intente revisar el código");
                } finally {
                        if (cadena == null) {
                                cadena = new Cadena(
                                "Mi cadena", 
                                new Tienda[5]
                                );
                        }
                }
                
                return cadena;
        }
        
        // Se almacenan la cadena con sus tiendas
        public static String guardarCadena(Cadena cadena) {
                try {
                        FileOutputStream fos = new FileOutputStream(".\\cadena.dat");
                        ObjectOutputStream oos = new ObjectOutputStream(fos);
                        oos.writeObject(cadena);
                        oos.close();
                        fos.close();
                        return "Se guardo la cadena con éxito";
                } catch (IOException e) {
                        return "Hubo un error al guardar la cadena";
                }
        }
        
        // Se hace el login, solo se dice que se equivoco pero no en que, para que sea más seguro
        public static Empleado login(Empleado[] empleados) {
                String user, pass;
                int index = -1;
                Scanner s = new Scanner(System.in);
                do {
                        System.out.print("Ingresa tu nombre de usuario: ");
                        user = s.next();
                        System.out.print("Ingresa tu contraseña: ");
                        pass = s.next();
                        
                        for (int i = 0; i < empleados.length; i++)
                        if (empleados[i] != null && empleados[i].getUser().equals(user))
                        if (empleados[i].getPassword().equals(pass)) {
                                index = i;
                                break;
                        }
                        if (index == -1)
                        System.out.println("\nHubo un error con tus credenciales, intenta de nuevo\n");
                } while (index == -1);
                
                return empleados[index];
        }
        
        // Se crea una tienda
        public static Tienda crearTienda() {
                String calle, numero, colonia, municipio, estado, codigoPostal;
                calle = "";
                numero = "";
                colonia = "";
                municipio = "";
                estado = "";
                codigoPostal = "";
                Tienda tienda = null;
                
                do {
                        Scanner s = new Scanner(System.in);
                        if (calle == "") {
                                System.out.print("Ingresa la calle de la tienda: ");
                                try {
                                        calle = s.nextLine();
                                } catch (NoSuchElementException e) {
                                        System.out.println("Hubo un error al leer la calle");
                                        continue;
                                }
                        }
                        if (numero == "") {
                                System.out.print("Ingresa el número de la tienda: ");
                                try {
                                        numero = s.nextLine();
                                } catch (NoSuchElementException e) {
                                        System.out.println("Hubo un error al leer el número");
                                        continue;
                                }
                        }
                        if (colonia == "") {
                                System.out.print("Ingresa la colonia de la tienda: ");
                                try {
                                        colonia = s.nextLine();
                                } catch (NoSuchElementException e) {
                                        System.out.println("Hubo un error al leer la colonia");
                                        continue;
                                }
                        }
                        if (municipio == "") {
                                System.out.print("Ingresa el municipio de la tienda: ");
                                try {
                                        municipio = s.nextLine();
                                } catch (NoSuchElementException e) {
                                        System.out.println("Hubo un error al leer el municipio");
                                        continue;
                                }
                        }
                        if (estado == "") {
                                System.out.print("Ingresa el estado de la tienda: ");
                                try {
                                        estado = s.nextLine();
                                } catch (NoSuchElementException e) {
                                        System.out.println("Hubo un error al leer el estado");
                                        continue;
                                }
                        }
                        if (codigoPostal == "") {
                                System.out.print("Ingresa el código postal de la tienda: ");
                                try {
                                        codigoPostal = s.next();
                                } catch (NoSuchElementException e) {
                                        System.out.println("Hubo un error al leer el código postal");
                                        continue;
                                }
                        }
                        
                        tienda = new Tienda(
                        new Direccion(calle, numero, colonia, municipio, estado, codigoPostal)
                        );
                } while (tienda == null);
                
                return tienda;
        }
        
        // Se imprimen las tiendas que tienen lo que buscaba
        public static void imprimirReporte(Direccion[] direcciones) {
                if (direcciones[0] != null) {
                        System.out.println("Encontramos lo que buscabas en las siguientes tiendas");
                        for (byte i = 0; i < direcciones.length; i++) {
                                if (direcciones[i] != null) {
                                        System.out.println("Tienda " + (i + 1) + ", se encuentra en: " + direcciones[i]);
                                }
                        }
                } else {
                        System.out.println("No pudimos encontrarlo, lo sentimos");
                }
        }
}