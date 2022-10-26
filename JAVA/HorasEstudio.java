// Jan Carlo Reyes Martínez, 577441
// 20/05/2021
// Programa para registrar las horas de estudio de cada materia por cada mes y obtener estadisticas de ellas
// Doy mi palabra de que he realizado esta actividad con integridad académica

import java.io.*;
import java.util.*;

class HorasEstudio {
        public static void main(String[] args) {
                // Este es un arreglo que uso para poder imprimir los nombres de los meses
                String[] meses = { "Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre" };
                short[][] datos = HorasEstudio.leerDatos(meses);
                int[] horasMateria = HorasEstudio.calcularMateria(datos);
                int[] horasMes = HorasEstudio.calcularMes(datos);
                HorasEstudio.mostrarResultados(horasMateria, horasMes, meses);
        }

        public static short[][] leerDatos(String[] meses) {
                short[][] datos = new short[5][12];
                Scanner lector = new Scanner(System.in);

                // En este ciclo voy leyendo por cada materia sus horas de estudio en cada mes
                for (int i = 0; i < 5; i++) {
                        for (int j = 0; j < 12; j++) {
                                // Aquí convierto el mes a minusculas para que cuadre mejor en la oración
                                System.out.println("\nIngresa las horas de estudio de la materia " + (i + 1) + " en " + meses[j].toLowerCase());
                                // Una pequeña validación para que no haya números negativos
                                do {
                                        System.out.print("Tiene que ser un entero mayor o igual a 0\n>>> ");
                                        datos[i][j] = lector.nextShort();
                                } while (datos[i][j] < 0);
                        }
                }

                return datos;
        }

        public static int[] calcularMateria(short[][] datos) {
                int[] horasMateria = new int[5];
                int acum;

                // Creo un arreglo de 5 para guardar el total por cada materia y aquí lo voy sumando
                for (int i = 0; i < 5; i++) {
                        acum = 0;
                        for (int j = 0; j < 12; j++)
                                acum += datos[i][j];
                        horasMateria[i] = acum;
                }

                return horasMateria;
        }

        public static int[] calcularMes(short[][] datos) {
                int[] horasMes = new int[12];
                int acum;

                // Es casi lo mismo que el método para las materias, pero aquí se itera diferente porque quiero sumar columnas
                for (int i = 0; i < 12; i++) {
                        acum = 0;
                        for (int j = 0; j < 5; j++)
                                acum += datos[j][i];
                        horasMes[i] = acum;
                }

                return horasMes;
        }

        public static void mostrarResultados(int[] horasMareria, int[] horasMes, String[] meses) {
                // Aquí imprimo los resultados
                System.out.println("Estas son las horas que invertiste por cada materia");
                for (int i = 0; i < 5; i++)
                        System.out.println("Materia " + (i + 1) + ": " + horasMareria[i]);

                // Uso de nuevo el arreglo con los nombres de los meses, pero ahora sin convertir a minusculas
                System.out.println("\nEstas son las horas que invertiste por cada mes");
                for (int i = 0; i < 12; i++)
                        System.out.println(meses[i] + ": " + horasMes[i]);
        }
}