import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Digite seu salario:");
        double salarios = sc.nextInt();
    Aumento pessoa = new Aumento(salarios);
    }
        }