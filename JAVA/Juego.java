//Jan Carlo Reyes Martínez - 577441
//María Fernanda Vázquez - 616683
/*Programa que genera un arreglo bidimensional de 8x7, con posiciones aleatorias para obstáculos(#),
jugador(*) y meta(M). El jugador se puede mover hacia arriba, abajo, derecha e izquierda. 
-Si jugador se topa con obtáculo, se reinicia el proceso.
-Mensajes de error "ganaste" y "perdiste"
*/

import java.io.*;
import java.util.*;

class Juego {
        public static void main(String[] args) {
                char status;
                do {
                        char[][] tablero = Juego.generarTablero(8, 7);
                        int[] coordenadasUsuario = Juego.acomodarUsuario(tablero);
                        do {
                                Juego.imprimirTablero(tablero, 8, 7);
                                status = Juego.moverse(coordenadasUsuario, tablero);
                        } while (status == 'j');
                        Juego.mensaje(status);
                } while (status == 'p');
        }

        public static char[][] generarTablero(int filas, int columnas) {
                char[][] tablero = new char[filas][columnas];
                int obstaculoX, obstaculoY, metaX, metaY;
                for (int i = 0; i < filas; i++)
                        for (int j = 0; j < columnas; j++)
                                tablero[i][j] = ' ';

                // Generar obstaculos
                for (int i = 0; i < 6; i++) {
                        do {
                                obstaculoX = (int) (Math.random() * 7);
                                obstaculoY = (int) (Math.random() * 8);
                        } while (tablero[obstaculoY][obstaculoX] == '#');
                        tablero[obstaculoY][obstaculoX] = '#';
                }

                // Generar meta
                do {
                        metaX = (int) (Math.random() * 7);
                        metaY = (int) (Math.random() * 8);
                } while (tablero[metaY][metaX] != ' ');
                tablero[metaY][metaX] = 'M';

                return tablero;
        }

        public static int[] acomodarUsuario(char[][] tablero) {
                int usuarioX, usuarioY;
                int[] coordenadasUsuario = new int[2];
                // Generar usuario
                do {
                        usuarioX = (int) (Math.random() * 7);
                        usuarioY = (int) (Math.random() * 8);
                } while ((tablero[usuarioY][usuarioX] != ' ') ||
                        ((usuarioX > 0 && tablero[usuarioY][usuarioX - 1] == '#') &&
                        (usuarioX < 6 && tablero[usuarioY][usuarioX + 1] == '#') &&
                        (usuarioY > 0 && tablero[usuarioY - 1][usuarioX] == '#') &&
                        (usuarioY < 7 && tablero[usuarioY + 1][usuarioX] == '#')
                        ));
                tablero[usuarioY][usuarioX] = '*';
                coordenadasUsuario[0] = usuarioX;
                coordenadasUsuario[1] = usuarioY;

                return coordenadasUsuario;
        }

        public static char moverse(int[] coordenadas, char[][] tablero) {
                Scanner s = new Scanner(System.in);
                char status = 'j';
                System.out.println("Qué dirección deseas ir:\n1. Arriba\n2. Abajo\n3. Derecha\n4. Izquierda");
                char direccion = s.next().charAt(0);
                tablero[coordenadas[1]][coordenadas[0]] = ' ';
                switch (direccion) {
                        case '1':
                                if (coordenadas[1] - 1 < 0)
                                        System.out.println("Movimiento imposible, intenta de nuevo");
                                else if (tablero[coordenadas[1] - 1][coordenadas[0]] == '#')
                                        status = 'p';
                                else if (tablero[coordenadas[1] - 1][coordenadas[0]] == 'M')
                                        status = 'g';
                                else
                                        coordenadas[1]--;
                                break;
                        case '2':
                                if (coordenadas[1] + 1 > 7)
                                        System.out.println("Movimiento imposible, intenta de nuevo");
                                else if (tablero[coordenadas[1] + 1][coordenadas[0]] == '#')
                                        status = 'p';
                                else if (tablero[coordenadas[1] + 1][coordenadas[0]] == 'M')
                                        status = 'g';
                                else
                                        coordenadas[1]++;
                                break;
                        case '3':
                                if (coordenadas[0] + 1 > 6)
                                        System.out.println("Movimiento imposible, intenta de nuevo");
                                else if (tablero[coordenadas[1]][coordenadas[0] + 1] == '#')
                                        status = 'p';
                                else if (tablero[coordenadas[1]][coordenadas[0] + 1] == 'M')
                                        status = 'g';
                                else
                                        coordenadas[0]++;
                                break;
                        case '4':
                                if (coordenadas[0] - 1 < 0)
                                        System.out.println("Movimiento imposible, intenta de nuevo");
                                else if (tablero[coordenadas[1]][coordenadas[0] - 1] == '#')
                                        status = 'p';
                                else if (tablero[coordenadas[1]][coordenadas[0] - 1] == 'M')
                                        status = 'g';
                                else
                                        coordenadas[0]--;
                                break;
                }
                tablero[coordenadas[1]][coordenadas[0]] = '*';

                return status;
        }

        public static void mensaje(char status) {
                switch (status) {
                        case 'g':
                               System.out.println("Felicidades, ganaste");
                               break;
                        case 'p':
                               System.out.println("Perdiste");
                               break;
                }
        }

        public static void imprimirTablero(char[][] tablero, int filas, int columnas) {
                System.out.print("\n\n\n");
                for (int i = 0; i < filas; i++) {
                        for (int j = 0; j < columnas; j++) {
                                System.out.print("|" + tablero[i][j]);
                        }
                        System.out.println("|");
                }
        }
}
