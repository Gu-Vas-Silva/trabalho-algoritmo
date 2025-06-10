import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Digite o nível de glicose (mg/dl): ");
        double nivelGlicose = scanner.nextDouble();

        Glicose glicose = new Glicose(nivelGlicose);
        String classificacao = glicose.classificar();

        System.out.println("Classificação: " + classificacao);

        scanner.close();
    }
}