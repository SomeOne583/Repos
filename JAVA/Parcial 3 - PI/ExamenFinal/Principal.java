// Código hecho por Jan Carlo Reyes Martínez
// Fecha: 26/11/2021
// Examen final de la materia de programación intermedia
// Usando dos archivos de texto se obtienen datos que deben ser impresos en la pantalla
// Doy mi palabra de que he realizado esta actividad con integridad académica

import java.io.*;

// Una interfaz con el método básico de un reporte
interface Reporte {
        void imprimirReporte();
}

// El reporte de ventas
class Ventas implements Reporte {
        double ventasSabado;
        double ventasDomingo;
        double ventasLunes;

        // Su constructor
        Ventas(double ventasSabado, double ventasDomingo, double ventasLunes) {
                setVentasSabado(ventasSabado);
                setVentasDomingo(ventasDomingo);
                setVentasLunes(ventasLunes);
        }

        // Sets
        public void setVentasSabado(double ventasSabado) { this.ventasSabado = ventasSabado; }

        public void setVentasDomingo(double ventasDomingo) { this.ventasDomingo = ventasDomingo; }

        public void setVentasLunes(double ventasLunes) { this.ventasLunes = ventasLunes; }

        // Gets
        public double getVentasSabado() { return ventasSabado; }

        public double getVentasDomingo() { return ventasDomingo; }

        public double getVentasLunes() { return ventasLunes; }

        // Se imprime el reporte, use String.format para que se agreguen espacios según corresponda
        public void imprimirReporte() {
                System.out.println(
                        "\nRelación de ventas\n" +
                        String.format("%-18s", "Día") + String.format("%10s", "Importe") + "\n" + 
                        String.format("%-17s", "Sábado") + "$" + String.format("%10.2f", getVentasSabado()) + "\n" + 
                        String.format("%-17s", "Domingo") + "$" + String.format("%10.2f", getVentasDomingo()) + "\n" + 
                        String.format("%-17s", "Lunes") + "$" + String.format("%10.2f", getVentasLunes())
                );
        }
}

// reporte de satisfacción
class Satisfaccion implements Reporte {
        int contento;
        int triste;
        int indiferente;

        // Su constructor
        Satisfaccion(int contento, int triste, int indiferente) {
                setContento(contento);
                setTriste(triste);
                setIndiferente(indiferente);
        }

        // Sets
        public void setContento(int contento) { this.contento = contento; }

        public void setTriste(int triste) { this.triste = triste; }

        public void setIndiferente(int indiferente) { this.indiferente = indiferente; }

        // Gets
        public int getContento() { return contento; }

        public int getTriste() { return triste; }

        public int getIndiferente() { return indiferente; }

        // Método para imprimir, muy similar al anterior y se alinean
        public void imprimirReporte() {
                System.out.println(
                        "\nSatisfacción del cliente\n" + 
                        String.format("%-18s", "Contentos:") + String.format("%10o", getContento()) + "\n" + 
                        String.format("%-18s", "Tristes:") + String.format("%10o", getTriste()) + "\n" + 
                        String.format("%-18s", "Indiferentes:") + String.format("%10o", getIndiferente()) + "\n"
                );
        }
}

class Main {
        public static void main(String[] args) {
                Ventas ventas = leerVentas();
                ventas.imprimirReporte();

                Satisfaccion satisfaccion = leerSatisfaccion();
                satisfaccion.imprimirReporte();
        }

        // Se leen las ventas del archivo
        public static Ventas leerVentas() {
                String registro;
                double sabado = 0;
                double domingo = 0;
                double lunes = 0;
                
                // Try en caso de errores con archivo
                try {
                        // Use una ruta relativa pues todos los archivos (código y txt) estan en la misma carpeta
                        File f = new File(".\\ventasExamenIntermedia.txt");
                        FileInputStream file = new FileInputStream(f);
                        InputStreamReader f1 = new InputStreamReader(file);
                        BufferedReader f2 = new BufferedReader(f1);

                        boolean seguirLeyendo = true;

                        // Ciclo para leer
                        while (seguirLeyendo) {
                                registro = f2.readLine();
                                // Condición de que existe el dato
                                if (registro != null)
                                        // Se determina que día es y se suma
                                        switch (registro.split(",")[0].toLowerCase().charAt(0)) {
                                        case 's':
                                                sabado += Double.parseDouble(registro.split(",")[1]);
                                                break;
                                        case 'd':
                                                domingo += Double.parseDouble(registro.split(",")[1]);
                                                break;
                                        case 'l':
                                                lunes += Double.parseDouble(registro.split(",")[1]);
                                                break;
                                        }
                                else
                                        seguirLeyendo = false;
                        }

                        f2.close();
                } catch (FileNotFoundException e) {
                        System.out.println("No se encontro el archivo");
                } catch (IOException e) {
                        System.out.println("Hubo un problema de lectura");
                }

                return new Ventas(sabado, domingo, lunes);
        }

        // Mismo funcionamiento que para ventas pero con satisfacción
        public static Satisfaccion leerSatisfaccion() {
                String registro;
                int contento = 0;
                int triste = 0;
                int indiferente = 0;
                
                try {
                        File f = new File(".\\respuestasClienteExamen.txt");
                        FileInputStream file = new FileInputStream(f);
                        InputStreamReader f1 = new InputStreamReader(file);
                        BufferedReader f2 = new BufferedReader(f1);

                        boolean seguirLeyendo = true;

                        while (seguirLeyendo) {
                                registro = f2.readLine();
                                if (registro != null)
                                        switch (registro.charAt(0)) {
                                        case '1':
                                                contento++;
                                                break;
                                        case '2':
                                                triste++;
                                                break;
                                        case '3':
                                                indiferente++;
                                                break;
                                        }
                                else
                                        seguirLeyendo = false;
                        }

                        f2.close();
                } catch (FileNotFoundException e) {
                        System.out.println("No se encontro el archivo");
                } catch (IOException e) {
                        System.out.println("Hubo un problema de lectura");
                }

                return new Satisfaccion(contento, triste, indiferente);
        }
}