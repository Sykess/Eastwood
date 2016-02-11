/*
 Program Name: SelectingShapes.java
 Author: Nathan Caron
 Assignment # 1
 Date: 2/3/2015
 Purpose: Create a JcomboBox and select a shape to be displayed
 		  20 times using paintComponent.
*/


import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import java.security.SecureRandom;


public class SelectingShapes extends JPanel implements ItemListener
{
	private static final String[] names = {"Line", "Square", "Rectangle", "Circle", "Oval", "Triangle"};
	private static final Color[] colors = {Color.RED, Color.GREEN, Color.BLUE,
											Color.ORANGE, Color.PINK, Color.CYAN,
											Color.MAGENTA, Color.YELLOW, Color.BLACK,
											Color.WHITE, Color.GRAY, Color.LIGHT_GRAY,
											Color.DARK_GRAY};
	int selectedIndex = 0;
	SecureRandom random = new SecureRandom();

   public SelectingShapes()
   {
	   JComboBox comboBox = new JComboBox(names);
	   add(comboBox);
	   comboBox.setSelectedIndex(0); // start index at Line
	   comboBox.addItemListener(this);
   }


	public void itemStateChanged(ItemEvent e)
	{
		if (e.getStateChange() == ItemEvent.SELECTED)
		{
			JComboBox combo = (JComboBox) e.getSource();
       		selectedIndex = combo.getSelectedIndex();
		}
		repaint();
	}

	@Override
	public void paintComponent(Graphics g)
	{
		super.paintComponent(g);

		for(int x = 0; x < 20; x++)
		{
			int equiSide = random.nextInt(250);
			int colorPos = random.nextInt(13);
			int triPt1 = random.nextInt(450);
			int triPt2 = random.nextInt(450);
			int triPt3 = random.nextInt(450);
			int triPt4 = random.nextInt(450);
			int triPt5 = random.nextInt(450);
			int triPt6 = random.nextInt(450);

			int[] xpts = {triPt1, triPt2, triPt3};
			int[] ypts = {triPt4, triPt5, triPt6};
			int pts = 3;

			g.setColor(colors[colorPos]);

			if(selectedIndex == 0)
				g.drawLine(random.nextInt(450), random.nextInt(450),
					random.nextInt(450), random.nextInt(450));
			if(selectedIndex == 1)
				g.drawRect(random.nextInt(250), random.nextInt(250), equiSide, equiSide);
			if(selectedIndex == 2)
				g.drawRect(random.nextInt(250), random.nextInt(250),
					random.nextInt(250), random.nextInt(250));
			if(selectedIndex == 3)
				g.drawOval(random.nextInt(250), random.nextInt(250), equiSide, equiSide);
			if(selectedIndex == 4)
				g.drawOval(random.nextInt(250), random.nextInt(250),
					random.nextInt(250), random.nextInt(250));
			if(selectedIndex == 5)
				g.drawPolygon(xpts, ypts, pts);
		}
	}
}