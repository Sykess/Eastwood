import java.util.HashMap;
public class Problem51
{

    public static HashMap<String, Boolean> all = new HashMap<String, Boolean>();
   
    public static boolean isPrime(int n) {
        if(n < 2) {
            return false;
        } 
        for(int i = 2; i*i <= n; i ++) {
            if(n%i == 0)
                return false;
            if(i != 2)
                i++;
        }
        return true;
    }
    
    public static void perms(String pre, String word) {
        int n = word.length();
        if(n == 0) {
            all.put(pre, true);
            
        } else {
            for(int i = 0; i < n; i++) {
                perms(pre + word.charAt(i), word.substring(0, i) + word.substring(i+1, n));
            }
        }
    }
    
    public static void main(String[] args) {
        long startTime = System.nanoTime();
        StringBuilder builder = new StringBuilder();
        builder.append("*");
        int distance = 1;
        int primes = 8;
        int numPrimes = 0;
        
        while(numPrimes < primes) {
            builder.append("*");
            String temp = builder.toString();
            for(int i = 1; i <= Math.pow(10,distance); i++) {
                builder.replace(temp.length()-String.valueOf(i-1).length(), temp.length(), String.valueOf(i-1));
                String temp2 = builder.toString();
                perms("", temp2);
            }
            for(String s : all.keySet()) {
                numPrimes = 0;
                for(int j = 0; j < 10; j++) {
                    String t = s.replace("*", String.valueOf(j));
                    int num = Integer.parseInt(t);
                    if(isPrime(num) && temp.length() == String.valueOf(num).length()) 
                        numPrimes++;
                }
                if(numPrimes == primes) {
                    System.out.println(s);
                    break;
                }
            }
            builder = new StringBuilder(temp);
            distance++;
        }
        
        System.out.println((System.nanoTime()-startTime)/1000000 + " ms");
    }
}