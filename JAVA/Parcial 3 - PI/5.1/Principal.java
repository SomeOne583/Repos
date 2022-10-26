import java.io.*;
import java.util.*;

class Mes {
        private String nombre;
        private double promedio;
        
        public Mes(String nombre, double promedio){
                setNombre(nombre);  
                setPromedio(promedio);
        }
        
        public void setNombre(String nombre){
                
                this.nombre=nombre;
                
        }
        
        public void setPromedio(double promedio){
                
                this.promedio=promedio;
        }
        
        public String getNombre(){
                
                return nombre;
        }
        
        public double getPromedio(){
                return promedio;  
        }
        
        public String toString(){
                return nombre+"\t\t"+promedio+"\n";
                
        }
}

class Reporte{
        private Mes[] meses;
        
        public Reporte(Mes[] meses){
                setMeses(meses);
        }
        
        public void setMeses(Mes[] meses){
                this.meses = meses;
        }
        public Mes[] getMeses(){
                return meses;
        }
        
        public int calcPromAlto(){
                int j = 0;
                for (int i = 0; i < 12 ; i++){
                        if(meses[i].getPromedio() > meses[j].getPromedio()){
                                j=i;
                        }
                }
                return j;
        } 
        
        public String toString(){
                String impresion ="\nPromedio de temperaturas del año 2020 \n Nombre \t\t\t Promedio \n";
                for(int i=0;i<12;i++){
                        impresion+=meses[i].toString();
                }
                impresion+="\nEl mes más alto es: \n" + meses[calcPromAlto()];
                return impresion;
        }
}

class Principal {
        public static void main(String[] args) {
                Mes[] mes = leerMeses();
                Reporte reporte = new Reporte(mes);
                System.out.print(reporte);
        }
        
        public static Mes[] leerMeses() {
                Mes[] m = new Mes[12];
                Scanner s = new Scanner(System.in);
                String[] meses = { "Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", 
                "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre" };
                for (int i = 0; i < 12; i++) {
                        System.out.print("Ingresa la temperatura promedio de " + meses[i] + ": ");
                        m[i] = new Mes(meses[i], s.nextDouble());
                }
                return m;
        }
}