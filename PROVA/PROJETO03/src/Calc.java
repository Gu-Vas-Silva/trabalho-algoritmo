public class Calc {
    int a,b,c;

    public Calc(int a, int b, int c) {
        this.a = a;
        this.b = b;
        this.c = c;
        int menor = a ;
        if(b < menor){
            menor = b;
        }
        if(c < menor){
        menor = c;
        }
        System.out.println("Menor: "+menor);
        }
    }

