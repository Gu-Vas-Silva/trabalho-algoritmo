public class Tempo {
    int horaInicial;
    int horaFinal;
    public Tempo(int incio, int fim){
        this.horaInicial = incio;
        this.horaFinal = fim;
    }
    public int calcularDuracao(){
        if(horaFinal > horaInicial){
            return horaFinal - horaInicial;
        }else{
            return (24 - horaInicial) + horaFinal;
        }
    }
}
