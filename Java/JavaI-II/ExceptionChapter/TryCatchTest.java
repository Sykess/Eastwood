


public class TryCatchTest
{
    public static void main(String args[])
    {
        int a = 10, b = 0;

        try
        {
            int c = a/b;
        }
        catch(ArithmeticException e)
        {
            System.err.printf("%s", e);
        }
        catch(RuntimeException e)
        {
            System.err.printf("%s", e);
        }
    }
}