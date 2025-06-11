public class Calculo {
    int num1, num2;
    public Calculo(int num1, int num2) {
        this.num1 = num1;
        this.num2 = num2;
        if (num1 == 0 || num2 == 0) {
            System.out.println("Zero não pode ser usado para verificar múltiplos.");
        } else if (num1 % num2 == 0 || num2 % num1 == 0) {
            System.out.println("Os números são múltiplos entre si.");
        } else {
            System.out.println("Os números NÃO são múltiplos entre si.");
        }

    }
    }

