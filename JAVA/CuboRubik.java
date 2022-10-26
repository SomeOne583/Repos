class CuboRubik {
        private String variedad;
        private boolean magnetico;

        public CuboRubik(String variedad, boolean magnetico) {
                this.variedad = variedad;
                this.magnetico = magnetico;
        }
}

class Principal {
        public static void main(String[] args) {
                CuboRubik cubo1 = new CuboRubik("3x3", true);
        }
}