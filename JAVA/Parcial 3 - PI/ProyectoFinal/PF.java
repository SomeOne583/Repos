// class Nombre {
//         private String nombre;
//         private String apellidoP;
//         private String apellidoM;
        
//         public Nombre(String nombreCompleto) {
//                 String nombre[] = nombreCompleto.split(" ");
//                 setNombre(nombre[0]);
//                 setApellidoP(nombre[1]);
//                 setApellidoM(nombre[2]);
//         }
        
//         public String getNombre() { return this.nombre; }
        
//         public void setNombre(String nombre) { this.nombre = nombre; }
        
//         public String getApellidoP() { return this.apellidoP; }
        
//         public void setApellidoP(String apellidoP) { this.apellidoP = apellidoP; }
        
//         public String getApellidoM() { return this.apellidoM; }
        
//         public void setApellidoM(String apellidoM) { this.apellidoM = apellidoM; }
        
//         public String toString() { return this.getNombre() + " " + this.getApellidoP() + " " + this.getApellidoM(); }
// }

// class RFC {
//         private String iniciales;
//         private String fechaNacimiento;
//         private String identificador;
        
//         public RFC(String rfc) {
//                 setIniciales(rfc.substring(0, 4));
//                 setFechaNacimiento(rfc.substring(4, 10));
//                 setIdentificador(rfc.substring(10));
//         }
        
//         public void setIniciales(String iniciales) { this.iniciales = iniciales; }
        
//         public String getIniciales() { return this.iniciales; }
        
//         public void setFechaNacimiento(String fechaNacimiento) { this.fechaNacimiento = fechaNacimiento; }
        
//         public String getFechaNacimiento() { return this.fechaNacimiento; }
        
//         public void setIdentificador(String identificador) { this.identificador = identificador; }
        
//         public String getIdentificador() { return this.identificador; }
        
//         public String toString() { return this.getIniciales() + this.getFechaNacimiento() + this.getIdentificador(); }
// }

// class Direccion {
//         private String calle;
//         private String numero;
//         private String colonia;
//         private String municipio;
//         private String estado;
//         private String codigoPostal;
        
//         public Direccion(String calle, String numero, String colonia, String municipio, String estado, String codigoPostal) {
//                 setCalle(calle);
//                 setNumero(numero);
//                 setColonia(colonia);
//                 setMunicipio(municipio);
//                 setEstado(estado);
//                 setCodigo(codigoPostal);
//         }
        
//         public void setCalle(String calle) { this.calle = calle; }
        
//         public String getCalle() { return this.calle; }
        
//         public void setNumero(String numero) { this.numero = numero; }
        
//         public String getNumero() { return this.numero; }
        
//         public void setColonia(String colonia) { this.colonia = colonia; }
        
//         public String getColonia() { return this.colonia; }
        
//         public void setMunicipio(String municipio) { this.municipio = municipio; }
        
//         public String getMunicipio() { return this.municipio; }
        
//         public void setEstado(String estado) { this.estado = estado; }
        
//         public String getEstado() { return this.estado; }
        
//         public void setCodigo(String codigoPostal) { this.codigoPostal = codigoPostal; }
        
//         public String getCodigo() { return this.codigoPostal; }
        
//         public String toString() {
//                 return this.getCalle() + " " + this.getNumero() + " " + this.getColonia() + " " + 
//                 this.getMunicipio() + " " + this.getEstado()+ " " + this.getCodigo();

//         }
// }

// class Fecha {
//         private String dia;
//         private String mes;
//         private String anio;
        
//         public Fecha(String fecha) {
//                 fecha = fecha.replace("-", "/");
//                 String partes[] = fecha.split("/");
//                 setDia(partes[0]);
//                 setMes(partes[1]);
//                 setAnio(partes[2]);
//         }
        
//         public void setDia(String dia) { this.dia = dia; }
        
//         public String getDia() { return this.dia; }
        
//         public void setMes(String mes) { this.mes = mes; }
        
//         public String getMes() { return this.mes; }
        
//         public void setAnio(String anio) { this.anio = anio; }
        
//         public String getAnio() { return this.anio; }
        
//         public String toString() { return this.getDia() + "/" + this.getMes() + "/" + this.getAnio(); }
// }


// class Empleado {
//         private Nombre nombre;
//         private Fecha fechaContratacion;
//         private RFC rfc;
//         private String user;
//         private String password;
        
//         Empleado(Nombre nombre, Fecha fechaContratacion, RFC rfc, String user, String password) {
//                 setNombre(nombre);
//                 setFechaContratacion(fechaContratacion);
//                 setRfc(rfc);
//                 setUser(user);
//                 setPassword(password);
//         }
        
//         public void setNombre(Nombre nombre) { this.nombre = nombre; }
        
//         public Nombre getNombre() { return this.nombre; }
        
//         public void setFechaContratacion(Fecha fechaContratacion) { this.fechaContratacion = fechaContratacion; }
        
//         public Fecha getFechaContratacion() { return this.fechaContratacion; }
        
//         public void setRfc(RFC rfc) { this.rfc = rfc; }
        
//         public RFC getRfc() { return this.rfc; }
        
//         public void setUser(String user) { this.user = user; }
        
//         public String getUser() { return this.user; }
        
//         public void setPassword(String password) { this.password = password; }
        
//         public String getPassword() { return this.password; }
// }

