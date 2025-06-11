public class Caixa {
    int quantidade;
    int valorRecebido;
    int valor;

    public Caixa(int quantidade, int valorRecebido, int valor) {
        this.quantidade = quantidade;
        this.valorRecebido = valorRecebido;
        this.valor = valor;
        int tots = valor * quantidade;
       tots=tots - valorRecebido;
       if(tots < 0){
           System.out.println("Valor a devolver: "+tots);
       }if(tots == 0){
           System.out.println("Sem troco");
        }
       if(tots > 0){
           System.out.println("Valor a receber:"+tots);
       }
    }
}
