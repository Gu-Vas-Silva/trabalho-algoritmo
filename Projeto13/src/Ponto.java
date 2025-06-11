public class Ponto {
    double x;
    double y;
    public Ponto(double x, double y){
        this.x = x;
        this.y = y;
    }
    public String posicao(){
        if (x == 0 && y == 0) {
            return "Origem";
        } else if (x == 0) {
            return "Eixo Y";
        } else if (y == 0) {
            return "Eixo X";
        } else if (x > 0 && y > 0) {
            return "Q1";
        } else if (x < 0 && y > 0) {
            return "Q2";
        } else if (x < 0 && y < 0) {
            return "Q3";
        } else {
            return "Q4";
        }
    }
}

