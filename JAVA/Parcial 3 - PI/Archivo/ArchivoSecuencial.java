import java.io.*;
import java.util.*;

class ArchivoSecuencial {
        public static void main(String[] args) {
                String amigo;
                String tel;

                try {
                        File f = new File("C:\\Users\\Algui\\Downloads\\Amigos.txt");
                        FileOutputStream fos = new FileOutputStream(f);
                        PrintStream sos = new PrintStream(fos);

                        Scanner s = new Scanner(System.in);

                        for (int i = 1; i <= 5; i++) {
                                System.out.println("Ingresa el nombre del amigo " + i);
                                amigo = s.nextLine();
                                System.out.println("Ingresa el telefono del amigo " + i);
                                tel = s.nextLine();
                                sos.println(amigo + "," + tel);
                        }

                        sos.close();
                } catch (IOException e) {
                        System.out.println("Error en archivo: " + e);
                }
        }
}