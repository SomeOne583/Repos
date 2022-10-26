// Joel Ángel   -       570221
// Jan Reyes    -       577441
// Alan Zapata  -       621944
/*
Objetivo: Utilizar métodos y arreglos para manejar los datos obtenidos con el instrumento de evaluación para obtener estadisticas (media,
mediana, moda, desviación estándar y varianza) y gráficar las frecuencias de cada respuesta por pregunta
*/
// Damos nuestra palabra de que hemos realizado esta actividad con integridad académica

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;
import javax.swing.JFrame;
import java.awt.geom.Line2D;
import javax.swing.*;
import java.awt.*;
import java.text.*;

class Dashboard extends JPanel {
        double[] estadisticas;
        byte[][] frecuencias;

        // Es el método constructor de la clase donde recibimos los parámetros
        public Dashboard(double[] estadisticas, byte[][] frecuencias) {
                this.estadisticas = estadisticas;
                this.frecuencias = frecuencias;
        }

        // Sobreescribimos uno de los métodos de JPanel para dibujar las figuras que necesitamos
        public void paintComponent(Graphics g) {
                super.paintComponent(g);
                Graphics2D g2d = (Graphics2D) g;
                String[] nombres = { "Media", "Moda", "Mediana", "Varianza", "Desviacion estandar" };
                DecimalFormat df = new DecimalFormat("0.00");

                g2d.setFont(new Font("Comic Sans", Font.PLAIN, 14));
                g2d.setStroke(new BasicStroke(2f));

                for (int i = 0; i < 5; i++) {
                        g2d.drawString(nombres[i] + ": " + df.format(estadisticas[i]), 15, 14 * (i + 1));
                }

                int x1, x2, y1, y2;
                // Estos ciclos sirven para crear las filas y columnas en el dashboard que se muestra
                for (int i = 0; i < 3; i++) {
                        for (int j = 0; j < 5; j++) {
                                g2d.drawString("Pregunta " + (i * 5 + j + 1), 80 + 250 * j, 120 + 150 * (i + 1));
                                // Con estre ciclo se imprimen tanto las leyendas como los divisores del eje y
                                for (int k = 0; k <= 10; k += 2) {
                                        g2d.setColor(Color.LIGHT_GRAY);
                                        // Divisor
                                        g2d.draw(new Line2D.Double(15 + 250 * j, 80 + 150 * (i + 1) - k * 10, 15 + 250 * j + 4 * 50, 80 + 150 * (i + 1) - k * 10));
                                        g2d.setColor(Color.BLACK);
                                        // Leyenda
                                        g2d.drawString(Integer.toString(k), 250 * j, 85 + 150 * (i + 1) - k * 10);
                                }
                                // En este ciclo se generan las gráficas y los divisores del eje x con sus leyendas
                                for (int k = 0; k < 4; k++) {
                                        x1 = 15 + 250 * j + k * 50;
                                        y1 = 80 + 150 * (i + 1) - frecuencias[i * 5 + j][k] * 10;
                                        x2 = 15 + 250 * j + (k + 1) * 50;
                                        y2 = 80 + 150 * (i + 1) - frecuencias[i * 5 + j][k + 1] * 10;
                                        g2d.setColor(Color.LIGHT_GRAY);
                                        // Divisor
                                        g2d.draw(new Line2D.Double(x1, 80 + 150 * (i + 1), x1, 150 * (i + 1) - 20));
                                        g2d.setColor(Color.BLACK);
                                        // Leyenda
                                        g2d.drawString(Integer.toString(k + 1), x1, 100 + 150 * (i + 1));
                                        // Gráfica
                                        g2d.draw(new Line2D.Double(x1, y1, x2, y2));
                                }
                                // Se añaden los últimos elementos del eje x que no estaban en el ciclo
                                g2d.setColor(Color.LIGHT_GRAY);
                                g2d.draw(new Line2D.Double(15 + 250 * j + 4 * 50, 80 + 150 * (i + 1), 15 + 250 * j + 4 * 50, 150 * (i + 1) - 20));
                                g2d.setColor(Color.BLACK);
                                g2d.drawString("5", 15 + 250 * j + 4 * 50, 100 + 150 * (i + 1));
                        }
                }
        }
}

class Evaluacion {
        public static void main(String[] args) throws FileNotFoundException {
                byte[][] aD = Evaluacion.leerDatos(); /* Leemos nuestro archivo y ordenamos los datos en un 
                arreglo bidimensional con las respuestas a las preguntas */
                double[] estadisticas = Evaluacion.calcularEstadisticas(aD); /* Calculamos las estadisticas globales de 
                nuestros resultados y las guardamos en un arreglo */
                byte[][] frecuencias = Evaluacion.calcularFrecuencias(aD); /* Calculamos las frecuencias de cada respuesta 
                por cada pregunta y eso se guarda en un arreglo bidimensional para gráficarlo */
                Evaluacion.show(estadisticas, frecuencias); /* Llamamos el método que se usa para graficar todos los resultados 
                obtenidos a través de una interfaz de usuario gráfica */
        }

        public static byte[][] leerDatos() throws FileNotFoundException {
                byte[][] respuestas = new byte[15][12]; /* Se crea un arreglo para guardar las respuestas teniendo dos dimensiones, 
                15 renglones por ser 15 preguntas y 12 columnas por tener 12 respuestas */
                String[] linea = new String[17]; // Se crean dos arreglos que se usan para poder leer los resultados de cada línea en forma de arreglos
                String[] linea2 = new String[15]; // Luego se le quitan el primer y último valor pues no son de importancia aquí
                Scanner s = new Scanner(new File("./Evaluacion.csv")); /* Se carga el archivo que contiene los datos */

                s.nextLine(); // Se usa este método para saltar la primera línea del archivo que tiene los encabezados

                for (int i = 0; i < 12; i++) {
                        /* En el ciclo se lee el archivo línea por línea donde cada línea se guarda en un arreglo que se limpia y cambia de
                        tipo para poder almacenarse en el arreglo que se devuelve al terminar */
                        linea = s.nextLine().split(",");
                        linea2 = Arrays.copyOfRange(linea, 1, 16);
                        for (int j = 0; j < 15; j++) {
                                linea2[j] = linea2[j].replaceAll("\"", "");
                                respuestas[j][i] = (linea2[j].equals("")) ? 0 : (Byte.parseByte(linea2[j])); /* Esta es una validación en caso
                                de que una celda este vacia */
                        }
                }

                return respuestas; // Se regresa el arreglo una vez limpio y con el orden que necesitamos
        }

        public static double[] calcularEstadisticas(byte[][] respuestas) {
                // media / moda / mediana / varianza / desviación estándar
                // Inicializamos nuestras variables que usamos para calcular cada estadística
                double[] estadisticas = new double[5];

                double acum = 0;
                double media;
                short[] frecuencias = new short[5];

                // En este ciclo se calculan el acumulado de todos los números y las frecuencias con las que aparece de forma global
                // Esto para calcular el promedio y la moda
                for (int i = 0; i < 15; i++)
                        for (int j = 0; j < 12; j++) {
                                acum += respuestas[i][j];
                                if (respuestas[i][j] > 0)
                                        frecuencias[respuestas[i][j] - 1]++;
                        }
                // Se calcula la media
                media = acum / (178.0);

                // Esta es la forma de calcular el número que más se repite
                // Se compara cada índice para ver cual tiene la mayor frecuencia y se guarda ese índice
                byte indiceMayor = 0;
                for (byte i = 0; i < 5; i++)
                        if (frecuencias[i] > frecuencias[indiceMayor])
                                indiceMayor = i;

                // Se crea un nuevo arreglo de una dimensión con todas las respuestas para ordenarlo y obtener la mediana
                byte[] respuestas1D = new byte[180];
                for (int i = 0; i < 15; i++)
                        for (int j = 0; j < 12; j++)
                                // i y j
                                // 0 y 11 = 11
                                // 1 y 0 = 12
                                // 1 y 1 = 13
                                respuestas1D[i * 12 + j] = respuestas[i][j];
                // Se ordena el arreglo para tomar los valores del centro (mediana)
                Arrays.sort(respuestas1D);

                // Se calcula la varianza y la desviación estandar donde el ciclo representa la sumatoria en la formula
                acum = 0;
                for (int i = 0; i < 180; i++)
                        if (respuestas1D[i] > 0)
                                acum += Math.pow((respuestas1D[i] - media), 2);
                double varianza = acum / 177.0;
                double desviacion = Math.sqrt(varianza);

                // Se asigna cada valor a un índice diferente en las estadisticas para devolver ese arreglo
                estadisticas[0] = media;
                estadisticas[1] = indiceMayor + 1;
                estadisticas[2] = (respuestas1D[89] + respuestas1D[90]) / 2.0;
                estadisticas[3] = varianza;
                estadisticas[4] = desviacion;

                return estadisticas;
        }

        public static byte[][] calcularFrecuencias(byte[][] respuestas) {
                // Se genera un nuevo arreglo donde se almacenan las frecuencias por pregunta
                byte[][] frecuencias = new byte[15][5];

                // Se usa un ciclo que por cada pregunta itera sus resultados y obtiene las frecuencias
                for (int i = 0; i < 15; i++)
                        for (int j = 0; j < 12; j++)
                                if (respuestas[i][j] > 0)
                                        frecuencias[i][respuestas[i][j] - 1]++;

                // Se regresa ese arreglo
                return frecuencias;
        }

        public static void show(double[] estadisticas, byte[][] frecuencias) {
                // Primero creamos un frame en el cual podemos añadir elementos gráficos
                JFrame f = new JFrame("Resultados evaluación a tutores APS 2021");
                // Definimos el tamaño del frame que vamos a manejar
                f.setSize(new Dimension(1250, 700));
                // Definimos que al cerrar la ventana se termina el programa
                f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
                // Creamos una instancia de la clase que hicimos donde se generan los objetos que graficamos
                Dashboard dashboard = new Dashboard(estadisticas, frecuencias);
                // Añadimos nuestros objetos al frame para que sean visibles
                f.add(dashboard);
                // Definimos la visibilidad del frame en verdadero para que se muestre en pantalla
                f.setVisible(true);
        }
}
