import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Codigo do produto que deseja do 1 ao 5: ");
        int cod = sc.nextInt();
        Produto produto = new Produto(cod);
        System.out.println("Quantidade a comprar: ");
        int qnt = sc.nextInt();
        System.out.println("Total a pagar: " +produto.calcularPreco(qnt));
        sc.close();
    }
}