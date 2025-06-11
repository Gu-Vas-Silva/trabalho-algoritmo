public class Celcius {
    int temperatura;
    public Celcius(int temperatura) {
        this.temperatura = temperatura;
        int celcius = temperatura -32;
        celcius = celcius / 10;
        System.out.println("Celcius: " + celcius);
    }
}
