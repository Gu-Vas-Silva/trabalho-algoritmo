import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Digite um numero: ");
        int num = sc.nextInt();
        System.out.println("Digite um numero: ");
        int num2 = sc.nextInt();
        Calculo calc = new Calculo(num, num2);
    }
}