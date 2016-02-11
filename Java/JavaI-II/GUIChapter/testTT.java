/*
 Program Name: testTT.java
 Author: Nathan Caron
 Assignment # 12
 Date:12/10/2014
 Purpose: Test out typing tutor.
*/

import javax.swing.JFrame;
import static java.lang.Math.;


public class testTT
{
	public static void main(String[] args)
	{
		CaronNateTT window = new CaronNateTT();
		window.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		window.setSize(710, 400);
		window.setVisible(true);
		window.setResizable(false);
	}
}