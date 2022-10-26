import java.io.*;
class Billetes {
  public static void main(String[] args) {
    int cantidad = 1576;
    int billetes_Quinientos = cantidad / 500;
    int restante = cantidad - billetes_Quinientos * 500;
    int billetes_Doscientos = restante / 200;
    int restante2 = restante - billetes_Doscientos * 200;
    int billetes_Cien = restante2 / 100;
    int restante3 = restante2 - billetes_Cien * 100;
    int billetes_Cincuenta = restante3 / 50;
    int restante4 = restante3 - billetes_Cincuenta * 50;
    int billetes_Veinte = restante4 / 20;
    int restante5 = restante4 - billetes_Veinte * 20;
    int monedas_Diez = restante5 / 10;
    int restante6 = restante5 - monedas_Diez * 10;
    int monedas_Cinco = restante6 / 5;
    int restante7 = restante6 - monedas_Cinco * 5;
    int monedas_Dos = restante7 / 2;
    int restante8 = restante7 - monedas_Dos * 2;
    int monedas_Uno = restante8;
    System.out.println("La cantidad es: $" + cantidad);
    System.out.println("La cantidad de billetes de $500 es: : " + billetes_Quinientos);
    System.out.println("La cantidad de billetes de $200 es: : " + billetes_Doscientos);
    System.out.println("La cantidad de billetes de $100 es: : " + billetes_Cien);
    System.out.println("La cantidad de billetes de $50 es: : " + billetes_Cincuenta);
    System.out.println("La cantidad de billetes de $20 es: : " + billetes_Veinte);
    System.out.println("La cantidad de monedas de $10 es: : " + monedas_Diez);
    System.out.println("La cantidad de monedas de $5 es: : " + monedas_Cinco);
    System.out.println("La cantidad de monedas de $2 es: : " + monedas_Dos);
    System.out.println("La cantidad de monedas de $1 es: : " + monedas_Uno);
  }
}