import java.lang.Math;

public class Pythagorean {
  public static void main(String[] args) {
   for (int a=1; a<500; a++)
    for (int b=a; b<Math.sqrt(250000-a*a); b++)
     if (Math.sqrt(a*a+b*b) == Math.round(Math.sqrt(a*a+b*b)))
      System.out.println(""+a+"² + "+b+"² = "+(int)Math.round(Math.sqrt(a*a+b*b))+"²");
  }
}