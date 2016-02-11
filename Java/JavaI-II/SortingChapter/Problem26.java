public class Problem26 {

    public static void main(String[] args) {
        double b = 10;
        double p;
        for (p = 1; p < 200; p++) {
            if (p % b != 0)

            System.out.println(((Math.pow(b, p - 1) - 1)) / p + "       " + p);
        }
    }
}