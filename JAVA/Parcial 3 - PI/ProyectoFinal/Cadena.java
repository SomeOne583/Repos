// import java.io.*;
// import java.util.*;
// import java.text.*;

// class Cadena{
//    //Atributos de clase cadena
//    private String nombreCadena;
//    private Tienda[] tiendasCadena;
//    //Constructor de clase cadena, recibe String y arreglo de objetos de clase Tienda
//    public Cadena(String nombresCadena, Tienda[] tiendasCadena){
//       setNombreCadena(nombresCadena);
//       setTiendasCadena(tiendasCadena);
//    }
//    //M�todos SET y GET
//    public void setNombreCadena(String nombresCadena){
//       this.nombresCadena = nombresCadena;
//    }
//    public void setTiendasCadena(Tienda[] tiendasCadena){
//       this.tiendasCadena = tiendasCadena;
//    }
//    public String getNombreCadena(){
//       return nombresCadena;
//    }
//    public Tienda[] getTiendasCadena(){
//       return tiendasCadena;
//    }
//    //M�todo para registrar en el arreglo de tiendas
//    public tiendasCadena[] registrarTienda(Tienda tienda1){
//       for (int i = 0; i < tiendasCadena.length; i++) {
//          if (tiendasCadena[i] == null){
//             tiendasCadena[i] = tienda1;
//             System.out.println("�Tienda agregada!");
//          }
//          else if(tiendaCadena[i] != null)
//             System.out.println("Registrando");
//          else
//             System.out.println("�Tienda no agregada!");
//       }
//       return tiendasCadena;
//    }
// }

// class Tienda{
//    //Atributos de clase Tienda
//    private Direccion direccionTienda;
//    private String[] nombresProducto;
//    private int[] cantProductos;   
//    private String[] nombresServicio; 
//    private boolean[] dispServicios;   

//    //Constructor de clase Tienda
//    public Tienda(Direccion direccionTienda){
//       setDireccionTienda(direccionTienda);
//    }
//    //M�todos SET y GET
//    public void setDireccionTienda(Direccion direccionTienda){
//       this.direccionTienda = direccionTienda;
//    }
//    public Direccion getDireccionTienda(){
//       return direccionTienda;
//    }
//    public void setNombresProducto(String[] nombresProducto){
//       this.nombresProducto = nombresProducto;
//    }
//    public String[] getNombresProducto(){
//       return nombresProducto;
//    }
//    public void setCantProducto(int[] cantProductos){
//       this.cantProductos = cantProductos;
//    }
//    public String[] getCantProducto(){
//       return cantProductos;
//    }
//    public void setNombresServicio(String[] nombresServicio){
//       this.nombresServicio = nombresServicio;
//    }
//    public String[] getNombresServicio(){
//       return nombresServicio;
//    }
//    public void setDispervicio(boolean[] dispServicios){
//       this.dispServicios = dispServicios;
//    }
//    public boolean[] getDispervicio(){
//       return dispServicios;
//    }
//    //meter un producto como argumento para meterlo al arreglo
//    public String[] registrarNombreProducto(String nombreP){
//       for (int i = 0; i < tiendasCadena.length; i++) {
//          if (nombresProducto[i] == null){
//             nombresProducto[i] = nombreP;
//             System.out.println("�Nombre agregado!");
//          }
//          else if(nombresProducto[i] != null)
//             System.out.println("Registrando");
//          else
//             System.out.println("�Nombre no agregado!");
//       }
//       return nombresProducto;
//    }
//    public int[] registrarCantProducto(int cantP){
//       for (int i = 0; i < tiendasCadena.length; i++) {
//          if (cantProductos[i] == null){
//             cantProductos[i] = cantP;
//             System.out.println("�Cantidad agregada!");
//          }
//          else if(nombresProducto[i] != null)
//             System.out.println("Registrando");
//          else
//             System.out.println("�Cantidad no agregada!");
//       }
//       return cantProductos;
//    }
//    public String[] registrarNombreServicio(String nombreS){
//       for (int i = 0; i < tiendasCadena.length; i++) {
//          if (nombresServicio[i] == null){
//             nombresServicio[i] = nombreS;
//             System.out.println("�Servicio agregado!");
//          }
//          else if(nombresServicio[i] != null)
//             System.out.println("Registrando");
//          else
//             System.out.println("�Servicio no agregado!");
//       }
//       return nombresServicio;
//    }
//    public boolean[] registrarDispServicio(boolean dispS){
//       for (int i = 0; i < tiendasCadena.length; i++) {
//          if (dispServicios[i] == null){
//             dispServicios[i] = dispS;
//             System.out.println("�Disponibilidad agregada!");
//          }
//          else if(dispServicios[i] != null)
//             System.out.println("Registrando");
//          else
//             System.out.println("�Disponibilidad no agregada!");
//       }
//       return dispServicios;
//    }
//    //En metodos de mod habr� que mddificar los 2 atributos al mismo tiempo
//    public void modificarProducto(){
//       Scanner s = new Scanner(System.in);
//       //Metodo para imprimir productos disponibles
//       imprimirProductos();
//       //Modificar producto
//       System.out.println("Escoge un producto a modificar: ");
//       int prodmod = s.nextInt();
//       System.out.println("Escoge un nuevo nombre de producto: "); 
//       nombresProducto[promdmod - 1] = s.next();
//       System.out.println("Escoge una nueva cantidad de producto: "); 
//       cantProductos[promdmod - 1] = s.nextInt();
//    }
//    public void modificarServicio(){
//       Scanner s = new Scanner(System.in);
//       //Metodo para imprimir servicios disponibles
//       imprimirServicios();
//       //Modificar servicio
//       System.out.println("Escoge un servicio a modificar: ");
//       int servmod = s.nextInt();
//       System.out.println("Escoge un nuevo nombre de servicio: "); 
//       nombresServicio[servmod - 6] = s.next();
//       System.out.println("Escoge una nueva disponibilidad de servicio: "); 
//       dispServicios[promdmod - 6] = s.nextBoolean();
//    }
//    public void eliminarElemento(){      
//       System.out.println("PRODUCTOS");
//       imprimirProductos();
//       System.out.println("SERVICIOS");
//       imprimirServicios();
//       System.out.println("Escoge un elemento a eliminar: ");
//       int elemdelete = s.nextInt();
//       //Eliminar Producto
//       if(elemdelee < 6){
//          nombresProducto[elemdelete-1] = null;
//          cantProductos[elemdelete-1] = null;
//       }
//       else{ //Eliminar Servicio
//          nombresServicio[elemdelete-6] = null;
//          dispServicios[elemdelete-6] = null;
//       }      
//    }
   
//    public void imprimirProductos(){
//       System.out.println("\t Numero "+"\t Nombre "+"\t Cantidad ");
//       for (int i = 0; i < tiendasCadena.length; i++) {
//          System.out.println("\t "+ (i+1) + "\t " + nombresProducto[i] + "\t " + cantProductos[i]);
//       }
//    }
   
//    public void imprimirServicios(){
//       System.out.println("\t Numero "+"\t Nombre "+"\t Disponibilidad ");
//       for (int i = 0; i < tiendasCadena.length; i++) {
//          System.out.println("\t "+ (i+6) + "\t " + nombresServicio[i] + "\t " + dispServicios[i]);
//       }
//    }
// }