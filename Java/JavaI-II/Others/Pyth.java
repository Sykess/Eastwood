/*
 Program Name: Pyth.java
 Author: Nathan Caron
 Assignment #4
 Date: 9/28/14
 Purpose: Create table with all pythagorean triples up to 500.
*/

public class Pyth
{
	public static void main(String[] args)
	{
		int side1, side2, hypotenuse;// declare all variables, we'll
									 // initialize them in loops

		System.out.printf("%-11s%-11s%-16s%n", "Side 1(A):", "Side 2(B):",
						  "Hypotenuse (C):"); // Print the top column for the table
						  					  // formatted right justified with 11
						  					  // spaces each for sides 1 and 2,
						  					  // and 16 sides for the hypotenuse.

		for(side1 = 1; side1 < 500; side1++) // loop through all side 1's
		{
			for(side2 = 1; side2 < 500; side2++)// for each side 1, loop all side 2's
			{

				// The following for loop will loop through every hypotenuse
				// 1-500 with every combination of sides 1 and 2
				for(hypotenuse = 1; hypotenuse < 500; hypotenuse++)
				{
					/* The following if statement will check every possible combination
					   of A^2 + B^2 = C^2 (side1^2 + side2^2 = hypotenuse^2) and for
					   every case that it is true, it will print side1 right justified
					   8 spaces over to be under the A, side2 11 spaces from that to
					   be under the B, and hypotenuse 16 spaces from that to be under
					   the c.  Note this list is so large that in order to print the
					   whole thing in the command prompt the buffer size had to be
					   increased before running the program, so I increased mine to
					   800 to make sure I got the entire table.
					 */
					if(side1*side1 + side2*side2 == hypotenuse * hypotenuse)
						System.out.printf("%8d%11d%16d%n", side1, side2, hypotenuse);

				} // end hypotenuse for loop
			} // end side2 for loop
		} // end side1 for loop
	} // end method main
} // end class Pyth