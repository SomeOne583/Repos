import java.io.*;

class ArchivoSecuencialL {
        public static void main(String[] args) {
                String amigo, nombre, telefono;
                File file = new File("C:\\Users\\Algui\\Downloads\\Amigos.txt");
                try {
                        FileInputStream f1 = new FileInputStream(file);
                        InputStreamReader f2 = new InputStreamReader(f1);
                        BufferedReader f3 = new BufferedReader(f2);

                        for (int i = 1; i <= 5; i++) {
                                amigo = f3.readLine();
                                nombre = amigo.split(",")[0];
                                telefono = amigo.split(",")[1];
                                System.out.println(nombre + ": " + telefono);
                        }
                        
                        f3.close();
                } catch (FileNotFoundException e) {
                        System.out.println("No se encontro el archivo");
                } catch (IOException e) {
                        System.out.println("Error en la lectura");
                }
        }
}
