import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Digite a distância da primeira tentativa (em metros): ");
        double t1 = scanner.nextDouble();

        System.out.print("Digite a distância da segunda tentativa (em metros): ");
        double t2 = scanner.nextDouble();

        System.out.print("Digite a distância da terceira tentativa (em metros): ");
        double t3 = scanner.nextDouble();

        Dardo arremesso = new Dardo(t1, t2, t3);
        System.out.println("Maior distancia: " + arremesso.maiorDis());
        scanner.close();
    }
}