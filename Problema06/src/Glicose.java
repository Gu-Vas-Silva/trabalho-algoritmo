public class Glicose {
    private double nivel;

    public Glicose(double nivel) {
        this.nivel = nivel;
    }

    public String classificar() {
        if (nivel <= 100) {
            return "Normal";
        } else if (nivel <= 140) {
            return "Elevado";
        } else {
            return "Diabetes";
        }
    }
}

