import java.util.Scanner; // program uses class Scanner

public class Anwo
{
    // main method begins execusion of Java application
    public static void main(String[] args)
    {
        int num1; // first number
        int num2; // second number
        int num3; //third number
        int sum, avg, prod, small, large; //total of all numbers


        // create Scanner to optain input from command line
        Scanner input=new Scanner(System.in);

        System.out.print("Enter the first integer: ");
        num1=input.nextInt(); // read first number from the user

        System.out.print("Enter the second integer: ");
        num2=input.nextInt(); //read second number from the user

        System.out.print("Enter the third integer: ");
        num3=input.nextInt(); // read third number from the user

        sum=num1+num2+num3; // total of all three numbers

        avg=(num1+num2+num3)/3; //average of the three numbers

        prod=num1*num2*num3; //product of all numbers

        //finding the largest number by using the if statment

        if(num1>num2)
        {
            if(num1>num3)
               large=num1;
            else
               large=num3;
        }
        else
        {
            if(num2>num3)
                large=num2;
            else
                   large=num3;
        }

        //finding smallest number by also using the if statment

        if(num1<num2)
        {
            if(num1<num3)
                small=num1;
            else
                small=num3;

        }
        else
        {
            if(num2<num3)
               small=num2;
            else

               small=num3;
        }


        //outputting sum, average, product, largest and smallest numbers

        System.out.printf("The three numbers of sum=%d",sum);         // to display sum
        System.out.printf("\n The three number of average=%d",avg);  // to display average
        System.out.printf("\n The three numbers of product=%d",prod);// to display product
        System.out.printf("\n The three number of largest=%d",large);// to display largest number
        System.out.printf("\n The three numbers of smallest=%d",small);// to display smallest number


        //exit program
        System.exit(0);
    } //end main
} //end class 
