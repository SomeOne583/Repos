import java.io.*;
import java.util.*;
class Amigo implements Serializable{
        private String nombre;
        private String correo;
        public Amigo(String nombre, String correo)
        {
                setNombre(nombre);
                setCorreo(correo);
        }
        public void setNombre(String nombre)
        {
                this.nombre=nombre;
        }
        public void setCorreo(String correo)
        {
                this.correo=correo;
        }
        public String toString()
        {
                return "amigo:"+nombre+" correo:"+correo;
        }
}
class ArchObjetoCrear implements Serializable{
        
        public static void main(String arg[])
        {
                try{
                        Scanner s=new Scanner(System.in);
                        FileOutputStream f=new FileOutputStream("C:\\Users\\Algui\\Documents\\Repos\\JAVA\\Parcial 3 - PI\\ArchivoObjetos\\archObj.dat");
                        ObjectOutputStream f2=new ObjectOutputStream(f);
                        System.out.println("ingresa el nombre del amigo");
                        String nom=s.next();
                        System.out.println("ingresa el correo electronico");
                        String correo=s.next();
                        Amigo a=new Amigo(nom,correo);
                        f2.writeObject(a);
                        f2.close();
                        f.close();
                }
                catch(IOException e){System.out.println("error en el archivo");}
                try{
                        FileInputStream f=new FileInputStream("C:\\Users\\Algui\\Documents\\Repos\\JAVA\\Parcial 3 - PI\\ArchivoObjetos\\archObj.dat");
                        ObjectInputStream f2=new ObjectInputStream(f);
                        Amigo a=(Amigo) f2.readObject();
                        System.out.println(a);
                        f2.close();
                        f.close();
                }
                catch(EOFException e){System.out.println("se llegó al fin de archivo");}
                catch(IOException e) {System.out.println("error en archivo");}
                catch(ClassNotFoundException e){System.out.println("no definida la clase");}   
                
        }
}
