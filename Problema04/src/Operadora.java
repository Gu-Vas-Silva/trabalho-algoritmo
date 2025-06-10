public class Operadora {
    public int minutos;

    public Operadora(int min){
        this.minutos = min;
        double valor = 50;
        if(min > 100){
            int sobra = min - 100;
            valor += sobra * 2;
        }
        System.out.println("Valor: " + valor);
    }
}
