import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Deseja usar Celcius ou Fahrenheit: ");
        int number = sc.nextInt();
        int temperatura;
        switch (number) {
            case 1:
                System.out.println("Temperatura em Fahrenheit: ");
                 temperatura = sc.nextInt();
                  Celcius calc = new Celcius(temperatura);
                  break;
             case 2:
                 System.out.println("Temperatura em Celcius: ");
                  temperatura = sc.nextInt();
                 Fahrenheit calc2 = new Fahrenheit(temperatura);
                  break;
                  default:
                      break;
        }
    }
}