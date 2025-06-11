public class Calcular {
    public double conf1;
    public double conf2;
    public double conf3;

    public Calcular(double conf1, double conf2, double conf3) {
        this.conf1 = conf1;
        this.conf2 = conf2;
        this.conf3 = conf3;
        if (conf1 == 0) {
            System.out.println("Coeficiente A deve ser diferente de 0");

        }
        double delta = conf2 * conf2 - 4 * conf1 * conf3;
        if (delta < 0) {
            System.out.println("Nao possui raiz");
        }else{
            double x1 = (-conf2 + Math.sqrt(delta)) / (2 * conf1);
            double x2 = (-conf2 - Math.sqrt(delta)) / (2 * conf1);

            System.out.printf("Raiz x1 = %.4f\n", x1);
            System.out.printf("Raiz x2 = %.4f\n", x2);
        }
    }
}
