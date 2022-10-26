import java.time.LocalDate;
import java.util.*;

class Main1 {
        public static void main(String[] args) {
                LocalDate nuevaFecha = calcularFecha();
                System.out.println(nuevaFecha);
        }

        public static LocalDate leerFecha() {
                Scanner s = new Scanner(System.in);
                System.out.println("Ingresa la fecha que quieres manipular usando el formato DD/MM/AAAA");
                String[] date = s.next().split("/");

                return LocalDate.of(Integer.parseInt(date[2]),
                                    Integer.parseInt(date[1]),
                                    Integer.parseInt(date[0]));
        }

        public static short[] leerPeriodo() {
                Scanner s = new Scanner(System.in);
                System.out.println("Ingresa el periodo que quieres añadir a la fecha (1 semana, 2 años, 3 meses, etc");
                String[] lectura = s.nextLine().split(" ");
                short[] periodo = new short[2];
                periodo[0] = Short.parseShort(lectura[0]);
                
                switch (lectura[1].toLowerCase().charAt(0)) {
                case 's':
                        periodo[1] = 1;
                        break;
                case 'm':
                        periodo[1] = 2;
                        break;
                case 'a':
                        periodo[1] = 3;
                        break;
                }

                return periodo;
        }

        public static LocalDate calcularFecha() {
                LocalDate fecha = leerFecha();
                short[] periodo = leerPeriodo();

                LocalDate nuevaFecha = fecha;
                switch (periodo[1]) {
                case 1:
                        nuevaFecha = nuevaFecha.plusWeeks(periodo[0]);
                        break;
                case 2:
                        nuevaFecha = nuevaFecha.plusMonths(periodo[0]);
                        break;
                case 3:
                        nuevaFecha = nuevaFecha.plusYears(periodo[0]);
                        break;
                }
                
                return nuevaFecha;
        }
}
