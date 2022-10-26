class Factorial {
        public static void main(String[] args) {
                System.out.println(calcularFactorial(20));
        }

        public static long calcularFactorial(int n) {
                if (n <= 1)
                        return 1;
                else
                        return n * calcularFactorial(n - 1);
        }
}
