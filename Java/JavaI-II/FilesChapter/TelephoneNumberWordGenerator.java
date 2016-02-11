
import java.util.Scanner;



public class TelephoneNumberWordGenerator

{

    String phoneNumber;
    char numberLetters[][] = {
            {'0','0','0'},{'1','1','1'},{'A','B','C'},
            {'D','E','F'},{'G','H','I'},{'J','K','L'},
            {'M','N','O'},{'P','R','S'},
            {'T','U','V'},{'W','X','Y'}};


    Scanner input = new Scanner (System.in);
    private ObjectOutputStream output;
    PrintStream printStream;
    char[] word = new char [7];


    public static void main(String[] args){
    public void getPhoneNumber(){
            System.out.println("Enter a seven-digit telephone number: ");
            phoneNumber = input.next();

        }
    }

    public void openFile()
    {
        try // open file
        {
            output = new ObjectOutputStream(
                    new FileOutputStream ( "Phonenumber.txt") );

        }// end try
        catch ( IOException ioEcception )
        {
            System.err.println( "Error opening file.");
        } // end catch
    }// end method open file

    public void addFileInfo( )
    {
        try
        {
            char[] chars = phoneNumber.toCharArray ();
            int [] digit = new int [chars.length];
            for (int i = 0; i < chars.length; i++)
            {
                digit[i] = Integer.parseInt(String.valueOf(chars[i]));
            }

            printStream = new PrintStream(output);
            printStream.println("\n");


            for ( int level0 = 0; level0 < 3; level0 ++ )
            {
                word[0] = numberLetters[digit[0]][level0];

                for ( int level1 = 0; level1 < 3; level1 ++ )
                {
                    word[1] = numberLetters[digit[1]][level1];

                    for ( int level2 = 0; level2 < 3; level2 ++ )
                    {
                        word[2] = numberLetters[digit[2]][level2];

                        for ( int level3 = 0; level3 < 3; level3 ++ )
                        {
                            word[3] = numberLetters[digit[3]][level3];

                            for ( int level4 = 0; level4 < 3; level4 ++ )
                            {
                                word[4] = numberLetters[digit[4]][level4];

                                for ( int level5 = 0; level5 < 3; level5 ++ )
                                {
                                    word[5] = numberLetters[digit[5]][level5];

                                    for ( int level6 = 0; level6 < 3; level6 ++ )
                                    {
                                        word[6] = numberLetters[digit[6]][level6];
                                        printStream.print(word);
                                    }
                                }
                            }
                        }
                    }
                }
            }

            System.out.println("File written.");
            System.exit(1);

        }
        catch (Exception exception )
        {
            System.err.println( "Error writing to file.");
            System.exit(1);
        }
    }

    public void closeFile()
    {
        try // close file
        {
            if ( output != null )
                output.close();
        }// end try
        catch (IOException ioException )
        {
            System.err.println( "Error closing file.");
            System.exit(1);
        }// end catch


    }// end method closeFile
}