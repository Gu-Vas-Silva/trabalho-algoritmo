import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Hora que começou: ");
        int h1 = sc.nextInt();
        System.out.println("Hora que terminou: ");
        int h2 = sc.nextInt();
        if (h1 < 0 || h1 > 23 || h2 < 0 || h2 > 23) {
            System.out.println("Hora inválida. Deve estar entre 0 e 23.");
        }
        Tempo duracao = new Tempo(h1, h2);
        System.out.println("Duracao: " + duracao.calcularDuracao());
        sc.close();
    }
}