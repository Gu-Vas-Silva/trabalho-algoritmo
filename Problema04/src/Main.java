import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("quantidade de minutos: ");
        int min = sc.nextInt();
        Operadora op = new Operadora(min);
        sc.close();
    }
}