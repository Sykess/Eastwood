public class Command
{
public static void main(String[] args)
{

// If a value is not entered on the command line this block executes
if(args.length < 1)
{
int [] array = new int[10];

System.out.printf("%s%8s%n", "Index" , "Value");

for(int counter = 0; counter < array.length; counter ++)
System.out.printf("%5s%8s%n", counter , array[counter]);
}

// If values are entered on the command line this block executes
else
{
int arrayLength = Integer.parseInt(args[0]);

int[] array = new int[arrayLength];

System.out.printf("%s%8s%n", "Index", "Value");

for(int counter = 0; counter < array.length; counter++)
System.out.printf("%5d%8d%n", counter, array[counter]);
}
}
}