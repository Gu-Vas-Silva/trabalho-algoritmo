public class Dardo {
    double dis1;
    double dis2;
    double dis3;
    public Dardo(double d1, double d2, double d3){
        this.dis1 = d1;
        this.dis2 = d2;
        this.dis3 = d3;
    }
    public double maiorDis(){
        double maior = dis1;
        if(dis2>maior){
            maior = dis2;
        }
        if (dis3>maior){
            maior = dis3;
        }
        return maior;
    }
}
