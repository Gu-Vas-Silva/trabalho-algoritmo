public class Aumento {
    double salario;
    public Aumento(double salario) {
        this.salario = salario;
        double percentual;
        if (salario <= 1000.00) {
            percentual = 20.0;
        } else if (salario <= 3000.00) {
            percentual = 15.0;
        } else if (salario <= 8000.00) {
            percentual = 10.0;
        } else {
            percentual = 5.0;
        }

        double aumento = salario * (percentual / 100);
        double novoSalario = salario + aumento;

        System.out.printf("Novo salario R$ %.2f\n", novoSalario);
        System.out.printf("Aumento R$ %.2f\n", aumento);
        System.out.printf("Porcentagem = %.0f%%\n", percentual);

    }
}
