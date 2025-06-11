import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
      System.out.println("Coeficiente 1:");
      int conf1 = sc.nextInt();
      System.out.println("Coeficiente 2:");
      int conf2 = sc.nextInt();
      System.out.println("Coeficiente 3:");
      int conf3 = sc.nextInt();
      Calcular calc = new Calcular(conf1, conf2, conf3);
    }

                    }