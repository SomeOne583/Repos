// interface Elemento{
//      Direccion [] buscarExistencia(Tienda [] tiendas);
// }

// class Producto implements Elemento{
//    private String nombre;
//    private double precio;
//    private int cantidadPro;
   
//    public Producto(String nombre, double precio, int cantidaPro){
//       setNombre(nombre);
//       setPrecio(precio);
//       setCantidadPro(cantidadPro);
//    }
//    //M�todos set
//    public void setNombre(String nombre){this.nombre=nombre;}
   
//    public void setPrecio(double precio){this.precio=precio;}
   
//    public void setCantidadPro(int cantidadPro){this.cantidadPro=cantidadPro;}
//    //M�todos get
//    public String getNombre(){return nombre;}
   
//    public double getPrecio(){return precio;}
   
//    public int getCantidadPro(){return cantidadPro;}
   
//    //M�todo para encontrar la ubicacion de la tienda que tenga cierto producto
//    public Direccion [] buscarExistencia (Tienda [] tiendas){
//       Direccion [] direcciones=new Direccion [5];
//       for (int i=0; i<tiendas.length;i++){
//          String [] productos=tiendas[i].getNombresProducto();
//          for (int j=0; j<productos.length;j++){
//             if (productos[j].equals(nombre)){
//                direcciones[i]=tiendas[i].getDireccionTienda();
//             }
            
//          }
//       }
      
//       return direcciones; 
//    }
// }


// class Servicio implements Elemento{
//    private String nombre;
//    private boolean disponibilidad;
//    private double comisionServ;
   
//    public Servicio (String nombre, boolean disponibilidad, double comisionServ){
//       setNombre(nombre);
//       setDisponibilidad(disponibilidad);
//       setComisionServ(comisionServ);
//    }
//    //M�todos set
//    public void setNombre(String nombre){this.nombre=nombre;}
   
//    public void setDisponibilidad(boolean disponibilidad){this.disponibilidad=disponibilidad;}
   
//    public void setComisionServ(double comisionServ){this.comisionServ=comisionServ;}
   
//    //M�todos get
//    public String getNombre(){return nombre;}
   
//    public boolean getDisponibilidad(){return disponibilidad;}
   
//    public double getComisionServ(){return comisionServ;}
   
//    //M�todo para encontrar la ubicacion de la tienda que tenga cierto servicio
//    public Direccion [] buscarExistencia(Tienda [] tiendas){
//       Direccion [] direcciones= new Direccion [5];
//       for (int i=0;i<tiendas.length;i++){
//          String [] servicios=tiendas[i].getNombresServicio();
//          boolean [] disponibilidad=tiendas[i].getDispervicio();
//          for (int j=0;j<servicios.length;j++){
//             if (disponibilidad[j]==true & servicios[j].equalsIgnoreCase(nombre)){
//                direcciones[i]=tiendas[i].getDireccionTienda();
//             }
//          }
//       }
//       return direcciones;  
   
//    }



// }




