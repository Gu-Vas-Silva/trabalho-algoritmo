import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("digite o valor de x: ");
        double x = sc.nextInt();
        System.out.println("digite o valor de y");
        double y = sc.nextInt();
        Ponto ponto = new Ponto(x, y);
        System.out.println("Posição: " + ponto.posicao());
        sc.close();
    }
}