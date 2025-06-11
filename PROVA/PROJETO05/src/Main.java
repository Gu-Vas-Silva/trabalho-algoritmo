import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.println("Valor do produto ");
        int valor = sc.nextInt();
        System.out.println("Quantidade de produtos ");
        int quantidade = sc.nextInt();
        System.out.println("Valor recebido do produto ");
        int valorRecebido = sc.nextInt();
        Caixa calc = new Caixa(quantidade, valorRecebido, valor);
    }
}