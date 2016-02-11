



public class PrimeFactor {

    public static void main(String[] args) {
        for (int i = 2; i <= 500; i++) {
            if (isPrime(i) == true) {
                System.out.println(i);
            }
        }
    }

    public static boolean isPrime(int number) {
        if (number == 1) return false;
        if (number == 2) return true;
        if (number % 2 == 0) return false;
        for (int i = 3; i < number; i++) {
            if (number % i == 0) return false;
        }
        return true;
    }
}