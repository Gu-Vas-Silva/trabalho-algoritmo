public class Nota {
    double nota1;
    double nota2;

    public Nota(double nota1, double nota2) {
        this.nota1 = nota1;
        this.nota2 = nota2;
        double mediafinal = (nota1+nota2);
        mediafinal = mediafinal / 2;
        System.out.println(mediafinal);
        if(mediafinal < 60){
            System.out.println("Reprovado");
        }else System.out.println("Aprovado");
    }

}
