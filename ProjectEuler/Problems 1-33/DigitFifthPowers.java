public class DigitFifthPowers {

    public static void main(String[] args) {
        long sum, num, total = 0;

        for (int i=10; i<200000; i++) {
            sum = 0; num = i;
            do {
                sum += (long)Math.pow(num % 10, 5);
                num /= 10;
            } while (num > 0);

            if (i == sum) total += i;
        }

        System.out.println("SUM: " + total);
    }
}