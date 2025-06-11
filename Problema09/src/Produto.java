public class Produto {
    public static int[] codigos = {1,2,3,4,5};
    public static double precos[] = {5.00, 3.50, 4.80, 8.90, 7.32};
    int codigo;
    double preco;

    public Produto(int codigo) {
        this.codigo = codigo;
        this.preco = buscarPreco(codigo);
    }
    public double buscarPreco(int codigo) {
        for(int i = 0; i<5; i++){
            if(codigos[i] == codigo){
                return precos[i];
            }
        }
        return 0;
    }
    public double calcularPreco(int quant){
        return preco * quant;
    }
}
