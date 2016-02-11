import java.util.ArrayList;
import java.util.List;

public class PrimeFactors {
  public static List<Integer> primeFactors(int number)
  {
    //int n = number;
    List<Integer> factors = new ArrayList<Integer>();
    for (int i = 2; i <= number; i++) {
      while (number % i == 0) {
        factors.add(i);
        number /= i;

      }
    }
    return factors;
  }

  public static void main(String[] args) {
    System.out.println("Primefactors of 44");
    for (Integer integer : primeFactors(44)) {
      System.out.println(integer);
    }
    System.out.println("Primefactors of 54");
    for (Integer integer : primeFactors(54)) {
      System.out.println(integer);
    }
    System.out.println("Primefactors of 11");
    for (Integer integer : primeFactors(11)) {
      System.out.println(integer);
    }
  }
}