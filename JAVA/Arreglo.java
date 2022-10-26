import java.io.*;

class Arreglo {
        public static void main(String[] args) {
                byte[] b = { 5, 8, 12, 35, 42, 0 };
                
                System.out.println(b[0]);
                System.out.println(b[2]);

                byte[][] r = { { 100, 88, 90 }, { 75, 95, 100 }, { 100, 45, 65 } };
                System.out.println(r[1][1]);
        }
}
